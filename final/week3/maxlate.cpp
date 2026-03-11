#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 100010;

int n;
int d[MAX_N], c[MAX_N];
pair<int, int> timee[MAX_N];

void read_input(){
  cin >>n;
  for(int i =0; i<n; i++){
    cin >> d[i] >> c[i];
    timee[i].first = d[i] +10;
    timee[i].second = c[i];
  } 
}


int main(){
  read_input();
  sort(timee, timee+n);

  long long cur = 0;
  long long max_c = 0;

  for(int i = 0; i<n; i++){
    cur += timee[i].second;
    long long late = cur - timee[i].first;

    if(late > max_c) max_c = late;
  }

  if (max_c <0) max_c  =0;
  cout << max_c * 1000;

  

}
