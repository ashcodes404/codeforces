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

        string s(n , 'a') ;

        for(int i = 0; i < n ; i ++) cin >> s[i] ; 

        bool three = false ;

        for(int i = 1 ; i < n - 1 ; i ++) {
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') {
                three = true ; 
                break ; 
            }
        }
        int cnt = 0 ; 
        if(!three) {
            for(int i = 0 ; i < n ; i ++) {
                if(s[i] == '.') cnt ++ ; 
            }
        }

        (three) ? cout << 2 << '\n' : cout << cnt << '\n' ; 
    }

    return 0;
}