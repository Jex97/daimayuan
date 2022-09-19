//
// Created by 74680 on 2022/9/3.
//

#include<bits/stdc++.h>
using namespace std;


int P20220903_3(){
    string s;
    cin >> s;
    int n = s.size();
    stack<int> stk;
    unordered_map<int,int> r;
    for(int i = 0; i < s.size(); ++i){
        char c = s[i];
        if(c == '('){
            stk.push(i);
        }else{
            if(!stk.empty()){
                r[stk.top()] = i;
                stk.pop();
            }
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '(' && r.count(i)){
            int x = i;
            int y = r[x];
            ans += (x+1) * 1LL * (n - y);
        }
    }

    cout << ans * 2  << endl;
    return 0;
}