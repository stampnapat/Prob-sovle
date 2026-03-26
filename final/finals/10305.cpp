#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void solve(){
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int> indegree(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i < result.size() - 1 ? " " : "\n");
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}