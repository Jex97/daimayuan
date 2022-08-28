#include<bits/stdc++.h>
using namespace std;


// INT_MAX 头文件为 climits


int solver304() {
    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 3));

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (len < 3) dp[i][j] = 0;
            else {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i-1];
        }
        vector<int> ans;
        for(auto& q : queries){
            auto it = upper_bound(nums.begin(), nums.end(), q);
            ans.push_back(it - nums.begin());
        }
        return ans;
    }
};