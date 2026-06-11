class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;

        int l = 0, r = n - 1;
        while(l < r){
            int len = min(height[l] , height[r]);
            int breadth = r - l;
            int area = len * breadth;

            res = max(res , area);

            if(height[l] > height[r]) r--;
            else l++;

        }

        return res;
    }
};