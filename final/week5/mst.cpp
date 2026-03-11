#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_N = 100010;
const int MAX_M = 200010;

int n, m;

pair<int, int> edges[MAX_M];
int weights[MAX_M];
vector<pair<int, int>> windex;

void read_input(){
  cin >> n >> m;
  windex.reserve(m);
  for(int i =0; i<m; i++){
    int u, v, l;
    cin >> u >> v >> l; u--; v--;
    edges[i] = {u, v};
    weights[i] = l;

    windex.push_back({l, i});
  }
  sort(windex.begin(), windex.end());

}

int parent_[MAX_N];
int rnk_[MAX_N];

void init_union_find()
{
  for(int i=0; i<n; i++){
    parent_[i] = i;
    rnk_[i] = 0;
  }
}

int find(int u)
{
  if(parent_[u] == u) return u;
  return parent_[u] = find(parent_[u]);
}

void union_sets(int u, int v)
{
  u  = find(u);
  v = find(v);
  if( u == v) return;

  if(rnk_[u] < rnk_[v]) swap(u, v);
  parent_[v] = u;
  if(rnk_[u] == rnk_[v]) rnk_[u]++;
  
}

int main()
{
  read_input();
  long long cost = 0;
  init_union_find();

  int used = 0;
  for(int i = 0; i<m; i++){
    int e = windex[i].second;
    int l = weights[e];
    int u = edges[e].first;
    int v = edges[e].second;

    if(find(u) != find(v)){
      cost += l;
      union_sets(u, v);
      used++;
      if(used == n-1) break;
    }
  }
  cout << cost;
  return 0;

}