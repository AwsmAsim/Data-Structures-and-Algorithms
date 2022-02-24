// Leetcode  subset II  --> https://leetcode.com/problems/subsets-ii/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    
private:
    void find_subsets(vector<int>& arr, int idx, vector<int> cList, vector<vector<int>>& outList){
        // if(idx == arr.size()){
        //     outList.push_back(cList);
        //     return outList;
        // }
        outList.push_back(cList);

        for(int i = idx; i < arr.size(); i++){
            if(i!=idx && arr[i] == arr[i-1]){
                continue;
            }
            cList.push_back(arr[i]);
            find_subsets(arr, i+1, cList, outList);
            cList.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> outList;
        vector<int> cList;
        find_subsets(nums, 0, cList, outList);
        return outList;
    }
};