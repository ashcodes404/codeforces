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
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) cin >> arr[i] ;
            

        sort(arr.begin() , arr.end(), [](int a , int b){
            return a > b ;
        }); 

        int flag = true ; 

        // All elements are equal
        if (arr[0] == arr[n - 1]) flag = false ; 

        if(flag) {
            cout << "YES\n" ; 
            swap(arr[n-1] , arr[1]) ; 
            for(int i = 0 ; i < n; i ++) cout << arr[i] << " " ; 
            cout << endl; 
        }
        else cout << "NO\n" ;
    }

    return 0;
}