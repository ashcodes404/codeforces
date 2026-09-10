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
        vector<int> nums(n);

        for(int i = 0 ; i < n; i ++) cin >> nums[i] ;
        
        int ans = 0 ; 

        for(int i = 1 ; i < n ; i ++) ans = max(ans , nums[i] - nums[0]) ; 
        for(int i = n - 2 ; i >= 0 ; i --) ans = max(ans , nums[n-1] - nums[i]) ; 

        for(int i = 0 ; i < n - 1 ; i ++) ans = max(ans , nums[i] - nums[i+1]) ; 

        cout << ans << endl ;

    }

    return 0;
}