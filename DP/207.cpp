//
// Created by 74680 on 2022/7/29.
//

// note: scanf 和 printf 会比 cin 和 cout快很多

#include<bits/stdc++.h>
using namespace std;

int solver207(){
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> q(1e5 +7);
    int st = 0;
    int ed = -1;
    for(int i = 1; i <= n; ++i){
        int a, b;
        scanf("%d %d",&a, &b);
        while(st <= ed && q[ed].second <= b) ed--;
        while(st <= ed && q[st].first < i)  st++;
        q[++ed] = pair<int,int>{a, b};
        printf("%d\n", q[st].second);
    }
    return 0;
}