#include<iostream>
using namespace std;

int main(){
  int n;

  cin >>n;

  long long s[1001], t[1001], w[1001];
  long long dp[1001];
  int parent[1001];

  for(int i=1; i<=n; i++){
    cin >>s[i] >> t[i] >> w[i];
  }
  
  long long maxvalue = 0;
  int last = -1;

  for(int i=1; i<=n; i++){
    dp[i] = w[i];
    parent[i] = -1;

    for(int j=1; j<i; j++){
      if(t[j] <= s[i]){
        if(dp[j] + w[i] > dp[i]){
          dp[i] = dp[j] +w[i];
          parent[i] = j;
        }
      }
    }

    if(dp[i] > maxvalue){
      maxvalue = dp[i];
      last = i;
    }


  }

  int result[1001];
  int cout =0;
  int cur = lastvalue;

  while(cur!= -1){
    result[count] = cur;
    count++;
    cur = parent[cur];

  }

  cout << maxvalue << endl;
  cout << count << endl;

  for(int i =count -1; i>=0; i--){
      cout << result[i] << " ";
  }

}
