//
// Created by 74680 on 2022/7/29.
//


// note: ret -= k; 要写在 k *= 2前

#include<bits/stdc++.h>
using namespace std;

int solver204(){
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
        int ret = l[i];
        for(int k = 1; k <= ret; k *= 2){
            for(int j = m; j >= v[i] * k; --j){
                dp[j] = max(dp[j], dp[j - v[i]*k] + w[i] * k);
            }
            ret -= k;
        }
        if(ret > 0) {
            for (int j = m; j >= v[i] * ret; --j) {
                dp[j] = max(dp[j], dp[j - v[i] * ret] + w[i] * ret);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}