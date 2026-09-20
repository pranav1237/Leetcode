class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixCount;
        prefixCount[0] = 1;  // base case: empty prefix
        int sum = 0, count = 0;

        for (int x : nums) {
            sum += x;
            if (prefixCount.count(sum - goal)) {
                count += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};
