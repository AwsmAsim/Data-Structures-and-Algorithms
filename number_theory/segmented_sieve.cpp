#include <bits/stdc++.h>

using namespace std;

vector<int> prime_numbers_final;

void print1d(vector<int> lst){
    cout << "\n{ ";
    for(auto a: lst) cout << a << ", ";
    cout << " }" << endl;
}

void print1dBool(vector<bool> lst){
    cout << "{ ";
    for(auto a: lst) cout << a << ", ";
    cout << " }" << endl;
}

vector<int> soe(int n){
    vector<bool> primes(n+1, true);
    print1dBool(primes);
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

    print1d(prime_numbers);

    return prime_numbers;
}

void segmented_sieve(int n){

    int limit = int(sqrt(n)) + 1;
    cout << "limit:" << limit << endl;
    vector<int> prime_numbers = soe(limit);

    int low = limit + 1;
    int high = limit*2;

    cout << "Initial values - low: " << low << " high: " << high << endl;

    while(low < n){
        if(high >= n) high = n;

        cout << "\nlow: " << low << " high: " << high << endl; 


        vector<bool> mark(limit+1, true);

        for(int i = 0; i < prime_numbers.size(); i++){

            cout << "\ti: " << i << endl;

            int lowLimit = int(low/prime_numbers[i]) * prime_numbers[i];

            if(lowLimit < low){
                lowLimit += prime_numbers[i];
            }

            cout << "\tlowLimit: " << lowLimit << endl;

            for(int j = lowLimit; j < high; j+=prime_numbers[i]){
                cout << "\t\tj: " << j << " low: " << low << endl;
                mark[j-low] = false;
            }
            cout << "\tmark: "; print1dBool(mark);

        }

        for(int i = low; i < high; i++){

            cout << "outer i: " << i << " low: " << low << endl;

            if(mark[i-low]) {
                cout << "\n" << i << " ";
            }
        }
        cout << endl;

        low = low + limit;
        high = high + limit;


    }

}

int main(){

    int n;
    cin >> n;

    segmented_sieve(n);




    return 0;
}