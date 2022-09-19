//
// Created by 74680 on 2022/8/31.
//


#include<bits/stdc++.h>
using namespace std;
int P20220831_3(){

    int D, N;
    cin >> D >> N;
    vector<int> w(N + 1, 0);
    vector<int> d(N + 1, 0);
    for(int i = 1; i <= N; ++i){
        cin >> d[i] >> w[i];
    }
    vector<int> q(N + 10000);
    int l = 0;
    int r = 0;
    vector<double> t(N+1, 0);
    q[r++] = 0;
    for(int i = 1; i <= N; ++i){
        while(l < r && d[q[l]] + 1000 < d[i]) l++;
        if(l >= r){
            cout << -1 << endl;
            return 0;
        }
        t[i] = t[q[l]] + (d[i] - d[q[l]])*1.0 / 100 + w[i];
        while(l < r && t[i] <= t[q[r-1]])  r--;
        q[r++] = i;
    }
    while(l < r && d[q[l]] + 1000 < D) l++;
    if(l >= r || d[q[l]] + 1000 < D) cout << -1 << endl;
    else cout << (int)(t[q[l]] + (D - d[q[l]]) / 100) << endl;
    return 0;
}