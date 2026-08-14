#include <bits/stdc++.h>
using namespace std;


bool check(vector<int> & arr , int fuel , int x) {
    int n = arr.size() ; 
    for(int i = 1 ; i < n ; i ++) {
       if(arr[i] - arr[i-1] > fuel ) return false ;
    }

    if( 2 *(x - arr[n - 1]) > fuel ) return false ;
    return true ; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n , x ; 
        cin >> n >> x ; 

        vector<int> arr(n + 1) ; 

        arr[0] = 0 ; 
        int end = 2 * x ; 
        int st = INT_MAX ; 
        int ans = 0 ; 
        for(int i = 1; i <= n ; i ++) {
            cin >> arr[i]; 
            st = min(arr[i] - arr[i-1] , st) ; 
        }

        while(st <= end) {
            int mid = st + (end - st) /2   ; 
            if(check(arr , mid , x)) {
                end = mid - 1; 
                ans = mid ; 
            }
            else {
                 st = mid + 1 ; 
            }
        }
         cout << ans << '\n'; 

    }

    return 0;
}