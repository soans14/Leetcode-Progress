class MinStack {
public:
    stack<pair<int,int>> st;
    int currMin=INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(value<currMin){
            st.push({value,value});
            currMin=value;
        }
        else{
            st.push({value,currMin});
        }
    }
    
    void pop() {
        st.pop();
        if(!st.empty()){
            currMin=st.top().second;
        }
        else{
            currMin=INT_MAX;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */