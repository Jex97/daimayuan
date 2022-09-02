//
// Created by 74680 on 2022/9/2.
//

// 求期望倒着来，此时所有概率相加等于1， 可直接在期望上进行加1操作
#include<bits/stdc++.h>

using namespace std;

const static int p = 1e9 + 7;

long long static quickPow(long long x, long long n){
    long long ans = 1;
    while(n){
        if(n & 1) ans = ans * x % p;
        x = x*x % p;
        n >>= 1;
    }
    return ans;
}

int solver803(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n+1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    vector<long long> dp(n + 1, 0);

    for(int i = n-1; i >= 1; --i){
        for(auto& y : G[i]){
            dp[i] = ((dp[i] + (dp[y]+1) % p * quickPow(G[i].size(), p-2) % p) %p) % p;
            //cout << y << " " << dp[y] << endl;
        }
    }

    cout << dp[1] << endl;
    return 0;
}