//
// Created by 74680 on 2022/9/1.
//

#include<bits/stdc++.h>

using namespace std;

int solver801(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    vector<double> dp(n+1, 0);
    dp[1] = 1;

    for(int i = 1; i <= n; ++i){
        for(auto& y : G[i]){
            dp[y] += dp[i] / G[i].size();
        }
    }
    cout << dp[n] << endl;
    return 0;
}