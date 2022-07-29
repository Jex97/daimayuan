//
// Created by 74680 on 2022/7/29.
//

// 二维背包

#include<bits/stdc++.h>
using namespace std;

int solver206(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1);
    vector<int> w(n + 1);
    vector<int> t(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i] >> t[i];
    }

    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= v[i]; --j){
            for(int s = k; s >= t[i]; --s){
                dp[j][s] = max(dp[j][s], dp[j - v[i]][s - t[i]] + w[i]);
            }
        }
    }
    cout << dp[m][k] << endl;

    return 0;
}