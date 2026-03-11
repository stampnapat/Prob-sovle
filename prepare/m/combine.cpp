#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // เพิ่มความเร็วในการรับส่งข้อมูล (I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    long long B;
    if (!(cin >> N >> B >> K)) return 0;

    vector<long long> V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    // Pre-calculate กำไรสุทธิของช่วง [i, j] หากรวมเป็นผืนเดียวกัน
    // profit[i][j] คือกำไรของการนำที่ดินผืนที่ i ถึง j มารวมกัน
    vector<vector<long long>> profit(N + 1, vector<long long>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        long long max_v = 0;
        for (int j = i; j <= N; j++) {
            max_v = max(max_v, V[j]);
            long long L = j - i + 1; // จำนวนที่ดินในกลุ่ม
            // ราคารวม = ราคาสูงสุด + (จำนวนชิ้น-1)*(ราคาสูงสุด/2) - (จำนวนชิ้น-1)*ค่าทุบรั้ว
            profit[i][j] = max_v + (L - 1) * (max_v / 2) - (L - 1) * B;
        }
    }

    // DP Table 
    // dp[i][j] คือ กำไรมากสุดเมื่อจัดการที่ดิน i ผืนแรก โดยแบ่งเป็น j กลุ่ม
    const long long INF = -1e18; // ค่าเริ่มต้นให้น้อยมากๆ ไว้ก่อน
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, INF));

    // Base case: ที่ดิน 0 ผืน แบ่งเป็น 0 กลุ่ม ได้กำไร 0
    dp[0][0] = 0;

    // ทำ Dynamic Programming
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            for (int m = 0; m < i; m++) {
                if (dp[m][j - 1] != INF) {
                    dp[i][j] = max(dp[i][j], dp[m][j - 1] + profit[m + 1][i]);
                }
            }
        }
    }

    // หาค่าที่สูงที่สุดที่แบ่งได้ไม่เกิน K กลุ่ม
    long long max_profit = INF;
    for (int j = 1; j <= K; j++) {
        max_profit = max(max_profit, dp[N][j]);
    }

    cout << max_profit << "\n";

    return 0;
}