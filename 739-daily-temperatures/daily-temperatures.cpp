class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> st;
        st.push(n-1);

        res[n- 1] = 0;
        for(int i = n - 2 ; i >= 0 ; i--){
            int ele = temperatures[i];

            while(!st.empty() && temperatures[st.top()] <= ele) {
                st.pop();
            }
            if(st.empty()) res[i] = 0;
            else res[i] = st.top() - i;

            st.push(i);
        }

        return res;
    }
};