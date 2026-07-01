class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        int rightOnes = 0;
        for (char ch : s) {
            if (ch == '1')
                rightOnes++;
        }

        int leftZeros = 0;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {

            if (s[i] == '0')
                leftZeros++;
            else
                rightOnes--;

            ans = max(ans, leftZeros + rightOnes);
        }

        return ans;
    }
};