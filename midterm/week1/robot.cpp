#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char position[1000];
  cin >> position;
  int size = strlen(position);
  int x = 0, y = 0;
  for (int i = 0; i<size; i++){
    char p = position[i];
    if (p == 'N') {
      y++;
    }else if ( p == 'S') {
      y--;
    }else if (p == 'E'){
      x++;
    }else if (p == 'W'){
      x--;
    }else if (p == 'Z'){
      x = 0;
      y = 0;
    }

  }

  cout << x << " " << y;
}
