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
        vector<int>arr(n) ; 
        for(int i = 0 ; i < n ; i ++) {
            cin >> arr[i] ; 
        }
        
        int i = 0 ; 
        while(i < n && arr[i] == 0) i ++ ;
        int swaps = 0 ;
        for( ; i  < n - 1 ; i ++) {
            if(arr[i] != 0 && arr[i+1] == 0) swaps ++ ;
        }
        if(arr[n-1] != 0) swaps ++ ;
           
        cout << min(swaps , 2) << endl ;
    }

    return 0;
}