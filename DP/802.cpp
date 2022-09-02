//
// Created by 74680 on 2022/9/2.
//

#include<bits/stdc++.h>
using namespace std;
static const int p = 1e9 + 7;
long long quickPow(long long x, long long n){
    long long ans = 1;
    while(n){
        if(n & 1) ans = ans * x % p;
        x = x*x % p;
        n >>= 1;
    }
    return ans;
}
int solver802(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
    }

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for(int i = 1; i <= n; ++i){
        for(auto& y : G[i]){
            dp[y] = (dp[y] + dp[i] * quickPow(G[i].size(), p - 2) % p) % p;
        }
    }
    cout << dp[n] << endl;
    return 0;
}