class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.size()==0)
        {
            while(s1.size()!=0)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.size()!=0)
        {   
            int x=s2.top();
            s2.pop();
            return x;
        }
        return -1;
    }
    
    int peek() {
        if(s2.size()==0)
        {
            while(s1.size()!=0)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(s2.size()!=0)
        {   
            int x=s2.top();
            return x;
        }
        return -1;
    }
    
    bool empty() {
        return s1.size()==0 && s2.size()==0;
    }
};