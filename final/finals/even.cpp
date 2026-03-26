#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to, weight;
};

struct Node {
    int u, state;
    long long d;
    bool operator>(const Node& other) const {
        return d > other.d;
    }
};

void solve() {
    int C, V;
    while (cin >> C >> V) {
        vector<vector<Edge>> adj(C + 1);
        for (int i = 0; i < V; i++) {
            int u, v, g;
            cin >> u >> v >> g;
            adj[u].push_back({v, g});
            adj[v].push_back({u, g});
        }

        vector<vector<long long>> dist(C + 1, vector<long long>(2, INF));
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        dist[1][0] = 0;
        pq.push({1, 0, 0});

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int u = curr.u;
            int s = curr.state;
            long long d = curr.d;

            if (d > dist[u][s]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.to;
                int next_s = 1 - s;
                if (dist[v][next_s] > d + edge.weight) {
                    dist[v][next_s] = d + edge.weight;
                    pq.push({v, next_s, dist[v][next_s]});
                }
            }
        }

        if (dist[C][0] == INF) cout << -1 << endl;
        else cout << dist[C][0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}