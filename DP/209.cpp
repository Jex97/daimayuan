//
// Created by 74680 on 2022/7/29.
//

// 混合背包
// 注意完全背包有一个条件限制，保证不越界
#include<bits/stdc++.h>
using namespace std;

int solver209(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    vector<int> w(n + 1);
    vector<int> l(n + 1);
    vector<int> ty(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> ty[i];
        if(ty[i] == 1){
            cin >> v[i] >> w[i];
        }else if(ty[i] == 2){
            cin >> v[i] >> w[i];
        }else{
            cin >> v[i] >> w[i] >> l[i];
        }
    }
    vector<int> dp(m + 1, 0);
    for(int i = 1; i <= n; ++i){
        if(ty[i] == 1){
            for(int j = m; j >= v[i]; --j){
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }else if(ty[i] == 2){
            for(int j = 1; j <= m; ++j){
                if(j >= v[i])
                    dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }else{
            int r = l[i];
            for(int x = 1; x <= r; x *= 2){
                for(int j = m; j >= v[i] * x; --j){
                    dp[j] = max(dp[j], dp[j - v[i]*x] + w[i] * x);
                }
                r -= x;
            }
            if(r) {
                for(int j = m; j >= v[i] * r; --j){
                    dp[j] = max(dp[j], dp[j - v[i]*r] + w[i] * r);
                }
            }
        }
    }
    cout << dp[m] << endl;

    return 0;
}