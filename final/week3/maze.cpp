#include <iostream>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool canreach(int n, char grid[20][21], int sr, int sc, int tr, int tc){
    int visted[20][20][2] = {};

    int qr[2000], qc[2000], qk[2000];
    int head = 0, tail = 0;

    visted[sr][sc][1] = 1;
    qr[tail] = sr;
    qc[tail] = sc;
    qk[tail] = 1;
    tail++;

    while (head < tail){
        int r = qr[head];
        int c = qc[head];
        int k = qk[head];
        head++;

        if (r == tr && c == tc) return true;

        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            char cell = grid[nr][nc];

            if (cell == '#') continue;

            if (cell == '.') {
                if (!visted[nr][nc][k]) {
                    visted[nr][nc][k] = 1;
                    qr[tail] = nr;
                    qc[tail] = nc;
                    qk[tail] = k;
                    tail++;
                }
            }
            else if (cell == 'O') {
                if (k == 1 && !visted[nr][nc][0]) {
                    visted[nr][nc][0] = 1;
                    qr[tail] = nr;
                    qc[tail] = nc;
                    qk[tail] = 0;
                    tail++;
                }
            }
        }
    }
    return false;
}

int main(){
    int n, q;
    cin >> n >> q;

    char grid[20][21];
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }

    while(q--){
        int r, c, a, b;
        cin >> r >> c >> a >> b;

        int sr = r - 1, sc = c - 1;
        int tr = a - 1, tc = b - 1;

        if (canreach(n, grid, sr, sc, tr, tc)) cout << "yes\n";
        else cout << "no\n";
    }
}
