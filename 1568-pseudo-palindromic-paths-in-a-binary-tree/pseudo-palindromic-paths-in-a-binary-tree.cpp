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
    int ans = 0;
    void solve(TreeNode* root, unordered_map<int, int> &mp)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        if(root->left == NULL && root->right == NULL)
        {
            int count = 0;
            for(auto it : mp)
            {
                if(it.second%2 == 1)
                    count++;
            }
            if(count<=1)
                ans++;
        }
        solve(root->left, mp);
        solve(root->right, mp);
        mp[root->val]--;
        if(mp[root->val] == 0)
            mp.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);
        return ans;
    }
};