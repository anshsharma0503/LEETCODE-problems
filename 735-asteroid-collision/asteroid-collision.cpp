class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);

        for(int i = 1 ; i < asteroids.size() ; i++){
            
            int ast = asteroids[i];
            bool flag = true;
            while(!st.empty() && st.top() > 0 && ast <0){
                int ele = st.top();
                if(abs(ele) == abs(ast)) {
                    st.pop();
                    flag = false;
                    break;
                }
                    
                else if(abs(ele) > abs(ast)) {
                    flag = false;
                    break;
                }
                else st.pop();
            }
            if(flag)  st.push(ast);
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin() , res.end());

        return res;
    }
};