//
// Created by 74680 on 2022/8/26.
//

#include<bits/stdc++.h>

using namespace std;

int solver701(){

    int n;
    cin >> n;
    vector<int> w(n + 1, 0);
    vector<int> G(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i){
        int l; cin >> l;
        for(int j = 0; j < l; ++j) {
            int k; cin >> k;
            G[i] |= (1 << (k - 1));
        }
    }

    int ans = 0;
    for(int i = 1; i < 1 << n; ++i){
        bool f = true;
        int cur = 0;
        for(int j = 0; j < n && f; ++j){
            if(i & (1 << j)){
                cur += w[j + 1];
                if(G[j + 1] == 0) continue;
                if( (G[j+1] & i) == G[j+1] ) f = false;
            }
        }

        if(f) ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}