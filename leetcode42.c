class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>nge(n);
        vector<int>pge(n);
        stack<int>st;
        for(int i=n-2; i>=0; i--) st.push(nums[i]);
        
        // finding nge;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(nums[i]);
        }

        return nge;
    }
};