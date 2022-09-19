//
// Created by ASUS on 2022/9/19.
//
#include<bits/stdc++.h>

using namespace std;

static const int M = 1e9 + 7;
int quick_pow(long long x, int p){
    int ans = 1;
    while(p){
        if(p & 1) ans = ans * x % M;
        x = x * x % M;
        p >>= 1;
    }
    return ans;
}


static void GaussianElimination(vector<vector<long long>>& A, vector<long long>& b){
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        int j = i;
        for(int k = i; k < n; ++k){
            if(abs(A[k][i]) > abs(A[j][i])) j = k;
        }
        swap(A[i], A[j]);
        swap(b[i], b[j]);

        int line_delta = A[i][i];
        for(int s = i; s < n; ++s){
            A[i][s]  *= quick_pow(line_delta, M-2), A[i][s] = (A[i][s] +  M) % M;
        }

        b[i] *= quick_pow(line_delta, M-2), b[i] = (b[i] + M) % M;
        for(int k = 0; k < n; ++k){
            if(i != k && A[k][i]){
                long long cur_delta = A[k][i];
                b[k] -= cur_delta * b[i], b[k] = (b[k] + M)%M;
                for(int s = i; s < n; ++s){
                    A[k][s] -= cur_delta * A[i][s], A[k][s] = (A[k][s] + M)%M;
                }
            }
        }
    }
}
int solver805(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
    }
    vector<vector<long long >> A(n, vector<long long>(n, 0));
    vector<long long> b(n, 0);

    A[n-1][n-1] = 1;
    b[n-1] = 0;
    for(int i = 0; i < n - 1; ++i){
        int k = G[i].size();
        A[i][i] = 1; b[i] = 1;
        for(auto& v : G[i]){
            A[i][v] = (-(1 * quick_pow(k, M-2)) + M) % M;
        }
    }
    GaussianElimination(A, b);
    cout << b[0] << endl;


    return 0;

}