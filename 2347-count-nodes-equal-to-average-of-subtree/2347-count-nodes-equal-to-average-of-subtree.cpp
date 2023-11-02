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
    int count=0;
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        pair<int,int> lsum=helper(root->left);
        pair<int,int> rsum=helper(root->right);
        int sum = lsum.first+rsum.first+root->val;
        int node = 1+lsum.second+rsum.second;
        if(sum/node==root->val)
            count++;
        return {sum,node};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
};