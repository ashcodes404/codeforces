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
        int n , a1 ; 
        cin >> n >> a1 ; 

        int x = a1 ; 
        for(int i = 2 ; i <= n ; i ++) {
            int a ; 
            cin >> a ;
            x ^= a ; 
        }

        if(n % 2 == 1) {
            cout << x << endl ; 
        }
        else if( x == 0) cout << 0 << endl ; 
        else cout << -1 << endl ; 

    }

    return 0;
}