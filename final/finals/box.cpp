#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring> // สำหรับ memset

using namespace std;

int n, m;
vector<string> grid;
bool visited[35][35];

bool can_place(int r, int c) {
    // เช็คขอบเขตของกล่อง 2x2
    if (r < 0 || r + 1 >= n || c < 0 || c + 1 >= m) return false;
    // เช็คสิ่งกีดขวางทั้ง 4 ช่อง
    return grid[r][c] == '.' && grid[r][c+1] == '.' && 
           grid[r+1][c] == '.' && grid[r+1][c+1] == '.';
}

void solve() {
    if (!(cin >> n >> m)) return;
    grid.assign(n, ""); 
    memset(visited, false, sizeof(visited)); // เคลียร์ค่า visited

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    queue<pair<int, int>> q;

    // หาจุดเริ่มต้นที่แถวบนสุด (r = 0)
    for (int j = 0; j <= m - 2; j++) {
        if (can_place(0, j)) {
            q.push({0, j});
            visited[0][j] = true;
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        // ถ้ามุมซ้ายบนของกล่องถึงแถว n-2 แสดงว่าขอบล่างของกล่องถึง n-1 แล้ว
        if (r == n - 2) {
            cout << "yes" << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // ตรวจสอบเงื่อนไขการเดิน
            if (nr >= 0 && nr <= n - 2 && nc >= 0 && nc <= m - 2) {
                if (!visited[nr][nc] && can_place(nr, nc)) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << "no" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); // เรียกใช้ครั้งเดียวตามโครงสร้างโจทย์ทั่วไป

    return 0;
}