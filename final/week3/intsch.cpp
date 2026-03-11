#include<iostream>
#include<algorithm>

using namespace std;

const int MAX_N = 100010;

int n;
int s[MAX_N], t[MAX_N];
pair<int, int> jobs[MAX_N];

void read_input(){
  cin >>n;
  for(int i =0; i<n; i++){
      cin >> s[i] >> t[i];
      jobs[i].first = t[i];
      jobs[i].second = s[i];
  }

}

int main(){
  read_input();
  sort(jobs, jobs+n);
  int count = 0;
  int last_t = -1;
  for(int i =0; i<n; i++){
    if(jobs[i].second >= last_t){
      count++;
      last_t = jobs[i].first;

    }
  }
  
  cout << count;

}
