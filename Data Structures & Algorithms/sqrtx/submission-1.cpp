class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        while(low <= high){
            int mid = (low+high)/2;
            long long res = 1LL * mid * mid;
            if(res == x){
                return mid;
            }
            else if(res > x){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return high;
    }
};