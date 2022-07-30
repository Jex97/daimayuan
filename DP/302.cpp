//
// Created by 74680 on 2022/7/30.
//

#include<bits/stdc++.h>

using namespace std;

int solver302(){

    int n; cin >> n;
    vector<int> v(n + 1, 0);

    for(int i = 1; i <= n; ++i){
        char c;
        cin >> c;
        if(c == '[') v[i] = 1;
        else if(c == ']') v[i] = -1;
        else if(c == '(') v[i] = 2;
        else v[i] = -2;
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for(int len = 2; len <= n; ++len){
        for(int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            if(v[i] > 0 && v[i] + v[j] == 0) {
                if(len == 2) dp[i][j] = 2;
                else dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
            }
            for(int k = i; k < j; ++k){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
