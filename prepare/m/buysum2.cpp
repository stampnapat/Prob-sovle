#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
        ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    vector<int> arr;
    vector<int> sort_arr;

    vector<int> ans;

    for(int i =0; i<m; i++){
        int ope;
        cin >> ope;
        if(ope == 1){
            int x;
            cin >> x;
            arr.push_back(x);
            sort_arr.push_back(x);
            sort(sort_arr.begin(), sort_arr.end());
        }else if(ope == 2){
            int Q, P;
            cin >> Q >> P;
            int target = P -Q;
            int bo = 0;
            int mini = 1e9;
            int idx = -1;

            auto it = lower_bound(sort_arr.begin(), sort_arr.end(), target);
            if (it != sort_arr.end()){
                target = *it;
                ans.push_back(distance(arr.begin(), find(arr.begin(), arr.end(), target))+1);
            }else{
                ans.push_back(-1);
        }
        }
        
    }

    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << "\n";

    }
    

}