//
// Created by 74680 on 2022/8/19.
//


// 树上背包
#include<bits/stdc++.h>

using namespace std;
static vector<vector<vector<int>>> dp;
int n, m;

void static dfs(int x, vector<vector<int>>& G, vector<int>& w){
    for(int i = 1; i <= m; ++i) dp[x][1][i] = w[x];
    for(auto y : G[x]){
        dfs(y, G, w);
        for(int j = m; j >= 1; --j){
            for(int k = 1; k <= j; ++k){
                dp[x][1][j] = max(dp[x][1][j], dp[x][1][j - k] + dp[y][0][k]) ;
                dp[x][0][j] = max(dp[x][0][j], dp[x][0][j - k] + max(dp[y][1][k], dp[y][0][k]));
            }
        }
    }
    //for(int j = m; j > 0; --j) dp[x][1][j] = dp[x][1][j-1] + w[x];
}
int solver404(){

    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> w(n + 1, 0);
    for(int i = 2; i <= n; ++i){
        int f; cin >> f;
        G[f].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> w[i];
    dp.resize(n + 1, vector<vector<int>>(2, vector<int>(m + 1, 0)));

    dfs(1, G, w);
    cout << max(dp[1][0][m], dp[1][1][m]) << endl;
    return 0;
}