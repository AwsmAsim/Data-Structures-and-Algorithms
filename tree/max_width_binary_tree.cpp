// Leetcode : https://leetcode.com/problems/maximum-width-of-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q;
        int ans = 0;
        q.push({root, 0});
        while(!q.empty()){
            int size  = q.size();
            int mmin = q.front().second;
            int start, end;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long curr_id = q.front().second - mmin;
                q.pop();
                if(node->left!=NULL) q.push({node->left, curr_id*2 + 1});
                if(node->right!=NULL) q.push({node->right, curr_id*2 + 2});
                if(i==0) start = curr_id;
                if(i==size-1) end = curr_id;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};