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
        int a, b, n;
        cin >> a >> b >> n;

        long long sec = b;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= 0; i--)
        {
            b = min(arr[i] + 1, a  ) - 1 ;
            sec += b;
        }
        cout << sec << endl;
    }

    return 0;
}