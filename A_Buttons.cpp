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
        int a , b , c ;
        cin >> a >> b >> c ;

        if(c % 2 == 1) {
            if( a + 1 > b ) cout << "First" << endl ;  
            else cout << "Second" << endl; 
        } else {
             (a > b) ? cout << "First" << endl : cout << "Second" << endl ; 
        }

    }

    return 0;
}