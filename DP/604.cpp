//
// Created by 74680 on 2022/8/24.
//

#include<bits/stdc++.h>

using namespace std;


static long long calc1(long long x){
    static long long dp[20][10][10][2][2] = {0};
    memset(dp, 0, sizeof(dp));
    long long ans = x;
    if(x == 0) return 0;
    if(x <= 100) return 0;
    vector<int> v;
    while(x){
        v.push_back(x%10);
        x /= 10;
    }
    reverse(v.begin(), v.end());

    int n = v.size();

    dp[0][0][0][0][0] = 1;
    for(int j = 1; j < v[0]; ++j) dp[0][0][j][0][0] = 1;
    dp[0][0][v[0]][0][1] = 1;

    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= 9; ++j){
            for(int jj = 0; jj <= 9; ++jj){
                if(dp[i-1][j][jj][0][0]){
                    // 前两位还未满
                    for(int k = 0; k <= 9; ++k) {
                        if(jj) dp[i][jj][k][1][0] += dp[i-1][j][jj][0][0];
                        else dp[i][jj][k][0][0] += dp[i-1][j][jj][0][0];
                    }
                }
                if(dp[i-1][j][jj][1][0]){
                    // 前两位已满
                    for(int k = 0; k <= jj; ++k) {
                        dp[i][jj][k][1][0] += dp[i-1][j][jj][1][0];
                    }
                    if(j >= jj) for(int k = jj + 1; k <= 9; ++k) {
                            dp[i][jj][k][1][0] += dp[i-1][j][jj][1][0];
                        }
                }
                if(dp[i-1][j][jj][0][1]){
                    // 前两位未满，后面可以取0-v[i]
                    for(int k = 0;  k < v[i]; ++k){
                        dp[i][jj][k][1][0] += dp[i-1][j][jj][0][1];
                    }
                    dp[i][jj][v[i]][1][1] += dp[i-1][j][jj][0][1];

                }
                if(dp[i-1][j][jj][1][1]){
                    // 前两位已满
                    for(int k = 0; k < v[i] && k <= jj; ++k){
                        dp[i][jj][k][1][0] += dp[i-1][j][jj][1][1];
                    }
                    if(v[i] <= jj){
                        dp[i][jj][v[i]][1][1] += dp[i-1][j][jj][1][1];
                    }else{
                        if(j >= jj){
                            dp[i][jj][v[i]][1][1] += dp[i-1][j][jj][1][1];
                            for(int k = jj + 1; k < v[i]; ++k){
                                dp[i][jj][k][1][0] += dp[i-1][j][jj][1][1];
                            }
                        }
                    }

                }
            }
        }
    }

    for(int j = 0; j <= 9; ++j){
        for(int jj = 0; jj <= 9; ++jj){
            for(int r = 0; r < 2; ++r){
                ans -= dp[n-1][j][jj][1][r];
                ans -= dp[n-1][j][jj][0][r];
            }
        }
    }
    return ans + 1;
}
static long long calc(long long x){
    static long long dp[20][10][2][2] = {0};    // dp[i][j][k][l] 前i位 最后一位为j 前i位是否已满 前两位是否满足严格递增
    memset(dp, 0, sizeof(dp));
    long long ans = x;
    if(x < 100) return 0;
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int n = v.size();

    dp[0][v[0]][1][0] = 1;
    for(int j = 1; j < v[0]; ++j) dp[0][j][0][0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            if(dp[i-1][j][1][0]){
                // 最大为v[i]
                for(int k = 0; k < v[i]; ++k) {
                    if(k > j) dp[i][k][0][1] += dp[i-1][j][1][0];
                    else dp[i][k][0][0] += dp[i-1][j][1][0];

                }
                dp[i][v[i]][1][v[i] > j] += dp[i-1][j][1][0];
            }
            if(dp[i-1][j][1][1]){
                for(int k = 0; k < v[i]; ++k){
                    if(k <= j) dp[i][k][0][0] += dp[i-1][j][1][1];
                    else break;
                }
                if(v[i] <= j) dp[i][v[i]][1][0] += dp[i-1][j][1][1];
            }
            if(dp[i-1][j][0][0]){
                for(int k = 0; k < 10; ++k){
                    dp[i][k][0][k > j] += dp[i-1][j][0][0];
                }
            }
            if(dp[i-1][j][0][1]){
                for(int k = 0; k <= j; ++k){
                    dp[i][k][0][0] += dp[i-1][j][0][1];
                }
            }
        }
        for(int k = 1; k < 10; ++k){
            dp[i][k][0][0]++;
        }
    }
    for(int j = 0; j < 10; ++j){
        for(int r = 0; r < 2; ++r){
            for(int s = 0; s < 2; ++s){
                //cout << dp[n-1][j][r][s] << endl;
                ans -= dp[n-1][j][r][s];
            }
        }
    }
    return ans;
}
int solver604(){
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << endl;
    cout << calc1(r) - calc1(l - 1) << endl;
    return 0;
}