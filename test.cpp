//
// Created by 74680 on 2022/8/24.
//

#include<bits/stdc++.h>

using namespace std;

class Point{
public:
    double x, y, z;
    int oldId;
    int EntryDim;
    int EntryDimID;
    bool operator<(const Point& _rhs){
        return EntryDim < _rhs.EntryDim || ((EntryDim == _rhs.EntryDim) && EntryDimID < _rhs.EntryDimID);
    }
};

vector<Point> Read(ifstream& input1){

    string line;
    bool f = false;
    vector<Point> data1;
    int dim;
    int id;
    int oldID = 1;
    while(getline(input1, line)){

        if(line == "$Nodes") {f = true; getline(input1, line); continue;}
        else if(line == "$EndNodes") break;

        if(f == false) continue;
        stringstream ss(line);
        int para, k;
        ss >> dim >> id >> para >> k;

        for(int i = 0; i < k; ++i){
            getline(input1, line);
        }
        for(int i = 0; i < k; ++i){
            getline(input1, line);
            double x, y, z;
            stringstream ssTemp(line);
            ssTemp >> x >> y >> z;
            data1.push_back({x, y, z, oldID, dim, id});
            oldID++;
            cout << x << " " << y << " " << z << endl;
        }
    }
    return data1;
}

double CalcDis(Point& p1, Point& p2){
    double deltaX = p1.x - p2.x;
    double deltaY = p1.y - p2.y;
    double deltaZ = p1.z - p2.z;
    return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

int main1(){
    ifstream input1("C:\\Users\\74680\\Desktop\\HighOrderMesh\\model_stp\\Example18.msh");
    ifstream input2("C:\\Users\\74680\\Desktop\\HighOrderMesh\\model_stp\\my18.msh");
    auto data1 = Read(input1);
    auto data2 = Read(input2);

    for(auto& p : data2){
        double err = 10000;
        Point nP = data1[0];
        for(auto& pp : data1){
            double curErr = CalcDis(p, pp);
            if(curErr < err){
                err = curErr;
                nP = pp;
            }
        }
        p.EntryDim = nP.EntryDim;
        p.EntryDimID = nP.EntryDimID;
    }
    sort(data2.begin(), data2.end());


    return 0;
}

#include<bits/stdc++.h>

using namespace std;
//int ff(vector<int>& v){
//    int ans = 0;
//    for(int i = 1; i < v.size(); ++i){
//        ans = max(ans, abs(v[i] - v[i-1]));
//    }
//    return ans;
//}
//int main(){
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for(int i = 0; i < n; ++i) cin >> v[i];
//    int ans = -1;
//    int cnt = 0;
//    for(int i = 1; i < n; ++i){
//        if(abs(v[i] - v[i-1]) > ans){
//            ans = abs(v[i] - v[i-1]);
//            cnt = 1;
//        }else if(abs(v[i] - v[i-1]) == ans) cnt++;
//    }
//    if(cnt == 2){
//        for(int i = 1; i < n-1; ++i){
//            if(abs(v[i] - v[i-1]) == ans && abs(v[i+1] - v[i]) == ans) v[i] = (v[i-1] + v[i+1]) / 2;
//        }
//
//        ans = ff(v);
//    }
//    if(cnt == 1){
//        int x = 0;
//        for(int i = 1; i < n; ++i){
//            if(abs(v[i] - v[i-1]) == ans){
//                x = i;
//                break;
//            }
//        }
//        int pre = x - 1; int af = x;
//
//        vector<int> vv = v;
//        if(pre == 0){
//            vv[0] = vv[1];
//        }else{
//            vv[pre] = (vv[pre-1] + vv[pre+1]) / 2;
//        }
//        ans = min(ans, ff(vv));
//        if(af == n-1){
//            v[n-1] = v[n-2];
//        }else{
//            v[af] = (v[af-1] + v[af+1]) / 2;
//        }
//        ans = min(ans, ff(v));
//    }
//    cout << ans << endl;
//    return 0;
//}

//
//int main(){
//    int q;
//    cin >> q;
//    while(q--){
//        int x;
//        cin >> x;
//        if(x % 2 == 0) cout << x << endl;
//        else{
//            vector<int> v;
//            bool f = false;
//            while(x){
//                int t = x % 10;
//                v.push_back(t);
//
//
//                if((t % 2 == 0) && f == false){
//                    f = true;
//                    swap(v[0], v[v.size() - 1]);
//                }
//                x /= 10;
//            }
//            if(f){
//                int ans = 0;
//                for(int i = v.size() - 1; i >= 0; --i){
//                    ans = ans*10 + v[i];
//                }
//                cout << ans << endl;
//            }else cout << -1 << endl;
//        }
//    }
//    return 0;
//}