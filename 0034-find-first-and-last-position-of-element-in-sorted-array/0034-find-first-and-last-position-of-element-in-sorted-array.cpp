// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> res = {-1, -1};
//         int left = BinaryS(nums, target, true);
//         int right = BinaryS(nums, target, false);
//         res[0] = left;
//         res[1] = right;
//         return res;
//     }

//     int BinaryS(vector<int>& nums, int target, bool isSearch){
//         int left = 0;
//         int right = nums.size() - 1;
//         int idx = -1;

//         while(left <= right){
//             int mid = left + (right - left)/2;

//             if(nums[mid] > target){
//                 right = mid - 1;
//             } else if(nums[mid] < target){
//                 left = mid + 1;

//             } else { 
//                 idx = mid;
//                 if(isSearch){
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             }
//         }

//         return idx;
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(vector<int>& nums, int target, bool searchLeft) {
        int left = 0, right = nums.size() - 1, idx = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                idx = mid;
                if (searchLeft) right = mid - 1;
                else left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return idx;
    }
};
