#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> arr;
    for(int i =0; i<n; i++){
        int x;
        cin >>x ;
        arr.push_back(x);
    }

    int ans = 0;

    sort(arr.begin(), arr.end());

    for(int i =0; i<n; i++){
        int target_left =  a - arr[i];  
        int target_right = b - arr[i];
        auto it = lower_bound(arr.begin()+i+1, arr.end(), target_left);
        auto it2 = upper_bound(arr.begin()+i+1, arr.end(), target_right);
        ans += it2 - it;
    }
    cout << ans << endl;
}