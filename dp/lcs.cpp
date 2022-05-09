#include <bits/stdc++.h>

using namespace std;

int recursive(string n, string m, int nIdx, int mIdx){
    
    if(nIdx < 0 || mIdx < 0) return 0;

    int count = 0;

    if(n[nIdx] == m[mIdx]){
        nIdx--; mIdx--;
        count += 1 + recursive(n, m, nIdx, mIdx);
    }
    else if(n[nIdx] != m[mIdx]){
        count += max(recursive(n, m, nIdx-1, mIdx), recursive(n, m, nIdx, mIdx-1));
    }

    return count;

}

int memoize(string n, string m, int nIdx, int mIdx, vector<vector<int>>& dp){

    if(dp[nIdx][mIdx] != -1) {
        // print used values
        // cout << "dp" << "[" << nIdx << ']' << "[" << mIdx << "] = " << dp[nIdx][mIdx] << endl; 
        return dp[nIdx][mIdx];
    }

    if( nIdx == 0 || mIdx == 0){
        return 0;
    }

    int count = 0;
    if(n[nIdx-1] == m[mIdx-1]) 
    count += 1 + memoize(n, m, nIdx-1, mIdx-1, dp);
    else count += max(memoize(n, m, nIdx-1, mIdx, dp), memoize(n, m, nIdx, mIdx-1, dp))  ;

    dp[nIdx][mIdx] = count;
    return dp[nIdx][mIdx];
}

int top_down(string n, string m){

    vector<vector<int>> dp(n.size()+1, vector<int>(m.size()+1, -1));

    for(int i = 0; i <= n.size(); i++){
        for(int j = 0; j <= m.size(); j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= n.size(); i++){
        for(int j = 1; j <= m.size(); j++){
            if(n[i-1] == m[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    for(auto row: dp){
        for(auto a: row) cout << a << " ";
        cout << endl;
    }

    return dp[n.size()][m.size()];

}

int main(){

    string n = "intension";//"abcdefg";
    string m = "execution";//"acgefi";

    int answer = recursive(n, m, n.size()-1, m.size()-1);
    cout << "Recurion answer: " << answer << "\n";

    vector<vector<int>> dp(n.size()+1, vector<int>(m.size()+1, -1));
    
    int memoAnswer = memoize(n, m, n.size(), m.size(), dp);
    cout << "Memoize answer: " << memoAnswer << "\n";

    // uncomment to print memoized dp matrix
    // for(auto row: dp){
    //     for(auto a: row) cout << a << " ";
    //     cout << endl;
    // }

    int top_down_answer = top_down(n, m);
    cout << "top down answer: " << top_down_answer << endl;





    return 0;
}