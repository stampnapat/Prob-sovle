#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e15;
long long dp[2][1 << 11]; // ใช้ Rolling Array เพื่อประหยัดหน่วยความจำ (32MB)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> C(N + 1);
    vector<int> S(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> C[i] >> S[i];
    }

    // เริ่มต้น DP
    for (int m = 0; m < (1 << 11); ++m) dp[0][m] = INF;
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        int curr = i % 2;
        int prev = (i - 1) % 2;
        for (int m = 0; m < (1 << 11); ++m) dp[curr][m] = INF;

        for (int m = 0; m < (1 << 11); ++m) {
            if (dp[prev][m] == INF) continue;

            // ทางเลือกที่ 1: ติดตั้งเครื่องบำบัดที่บ้านหลังที่ i
            int L = max(1, i - S[i]);
            int R = min(N, i + S[i]);
            
            // ปรับ Mask ใหม่ตามระยะครอบคลุมของเครื่องที่บ้าน i
            int new_mask = m;
            for (int k = L; k <= R; ++k) {
                if (k >= i) { // สนใจเฉพาะบ้านที่ i เป็นต้นไป
                    new_mask |= (1 << (k - i));
                }
            }
            dp[curr][new_mask >> 1] = min(dp[curr][new_mask >> 1], dp[prev][m] + C[i]);

            // ทางเลือกที่ 2: ไม่ติดตั้งเครื่องที่บ้าน i
            // เงื่อนไข: บ้านหลังที่ i ต้องถูกครอบคลุมโดยเครื่องก่อนหน้าแล้ว (บิตที่ 0 ของ m ต้องเป็น 1)
            if (m & 1) {
                dp[curr][m >> 1] = min(dp[curr][m >> 1], dp[prev][m]);
            }
        }
    }

    // คำตอบคือสถานะที่บ้านทุกหลัง (จนถึง N) ถูกครอบคลุม
    // หลังจาก loop จบ เราจะได้คำตอบที่ dp[N%2][0] 
    // เพราะเรา shift mask ออกไปเรื่อยๆ จนครบ N ครั้ง
    cout << dp[N % 2][0] << endl;

    return 0;
}