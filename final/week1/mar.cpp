#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int dist26(int a, int b){
  int d = a-b;
  if(d<0) d = -d;

  return min(d, 26-d);
}

int main(){
  int t;
  cin >> t;

  while (t--){
    string s;
    cin >> s;

    int dp[26][26];
    int ndp[26][26];

    for(int i =0; i<26; i++)
      for(int j =0; j<26; j++)
        dp[i][j] = INF;

    dp[0][0] = 0;

    for(char ch:s){
      int c = ch-'A';

      for(int i =0; i<26; i++)
        for(int j=0; j<26; j++)
          ndp[i][j] =  INF;

      for(int l = 0; l<26; l++){
        for(int r =0; r<26; r++){
          int cur = dp[l][r];
          if(cur >= INF) continue;

          ndp[c][r] = min(ndp[c][r], cur + dist26(l, c));
          ndp[l][c] = min(ndp[l][c], cur +dist26(r, c));

        }

      }

      for(int i =0; i<26; i++)
        for(int j=0; j<26; j++)
          dp[i][j] = ndp[i][j];
      

    }
    int ans = INF;
    for(int l =0; l<26; l++)
      for(int r = 0; r<26; r++)
        ans = min(ans, dp[l][r]);

    cout<<ans;

  }

}
