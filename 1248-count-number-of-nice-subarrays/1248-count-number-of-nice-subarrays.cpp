class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k){
        if(k<0) return 0;
        int left = 0, odds = 0, count = 0;
        for(int right = 0; right < (int)nums.size(); ++right){
            odds += nums[right] & 1;
            while(odds > k) { odds -= nums[left] & 1; left++; }
            count += right - left +1;
        }
        return count;
    }
};