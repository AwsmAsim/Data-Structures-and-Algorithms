#include <bits/stdc++.h>

using namespace std;

int topDown(vector<int>& arr){
    vector<int> dp(arr.size()+1, 0);
    int maxElement = INT_MIN;

    for(auto a: arr) cout << a << " "; 

    for(int i = 1; i <= arr.size(); i++){
        int pick, notPick;
        if(arr[i-1] > maxElement){
            maxElement = arr[i-1];
            pick = 1 + dp[i-1];
            cout << "\npick: " << dp[i-1] << endl;
        }else{
            pick = dp[i-1];
        }
        dp[i] = pick;
    }

    // for(auto a: dp) cout << a << " "; 

    return dp[arr.size()];

}

int recursive1(vector<int>& arr, int idx, int maxElement){
    if(idx==arr.size()) return 0;

    int notPick, pick;

    if(maxElement == INT_MIN || arr[idx] > maxElement){
        maxElement = arr[idx];
        pick = 1 + recursive1(arr, idx + 1, maxElement);
    }
    else pick = recursive1(arr, idx + 1, maxElement);

    notPick = recursive1(arr, idx + 1, INT_MIN);

    return max(pick, notPick);
}



int main(){

    vector<int> arr = {10, 20, 1, 2, 3, 4};//{3, 10, 2, 1, 20};//{10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> curList;
    int answer = recursive1(arr, 0, INT_MIN);
    // int answer = topDown(arr);
    cout << answer << endl;
    return 0;
}