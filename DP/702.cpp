//
// Created by 74680 on 2022/8/26.
//

#include<bits/stdc++.h>

using namespace std;

int solver702(){
    int n;
    cin >> n;
    vector<vector<int>> G(n , vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> G[i][j];
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    dp[1][0] = 0;
    for(int s = 1; s < 1 << n; ++s){
        for(int i = 0; i < n; ++i){
            if(dp[s][i] < INT_MAX/2){
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    if(s & (1 << j)) continue;
                    dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + G[i][j]);
                }
            }
        }
    }
//    for(int s = 0; s < 1 << n; ++s){
//        for(int i = 0; i < n; ++i){
//            cout << dp[s][i] << " ";
//        }
//        cout << endl;
//    }
    int ans = INT_MAX / 2;
    for(int i = 1; i < n; ++i){
        ans = min(ans, dp[(1 << n)-1][i] + G[i][0]);
    }
    cout << ans << endl;
    return 0;
}