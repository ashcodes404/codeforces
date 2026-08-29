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
        int cnt = 0 ; 
        vector<int> arr(n) ; 
        for(int i = 0 ; i < n; i ++) cin >> arr[i] ; 

        int j = 0 , i = 0 ; 
        while(j < n) {
            while(j < n && arr[j] == 1) {
                j ++; 
                i = j ; 
            }
            if(j < n && arr[j] == 0){
                j ++ ; 
                cnt = max(cnt , j - i ) ; 
            }
            
        }
        cout << cnt << endl ; 
    }

    return 0;
}