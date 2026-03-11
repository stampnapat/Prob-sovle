#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// กำหนดค่าอนันต์ (Infinity) สำหรับใช้เปรียบเทียบค่าต่ำสุด
const long long INF = 1e18; 

int main() {
    // ปรับแต่งเพื่อให้รับ input ได้รวดเร็วขึ้น
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, l;
    long long b; // ใช้ long long กัน overflow
    cin >> h >> l >> b;
    
    // สร้าง 2D Vector เก็บค่าใช้จ่ายในการเข้าช่องนั้นๆ
    vector<vector<long long>> arr(h, vector<long long>(l));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < l; j++){
            cin >> arr[i][j];
        }
    }

    // สร้างตาราง DP เพื่อเก็บ "ค่าใช้จ่ายที่น้อยที่สุดในการมาถึงช่อง [i][j]"
    vector<vector<long long>> dp(h, vector<long long>(l, INF));

    // Base Case: คอลัมน์แรก (j=0) ค่าใช้จ่ายจะเท่ากับค่าอากาศของช่องนั้นเลย
    for(int i = 0; i < h; i++){
        dp[i][0] = arr[i][0];
    }

    // เริ่มเดินจากคอลัมน์ที่ 1 ไปจนถึง L-1
    for(int j = 1; j < l; j++){
        for(int i = 0; i < h; i++){
            // กรณี 1: มาจากแถวเดียวกัน (ไม่เสียค่า B)
            dp[i][j] = dp[i][j-1] + arr[i][j];

            // กรณี 2: มาจากแถวบน หรือ i-1 (ต้องเช็คว่าไม่ทะลุขอบบน และเสียค่า B)
            if(i > 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + arr[i][j] + b);
            }

            // กรณี 3: มาจากแถวล่าง หรือ i+1 (ต้องเช็คว่าไม่ทะลุขอบล่าง และเสียค่า B)
            if(i < h - 1){
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + arr[i][j] + b);
            }
        }
    }

    // หาค่าที่น้อยที่สุดในคอลัมน์สุดท้าย
    long long min_cost = INF;
    for(int i = 0; i < h; i++){
        min_cost = min(min_cost, dp[i][l-1]);
    }

    // แสดงผลลัพธ์
    cout << min_cost << "\n";

    return 0;
}