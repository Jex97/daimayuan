//
// Created by 74680 on 2022/7/30.
//


#include<bits/stdc++.h>
using namespace std;

int solver301(){

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> preSum(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> v[i], preSum[i] = preSum[i-1] + v[i];
    vector<vector<int>> dp(501, vector<int>(501, INT_MAX / 3));
    for(int len = 1; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if(len == 1) dp[i][j] = 0;
            for(int left = 1; left < len; ++left){
                dp[i][j] =
                    min(dp[i][j],
                    dp[i][i + left - 1] + dp[i + left][i + len - 1] + preSum[j] - preSum[i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}