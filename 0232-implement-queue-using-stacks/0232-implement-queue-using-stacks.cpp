class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(st.size()==1){
            int ans=st.top();
            st.pop();
            return ans;
        }
        int ele=st.top();
        st.pop();
        int ans=pop();
        st.push(ele);
        return ans;
    }
    
    int peek() {
         if(st.size()==1){
            int ans=st.top();
            return ans;
        }
        int ele=st.top();
        st.pop();
        int ans=peek();
        st.push(ele);
        return ans;
    }
    
    bool empty() {
        return st.size()==0?true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */