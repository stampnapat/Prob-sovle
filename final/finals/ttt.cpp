#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge {
    int u, v;
};

bool is_piartite(int n, const vector<vector<int>>& adj){
    vector<int> color(n+1, -1);

    for(int i =1; i<=n; i++){
        if(color[i] == -1){
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : adj[u]){
                    if(color[v] == -1){
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if(color[v] == color[u]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v;
    }

    for(int i = 0; i < m; i++){
        vector<vector<int>> adj(n+1);
        for(int j = 0; j < m; j++){
            if(i != j){
                adj[edges[j].u].push_back(edges[j].v);
                adj[edges[j].v].push_back(edges[j].u);
            }
        }
        if(is_piartite(n, adj)){
            cout << edges[i].u << " " << edges[i].v << "\n";
            return 0;
        }
    }
}