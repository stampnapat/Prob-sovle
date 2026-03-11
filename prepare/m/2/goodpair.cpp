#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> arr;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int ans = 0;

    for(int i =0; i<n; i++){
        int target_left = s - arr[i];
        int target_right = arr[i]+t;
        if(target_left > target_right) continue;

        auto left = lower_bound(arr.begin()+i+1, arr.end(), target_left);
        auto right = upper_bound(arr.begin()+i+1, arr.end(), target_right);

        ans += (right - left);

    }
    cout << ans;

    

}


#####รังเรื่องขอบเขตด้วย เเบบเกินขอบ lower uppper ไหม