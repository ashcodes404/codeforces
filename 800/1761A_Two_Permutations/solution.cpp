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
        int n , a , b ; 
        cin >> n >> a >> b ; 
        string ans = "Yes" ; 
        if(n == a && n == b) ans = "Yes" ;
        else if(a + b >= n) ans = "No" ; 
        else if(n - (a + b) == 1) ans = "No" ; 
        else if(n - a > 2) ans = "Yes" ; 
        else if(n - a <= 2) ans = "No";

        cout << ans << endl ; 
    }

    return 0;
}