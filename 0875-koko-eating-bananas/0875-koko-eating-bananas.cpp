// class Solution {
// public:

//     int minEatingSpeed(vector<int>& piles, int h) {

//         long long left = 1;
//         long long right = 1000000000;

//         while (left <= right) {

//             long long mid = left + (right - left) / 2;

//             if (canEatInTime(piles, mid, h)) {
//                 right = mid - 1;
//             }
//             else {
//                 left = mid + 1;
//             }
//         }

//         return (int)left;
//     }

//     bool canEatInTime(vector<int>& piles, long long k, int h) {

//         long long hours = 0;

//         for (int pile : piles) {

//             hours += pile / k;

//             if (pile % k != 0) {
//                 hours++;
//             }
//         }

//         return hours <= h;
//     }
// };

class Solution {
public:
    
        long long calculateTotalHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for (int bananas : piles) {
            totalH += ((long long)bananas +speed -1) / speed;
        }
        return totalH;
    }

   
    int minEatingSpeed(vector<int>& piles, int h) {
     
        int maxPile = *max_element(piles.begin(), piles.end());

       
        int low = 1, high = maxPile;
        int ans = maxPile;

      
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calculateTotalHours(piles, mid);

           
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
        
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};