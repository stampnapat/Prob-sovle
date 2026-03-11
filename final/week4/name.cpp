#include<iostream>
#include<string>

using namespace std;

string s, t;

int main(){
  cin >> s >>t;

  int j = 0;
  int ans = 0;
  int n = s.length();

  for(int i = 0; i< t.length(); i++){
    if(t[i] == s[j]){
      j++;
      if(j==n){
        ans++;
        j=0;
      }
    }
  }
  cout<<ans;
}
