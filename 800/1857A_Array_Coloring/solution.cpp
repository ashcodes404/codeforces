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
        int sum = 0  ; 
        for(int i = 1  ; i <= n ; i ++) {
            int x ; 
            cin >> x ; 
            sum += x ; 
        }

        (sum % 2) ? cout << "NO" << endl : cout << "YES" << endl ; 
    }

    return 0;
}