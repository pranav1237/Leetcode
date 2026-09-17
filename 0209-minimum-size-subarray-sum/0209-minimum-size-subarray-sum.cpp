// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int minLen = numeric_limits<int>::max();
//         int left = 0;
//         int currSum = 0;

//         for(int right = 0; right < nums.size(); right++){
//             currSum += nums[right];

//             while(currSum >= target){
//                 if (right - left + 1 < minLen){
//                     minLen = right - left + 1;
//                 }

//                 currSum -= nums[left];
//                 left++;
//             }
//         }

//         return minLen != numeric_limits<int>::max() ? minLen : 0;
//     }
// };



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};