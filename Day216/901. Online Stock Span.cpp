class StockSpanner {
public:
    stack<pair<int,int>>st;  //pair of price and span

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;  //current span is 1
        while(!st.empty() && st.top().first<=price){
            span=span+st.top().second;
            st.pop();

        }
        st.push({price,span});
        return span;
    }
};