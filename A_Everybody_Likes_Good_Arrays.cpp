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
        int n , ele; 
        cin >> n >> ele ;
        int cnt = 1 ; int ans = 0 ;   
        for(int i = 1 ; i < n ; i ++) {
            int x ; 
            cin >> x ; 
            if(ele % 2 == x % 2) cnt ++ ;  
            else {
                ans += cnt - 1; 
                cnt = 1 ; 
            }
            ele = x ; 
        }
        ans += cnt - 1  ; 
        cout << ans << endl ; 
    }

    return 0;
}