//
// Created by 74680 on 2022/7/30.
//

#include<bits/stdc++.h>

using namespace std;

int solver303(){
    int n; cin >> n;

    vector<int> v(2*n + 1);
    vector<int> s(2*n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i + n] = v[i];
    }
    for(int i = 1; i <= 2*n; ++i){

        s[i] = s[i - 1] + v[i];
    }

    vector<vector<int>> dp(2*n + 1, vector<int>(2*n + 1, INT_MAX / 3));
    int ans = INT_MAX;
    for(int len = 1; len <= n; ++len){
        for(int i = 1; i + len - 1 <= 2*n; ++i){
            int j = i + len - 1;
            if(i == j) dp[i][j] = 0;
            for(int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i-1]);
            }

            if(len == n){
                ans = min(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}