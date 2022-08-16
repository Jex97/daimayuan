//
// Created by 74680 on 2022/8/16.
//

#include<bits/stdc++.h>

using namespace std;
vector<int> w;
vector<vector<int>> g;
vector<long long> dp[2];

void dfs(int x, vector<vector<int>>& f, vector<int>& w){
    dp[0][x] = 0;
    dp[1][x] = w[x];
    for(auto& y : f[x]) {
        dfs(y, f, w);
        dp[0][x] += max(dp[1][y], dp[0][y]);
        dp[1][x] += dp[0][y];
    }
}
int solver402(){
    int n;
    cin >> n;
    g.resize(n + 1);
    w.resize(n + 1, 0);
    dp[0].resize(n + 1, 0);
    dp[1].resize(n + 1, 0);
    for(int i = 2; i <= n; ++i) {
        int f; cin >> f;
        g[f].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> w[i];

    dfs(1, g, w);

    cout << max(dp[0][1], dp[1][1]) << endl;

    return 0;
}