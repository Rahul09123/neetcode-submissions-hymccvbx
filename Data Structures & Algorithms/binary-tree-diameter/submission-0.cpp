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
    //<height,diameter> 
    int maxD = 0;
    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto [lh,ld] = helper(root->left);
        auto [rh,rd] = helper(root->right);
        int currHeight = 1 + max(lh,rh);
        int currDiameter = lh + rh;
        maxD = max(currDiameter,maxD);
        return {currHeight,currDiameter};

    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxD;
    }
};
