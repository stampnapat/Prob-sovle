#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> graph(n+1);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    const int INF = 1e9;

    // แก้ตรงนี้
    vector<vector<int>> dist(n+1, vector<int>(3, INF));

    queue<pair<int, int>> q;

    dist[s][0] = 0;
    q.push({s, 0});

    while (!q.empty()){
        int u = q.front().first;
        int w = q.front().second;
        q.pop();

        int current = dist[u][w];

        for(auto edge: graph[u]){
            int v = edge.first;
            int c = edge.second;

            int new_w = -1;

            if (c == 0){
                new_w = w;
            } 
            else {
                if (w == 0){
                    new_w = c;
                }
                else if (w == c){
                    new_w = w;
                }
                else {
                    continue;
                }
            }

            if (dist[v][new_w] > current + 1){
                dist[v][new_w] = current + 1;
                q.push({v, new_w});
            }
        }
    }

    int ans = min(dist[t][0], min(dist[t][1], dist[t][2]));

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}