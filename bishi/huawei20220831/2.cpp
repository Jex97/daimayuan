//
// Created by 74680 on 2022/8/31.
//


#include<bits/stdc++.h>
using namespace std;
struct Pt{
    int x; int y; int t;
    bool operator<(const Pt& _rhs) const{
        return t < _rhs.t;
    }
};
int dir[4][2] = {{0, 1}, {0,-1}, {1, 0},{-1, 0}};
bool check(int x, int y, int m, int n){
    return x < m && x >= 0 && y < n && y >= 0;
}
int P20220831_2(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(m, 0));
    Pt st;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> G[i][j];
            if(G[i][j] == 2) st = {i, j, 0};
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    priority_queue<Pt> q;
    q.push(st);
    vis[st.x][st.y] =  1;

    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        cout << cur.x << " " << cur.y << endl;
        for(int i =0; i < 4; ++i){
            if(check(cur.x + dir[i][0], cur.y + dir[i][1], n, m) && vis[cur.x + dir[i][0]][cur.y + dir[i][1]] == 0){
                int xx = cur.x + dir[i][0];
                int yy = cur.y + dir[i][1];
                int t = cur.t + 1;
                cout << xx << " " << yy << " " << t<< endl;
                if(G[xx][yy] == 3) {
                    cout << t << endl;
                    return 0;
                }else if(G[xx][yy] == 1) continue;
                else if(G[xx][yy] == 0){
                    q.push({xx, yy, t});
                    vis[xx][yy] = 1;
                }else if(G[xx][yy] == 4){
                    t += 3;
                    q.push({xx, yy, t});
                    vis[xx][yy] = 1;
                }else if(G[xx][yy] == 6){
                    for(int kk = 0; kk < 4; ++kk){
                        if(check(xx + dir[i][0], yy + dir[i][1], n, m) && G[xx + dir[i][0]][yy + dir[i][1]] == 1){
                            G[xx + dir[i][0]][yy + dir[i][1]] = 0;
                        }
                        q.push({xx, yy, t});
                        vis[xx][yy] = 1;
                    }
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}