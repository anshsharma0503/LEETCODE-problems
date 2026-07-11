class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> res(1e4 + 1 , -1);

        stack<int> st;
        st.push(nums2[m - 1]);
        for(int i = m - 2 ; i >= 0 ; i--){
            while(!st.empty() && st.top() < nums2[i])
                st.pop();

            if(st.empty()) 
                res[nums2[i]] = -1;
            else
                res[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        vector<int> ans(n);
        for(int i = 0; i < n ; i++)
            ans[i] = res[nums1[i]];
        
        return ans;
    }
};