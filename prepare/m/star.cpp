#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;

    for(int i = 3; i<=n; i++){
        dp[i] = max(dp[i-1], dp[i-3]+arr[i]);
        }

    
    cout << dp[n] << "\n";
}
