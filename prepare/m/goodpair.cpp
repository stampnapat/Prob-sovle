#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int main(){
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> arr;

    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);

    }

    long long ans = 0;

    sort(arr.begin(), arr.end());


    for(int i =0; i<n; i++){
        int target = s - arr[i];
        int target2 =  arr[i] + t;
                if(target > target2) continue;  

        auto l = lower_bound(arr.begin() +i + 1, arr.end(), target);
        auto r = upper_bound(arr.begin() + i + 1, arr.end(), target2);


        ans += distance(l, r) ;
    }
    cout << ans;
}

