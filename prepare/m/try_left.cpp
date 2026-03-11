#include<iostream>
#include<vector>

using namespace std;


int main(){
    int h,l, b;
    cin >> h >> l >> b;
    vector<vector<int>> arr(h, vector<int>(l));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(h, vector<int>(l, 1e9));
    for(int i = 0; i<h; i++){
        dp[i][0] = arr[i][0];
    }

    for(int j = 1; j<l ; j++){
        for(int i =0; i<h; i++){
            dp[i][j] = dp[i][j-1] + arr[i][j];
            if(i>0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + arr[i][j] + b);
            }if(i<h-1){
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + arr[i][j] + b);
            }
        }
    }

    int ans = 999999999;
    for(int i = 0; i<h; i++){
        ans = min(ans,dp[i][l-1]);
    } 

    cout << ans << "\n";
}