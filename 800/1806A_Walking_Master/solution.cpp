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
        int a , b, c, d ; 
        cin >> a >> b >> c >> d ; 
        int my = (d - b) ;
        int mx = a + my - c ;  
        if(b > d || mx < 0) cout << -1 << endl ; 
        else cout << mx + my << endl  ; 

    }

    return 0;
}