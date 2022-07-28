//
// Created by 74680 on 2022/7/28.
//
// note: 会爆int
#include<bits/stdc++.h>
using namespace std;
int solver101(){
    int n;
    cin >> n;
    vector<long long> dp(n + 10, 0);
    dp[0] = 1;
    dp[1] = 1;
    //dp[2] = 2;
    for(int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
    return 0;
}
