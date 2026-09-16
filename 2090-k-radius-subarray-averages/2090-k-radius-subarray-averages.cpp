class Solution {
public:
    using ll = long long;
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (k == 0) return nums; // no averaging needed
        if (2 * k + 1 > n) return ans; // window too large

        ll windowSum = 0;
        int windowSize = 2 * k + 1;

        // initial window
        for (int i = 0; i < windowSize; i++) {
            windowSum += nums[i];
        }
        ans[k] = windowSum / windowSize;

        // slide the window
        for (int i = windowSize; i < n; i++) {
            windowSum += nums[i] - nums[i - windowSize];
            ans[i - k] = windowSum / windowSize;
        }

        return ans;
    }
};
