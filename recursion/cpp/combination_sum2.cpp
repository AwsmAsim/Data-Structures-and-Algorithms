#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> outL;

void getCombinations(vector<int>& arr, int target, int idx, vector<int>& ds){


    // if(idx == arr.size()-1){
    //     // cout << target << endl; 
        
    //     return;
    // }

    if(target == 0){
        outL.push_back(ds);
        return;
    }

    

    if(target < 0){
        return;
    }

    for(int i = idx; i < arr.size(); i++){
        if(i>idx && arr[i] == arr[i-1]) continue;
        if(arr[i] > target ) break;
        ds.push_back(arr[i]);
        getCombinations(arr, target - arr[i], i, ds);
        ds.pop_back();
    }

}

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds) {
    if(target==0) {
        ans.push_back(ds);
        return;
    }        
    for(int i = ind;i<arr.size();i++) {
        if(i>ind && arr[i]==arr[i-1]) continue; 
        if(arr[i]>target) break; 
        ds.push_back(arr[i]);
        findCombination(i+1, target - arr[i], arr, ans, ds); 
        ds.pop_back(); 
    }
}


int main(){

    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 4;
    vector<int> ds;
    getCombinations(arr, target, 0, ds);
    // findCombination(0,target,arr,outL,ds);
    cout << outL.size();
    for(auto a: outL){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}