param(
    [switch]$Test
)

$ErrorActionPreference = "Stop"

# ============================================================
# CONFIG
# ============================================================

$RepoRoot = Split-Path -Parent $PSScriptRoot
$CodeforcesHandle = "ashCodes404"

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "       CODEFORCES SOLUTION ORGANIZER    " -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# ============================================================
# FIND LATEST CPH .PROB FILE
# ============================================================

$probFiles = Get-ChildItem `
    -Path (Join-Path $RepoRoot ".cph") `
    -Filter "*.prob" `
    -File `
    -ErrorAction SilentlyContinue

if (-not $probFiles) {
    Write-Host "No CPH .prob file found." -ForegroundColor Red
    exit 1
}

$probFile = $probFiles |
    Sort-Object LastWriteTime -Descending |
    Select-Object -First 1

Write-Host "CPH problem file:" -ForegroundColor Yellow
Write-Host $probFile.Name

# ============================================================
# READ CPH DATA
# ============================================================

$data = Get-Content $probFile.FullName -Raw | ConvertFrom-Json

$name = $data.name
$url = $data.url
$sourcePath = $data.srcPath

if (-not $name) {
    Write-Host "Problem name not found." -ForegroundColor Red
    exit 1
}

if (-not $url) {
    Write-Host "Problem URL not found." -ForegroundColor Red
    exit 1
}

if (-not $sourcePath) {
    Write-Host "Source path not found." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Problem : $name" -ForegroundColor Green
Write-Host "URL     : $url" -ForegroundColor Green
Write-Host "Source  : $sourcePath" -ForegroundColor Green

# ============================================================
# EXTRACT CONTEST ID + PROBLEM INDEX
# ============================================================

if ($url -match "/problem/(\d+)/([A-Za-z0-9]+)") {

    $contestId = $Matches[1]
    $problemIndex = $Matches[2]

}
else {

    Write-Host ""
    Write-Host "Could not extract contest ID and problem index." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Contest : $contestId" -ForegroundColor Cyan
Write-Host "Index   : $problemIndex" -ForegroundColor Cyan

# ============================================================
# GET CODEFORCES PROBLEM INFORMATION
# ============================================================

Write-Host ""
Write-Host "Fetching Codeforces rating and tags..." -ForegroundColor Yellow

$api = Invoke-RestMethod `
    -Uri "https://codeforces.com/api/problemset.problems"

$problem = $api.result.problems |
    Where-Object {
        $_.contestId -eq [int]$contestId -and
        $_.index -eq $problemIndex
    } |
    Select-Object -First 1

if (-not $problem) {

    Write-Host "Problem not found in Codeforces API." -ForegroundColor Red
    exit 1
}

$rating = $problem.rating

if (-not $rating) {
    $rating = "Unrated"
}

$tags = $problem.tags -join ", "

Write-Host ""
Write-Host "Rating : $rating" -ForegroundColor Green
Write-Host "Tags   : $tags" -ForegroundColor Green

# ============================================================
# VERIFY SOURCE FILE
# ============================================================

if (-not (Test-Path $sourcePath)) {

    Write-Host ""
    Write-Host "Source file does not exist:" -ForegroundColor Red
    Write-Host $sourcePath

    exit 1
}

# ============================================================
# CHECK CODEFORCES ACCEPTANCE
# ============================================================

if (-not $Test) {

    Write-Host ""
    Write-Host "Checking Codeforces submission..." -ForegroundColor Yellow

    $statusApi = Invoke-RestMethod `
        -Uri "https://codeforces.com/api/user.status?handle=$CodeforcesHandle&count=1000"

    $accepted = $statusApi.result |
        Where-Object {
            $_.contestId -eq [int]$contestId -and
            $_.problem.index -eq $problemIndex -and
            $_.verdict -eq "OK"
        } |
        Select-Object -First 1

    if (-not $accepted) {

        Write-Host ""
        Write-Host "NOT ACCEPTED YET." -ForegroundColor Yellow
        Write-Host ""
        Write-Host "Submit the solution on Codeforces first." -ForegroundColor Yellow
        Write-Host "Nothing has been moved or deleted." -ForegroundColor Yellow
        Write-Host ""

        exit 0
    }

    Write-Host ""
    Write-Host "ACCEPTED!" -ForegroundColor Green
}

# ============================================================
# CREATE SAFE FOLDER NAME
# ============================================================

$safeName = $name -replace '[<>:"/\\|?*]', ''
$safeName = $safeName -replace '\s+', '_'
$safeName = $safeName.Trim('_')

$folderName = "${contestId}${problemIndex}_${safeName}"

# ============================================================
# CREATE RATING FOLDER
# ============================================================

$ratingFolder = Join-Path $RepoRoot "$rating"

if (-not (Test-Path $ratingFolder)) {

    New-Item `
        -ItemType Directory `
        -Path $ratingFolder |
        Out-Null
}

# ============================================================
# CREATE PROBLEM FOLDER
# ============================================================

$problemFolder = Join-Path $ratingFolder $folderName

if (-not (Test-Path $problemFolder)) {

    New-Item `
        -ItemType Directory `
        -Path $problemFolder |
        Out-Null
}

Write-Host ""
Write-Host "Created folder:" -ForegroundColor Cyan
Write-Host "$rating\$folderName"

# ============================================================
# COPY SOLUTION
# ============================================================

$destination = Join-Path $problemFolder "solution.cpp"

Copy-Item `
    -Path $sourcePath `
    -Destination $destination `
    -Force

Write-Host ""
Write-Host "Solution copied." -ForegroundColor Green

# ============================================================
# CREATE README
# ============================================================

$readme = @"
# $name

- **Codeforces:** [$contestId$problemIndex]($url)
- **Rating:** $rating
- **Tags:** $tags
- **Status:** Accepted

## Approach

Write your approach here.

## Complexity

- **Time:** 
- **Space:** 
"@

$readmePath = Join-Path $problemFolder "README.md"

Set-Content `
    -Path $readmePath `
    -Value $readme `
    -Encoding UTF8

Write-Host "README created." -ForegroundColor Green

# ============================================================
# DELETE ORIGINAL CPH SOURCE
# ============================================================

Remove-Item `
    -Path $sourcePath `
    -Force

# ============================================================
# DELETE CPH PROBLEM FILE
# ============================================================

Remove-Item `
    -Path $probFile.FullName `
    -Force

Write-Host ""
Write-Host "Original CPH files cleaned." -ForegroundColor Green

# ============================================================
# GIT
# ============================================================

Set-Location $RepoRoot

git add .

git commit -m "Solve $contestId$problemIndex - $name"

git push origin main

# ============================================================
# DONE
# ============================================================

Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "             GITHUB UPDATED             " -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""

Write-Host "$rating/$folderName/" -ForegroundColor Cyan
Write-Host "    solution.cpp"
Write-Host "    README.md"
Write-Host ""