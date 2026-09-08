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
        int n , q , l , r , k ; 
        cin >> n >> q ; 
        vector<int> arr(n) ; 
        for(int i = 0 ; i < n ; i ++) cin >> arr[i] ; 

        long long sum = accumulate(arr.begin() , arr.end() , 0) ; 
        vector<long long>prefixSum(n) ; 
        prefixSum[0] = arr[0] ; 
        for(int i = 1 ; i < n ; i ++){
            prefixSum[i] = prefixSum[i-1] + arr[i] ; 
        }

        
        for(int p = 0 ; p < q ; p ++) {
            cin >> l >> r >> k ;
            long long  currSum = 0 ; 
            if(l == 1) currSum = prefixSum[r-1] ; 
            else currSum = prefixSum[r-1] - prefixSum[l-2] ; 
            int len = (r - l + 1) ;
            long long  kSum = len * k ;
            if( (sum - currSum + kSum) % 2) cout << "YES" ;
            else cout << "NO" ; 
            cout << endl ;
        }
    }

    return 0;
}