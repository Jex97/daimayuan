//
// Created by 74680 on 2022/8/24.
//

#include<bits/stdc++.h>
using namespace std;

static long long dp[20][200][2][2] = {0};
static long long calc(long long x){
    memset(dp, 0,sizeof(dp));
    if(x == 0) return 0;
    long long ans = 0;
    vector<int> v;
    while(x){
        v.push_back(x%10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int n = v.size();
    dp[0][0][0][0] = 1;
    for(int j = 1; j < v[0]; ++j) dp[0][j][1][0] = 1;
    dp[0][v[0]][1][1] = 1;

    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= 180; ++j){
            if(dp[i-1][j][1][0] > 0){
                for(int k = 0; k <= 9; ++k){
                    if(j + k >= 180) continue;
                    dp[i][k + j][1][0] += dp[i-1][j][1][0];
                }
            }
            if(dp[i-1][j][1][1] > 0){
                for(int k = 0; k <= v[i]; ++k){
                    if(j + k >= 180) continue;
                    if(k != v[i]) dp[i][k + j][1][0] += dp[i-1][j][1][1];
                    else dp[i][k + j][1][1] += dp[i-1][j][1][1];
                }
            }
            if(dp[i-1][j][0][0] > 0){
                for(int k = 1; k <= 9; ++k) if(j + k < 180) dp[i][k + j][1][0] += dp[i-1][j][0][0];
                dp[i][j][0][0] += dp[i-1][j][0][0];
            }
        }
    }
    for(int j = 2; j <= 180; ++j){
        bool ff = true;
        for(int jj = 2; jj < j && ff; ++jj){
            if(j % jj == 0) ff = false;
        }
        if(!ff) continue;

        for(int r = 0; r < 2; ++r){
            ans += dp[n-1][j][1][r];
        }
    }
    return ans;
}
int solver603(){

    long long r, l;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
// 48744 - 19933 = 28811
    return 0;
}