//
// Created by 74680 on 2022/9/2.
//

#include<bits/stdc++.h>

using namespace std;
const static int p = 998244353;
long long static quickPow(long long x, long long n){
    long long ans = 1;
    while(n){
        if(n & 1) ans = ans * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return ans;
}
int solver804(){
    int n;
    cin >> n;
    vector<long long> qP(2*n + 1);
    for(int i = 0; i <= 2*n; ++i){
        qP[i] = quickPow(i, p-2) % p;
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(2*n + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 2*(n - i); ++j){
            dp[i][j] += (i) * dp[i-1][j+2]  % p * qP[i + j] % p;
            if(j) dp[i][j] += (j) * dp[i][j-1] % p  * qP[i + j] % p;
            dp[i][j]++;
            dp[i][j] %= p;
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}