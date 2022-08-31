//
// Created by 74680 on 2022/8/30.
//

#include<bits/stdc++.h>

using namespace std;

int solver704(){
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    vector<int> dp(1 << m, 0);

    for(int i = 1; i < 1 << m && 1 << n; ++i){
        int sumV = 0;
        int cnt = 0;
        for(int j = 0; j < m && j < n; ++j){
            if(i & (1 << j)){
                cnt++;
                sumV += w[j];
            }
        }
        if(cnt <= m / 2) dp[i] = sumV;
    }
    for(int i = m; i < n; ++i){

        vector<int> newDp(1 << m, 0);
        for(int j = 0; j < (1 << m); ++j){
            int cnt = 0;

            for(int k = 0; k < m; ++k){
                if(j & (1 << k)){
                    cnt++;
                }
            }
            if(cnt <= m / 2){
                newDp[j] = max(dp[((j << 1) &(~(1 << (m)))) + 1] , dp[((j << 1) &(~(1 << (m))))]);
                if(j & (1 << (m-1))) newDp[j] += w[i];

            }
        }
        dp = newDp;

    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}