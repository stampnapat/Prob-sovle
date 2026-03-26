#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, T;

    cin >> N >> M >> S >> T;

    vector<vector<int>> adj(N+1);

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N+1, INF);

    queue<int> q;

    for(int i =0; i< S; i++){
        int s;
        cin >> s;
        dist[s] = 0;
        q.push(s);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : adj[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 0; i<T; i++){
        int fac;
        cin >> fac;
        cout << dist[fac] << "\n";
    }
}

