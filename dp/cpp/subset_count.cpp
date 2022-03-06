#include <bits/stdc++.h>

using namespace std;

int countSubSets(vector<int> arr, int idx, int sum){
    // cout << sum << " ";
    if(sum==0 || idx < 0){
        if(sum==0){
            cout << idx << " ";
            return 1;
        } 
        return 0;
    }

    int count = 0;
    if(arr[idx] <= sum)
    count += countSubSets(arr, idx-1, sum - arr[idx]);  
    else count += countSubSets(arr, idx-1, sum);

    count += countSubSets(arr, idx-1, sum);

    return count;

}

int main(){

    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum1 = 10;

    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum1+1, 0));

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j <= sum1; j++){
            if(j==0){
                dp[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= arr.size(); i++){
        for(int j = 1; j<=sum1; j++){
            if(j>=arr[i-1])
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else 
            dp[i][j] = dp[i-1][j];

        }
    }
    int ans = countSubSets(arr, arr.size()-1, sum1);
    cout << "Answer: " << ans << endl;
    cout << dp[arr.size()][sum1] << endl;


    return 0;
}