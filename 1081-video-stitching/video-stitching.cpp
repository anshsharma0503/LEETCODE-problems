class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {

        sort(clips.begin(), clips.end(), [](auto a, auto b) {
                return a[0] < b[0];
        });

        int currentEnd = 0;
        int farthest = 0;
        int ans = 0;
        int i = 0;

        while (currentEnd < time) {
            while (i < clips.size() &&
                   clips[i][0] <= currentEnd) {

                farthest = max(farthest, clips[i][1]);
                i++;
            }
            if (farthest == currentEnd)
                return -1;

            ans++;
            currentEnd = farthest;
        }

        return ans;
    }
};