#include <bits/stdc++.h>
using namespace std;

int diasDescanso(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int> (3, 101));

    dp[0][0] = 1;
    if(nums[0] == 1 || nums[0] == 3) dp[0][1] = 0;
    if(nums[0] == 2 || nums[0] == 3) dp[0][2] = 0;

    for (int i = 1; i < n; i++) {
        dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

        if (nums[i] == 1 || nums[i] == 3) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }

        if (nums[i] == 2 || nums[i] == 3) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main() {
    int n;

    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << diasDescanso(nums) << endl;
}