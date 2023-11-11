//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}


// } Driver Code Ends
/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
         Node* temp1 = head2;
        Node* temp2 = head1;
        Node* head3 = NULL;
        Node* temp;
        map<int,int> mp;
        while(temp1){    //STORE VALUES OF LIST IN HASHMAP
            mp[temp1->data]++;
            temp1=temp1->next;
        }
        
        while(temp2){ 
            if(mp[temp2->data]){   
   //IF SAME VALUE ALREADY PRESENT, ADD TO NEW LIST
                Node* newnode = new Node(temp2->data);
                if(head3 == NULL){
                    head3 = newnode;
                    temp = head3;
                }else{
                    temp->next = newnode;
                    temp = temp->next;
                }
                
            }
            temp2=temp2->next;
        }
        return head3;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    
	    cin>> n;
	    Node* head1 = inputList(n);
	    
	    cin>>m;
	    Node* head2 = inputList(m);
	    Solution obj;
	    Node* result = obj.findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends