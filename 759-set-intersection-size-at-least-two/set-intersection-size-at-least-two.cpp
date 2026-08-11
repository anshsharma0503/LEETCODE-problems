class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),[](auto a, auto b) {
                 if (a[1] == b[1])
                     return a[0] > b[0];

                 return a[1] < b[1];
        });

        int a = -1;
        int b = -1;

        int ans = 0;

        for (auto interval : intervals) {

            int start = interval[0];
            int end = interval[1];

            if (a >= start) {
                continue;
            }

            if (b >= start) {

                ans++;
                a = b;
                b = end;
            }
            else {

                ans += 2;
                a = end - 1;
                b = end;
            }
        }

        return ans;
    }
};