//
// Created by 74680 on 2022/8/30.
//

#include<bits/stdc++.h>

using namespace std;

int solver703(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<int> f(1 << n, INT_MAX / 2);
    f[0] = 0;
    for(int i = 1; i < 1 << n; ++i){
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)){
                f[i] = min(f[i], f[i - (1 << j)] + v[j]);
                for(int k = j + 1; k < n; ++k){
                    if(i & (1 << k)){
                        f[i] = min(f[i], f[i - (1 << j) - (1 << k)] + (v[j] ^ v[k]));
                    }
                }
                break;
            }
        }
       // cout << i << " " << f[i] << endl;
    }
    cout << f[(1 << n) - 1] << endl;
    return 0;
}