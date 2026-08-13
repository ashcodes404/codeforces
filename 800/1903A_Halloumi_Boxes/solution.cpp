#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // If k >= 2, we can swap adjacent elements, allowing us to sort any array.
    if (k >= 2)
    {
        cout << "YES\n";
    }
    else
    {
        // If k == 1, we can't change the array. It must already be sorted.
        bool is_sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                is_sorted = false;
                break;
            }
        }

        if (is_sorted)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}