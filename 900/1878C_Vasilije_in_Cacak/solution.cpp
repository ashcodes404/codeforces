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
        int n , k  ;
        long long x ;  
        cin >> n >> k >> x ;
        
        long long minsum = (1LL * k * (k + 1) ) /2 ; 
        long long maxsum = (1LL * n * k) - (1LL * (k-1) * k)/2 ; 
        if(x >= minsum &&  x <= maxsum) cout << "YES" << endl ; 
        else cout << "NO" << endl ;

    }

    return 0;
}