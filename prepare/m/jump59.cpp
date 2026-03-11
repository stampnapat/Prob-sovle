#include <iostream>
#include <vector>

using namespace std;

int N, K;
int grid[25][25];
bool visited[25][25];

// ทิศทางการเดิน 4 ทิศ (ขวา, ซ้าย, ลง, ขึ้น)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool canReach = false;

void dfs(int r, int c) {
    // ถ้าถึงมุมขวาล่างแล้ว
    if (r == N - 1 && c == N - 1) {
        canReach = true;
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        // 1. ตรวจสอบขอบตาราง
        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            // 2. ถ้ายังไม่เคยไป
            if (!visited[nr][nc]) {
                // 3. ตรวจสอบเงื่อนไขความสูง
                // ถ้าความสูงใหม่ <= ความสูงเดิม + K (ครอบคลุมทั้งกรณีความสูงลดลงและเพิ่มไม่เกิน K)
                if (grid[nr][nc] <= grid[r][c] + K) {
                    dfs(nr, nc);
                    if (canReach) return; // ถ้าเจอทางแล้วให้หยุดหาทันที
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    dfs(0, 0);

    if (canReach) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}