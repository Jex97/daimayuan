//
// Created by 74680 on 2022/7/28.
//

#include<bits/stdc++.h>
using namespace std;

int solver105() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> v(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int len = 1; len <= n; ++len){
        for(int i = 0; i + len - 1 < n; ++i){
            int j = i + len - 1;
            if(len == 1) dp[i][j] = 1, ans = len;
            else if(len == 2){
                if(v[i] == v[j]) dp[i][j] = 1, ans = len;
            }else{
                if(v[i] == v[j]) dp[i][j] = dp[i+1][j-1];
                if(dp[i][j]) ans = len;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
