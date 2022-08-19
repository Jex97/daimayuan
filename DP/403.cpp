//
// Created by 74680 on 2022/8/19.
//

#include<bits/stdc++.h>

using namespace std;

int solver403(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> w[i][j];
        }
    }

    vector<int> dp(m + 1, 0);

    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 1; --j){
            for(int k = 1; k <= j; ++k){

                dp[j] = max(dp[j], dp[j - k] + w[i][k]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}