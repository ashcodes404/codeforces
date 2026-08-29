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
        string s ;
        cin >> s;

        int i = 0 ; int j = n -1 ; 
        int cnt = 0 ; 
        while(i < j){
            if((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0')){
                cnt ++ ; 
                i ++ ; 
                j -- ; 
            }
            else break ; 
        }
        cout << n - (2 * cnt) << endl ; 
    }

    return 0;
}