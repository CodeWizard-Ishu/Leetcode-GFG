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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> arr;
//         preorder(root, arr);
//         return arr;
//     }
// private:
//     void preorder(TreeNode* root, vector<int> &arr){
//         if(root==NULL)
//             return;
//         arr.push_back(root->val);
//         preorder(root->left, arr);
//         preorder(root->right, arr);
//     }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(st.empty()==false)
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right != NULL)
                st.push(root->right);
            if(root->left != NULL)
                st.push(root->left);
        }
        return ans;
    }
};