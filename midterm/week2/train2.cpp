#include <iostream>
#include <list>
#include <vector>

using namespace std;

// กำหนดจำนวนชานชลาสูงสุดตามโจทย์ (100,000)
const int MAX_PLATFORMS = 100000;

int main() {
    // I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    // โค้ดที่แก้ไข: รับแค่ M ตัวเดียว
    if (!(cin >> m)) return 0;
    
    // N (จำนวนชานชลา) ถูกกำหนดโดย MAX_PLATFORMS
    vector<list<long long> > l(MAX_PLATFORMS + 1);

    for (int k = 0; k < m; ++k) {
        char type;
        if (!(cin >> type)) break; 

        if (type == 'N') {
            long long x;
            int i;
            if (!(cin >> x >> i)) break;
            
            // ตรวจสอบขอบเขต
            if (i >= 1 && i <= MAX_PLATFORMS) {
                l[i].push_back(x);
            }
        } else { // type == 'M'
            int i, j;
            if (!(cin >> i >> j)) break; 
            
            // ตรวจสอบขอบเขต
            if (i >= 1 && i <= MAX_PLATFORMS && j >= 1 && j <= MAX_PLATFORMS) {
                l[j].splice(l[j].end(), l[i]);
            }
        }
    }

    // แสดงผลลัพธ์จากชานชลา 1 ถึง 100000
    for (int i = 1; i <= MAX_PLATFORMS; ++i) {
        for (auto t : l[i]) {
            cout << t << "\n";
        }
    }
    
    return 0;
}
