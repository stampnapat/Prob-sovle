#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i =0; i<t; i++){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 1e9));

    for(int i =0; i<n; i++){
        dp[0][i] = arr[0][i];
    }

    for(int i = 1; i<m; i++){
        for(int j =0; j<n; j++){
            dp[i][j] = dp[i-1][j]+arr[i][j];
            if(j>0){
               // top left
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + arr[i][j]);
            }if (j < n-1 ){
                // top right

                dp[i][j] = min(dp[i][j], dp[i-1][j+1] + arr[i][j]);
            }
            
        }
    }

    int ans = 1e9;
    for(int i =0; i<n; i++){
        ans = min(ans, dp[m-1][i]);
    }
    cout << ans << "\n";

}
}