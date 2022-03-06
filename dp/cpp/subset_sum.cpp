#include <bits/stdc++.h>

using namespace std;

bool subsetSumTabulation(vector<int> arr, int sum){

    vector<vector<bool>> dp(arr.size()+1, vector<bool>(sum+1, false));

    for(int i = 0; i <= arr.size(); i++){
        for(int j = 0; j <= sum; j++){
            if(j == 0) dp[i][j] = true;
            else if(i==0) dp[i][j] = false;
        }
    }

    for(int i = 1; i <= arr.size(); i++){
        for(int j = 1; j <= sum; j++){
            if(j>=arr[i-1] && dp[i-1][j-arr[i-1]] == true){
                dp[i][j] = true;
            }else 
                if(dp[i-1][j]==true) dp[i][j] = true;
            else dp[i][j] = false;
        }
    }

    // Un-comment to print DP
    // for(auto row: dp){
    //     for(auto a: row){
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }

    return dp[arr.size()][sum];
}


int main(){

    vector<int> arr = {1, 2, 1};
    bool answer = subsetSumTabulation(arr, 3);
    if(answer) cout << "\nSubSet Sum Possible !!!";
    else cout << "\nSubSet Sum not Possible!!!";

    return 0;
}