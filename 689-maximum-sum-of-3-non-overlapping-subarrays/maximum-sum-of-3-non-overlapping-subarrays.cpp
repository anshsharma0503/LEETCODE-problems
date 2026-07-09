class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> windowSum(n - k + 1);

        int sum = 0;

        for (int i = 0; i < k; i++)
            sum += nums[i];

        windowSum[0] = sum;

        for (int i = k; i < n; i++) {
            sum += nums[i];
            sum -= nums[i - k];
            windowSum[i - k + 1] = sum;
        }

        int m = windowSum.size();

        vector<int> left(m);

        int best = 0;

        for (int i = 0; i < m; i++) {

            if (windowSum[i] > windowSum[best])
                best = i;

            left[i] = best;
        }

        vector<int> right(m);

        best = m - 1;

        for (int i = m - 1; i >= 0; i--) {

            if (windowSum[i] >= windowSum[best])
                best = i;

            right[i] = best;
        }
        
        vector<int> ans(3);

        int maxSum = 0;

        for (int mid = k; mid < m - k; mid++) {

            int l = left[mid - k];
            int r = right[mid + k];

            int total = windowSum[l] +
                        windowSum[mid] +
                        windowSum[r];

            if (total > maxSum) {

                maxSum = total;

                ans = {l, mid, r};
            }
        }

        return ans;
    }
};