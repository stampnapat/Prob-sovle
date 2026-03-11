#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for(int i =0; i<n; i++){
    cin >> arr[i];
  }

  ///arr = [1, -1, 2, -2, 3]

  vector<int> dp(n, 1);
  vector<int> parent(n, -1);
  
  int best = 1;
  int end =0;

  for(int i =0; i<n; i++){
    for(int j =0; j<i; j++){
      if(arr[j] < arr[i] && dp[j] +1  >dp[i]){
        dp[i] = dp[j] +1;
        parent[i] = j;
      }
    }
    if (dp[i] > best){
      best = dp[i];
      end = i;
    }
  }

  vector<int> ans;
  for(int cur = end; cur!=-1; cur = parent[cur]){
    ans.push_back(arr[cur]);
  }

  reverse(ans.begin(), ans.end());

  cout << best << "\n";

  for(int i =0; i< ans.size(); i++){
    if(i) cout << ' ';
    cout << ans[i];
  }
}
