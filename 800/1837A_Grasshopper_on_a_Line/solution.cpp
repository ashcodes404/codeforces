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
        int x , k ; 
        cin >> x >> k ;
        if(x % k != 0 ) {
            cout << 1 << endl << x << endl ; 
        }
        else {
            cout << 2 << endl ; 
            cout << k + 1 << " " << x - (k + 1) << endl ; 
        }
    }

    return 0;
}