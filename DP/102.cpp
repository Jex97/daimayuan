//
// Created by 74680 on 2022/7/28.
//

#include<bits/stdc++.h>
using namespace std;

int solver102(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<vector<int>> W(n + 1);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        W[u].push_back(w);
    }
    vector<int> dp(n + 1, INT_MAX / 2);
    dp[1] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < G[i].size(); ++j){
            int x = G[i][j];
            dp[x] = min(dp[x], dp[i] + W[i][j]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}