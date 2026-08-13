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
Write-Host "      CODEFORCES SOLUTION ORGANIZER     " -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# ============================================================
# FIND LATEST CPH PROBLEM
# ============================================================

$cphFolder = Join-Path $RepoRoot ".cph"

$probFiles = Get-ChildItem `
    -Path $cphFolder `
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

Write-Host "CPH problem:" -ForegroundColor Yellow
Write-Host $probFile.Name

# ============================================================
# READ CPH DATA
# ============================================================

$data = Get-Content $probFile.FullName -Raw | ConvertFrom-Json

$name = $data.name
$url = $data.url
$sourcePath = $data.srcPath

if (-not $name -or -not $url -or -not $sourcePath) {
    Write-Host "CPH data is incomplete." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Problem : $name" -ForegroundColor Green
Write-Host "URL     : $url" -ForegroundColor Green
Write-Host "Source  : $sourcePath" -ForegroundColor Green

# ============================================================
# EXTRACT CONTEST ID + INDEX
# ============================================================

if ($url -match "/problem/(\d+)/([A-Za-z0-9]+)") {

    $contestId = $Matches[1]
    $problemIndex = $Matches[2]

}
else {

    Write-Host "Could not extract Codeforces problem ID." -ForegroundColor Red
    exit 1
}

Write-Host ""
Write-Host "Contest : $contestId" -ForegroundColor Cyan
Write-Host "Index   : $problemIndex" -ForegroundColor Cyan

# ============================================================
# GET PROBLEM METADATA
# ============================================================

Write-Host ""
Write-Host "Fetching Codeforces metadata..." -ForegroundColor Yellow

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
# CHECK SOURCE FILE
# ============================================================

if (-not (Test-Path $sourcePath)) {

    Write-Host ""
    Write-Host "Source file does not exist:" -ForegroundColor Red
    Write-Host $sourcePath

    exit 1
}

# ============================================================
# CLEAN PROBLEM NAME
# ============================================================

# Remove "A. ", "B. ", "C. ", etc.
$cleanName = $name -replace '^[A-Za-z]\.\s*', ''

# Remove Windows-invalid filename characters
$cleanName = $cleanName -replace '[<>:"/\\|?*]', ''

# Replace spaces with underscores
$cleanName = $cleanName -replace '\s+', '_'

# Remove duplicate underscores
$cleanName = $cleanName -replace '_+', '_'

# Remove leading/trailing underscores
$cleanName = $cleanName.Trim('_')

$folderName = "${contestId}${problemIndex}_${cleanName}"

# ============================================================
# DETERMINE RATING FOLDER
# ============================================================

$ratingFolderName = "$rating"

$ratingFolder = Join-Path `
    $RepoRoot `
    $ratingFolderName

$problemFolder = Join-Path `
    $ratingFolder `
    $folderName

# ============================================================
# TEST MODE
# ============================================================

if ($Test) {

    Write-Host ""
    Write-Host "========================================" -ForegroundColor Yellow
    Write-Host "             TEST / DRY RUN            " -ForegroundColor Yellow
    Write-Host "========================================" -ForegroundColor Yellow

    Write-Host ""
    Write-Host "Would create:" -ForegroundColor Cyan
    Write-Host "$ratingFolderName\$folderName"

    Write-Host ""
    Write-Host "Would create:"
    Write-Host "  solution.cpp"
    Write-Host "  README.md"

    Write-Host ""
    Write-Host "NO files moved."
    Write-Host "NO files deleted."
    Write-Host "NO git commit."
    Write-Host "NO git push."

    Write-Host ""
    Write-Host "Test completed successfully." -ForegroundColor Green

    exit 0
}

# ============================================================
# CHECK ACCEPTED STATUS
# ============================================================

Write-Host ""
Write-Host "Checking Codeforces submission status..." -ForegroundColor Yellow

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
    Write-Host "NOT ACCEPTED." -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Submit the problem on Codeforces first." -ForegroundColor Yellow
    Write-Host "Nothing was changed." -ForegroundColor Yellow
    Write-Host ""

    exit 0
}

Write-Host ""
Write-Host "ACCEPTED!" -ForegroundColor Green

# ============================================================
# CREATE RATING FOLDER
# ============================================================

if (-not (Test-Path $ratingFolder)) {

    New-Item `
        -ItemType Directory `
        -Path $ratingFolder |
        Out-Null
}

# ============================================================
# CREATE PROBLEM FOLDER
# ============================================================

if (-not (Test-Path $problemFolder)) {

    New-Item `
        -ItemType Directory `
        -Path $problemFolder |
        Out-Null
}

Write-Host ""
Write-Host "Problem folder:" -ForegroundColor Cyan
Write-Host "$ratingFolderName\$folderName"

# ============================================================
# COPY SOLUTION
# ============================================================

$destination = Join-Path `
    $problemFolder `
    "solution.cpp"

Copy-Item `
    -Path $sourcePath `
    -Destination $destination `
    -Force

Write-Host ""
Write-Host "solution.cpp created." -ForegroundColor Green

# ============================================================
# CREATE README
# ============================================================

$readme = @"
# $cleanName

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

$readmePath = Join-Path `
    $problemFolder `
    "README.md"

Set-Content `
    -Path $readmePath `
    -Value $readme `
    -Encoding UTF8

Write-Host "README.md created." -ForegroundColor Green

# ============================================================
# REMOVE ORIGINAL CPH SOURCE
# ============================================================

Remove-Item `
    -Path $sourcePath `
    -Force

# ============================================================
# REMOVE CPH PROBLEM DATA
# ============================================================

Remove-Item `
    -Path $probFile.FullName `
    -Force

Write-Host ""
Write-Host "Temporary CPH files cleaned." -ForegroundColor Green

# ============================================================
# GIT
# ============================================================

Set-Location $RepoRoot

git add .

git commit -m "Solve $contestId$problemIndex - $cleanName"

git push origin main

# ============================================================
# FINISHED
# ============================================================

Write-Host ""
Write-Host "========================================" -ForegroundColor Green
Write-Host "          GITHUB UPDATED               " -ForegroundColor Green
Write-Host "========================================" -ForegroundColor Green
Write-Host ""

Write-Host "$ratingFolderName\$folderName\" -ForegroundColor Cyan
Write-Host "    solution.cpp"
Write-Host "    README.md"
Write-Host ""
