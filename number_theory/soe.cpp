#include <bits/stdc++.h>

using namespace std;

vector<int> soe(int n, vector<bool>& primes){
    primes[0] = primes[1] = false;
    for(int i = 2; i < primes.size(); i++){
        if(primes[i]==true){
            for(int j = i*i; j < primes.size(); j+=i){
                primes[j] = false;
            }
        }
    }

    vector<int> prime_numbers;
    for(int i = 0 ; i < primes.size(); i++){
        if(primes[i]==true) prime_numbers.push_back(i);
    }

    return prime_numbers;
}

int main(){
    int n;
    cin >> n;
    vector<bool> primes(n+1, true);

    vector<int> prime_numbers = soe(n, primes);

    cout << "Primes obtained:" << '\n' << "{ ";

    for(auto a: prime_numbers) cout << a << ", ";
    cout << "}";


    return 0;
}