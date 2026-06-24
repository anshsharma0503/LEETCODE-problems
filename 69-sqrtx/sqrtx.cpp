class Solution {
public:

    bool isValid(long long mid, int x){
        return mid * mid <= x;
    }

    int mySqrt(int x) {

        long long lo = 0;
        long long hi = x;

        while(lo < hi){

            long long mid = lo + (hi - lo + 1) / 2;

            if(isValid(mid, x))
                lo = mid;
            else
                hi = mid - 1;
        }

        return (int)lo;
    }
};