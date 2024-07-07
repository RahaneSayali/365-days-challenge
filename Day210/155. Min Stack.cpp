class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        while(st.empty()==false) st.pop();
        mini=INT_MAX;

    }
    
    void push(int value) {
        long long val=value;
                if(st.empty()){ 
                mini=val;
                st.push(val);

         }
         else{
           if (val<mini){
            st.push(2*val*1LL - mini);
            mini=val;
           }
           else{
            st.push(val);
           }

         }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=2*mini-el;
        }
    }
    
    int top() {
                if(st.empty()) return -1;
                 long long el=st.top();
             if(el<mini)
                return mini;
             return el;


    }
    
    int getMin() {
        return mini;
    }
};