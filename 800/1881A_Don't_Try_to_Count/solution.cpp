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
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;

        int cnt = 0;
        if(x.find(s) == string::npos){
            x += x ; 
            cnt ++ ; 
        }
        while (x.find(s) == string::npos && x.length() <= 2 * s.length())
        {
            x += x;
            cnt++;
        }

        if (x.find(s) != string::npos)
            cout << cnt << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}