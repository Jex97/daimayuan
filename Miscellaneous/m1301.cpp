//
// Created by ASUS on 2022/9/19.
//

#include<bits/stdc++.h>

using namespace std;

// 需要特别注意！！ 比较时需要加绝对值！！

static int GaussianElimination(vector<vector<double>>& A, vector<double>& b){
    const double EPS = 1E-6;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        int j = i;
        for(int k = i; k < n; ++k){
            if(abs(A[k][i]) > abs(A[j][i])) j = k;
        }
        if(EPS > abs(A[j][i])) {
            if(b[j] == 0) return -2;
            else return -1;
        }
        swap(A[i], A[j]);
        swap(b[i], b[j]);

        double line_delta = A[i][i];
        for(int s = i; s < n; ++s){
            A[i][s]  /= line_delta;

        }
        b[i] /= line_delta;

        for(int k = 0; k < n; ++k){
            if(i != k && abs(A[k][i]) > EPS){
                double cur_delta = A[k][i];

                b[k] -= cur_delta * b[i];
                for(int s = i; s < n; ++s){
                    A[k][s] -= cur_delta * A[i][s];

                }
            }
        }
//
//        for(int i = 0; i < n; ++i){
//            for(int j = 0; j < n; ++j){
//                cout << A[i][j] << " ";
//            }
//            cout << b[i] << endl;
//        }
    }
    return 0;
}

int solverm1301(){

    int n;
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n, 0));
    vector<double> b(n, 0);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    int state = GaussianElimination(A, b);
    if(state < 0) cout << state << endl;
    else{
        for(int i = 0; i < n; ++i) cout << b[i] << endl;
    }

    return 0;
};