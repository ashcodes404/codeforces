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
        vector<int> arr(n) ;
        for(int i = 0 ; i < n ; i ++){
            cin >> arr[i] ; 
        }

        sort(arr.begin() , arr.end()) ;
        vector<int> b ; 
        vector<int> c ; 

        if( arr.back() == arr[0]) {
            cout << -1 << endl ;
            continue; 
        }
        int j = n - 1 ; 
        while(j> 0 && arr[j] == arr[j-1]) j -- ; 
        
        for(int i = 0 ; i < j ; i ++) b.push_back(arr[i]) ; 

        for(int i = j ; i < n ; i ++) c.push_back(arr[i]) ;

        cout << b.size() << " " << c.size() << endl ; 

        for(int & i : b) {
            cout << i << " " ;
        }

        cout << endl ; 
        for(int & i : c) {
            cout << i << " ";
        }
        cout << endl ; 
    }


    return 0;
}