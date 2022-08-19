//
// Created by 74680 on 2022/8/19.
//

#include<bits/stdc++.h>

using namespace std;
static vector<vector<int>> dp;

static void dfs(int x, vector<vector<int>>& G){
    for(auto y : G[x]){
        dfs(y, G);
        dp[x][0] += dp[y][1];
        dp[x][1] += min(dp[y][1], dp[y][0]);
    }
    dp[x][1]++;
}
int solver405(){

    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for(int i = 2; i <= n; ++i){
        int f; cin >> f;
        G[f].push_back(i);
    }

    dp.resize(n + 1, vector<int> (2, 0));
    dfs(1, G);
    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}