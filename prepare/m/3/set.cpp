#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<int> Sn(n);
    vector<int> Sm(m);

    for(int i = 0; i < n; i++){
        cin >> Sn[i];
    }   

    for(int i = 0; i < m; i++){
        cin >> Sm[i];
    }   

    vector<int> ans(m);

    sort(Sn.begin(), Sn.end());
    Sn.erase(unique(Sn.begin(), Sn.end()), Sn.end());


    for(int i =0; i<m; i++){
        int target = Sm[i];

        auto it = upper_bound(Sn.begin(), Sn.end(), target);
        if(it == Sn.end()){
            ans[i] = Sn[n-1];
        }else if(it == Sn.begin()){
            ans[i] = Sn[0];
        }else{
            int left = *(it - 1);
            int cur = *it;
            if(abs(left - target) <= abs(cur-target)){
                ans[i] = left;
            }else {
                ans[i] = cur;
            }

    }
}

    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }

}


