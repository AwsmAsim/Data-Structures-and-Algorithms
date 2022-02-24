#include <bits/stdc++.h>

using namespace std;

int climbStairsRecursive(int n, vector<int>& dp){

        // cout << n << " " << dp[n] << endl;
        if(n > 0 && dp[n]!=-1){
            return dp[n];
        }
        
        if(n<=0){
            if(n==0) return 1;
            return 0;
        }
        
        int n1 = climbStairsRecursive(n-1, dp);
        int n2 = climbStairsRecursive(n-2, dp);
        dp[n] = n1 + n2;
        // cout << n << " " << dp[n] << endl;
        return dp[n];
    }

int main(){
    int givenN = 3;

    // vector<int> dp(givenN+1, -1);
    givenN++;
    vector<int> dp(givenN, -1);

    int sol = climbStairsRecursive(--givenN, dp);
    // vector<int> dp(givenN, -1);

    for(auto i: dp){
        cout << i << " " ;
    }
    cout << endl;

    cout << "Solution: " << sol << endl;
    return 0;
}