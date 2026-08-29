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
       int ops = 0 , cntA = 0 , sum = 0 , cntB = 0  ; 
       for(int i = 1 ; i <= n ; i ++ ){
            int x ; 
            cin >> x ; 
            (x == -1) ? cntA ++ : cntB ++ ; 
            sum += x ; 
       }

      while(cntB < cntA || cntA % 2 == 1){
        cntB ++; 
        cntA -- ; 
        ops ++ ; 
      }
      cout << ops << endl ; 
       
    }

    return 0;
}