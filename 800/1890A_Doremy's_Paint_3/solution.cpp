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
       for(int i = 0 ; i  < n ; i ++) cin >> arr[i] ; 

       int x = 0 ; int y = -1 ; 
       
       int cnt_y = 0 , cnt_x ; 

       if(n > 2){
            x = arr[0] ; 
            cnt_x = 1 ;  
            for(int i = 1 ; i < n ; i ++){
                if(arr[i] == x) cnt_x ++ ; 
                else {
                    if(y == -1) {
                        y = arr[i] ; 
                    }
                    if(y == arr[i]) cnt_y ++ ; 
                }
            }

            if(cnt_x + cnt_y != n) cout << "No" << endl; 
            else if(cnt_x == n || cnt_y == n) cout << "Yes" << endl ;  
            else {
            if(n % 2 == 0) {
                (cnt_x == cnt_y) ? cout << "Yes" << endl  : cout << "No" <<endl ;
            }
            else{
                (abs(cnt_x - cnt_y) == 1) ? cout << "Yes" << endl  : cout << "No" <<endl ;
            }
            }
       }
       else cout << "Yes" << endl; 
       
    }

    return 0;
}