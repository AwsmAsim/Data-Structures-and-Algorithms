#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    vector<vector<int>> answers;
    cin >> t;
    while(t){
        int n, m, a;
    	cin >> n >> m;
    	vector<int> arr, answer;
    	// n -> target, m -> given length
    	for(int i = 0; i < m; i++){
    	    cin >> a;
    	    arr.push_back(a);
    	}
    	int range = 0;
    	for(int i = 0; i < m; i++){
    	    for(int j = arr[i]; j > range; j--){
    	        answer.push_back(j);
    	    }
    	    range = arr[i];
    	}
    	answers.push_back(answer); // Pushing array obtained by this test case to final 
        --t;
    }
    for(auto a: answers){
        for(auto i: a){
            cout << i << " ";
        }
        cout << endl;
    }
}