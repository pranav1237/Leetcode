class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {

        long long left = 1;
        long long right = 1000000000;

        while (left <= right) {

            long long mid = left + (right - left) / 2;

            if (canEatInTime(piles, mid, h)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return (int)left;
    }

    bool canEatInTime(vector<int>& piles, long long k, int h) {

        long long hours = 0;

        for (int pile : piles) {

            hours += pile / k;

            if (pile % k != 0) {
                hours++;
            }
        }

        return hours <= h;
    }
};