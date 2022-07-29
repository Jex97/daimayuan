//
// Created by 74680 on 2022/7/29.

// 多重背包  单调队列


// 每次队列要重置 #29 #30

#include<bits/stdc++.h>

using namespace std;

int solver208(){

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> w(n + 1);
    vector<int> l(n + 1);

    for(int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i] >> l[i];
    }
    vector<int> dp(m + 1, 0);
    for(int i = 1; i <= n; ++i){
        vector<pair<int,int>> q(10005);

        for(int x = 0; x < v[i]; ++x){
            int st = 0;
            int ed = -1;
            // x为余数， 按余数分组
            for(int j = x, k = 1; j <= m; j += v[i], ++k){
                int a = k + l[i];
                int b = dp[j] - w[i] * k;
                while(st <= ed && q[ed].second < b) ed--;
                while(st <= ed && q[st].first < k) st++;
                q[++ed] = pair<int,int>{a, b};
                dp[j] = q[st].second + k * w[i];
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
