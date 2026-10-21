class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        // the number is 32 bit integer
        for(int b = 0 ;b < 32;b++){
            int x = 0, y = 0;
            int mask = 1 << b;
            for(int num : nums){ // count the numbers which has the bit set
                if(num & mask) x++;
            }

            for(int num = 1 ; num < n ;num++){
                if(mask & num){ // find the number b/w 1 and n-1 and has bit set
                    y++;
                }
            }
            if(x > y){
                res |= mask;
            }
        }
        return res;
    }
};
