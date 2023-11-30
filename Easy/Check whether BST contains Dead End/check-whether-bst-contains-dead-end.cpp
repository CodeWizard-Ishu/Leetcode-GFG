//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    void path(Node *root,vector<Node*> &inorder)
    {
        if(root==NULL)return;
        if(root->left)path(root->left,inorder);
        inorder.push_back(root);
        if(root->right)path(root->right,inorder);
    }
  
    bool isDeadEnd(Node *root)
    {
        //Your code here
        vector<Node*> inorder;
        path(root,inorder);
        int n=inorder.size();
        for(int i=0;i<n;i++){
            if(i==0 && inorder[i]->data==1 && inorder[i+1]->data==2){
                if(inorder[i]->left==NULL && inorder[i]->right==NULL)
                return true;
            }
            if(i==n-1)return false;
            if(i!=0){
                int curr=inorder[i]->data;
                int prev=inorder[i-1]->data;
                int next=inorder[i+1]->data;
                if((prev==curr-1) && (next==curr+1)){
                    if(inorder[i]->left==NULL && inorder[i]->right==NULL)
                return true;
                }
            }
        }
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends