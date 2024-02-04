//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string convertTostring(Node * head1)
    {
        string s="";
        while(head1)
        {
            s+=('0'+head1->data);
            head1=head1->next;
        }
        return s;
    }
        
    string trimZeroes(string &s)
    {
        int i=0;
        while(s[i]=='0')
            i++;
        return s.substr(i);
    }
    
    void findGreater(string &a,string &b)
    {
        if(b.size()>a.size())
            swap(a,b);
        else if(a.size()==b.size())
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]==b[i])
                    continue;
                else if(a[i]<b[i])
                    swap(a,b);
                return;
            }
        }
    }
        
    string sub(string a,string b)
    {
        string s="";
    
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    
        int i=0;
    
        for(i=0;i<b.size();i++)
        {
            int t=(a[i]-'0')-(b[i]-'0');
            if(t>=0)
                s+=(t+'0');
            else
            {
                
                s+=(((a[i]-'0')+10)-(b[i]-'0'))+'0';
                if(a[i+1]=='0'){
                    int b=i+1;
                    while(a[b]=='0'){
                        b++;
                    }
                    a[b]=a[b]-1;
                    b--;
                    while(b>=i+1){
                        a[b]='0'+9;
                        b--;
                    }
                }
                else
                    a[i+1]=(a[i+1]-1);
            }
        }
    
        for(;i<a.size();i++)
        {
            s+=a[i];
        }
        reverse(s.begin(),s.end());
        trimZeroes(s);
        return s;
    }
    
    Node * insertrear(string a,int n)
    {
        Node * head,*t,*tp;
        for(int i=0;i<n;i++)
        {
            t=new Node(a[i]-'0');
            if(i==0)
            {
                tp=t;
                head=t;
            }
            else
            {
                tp->next=t;
                tp=tp->next;
            }
        }
        t=head;
        while(t->data==0)
            t=t->next;
        return t;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        string sa="",sb="";
        sa=convertTostring(head1);
        sb=convertTostring(head2);
        sa=trimZeroes(sa);
        sb=trimZeroes(sb);
        
        if(sa==sb)
            return new Node(0);
        findGreater(sa,sb);
        
        string s=sub(sa,sb);
        Node * head=insertrear(s,s.size());
        return head;
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends