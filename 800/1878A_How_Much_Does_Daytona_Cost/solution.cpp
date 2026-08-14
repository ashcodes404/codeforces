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
        int n , k ; 
        cin >> n >> k ; 
        vector<int> arr(n) ; 
        bool ans = false ; 
        for(int i = 0 ; i < n; i ++){
            cin >> arr[i] ; 
            if(arr[i] == k) ans = true ; 
        } 
 
        (ans) ? cout << "YES" << endl : cout << "NO" << endl ; 
    }

    return 0;
}