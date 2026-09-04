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
        int n , k ; 
        cin >> n >> k ; 
        vector<int> nums(n) ; 
        for(int i = 0 ; i < n ; i++) {
            cin >> nums[i] ; 
        }
        sort(nums.begin() , nums.end()) ; 
        int i = 0 ; 
        int j = 0 ; 

        int maxLen = 0 ; 

        while( j < n ) {
            if(j + 1 < n && nums[j+1] - nums[j] > k) {
                maxLen = max(maxLen , j - i +1 ) ; 
                i = j + 1 ; 
            }
            j ++ ;
        }
        maxLen = max(maxLen , j - i) ; 

        cout << n - maxLen << endl ;  
    }

    return 0;
}