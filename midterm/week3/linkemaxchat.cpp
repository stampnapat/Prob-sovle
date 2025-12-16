#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main() {
    int n;
    // เพิ่มการเช็ค input เล็กน้อยเพื่อความปลอดภัย
    if (!(cin >> n)) return 0; 

    map<int, int> like;
    map<int, int> index; // ใช้ตัวแปร index ตามเดิม

    int best = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        like[x]++;
        index[x] = i; // บันทึกว่า x มาล่าสุดที่ลำดับ i

        if (best == 0) {
            best = x;
        } else {
            int current = like[x];     // Like ของตัวปัจจุบัน
            int best_c = like[best];   // Like ของแชมป์เก่า

            // --- ส่วนที่แก้ไข ---
            
            // กรณี 1: ถ้า Like ปัจจุบัน "มากกว่า" แชมป์เก่า -> เปลี่ยนแชมป์
            if (current > best_c) {
                best = x; // แก้จาก best = current เป็น best = x
            }
            // กรณี 2: ถ้า Like "เท่ากัน" -> ให้เช็ค index (ตามโจทย์)
            else if (current == best_c) {
                // เช็คว่าใครมาทีหลัง (index มากกว่า คือ สดใหม่กว่า)
                if (index[x] > index[best]) {
                    best = x;
                }
            }
        }

        cout << best << "\n";
    }
    return 0;
}
