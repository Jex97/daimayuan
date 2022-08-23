//
// Created by 74680 on 2022/8/22.
//

#include<bits/stdc++.h>

using namespace std;


void up(int x, vector<int>& vis, vector<vector<int>>& G, vector<long long>& sz, vector<long long>& f){
    vis[x] = 1;
    for(auto& y : G[x]) {
        if(vis[y] == 0) {
            up(y, vis, G, sz, f);
            sz[x] += sz[y];
            f[x] += f[y] + sz[y];
        }
    }
    sz[x]++;
}

void down(int x, int root, vector<int>& vis, vector<vector<int>>& G, vector<long long>& sz, vector<long long>& f, vector<long long>& v){
    vis[x] = 1;
    if(root != -1) v[x] = f[root] - f[x] - sz[x] + v[root] + G.size() - sz[x];
    for(auto& y : G[x]) if(vis[y] == 0) down(y, x, vis, G, sz, f, v);
}
int solver501(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> G(n);
    for(int i = 1; i < n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<long long> sz(n, 0);   // 子树的大小
    vector<long long> f(n, 0);    // 子树的距离和
    vector<long long> v(n, 0);    // 父亲节点对子树的贡献
    vector<int> vis(n, 0);

    up(0, vis, G, sz, f);

    vis = vector<int>(n, 0);

    down(0, -1, vis, G, sz, f, v);

    for(int i = 0; i < n; ++i){
        printf("%lld\n", f[i] + v[i]);

    }

    return 0;
}