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
        cin >> n  ; 
        vector<int> arr(n) ; 
        int maxGap = INT_MAX ; 
        cin >> arr[0] ; 
        for(int i = 1 ; i < n ; i ++) {
            cin >> arr[i] ; 
            maxGap = min(maxGap , arr[i] - arr[i-1]) ; 
        }

        vector<int>arr_copy = arr; 
        sort(arr_copy.begin() , arr_copy.end()) ; 
        if(arr_copy != arr  ) cout << 0 << endl;
        else if(maxGap == 0) cout << 1 << endl ; 
        else cout << maxGap / 2 + 1 << endl ;


    }

    return 0;
}