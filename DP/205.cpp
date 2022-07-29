//
// Created by 74680 on 2022/7/29.
//
// 分组背包 0-1背包的升级版
// note1: k作为下标使用时不要写成v[i][j], 要写成v[i][k]
// note2: 注意分组的数据如何存储

#include<bits/stdc++.h>

using namespace std;


int solver205(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> w(n + 1);
    vector<vector<int>> c(1001);
    for(int i = 1; i <= n; ++i){
        int a, vi, wi; cin >> a;
        cin >> v[i] >> w[i];
        c[a].push_back(i);
    }

    vector<int> dp(m + 1, 0);
    for(int i = 1; i <= 1000; ++i){
        for(int j = m; j >= 0; --j) {
            for (auto& k : c[i]) {
                if(j >= v[k]) dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}