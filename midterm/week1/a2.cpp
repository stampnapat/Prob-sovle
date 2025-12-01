#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int total = 0;
  int times;
  cin >> times;

  for (int i = 0; i<times; i++) {
    int x, y;
    int area2, area4, area6, area8, area10;
    int area;
    const double pi = 3.14159265358979323846;
    cin >> x >> y;
    double r = sqrt(x*x + y*y);
    area = pi * r * r;

    area2 = pi * 2 * 2;
    area4 = pi * 4 * 4;
    area6 = pi * 6 * 6;
    area8 = pi * 8 * 8;
    area10 = pi * 10 * 10;
    if (area <= area2){
      total += 5;
    }else if ( area <= area4) {
      total += 4;
    }else if ( area <= area6) {
      total += 3;
    }else if ( area <= area8) {
      total += 2;
    }else if ( area <= area10) {
      total += 1;
    }else {
      total += 0;
    }
    
 
  }
  cout << total;

}
