// Find all prime numbers between 1 to n  -->  O(n*sqrt(n))) approach  not optimal
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){

    for(int i = 2; i*i <= n; i++){
        if(n%i==0) return false;
    }

    return true;
}

int main(){

    int n;

    cin >> n;

    vector<int> primes;
    for(int i = 2; i <= n; i++){
        if(isPrime(i)) primes.push_back(i);
    }
    cout << "There are " << primes.size() << " primes between 1 and " << n << endl;  
    cout << "primes: ";
    for(auto prime: primes) cout << prime << " ";
    cout << endl;

    return 0;
}