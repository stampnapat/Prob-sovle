#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;

void read_input()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
}

int find_max(vector<int>& x, int n)
{
  if(n == 1)
     return x[0];
  return  max(x[n-1], find_max(x, n-1));
}

int main()
{
  read_input();
  cout << find_max(x,n) << endl;
}
