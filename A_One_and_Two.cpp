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
        int n , tt  ;
        cin >> n ;
        vector<int> arr(n) ; 
        tt = 0 ; 
        for(int i = 0 ; i < n ; i ++) {
            cin >> arr[i] ; 
            if(arr[i] == 2) tt ++ ; 
        }

         int ans = -1 ; int ct = 0 ; 
        if(tt % 2 == 0){
            for(int k = 0 ; k < n - 1 ; k ++ ){
           if(arr[k] == 2 ) ct ++ ; 
            if(ct == tt / 2) {
                ans = k +1 ; 
                break ; 
            }
        
        }
}
        cout << ans << endl ;
    }

    return 0;
}