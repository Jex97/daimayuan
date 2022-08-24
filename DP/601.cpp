//
// Created by 74680 on 2022/8/23.
//

#include<bits/stdc++.h>

using namespace std;

void static calc(long long x, vector<long long>& c){
    vector<int> v;
    vector<long long> f;
    f.push_back(1);
    while(f.back() < 1e17) f.push_back(f.back() * 10);
    long long xx = x;
    while(xx){
        v.push_back(xx % 10);
        xx /= 10;
        c[v.back()]++;
    }
    reverse(v.begin(), v.end());
    int sz = v.size();

    for(int i = 0; i < sz; ++i){
        // 第i位不同
        // 计算前面固定位的数的个数
        for(int j = 0; j < i; ++j){
            c[v[j]] += v[i] * f[sz - i - 1];
        }
        // 计算当前位的数的个数
        for(int j = 1; j < v[i]; ++j){
            c[j] += f[sz - i - 1];
        }
        if(i && v[i]) c[0] += f[sz - i - 1];
        // 计算后置位的个数
        if(i < sz - 1){
            for(int j = 1; j < 10; ++j){
                c[j] += f[sz - i - 2] * v[i] * (sz - i - 1);
            }
            if(i) c[0] += f[sz - i - 2] * v[i] * (sz - i - 1);
        }
        if(i == 0) {
            if(sz >= 2){
                for(int j = 0; j < sz; ++j) {
                    if(j) c[0] += 9*f[sz - j - 2]*(sz - j - 1);
                    else c[0] += (v[j] - 1)*f[sz - j - 2]*(sz - j - 1);
                }
            }
        }
    }


}

int solver601(){
    long long l, r;
    cin >> l >> r;
    vector<long long> cnt1(10, 0);
    vector<long long> cnt2(10, 0);

    calc(l - 1, cnt1);
    calc(r, cnt2);
    for(int i = 0; i < 10; ++i){
        if(i) cout <<" ";
        cout << cnt2[i] - cnt1[i];
    }
    return 0;
}