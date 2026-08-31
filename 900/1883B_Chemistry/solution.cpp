#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k ;
        cin >> n >> k ;  
        string s ; 
        cin >> s ; 
        vector<int> freq(26 , 0) ; 

        int i = 0 ; int j = n -1 ; 
        while (i <= j)
        {   
            if(i != j)
            freq[s[i] - 'a'] ++ ; 
            freq[s[j] - 'a'] ++ ; 
            i ++ ;
            j -- ; 
        }
int odd_cnt = 0;

for (int i = 0; i < 26; i++) {
    if (freq[i] % 2)
        odd_cnt++;
}

if (odd_cnt - k <= 1 )
    cout << "YES\n";
else
    cout << "NO\n";

    }

    return 0;
}