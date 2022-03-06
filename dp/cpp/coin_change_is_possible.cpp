#include <bits/stdc++.h>

using namespace std;

int tabulation(vector<int> arr, int idx, int sum1){
    int n = arr.size();
    vector<vector<bool>> dp(n+1, vector<bool>(sum1+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum1; j++){

            if(j == 0){
                dp[i][j] = true;
            }else if(dp[i-1][j] == true){
                dp[i][j] = true;
            }else if((j-arr[i-1]>=0) && dp[i - 1][j-arr[i-1]]){
                dp[i][j] = true;
            }else dp[i][j] = false;
        }
    }

    return (int) dp[idx][sum1];

}

int memoize(vector<int> arr, int idx, int sum1, vector<vector<int>>& dp){
    if(dp[idx][sum1] != -1){
        cout << "Using the value of: " << " idx: "<< idx << " sum1: " << sum1 << " " << dp[idx][sum1] << endl;
        return dp[idx][sum1];
    }

    if(idx == 0 || sum1 <= 0){
        if(sum1 == 0){
            dp[idx][sum1] = 1;
        }else{
            dp[idx][sum1] = 0;  
        } 
        return dp[idx][sum1];
    }
    
    if(memoize(arr, idx - 1, sum1, dp)){
        dp[idx][sum1] = true;
    }else if(memoize(arr, idx - 1, sum1 - arr[idx], dp)){
        dp[idx][sum1] = true;
    }else{
        dp[idx][sum1] = false;
    }
    return dp[idx][sum1];
}

bool recursion(vector<int> arr, int idx, int sum1){
    if(idx == 0 || sum1 == 0){
        if(sum1 == 0) return true;
        return false;
    }

    if(recursion(arr, idx - 1, sum1)){
        return true;
    }else if(recursion(arr, idx - 1, sum1 - arr[idx])){
        return true;
    }
    return false;
}

int main(){

    vector<int> arr; //= {4, 2, 7, 1, 3};
    int temp, n, target = 10;
    cin >> n >> target; // no of elements in array
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    int dpSize = arr.size() + 1;
    vector<vector<int>> dp(dpSize, vector<int>(target+1, -1));

    int possible = tabulation(arr, arr.size()-1, target);

    
    if(possible) cout << "POSSIBLE" << endl; 
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}