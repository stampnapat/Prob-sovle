#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n+1);
  
  for(int i =1; i<=n; i++){
    cin >> arr[i];
  }

  vector<vector<int>> mx(n+1, vector<int>(n+1, 0));

  for(int l=1; l<=n; l++){
    int m =0;
    for(int r=l; r<= n; r++){
      m = max(m, arr[r]);
      mx[l][r]  = m;
    }
  }

  const long long neg = -(1LL << 60);
  vector<long long> dp(n+1, neg);
  dp[0] = 0;

  for(int i =5; i<=n; i++){
    for(int k =0; k<= i-5; k++){
      dp[i] = max(dp[i], dp[k] + (long long)mx[k+1][i]);

    }
  }

  cout<< dp[n];

}

