// leetcode  permutations  --> https://leetcode.com/problems/permutations/
// all possible permutations of a string.
// sample input = [1,2,3]
// sample output = [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Time complexity: n! x n

#include <bits/stdc++.h>
using namespace std;

//answer
class Solution {
    
private:
    void getPermutations(vector<int>& nums, vector<int> cList, vector<vector<int>>& outL, unordered_map<int, int> hMap){
        if(cList.size() == nums.size()){
            outL.push_back(cList);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(hMap[nums[i]] == 1) continue;
            cList.push_back(nums[i]);
            hMap[nums[i]] = 1;
            // recursive call here
            getPermutations(nums, cList, outL, hMap);
            cList.pop_back();
            hMap[nums[i]] = 0;          
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> outL;
        vector<int> cList;
        unordered_map<int, int> hMap;
        getPermutations(nums, cList, outL, hMap);
        return outL;
    }
};