//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    struct Node* reverse(Node *head) {
     Node *temp = NULL;
     Node *prev = NULL;
    Node *current = head;
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node2==NULL)
        {
            return reverse(node1);
        }
        if(node1==NULL)
        {
            return reverse(node2);
        }
        if(node2->data>node1->data)
        {
            return mergeResult(node2,node1);
        }
        Node * curr1=node1;
        Node * prev1=node1;
        Node * curr2=node2->next;
        Node * prev2=node2;

        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->data<=curr2->data)
       {
                curr1=curr1->next;
                prev2->next=prev1;
                prev1->next=curr2;
                prev2=prev1;
                prev1=curr1;

                
            }
            else if(curr1->data>curr2->data)
            {
                curr2=curr2->next;
                prev2=prev2->next;
            }
        }
        if(curr1!=NULL)
        {
            prev2->next=curr1;
        }
        
        return reverse(node2);
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends