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
        int n, k, x;
        cin >> n >> k >> x;

        bool found = false;

        // Special case: 1 is forbidden
        if (x == 1 && k >= 3 && n % 2 == 1)
        {
            found = true;

            cout << "YES" << endl;

            int m = (n - 3) / 2 + 1;
            cout << m << endl;

            cout << 3 << " ";
            for (int j = 1; j <= (n - 3) / 2; j++)
                cout << 2 << " ";

            cout << endl;
        }
        else
        {
            for (int i = 1; i <= k; i++)
            {
                if (i == x)
                    continue;

                if (n % i == 0)
                {
                    found = true;

                    cout << "YES" << endl;

                    int m = n / i;
                    cout << m << endl;

                    for (int j = 1; j <= m; j++)
                        cout << i << " ";

                    cout << endl;
                    break;
                }
                else if (n % i != x)
                {
                    found = true;

                    cout << "YES" << endl;

                    int m = n / i;
                    cout << m + 1 << endl;

                    for (int j = 1; j <= m; j++)
                        cout << i << " ";

                    cout << n % i << endl;
                    break;
                }
            }
        }

        if (!found)
            cout << "NO" << endl;
    }

    return 0;
}