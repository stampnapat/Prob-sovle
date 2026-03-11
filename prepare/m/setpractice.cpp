#include<iostream>
#include<vector>    
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> sn(n);
    vector<int> sm(m);
    for(int i = 0; i < n; i++){
        cin >> sn[i];
    }

    for(int i = 0; i < m; i++){
        cin >> sm[i];
    }

    vector<int> ans;

    sort(sn.begin(), sn.end());
    sn.erase(unique(sn.begin(), sn.end()), sn.end());
    


    for(int i = 0; i<m; i++){
        auto it = lower_bound(sn.begin() , sn.end(), sm[i]);
        if(it == sn.end()){
            ans.push_back(sn[n-1]);
        }else if(it == sn.begin()){
            ans.push_back(sn[0]);
        }else{ 
            int cur = *it;
            int prev = *(it-1);
            if(abs(cur-sm[i]) < abs(prev-sm[i])){
                ans.push_back(cur);
            }else{
                ans.push_back(prev);
            }
        } 
        

    }
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }

}
