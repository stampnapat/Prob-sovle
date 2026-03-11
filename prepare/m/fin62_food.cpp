#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> m(N + 1);
    for (int i = 1; i <= N; i++) cin >> m[i];

    const long long INF = (1LL << 60);

    // dp[food] = คนพลาดน้อยที่สุด "หลังจบช่วงเวลาก่อนหน้า"
    // และตอนนี้เหลืออาหาร food
    vector<long long> dp(K + 1, INF), ndp(K + 1, INF);

    // เริ่มต้นก่อนเวลา 1: อาหารเต็ม K และยังไม่มีคนพลาด
    dp[K] = 0;
    // ไล่ทุกช่วงเวลา
    for (int i = 1; i <= N; i++) {
        // สร้าง dp ใหม่สำหรับ "หลังจบเวลา i"
        fill(ndp.begin(), ndp.end(), INF);
        // ลองทุกปริมาณอาหารที่อาจเหลืออยู่ตอนเริ่มเวลา i
        for (int food = 0; food <= K; food++) {
            if (dp[food] == INF) continue; // สถานะนี้ไม่เคยเกิด
            // ========= ทางเลือก 1: อยู่แจก =========
            if (food >= m[i]) {
                // อาหารพอ -> แจกหมดทุกคน -> คนพลาดไม่เพิ่ม
                int newFood = food - m[i];
                ndp[newFood] = min(ndp[newFood], dp[food]);
            } else {
                // อาหารไม่พอ -> ห้ามแจก -> ทุกคนพลาด
                ndp[food] = min(ndp[food], dp[food] + m[i]);
            }
            // ========= ทางเลือก 2: กลับบ้านเติม =========
            // ช่วงเวลานี้ไม่อยู่ -> คนพลาด m[i]
            // แต่กลับมาช่วงหน้าด้วยอาหารเต็ม K
            ndp[K] = min(ndp[K], dp[food] + m[i]);
        }
        // อัปเดต dp ไปเป็นของรอบถัดไป
        dp.swap(ndp);
    }

    // คำตอบคือค่าพลาดน้อยที่สุดในทุก food ที่เป็นไปได้
    cout << *min_element(dp.begin(), dp.end()) << "\n";
    return 0;
}