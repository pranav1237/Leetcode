class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int n = a.size(), m = b.size();
        int lo = 0, hi = n;

        while (lo <= hi) {
            int cutA = (lo + hi) / 2;
            int cutB = (n + m + 1) / 2 - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];

            int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                int leftMax = max(leftA, leftB);

                if ((n + m) % 2)
                    return leftMax;

                int rightMin = min(rightA, rightB);
                return (leftMax + rightMin) / 2.0;
            }

            if (leftA > rightB)
                hi = cutA - 1;
            else
                lo = cutA + 1;
        }

        return 0.0;
    }
};