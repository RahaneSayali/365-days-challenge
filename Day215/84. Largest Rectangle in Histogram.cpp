//TC- O(N) SC=O(3N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int leftsmall[n], rightsmall[n];
        //for left  small

        for(int i = 0 ; i < n ; i ++ ){
            while( !st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) leftsmall[i]=0;
            else leftsmall[i]=st.top()+1;
                st.push(i);
            
        }

        //clear stack and reuse
        while(!st.empty()){
            st.pop();
        }

        //for right small
        for(int i = n - 1 ; i >= 0 ; i--){
            while( !st.empty() && heights[st.top()] >= heights[i] ){
                st.pop();
            }
            if(st.empty()) rightsmall[i]=n-1;
            
            else rightsmall[i]=st.top()-1;
                st.push(i);
    
        }

        int maxArea=0;
        for(int i = 0 ; i < n ; i++ ){

            maxArea = max (maxArea, heights[i] * (rightsmall[i]-leftsmall[i]+1));

        }
        return maxArea;
    }

};