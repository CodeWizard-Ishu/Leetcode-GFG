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

        /*Recursive*/

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> arr;
//         postorder(root, arr);
//         return arr;
//     }

// private:
//     void postorder(TreeNode* root, vector<int> &arr){
//         if(root==NULL)
//             return;
//         postorder(root->left, arr);
//         postorder(root->right, arr);
//         arr.push_back(root->val);
//     }

        /*Iterative*/

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<TreeNode*> st1, st2;
        TreeNode* node = root;
        st1.push(node);
        while(st1.empty()==false)
        {
            node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left != NULL)
                st1.push(node->left);
            if(node->right != NULL)
                st1.push(node->right);
        }
        while(st2.empty()==false)
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};