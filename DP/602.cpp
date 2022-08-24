//
// Created by 74680 on 2022/8/24.
//

#include<bits/stdc++.h>
using namespace std;

static long long calc_1(long long x){
    long long ans = 0;
    if(!x) return 0;
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int n = v.size();
    vector<vector<vector<vector<long long>>>> dp(n, vector<vector<vector<long long>>>(10, vector<vector<long long>>(2, vector<long long> (2, 0))));
    dp[0][0][0][0] = 1;
    for(int j = 1; j < v[0]; ++j) dp[0][j][1][0] = 1;
    dp[0][v[0]][1][1] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            if(dp[i-1][j][1][0]){
                for(int k = 0; k < 10; ++k) if(abs(k - j) <= 2) dp[i][k][1][0] += dp[i-1][j][1][0];
            }
            if(dp[i-1][j][1][1]){
                for(int k = 0; k <= v[i]; ++k) {
                    if(abs(k - j) > 2) continue;
                    if(k != v[i]) dp[i][k][1][0] += dp[i-1][j][1][1];
                    else dp[i][k][1][1] += dp[i-1][j][1][1];
                }
            }
            if(dp[i-1][j][0][0]){
                for(int k = 0; k < 10; ++k){

                    if(k) dp[i][k][1][0] += dp[i-1][j][0][0];
                    else dp[i][k][0][0] += dp[i-1][j][0][0];
                }
            }
        }
    }
    for(int j = 0; j < 10; ++j){
        for(int r = 0; r < 2; ++r){
            ans += dp[n-1][j][1][r];

        }
    }
    return ans;
}

static long long calc_2(long long x){
    if(x == 0) return 0;
    long long ans = 0;
    vector<int> v;
    while(x){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    bool flag = true;
    for(int i = 1; i < v.size(); ++i) {
        if(abs(v[i] - v[i-1]) > 2) {flag = false;break;}
    }
    if(flag) ans++;
    int n = v.size();
    for(int i = 0; i < n; ++i){
        bool ff = true;
        for(int ii = 1; ii <= i - 1 && ff;  ++ii) {
            if(abs(v[ii] - v[ii-1]) > 2) ff = false;
        }
        if(!ff) break;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(10, vector<long long>(2, 0)));
        for(int j = 0; j < v[i]; ++j){
            if(i && abs(j - v[i-1]) > 2) continue;
            if(i == 0 && j == 0) dp[i][j][0] = 1;
            else dp[i][j][1] = 1;
        }
        for(int k = i + 1; k < n; ++k){
            for(int l = 0; l <= 9; ++l){
                for(int s = 0; s <= 9; ++s){
                    if(abs(l - s) <= 2 && dp[k-1][s][1]) dp[k][l][1] += dp[k-1][s][1];
                    if(dp[k-1][s][0]) {
                        if(l) dp[k][l][1] += dp[k-1][0][0];
                        else dp[k][0][0] += dp[k-1][0][0];
                    }
                }
            }
        }
        for(int j = 0; j <= 9; ++j) ans +=dp[n-1][j][1];
    }

    return ans;
}
int solver602(){

    long long l, r;
    cin >> l >> r;
    long long c1 = calc_1(l - 1);
    long long c2 = calc_2(r);
    cout << c2 - c1 << endl;

    return 0;
}