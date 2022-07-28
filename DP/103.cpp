//
// Created by 74680 on 2022/7/28.
//

// note: 需要取整个数组的最大值

#include<bits/stdc++.h>
using namespace std;

int solver103(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<int> dp(n, 1);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(v[i] > v[j]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;

}
