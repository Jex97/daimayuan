//
// Created by 74680 on 2022/8/31.
//

#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int solver705(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(1 << m, 0);
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(i == 0 && j == 0) continue;
            vector<int> newDp(1 << m, 0);
            for(int k = 0; k < 1 << m; ++k){
                if(k & (1 << j)){
                    if(i != n - 1) newDp[k] = dp[k & (~(1 << j))];
                }else{
                    newDp[k] = dp[k | (1 << j)] ;
                    if(j != m - 1 && ((k & (1 << (j+1))) != 0) ) newDp[k] = (newDp[k] + dp[k & (~(1 << (j + 1)))]) % mod;
                }
            }
            dp = newDp;
        }
    }
    cout << dp[0] << endl;
    return 0;
}