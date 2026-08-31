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
        int a , b , xk , yk , xq , yq ; 
        cin >> a >> b >> xk >> yk >> xq >> yq ;

        set<pair<int,int>> positions;
        
        vector<vector<int>> dir{
            {a , b} , {-a , b} , {a , -b} , {-a , -b},
            {b, a}, {-b, a}, {b, -a}, {-b, -a}
        } ; 

        
        for(vector<int> & vec : dir){
            int i = vec[0] ; 
            int j = vec[1] ;
            
            int nx = xq + i ; 
            int ny = yq + j ; 

            for(vector<int> & vec2 : dir){
                int x = vec2[0] ; 
                int y = vec2[1] ; 

                int nx1 = nx + x ; 
                int ny2 = ny + y ; 

                if(nx1 == xk && ny2 == yk ) positions.insert({nx , ny}) ; 
            }
        }
            cout << positions.size() << endl ; 

    }

    return 0;
}