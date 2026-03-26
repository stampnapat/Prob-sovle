#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }   

    sort(arr.begin(), arr.end());

    int ans = 0;

    for(int i =0; i<n; i++){
        int left = s -arr[i];
        int right = arr[i] + t;


        if (left > right) continue;

        auto l = lower_bound(arr.begin() +i +1, arr.end(), left);
        auto r = upper_bound(arr.begin() + i +1, arr.end(), right);

        ans += distance(l, r);
    }

    cout << ans << endl;


}