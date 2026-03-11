#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> heights(n);
    vector<int> sorted(n);

    for(int i = 0; i < n; i++){
        cin >> heights[i];
        sorted[i] = heights[i];
    }

    sort(sorted.begin(), sorted.end());

    vector<int> ans(n);

    for(int i = 0; i<n; i++){
        int cur = heights[i];
        auto it = lower_bound(sorted.begin(), sorted.end(), cur);
        int left = *(it-1);
        int right = *(it+1);
        // cout << "cur " << cur << "lower" << *it << endl;
        if(it != sorted.begin() && it != sorted.end()){
            ans[i] = min(abs(cur - left), abs(cur - right));
        } else if(it == sorted.begin()){
            ans[i] = abs(cur - right);
        } else {
            ans[i] = abs(cur - left);
        }


    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }
}