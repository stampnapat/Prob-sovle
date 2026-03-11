#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> Sn;
    vector<int> Sm;

    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        Sn.push_back(x);
    }

    for(int i =0; i<m; i++){
        int y;
        cin >> y;
        Sm.push_back(y);
    }

    sort(Sn.begin(), Sn.end());
    Sn.erase(unique(Sn.begin(), Sn.end()), Sn.end());


    vector<int> ans;
    for(int i =0; i<m; i++){
        auto it = upper_bound(Sn.begin(), Sn.end(), Sm[i]);
        if(it ==Sn.begin()){
            ans.push_back(Sn[0]);
        }else if (it == Sn.end()){
            ans.push_back(Sn[n-1]);
        }else {
            int cur = *it;
            int left = *(it-1);
            if(abs(Sm[i] - left) > abs(Sm[i] - cur))
                ans.push_back(cur);
            else ans.push_back(left);
        }

    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";

    }
   




}
###### sort ก่อนแล้วค่อยลบซ้ำออกไป
