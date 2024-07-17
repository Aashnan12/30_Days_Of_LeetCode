class MinStack {
public:
    stack<pair<long long,long long>> st;

    MinStack() 
    {

    }
    
    void push(long long int val) 
    {
        long long mini = LLONG_MAX;
        if(st.empty())
        {
            st.push({val,val});
        }
        else 
        {
            mini = st.top().second;
            mini = min(mini,val);
            st.push({val,mini});
        }
    }
    
    void pop()
    {
        if(!st.empty())
        {
            st.pop();
        }
    }
    
    int top() 
    {
        if(!st.empty())
        {
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() 
    {
        if(!st.empty())
        {
            return st.top().second;
        }
        return -1;
    }
};