class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,1);
        vector<int>suffix(n+1,1);
        vector<int>ans;
        for(int i = 1 ;i <= nums.size() ;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for(int j = n-1 ;j >= 0 ;j--){
            suffix[j] = suffix[j+1] * nums[j];
        }
        for(int i = 0 ; i < n ;i++){
            int curr = prefix[i] * suffix[i+1];
            ans.push_back(curr);
        }
        return ans;
    }
};
