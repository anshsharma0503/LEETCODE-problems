class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , [](vector<int> a , vector<int> b){
            return a[1] < b[1];
        });

        int arrow =points[0][1];
        int ans=1;

        for(int i = 0;  i< points.size() ; i++){
            if(arrow >= points[i][0] && arrow <= points[i][1]) continue;

            arrow = points[i][1];
            ans++;
            

        }

        return ans;
    }
};