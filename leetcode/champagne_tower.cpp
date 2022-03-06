#include <bits/stdc++.h>

using namespace std;

int main(){

    // int n;
    // cin >> n;
    // vector<int> dp(n, 0); // Because 0 based indexing
    // dp[0] = 1;
    // for(int i = 2; i <= n; i++){
    //     dp[i-1] = dp[i-2] + i; 
    // }

    // for(auto a: dp) cout << a << " ";

    double row, poured, glass;
    cin >> poured >> row >> glass;
    vector<vector<double>> dp(row+1, vector<double>(glass+1, 0));

    dp[0][0] = poured;

    for(int i = 1; i <= row; i++ ){
        for(int j = 0; j <= glass; j++){
            cout << i << endl;
            if(j == 0){
                if(dp[i-1][j]>1){
                    dp[i][j] = (dp[i-1][j] - 1)/2;
                }else dp[i][j] = 0;
            }else if(j==i){
                if(dp[i-1][j-1] > 0){
                    dp[i][j] = (dp[i-1][j-1]-1)/2;
                }else dp[i][j] = 0;
            }else{
                if(dp[i-1][j-1] > 1 && dp[i-1][j]>1){
                    dp[i][j] = dp[i][j] = ((dp[i-1][j] - 1)/2) + ((dp[i-1][j-1]-1)/2);
                }
                else if(dp[i-1][j]>1){
                    dp[i][j] = (dp[i-1][j] - 1)/2;
                }else if(dp[i-1][j-1] > 1){
                    dp[i][j] = (dp[i-1][j-1]-1)/2;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
    }


    for( auto row: dp){
        for(auto a: row) cout << a << " ";
        cout << "\n";
    }

    if(dp[row][glass] >= 1)
    cout << "\nAnswer: " << 1;
    else  cout << "\nAnswer: " << dp[row][glass];


    return 0;
}