#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int weight;
};

struct Node {
    int u;
    long long dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void solve(int caseNum) {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[s] = 0;
    pq.push({s, 0});

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int u = curr.u;
        long long d = curr.dist;

        if (d > dist[u]) continue;
        if (u == t) break;

        for (auto& edge : adj[u]) {
            if (dist[edge.to] > dist[u] + edge.weight) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({edge.to, dist[edge.to]});
            }
        }
    }

    cout << "Case #" << caseNum << ": ";
    if (dist[t] == INF) {
        cout << "unreachable" << endl;
    } else {
        cout << dist[t] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_test_cases;
    cin >> num_test_cases;
    for (int i = 1; i <= num_test_cases; i++) {
        solve(i);
    }

    return 0;
}