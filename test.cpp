#include<bits/stdc++.h>

using namespace std;

int main1(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    vector<int> cnt(n, 0);

    for(int i = 0; i < n; ++i){
        int k = (v[i] - i + n) % n;
        cnt[(k+1) % n]++;
        cnt[k]++;
        cnt[(k-1 + n) % n]++;
    }
    int ans = 0;
    int maxv = -1;
    for(int i = 0; i < n; ++i){
        if(cnt[i] > maxv) maxv = cnt[i], ans = i;
    }
    cout << cnt[ans] << endl;
    return 0;
}