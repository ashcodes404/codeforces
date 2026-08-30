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
        int n ; 
        cin >> n ; 
        int ans =  0 ;
        if(n <= 9) ans = n  ; 
        else if(n >= 10 && n <= 99){
            ans = 9 + (n / 10) ; 
        }
        else if(n>=100 && n <= 999) ans = 2 * 9 + (n / 100) ; 
        else if(n >= 1000 && n <= 9999) ans = 3 * 9 + (n / 1000) ; 
        else if(n >= 10000 && n <= 99999) ans = 4 * 9 + (n / 10000) ; 
        else if(n >= 100000 && n <= 999999) ans = 5 * 9 + (n / 100000) ; 
        else if(n >= 1000000 && n <= 9999999) ans = 6 * 9 + (n / 1000000) ; 
        else if(n >= 10000000 && n <= 99999999) ans = 7 * 9 + (n / 10000000) ; 

        cout << ans << endl; 
       
    }

    return 0;
}