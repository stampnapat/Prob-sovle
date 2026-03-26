#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int m;
    cin >> m;
    vector<int> arr;

    vector<int> ans;

    for(int i =0; i<m; i++){
        int ope;
        cin >> ope;
        if(ope == 1){
            int x;
            cin >> x;
            arr.push_back(x);
        }else if(ope == 2){
            int Q, P;
            cin >> Q >> P;
            int target = P -Q;
            auto it = find(arr.begin(), arr.end(), target);

            if (it != arr.end() && *it > target){
                ans.push_back(distance(arr.begin(), it));
            }else {
                ans.push_back(-1);
            }

        }
        
    }

    for(int i =0; i<ans.size(); i++){
        cout << ans[i] << "\n";

    }
    

}