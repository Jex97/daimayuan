//
// Created by 74680 on 2022/7/29.
//

#include<bits/stdc++.h>

using namespace std;

// 0-1背包

int solver201(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    vector<int> w(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> v[i] >> w[i];
    }
    vector<int> dp(m + 1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= v[i]; --j){
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << endl;

    return 0;
}