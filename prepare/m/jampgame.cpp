#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// กำหนดทิศทางการเดิน 4 ทิศทาง (ขวา, ซ้าย, ล่าง, บน)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    // ใช้ Queue สำหรับ BFS
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    bool reached = false;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        // ถ้าถึงมุมขวาล่างแล้วให้หยุด
        if (r == N - 1 && c == N - 1) {
            reached = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // ตรวจสอบขอบตารางและว่าเคยไปหรือยัง
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc]) {
                
                // เงื่อนไขการเดิน: 
                // 1. ถ้าความสูงลดลงหรือเท่าเดิม (grid[nr][nc] <= grid[r][c]) เดินได้เสมอ
                // 2. ถ้าความสูงเพิ่มขึ้น ต้องไม่เกิน K (grid[nr][nc] - grid[r][c] <= K)
                if (grid[nr][nc] <= grid[r][c] || (grid[nr][nc] - grid[r][c] <= K)) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    if (reached) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}