// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums1.size() > nums2.size()){
//             return findMedianSortedArrays(nums2, nums1);
//         }

//         int len1 = nums1.size(), len2 = nums2.size();
//         int left = 0, right = len1;

//         while(left <= right){
//             int part1 = (left + right) / 2;
//             int part2 = (len1 + len2 + 1) / 2 - part1;

//             int maxLeft1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
//             int minRight1 = (part1 == len1) ? INT_MAX : nums1[part1];
//             int maxLeft2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
//             int minRight2 = (part2 == len2) ? INT_MAX : nums2[part2];

//             if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1){
//                 if((len1 + len2) % 2 == 0){
//                     return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
//                 }else{
//                     return max(maxLeft1, maxLeft2);
//                 }
//             } else if (maxLeft1 > minRight2){
//                 right = part1 - 1;
//             }else{
//                 left = part1 + 1;
//             }
//         }

//         return 0.0;
//     }
// };


class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // Ensure A is the smaller array
        if (A.size() > B.size()) swap(A, B);
        
        int m = A.size(), n = B.size();
        int left = 0, right = m;
        int total = m + n;
        
        while (left <= right) {
            int i = (left + right) / 2;           // partition in A
            int j = (total + 1) / 2 - i;          // partition in B
            
            int A_left = (i == 0) ? INT_MIN : A[i-1];
            int A_right = (i == m) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j-1];
            int B_right = (j == n) ? INT_MAX : B[j];
            
            // Correct partition found
            if (A_left <= B_right && B_left <= A_right) {
                if (total % 2 == 1) 
                    return max(A_left, B_left);           // odd length
                return (max(A_left, B_left) + min(A_right, B_right)) / 2.0; // even
            }
            // Move towards correct partition
            else if (A_left > B_right) 
                right = i - 1;      // too many elements from A, move left
            else 
                left = i + 1;       // too few from A, move right
        }
        return 0.0;
    }
};