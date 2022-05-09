#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> primes;
    for(int i = 2; i <= n; i++){
        // cout << "Checking: " << i << endl; 
        while(n%i==0){
            primes.push_back(i);
            n = n/i;
        }
    }

    for(auto prime: primes) cout << prime << " ";
}