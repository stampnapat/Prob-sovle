#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
    int r, c, dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void solve() {
    int H, W;
    if (!(cin >> H >> W)) return;

    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    if (grid[H - 1][0] == 'X' || grid[0][W - 1] == 'X') {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> min_energy(H, vector<int>(W, 1e9));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    min_energy[H - 1][0] = 0;
    pq.push({H - 1, 0, 0});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int cost[] = {5, 0, 1, 1}; // ขึ้น (แถวลด), ลง (แถวเพิ่ม), ซ้าย, ขวา

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int r = curr.r;
        int c = curr.c;
        int d = curr.dist;

        if (d > min_energy[r][c]) continue;
        if (r == 0 && c == W - 1) {
            cout << d << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '.') {
                if (min_energy[nr][nc] > d + cost[i]) {
                    min_energy[nr][nc] = d + cost[i];
                    pq.push({nr, nc, min_energy[nr][nc]});
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}