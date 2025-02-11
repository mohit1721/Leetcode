class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>ans(n, -1);//
        stack<int>st;
        for(int i= n-1;i>=0;i--){
            
            //invalid case
            while(!st.empty() && arr[st.top()] >= arr[i] ){
                st.pop();
            }

            if(!st.empty())
                ans[i]=st.top();
            
            st.push(i);
        }
         return ans;
    }
    vector<int>prevSmallerElement(vector<int>&arr)
    {
        int n= arr.size();
        vector<int>ans(n, -1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
        
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(!st.empty())
                ans[i]=st.top();
            
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n) ;
        next = nextSmallerElement(heights);
        //make sure ** VVVI ** koi -1 store n kre next wale m
       
        vector<int>prev(n);
        prev = prevSmallerElement(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
           //iteration save
            if(next[i]==-1)
            next[i]=n;

          int length=heights[i];
          int width=next[i]-prev[i]-1;
          int currArea= length * width;
            maxArea=max(maxArea,currArea);
        }
    return maxArea;

    }
};