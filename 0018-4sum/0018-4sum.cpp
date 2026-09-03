// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int>>ans;

//         for(int i = 0; i < n-3; i++){
//             if(i>0 && nums[i] == nums[i-1]) continue;
//             for(int j = i+1; j < n-2; j++){
//                 if(j > i+1 && nums[j] == nums[j-1]) continue;
//                 int left = j+1 , right = n - 1;
//                 while(left < right){
//                     long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
//                     if(sum == target){
//                         ans.push_back({nums[i],nums[j],nums[left],nums[right]});

//                         while(left < right && nums[left] == nums[left + 1])left++;
//                         while(left < right && nums[right] == nums[right - 1])right--;

//                         left++;
//                         right--;
//                     }
//                     else if(sum > target) right--;
//                     else left++;
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};  // Edge case
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n - 3; i++) {
            // Early pruning 1: Minimum sum with current i is too large
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            
            // Early pruning 2: Maximum sum with current i is too small
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i + 1; j < n - 2; j++) {
                // Early pruning 3: Minimum sum with current i,j is too large
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                
                // Early pruning 4: Maximum sum with current i,j is too small
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int left = j + 1, right = n - 1;
                
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for left pointer
                        int left_val = nums[left];
                        while (left < right && nums[left] == left_val) left++;
                        
                        // Skip duplicates for right pointer
                        int right_val = nums[right];
                        while (left < right && nums[right] == right_val) right--;
                    } 
                    else if (sum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};