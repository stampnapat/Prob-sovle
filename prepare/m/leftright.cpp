#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));

    for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, -1e9));   

    for(int i =0; i<n; i++){
        dp[0][i] = arr[0][i];
    }

    for(int i =1; i<m; i++){
        for(int j =0; j<n; j++){
            dp[i][j] = dp[i-1][j] + arr[i][j];
            if(j > 0 && j < n-1){
                if(i %2 == 1){
                    int sum = dp[i][j];
                    for(int k = j; k<n; k++){
                        if(k == j) continue;
                        sum += arr[i][k];
                        dp[i][k] = max(dp[i][k], sum);
                    }
                }else {
                    int sum = dp[i][j];
                    for(int k = j; k>=0; k--){
                        if(k == j) continue;
                        sum += arr[i][k];
                        dp[i][k] = max(dp[i][k], sum);
                    }

                }
            }
       
        }
    }

    int ans = -1e9;
    for(int i =0; i<n; i++){
        ans = max(ans, dp[m-1][i]);
    }

    cout << ans << "\n";

}

