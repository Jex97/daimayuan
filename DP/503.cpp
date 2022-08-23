//
// Created by 74680 on 2022/8/23.
//

#include<bits/stdc++.h>

using namespace std;
void up(int x, vector<vector<int>>& G, vector<vector<int>>& f, vector<int>& vis){
    vis[x] = 1;
    for(auto& y : G[x]){
        if(vis[y] == 0){
            up(y, G, f, vis);
            if(f[y][0] + 1 > f[x][0]) f[x][1] = f[x][0], f[x][0] = f[y][0] + 1;
            else if(f[y][0] + 1 > f[x][1]) f[x][1] = f[y][0] + 1;
        }
    }
}
void down(int x, vector<vector<int>>& G, vector<vector<int>>& f, vector<int>& v, vector<int>& vis){
    vis[x] = 1;
    for(auto& y : G[x]){
        if(vis[y] == 0){
            if(f[x][0] == f[y][0] + 1) v[y] = max(f[x][1], v[x]) + 1;
            else v[y] = max(f[x][0],v[x]) + 1;
            down(y, G, f, v, vis);
        }
    }
}
int solver503(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> G(n);
    for(int i = 1; i < n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> d(n, 0);
    vector<vector<int>> f(n, vector<int>(2, 0));
    vector<int> v(n, 0);
    vector<int> vis(n, 0);
    up(0, G, f, vis);
    vis = vector<int>(n, 0);
    down(0, G, f, v, vis);
    for(int i = 0; i < n; ++i){
        //printf("%d %d\n", f[i][0], f[i][1]);
        //printf("%d\n", v[i]);
        printf("%d\n", f[i][0] + max(v[i], f[i][1]) );
    }
    return 0;
}