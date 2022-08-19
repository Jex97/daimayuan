//
// Created by 74680 on 2022/8/16.
//

#include<bits/stdc++.h>
using namespace std;


int dfs(int x, vector<int>& cnt, vector<vector<int>>& G){
    int ans = 1;
    for(auto& y : G[x]) {
        ans += dfs(y, cnt, G);
    }
    cnt[x] = ans;
    return ans;
}

int solver401() {
    int n;
    cin >> n;

    vector<vector<int>> G(n + 1);
    for(int i = 2; i <= n; ++i){
        int f;
        cin >> f;
        G[f].push_back(i);
    }
    vector<int> cnt(n + 1, 0);
    dfs(1, cnt, G);

    for(int i = 1; i <= n; ++i) cout << cnt[i] << " ";

    return 0;
}
