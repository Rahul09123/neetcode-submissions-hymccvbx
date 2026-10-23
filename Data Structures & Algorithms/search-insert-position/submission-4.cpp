class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = -1;
        // edge cases
        if(target <= nums[0]){
            return 0;
        }
        if(target > nums[n-1]){
            return n;
        }
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
                idx = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return idx;
    }
};