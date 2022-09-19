//
// Created by 74680 on 2022/9/1.
//

// 错误！ 不能二分 直接暴力做吧
#include<bits/stdc++.h>

using namespace std;
bool static check(int mid, vector<int>& v){
    set<int> st;
    if(mid > v.size()) return false;
    unordered_map<int,int> cnt;
    for(int i = 0; i < mid; ++i){
        cnt[v[i]]++;
        st.insert(v[i]);

    }
    if(st.size() == mid && (*(st.rbegin())) - (*(st.begin())) == mid - 1) return true;
    cnt[v[0]]--;
    if(cnt[v[0]] == 0) st.erase(v[0]);
    for(int j = mid; j < v.size(); ++j){
        cnt[v[j]]++;
        if(cnt[v[j]] == 1) st.insert(v[j]);
        if(st.size() == mid && (*(st.rbegin())) - (*(st.begin())) == mid - 1) return true;
        cnt[v[j - mid + 1]]--;
        if(cnt[v[j - mid + 1]] == 0) st.erase(v[j - mid + 1]);
    }
    return false;
}
int P20220901(){

    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid, v)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
    return 0;
}