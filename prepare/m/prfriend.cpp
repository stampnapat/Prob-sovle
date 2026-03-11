#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPrime(int num){
    if(num < 2) return false;

    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int l, r;
    cin >> l >> r;

    vector<int> prime; 
    int ans = 0;

    for(int i = l; i <= r; i++){
        if(isPrime(i)){
            prime.push_back(i);
        }
    }

    for(int i = 0; i < prime.size() - 1; i++){
        if(prime[i+1] - prime[i] == 2){
            ans++;
        }
    }

    cout << ans << endl;
}