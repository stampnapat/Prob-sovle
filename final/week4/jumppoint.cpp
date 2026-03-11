#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
   int n, r;
   cin >> n >> r;
   vector<int> x(n+2), y(n+2);

   x[0] = 0; y[0] = 0;

   for(int i = 1; i<= n; i++){
    cin >> x[i] >> y[i];
   }
    x[n+1] = 100; 
    y[n+1] = 100;


   
   auto jump = [&](int i, int j) -> bool{
    long long dx = x[i] - x[j];
    long long dy = y[i] - y[j];
    return dx*dx + dy*dy <= 1LL * r * r;
   };


   int v = n+2;
   vector<int> dist(v, -1);

   queue<int> q;

   dist[0] = 0;
   q.push(0);

   while (!q.empty()){
    int u = q.front();
    q.pop();

    for(int i = 0; i< v; i++){
        if(dist[i] != -1) continue;

        if(!jump(u, i)) continue;

        dist[i] = dist[u]+1;
        q.push(i);
    }
    
   }
   
   cout << dist[v-1] << "\n";


   

}
