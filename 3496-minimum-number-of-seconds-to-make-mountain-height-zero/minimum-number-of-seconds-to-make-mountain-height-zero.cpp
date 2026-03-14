class Solution {
public:

    bool isValid(long long t , int mh , vector<int>& wt){
        long long total = 0;

        for(int w : wt){
            long long k = (-1 + sqrt(1 + 8.0 * t / w)) / 2;
            total += k;
            if(total >= mh) return true;
        }

        return total >= mh;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long lo = 0 , hi = 1e18;
        while(lo < hi){
            long long mid = lo + (hi - lo) / 2;

            if(isValid(mid , mountainHeight , workerTimes)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};