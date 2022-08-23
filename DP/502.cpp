//
// Created by 74680 on 2022/8/22.
//

//

#include<bits/stdc++.h>

using namespace std;

void up(int x, vector<vector<pair<int,long long>>>& G, vector<int>& vis, vector<long long>& f){
    vis[x] = 1;
    bool ifEnd = false;
    for(auto& [y, w] : G[x]){
        if(vis[y] == 0){
            ifEnd = true;
            up(y, G, vis, f);
            f[x] += min(f[y], w);
        }
    }
    if(!ifEnd) f[x] = LONG_MAX;
}
void down(int x, int root, long long w, vector<vector<pair<int,long long>>>& G, vector<int>& vis, vector<long long>& f, vector<long long>& v){
    vis[x] = 1;
    if(root != -1){
        if(f[root] - min(f[x], w) + v[root]) v[x] = min(f[root] - min(f[x], w) + v[root], w);
        else v[x] = w;
    }
    for(auto& [y, ww] : G[x]){
        if(vis[y] == 0){
            down(y, x, ww, G, vis, f, v);
        }
    }
}
int solver502(){
    int n;
    cin >> n;
    vector<vector<pair<int,long long>>> G(n);
    for(int i = 0; i < n - 1; ++i){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--; y--;
        G[x].push_back({y, z});
        G[y].push_back({x, z});
    }

    vector<long long> f(n, 0);
    vector<long long> v(n, 0);
    vector<int> vis(n, 0);
    up(0, G, vis, f);
    vis = vector<int>(n, 0);
    down(0,-1,0, G, vis, f, v);

    for(int i = 0; i < n; ++i){
        if(f[i] != LONG_MAX) printf("%lld\n", f[i] + v[i]);
        else printf("%lld\n", v[i]);
    }
    return 0;
}