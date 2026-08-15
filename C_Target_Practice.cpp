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
        vector<vector<char>>grid(10 , vector<char>(10)) ; 
        int cnt_x = 0 ; 
        int ans = 0 ; 
        for(int i = 1 ; i <= 10 ; i ++) {
            if(i>5 ) cnt_x ++ ; 
            int cnt_y = 0 ;
            for(int j = 1 ; j <= 10 ; j ++) {
                if(j > 5) cnt_y ++ ; 
                cin >> grid[i-1][j-1] ; 
                if(grid[i-1][j-1] == 'X'){
                    if(i <= 5 && j <= 5 ){
                        ans += min(i , j) ;
                    }
                    else if(i > 5 && j > 5) {
                        ans += min(i - (2 * cnt_x - 1) , j - (2 * cnt_y  - 1)) ; 
                    }
                    else if( i <= 5 && j> 5){
                        ans += min(i  , j - (2 * cnt_y  - 1)) ;
                    }
                    else if(i > 5 && j <= 5) {
                        ans += min(i - (2 * cnt_x - 1) , j ) ; 
                    }
                }

            }
        }

        cout << ans << endl ; 
    }

    return 0;
}