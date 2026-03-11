#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool pairable(char a, char b) {
    if (a == 'A' && b == 'U') return true;
    if (a == 'U' && b == 'A') return true;
    if (a == 'C' && b == 'G') return true;
    if (a == 'G' && b == 'C') return true;
    return false;
}


int main(){
    string b;
    cin >> b;
    int sb = b.size();



}