#incldue <bits/stdc++.h>

using namespace std;

// Time complexity: O(N), Since we are traversing N number of nodes once.

class Solution {
    
    int getDiameter(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        
        int lh = getDiameter(root->left, maxi), 
            rh = getDiameter(root->right, maxi);
        
        maxi = max(lh + rh, maxi);
        return 1 + max(lh, rh);
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = INT_MIN;
        getDiameter(root, maxi);
        return maxi;
    }
};








// Naive

// class Solution {
    
//     int getHeight(TreeNode* root){
//         if(root == NULL) return 0;
//         return 1 + max(getHeight(root->left), getHeight(root->right));
//     }
    
//     int getDiameter(TreeNode* root){
//         if(root == NULL) return 0;
        
//         int lh = getHeight(root->left), 
//             rh = getHeight(root->right);
        
//         return max(lh+rh, 
//                    max(getDiameter(root->left), getDiameter(root->right))
//                   );
//     }
    
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         return getDiameter(root);
//     }
// };