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

//optimized
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width= i - st.top() - 1;
                maxA =max(maxA, width*height);


            }
            st.push(i);

        }
        return maxA;
        
    }
};