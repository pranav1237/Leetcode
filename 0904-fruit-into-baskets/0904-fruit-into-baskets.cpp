// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int start = 0, maxLen = 0;
//         unordered_map<int, int> basket;
//         for(int end = 0; end < fruits.size(); ++end){
//             basket[fruits[end]]++;


//             while(basket.size() > 2){
//                 basket[fruits[start]]--;
//                 if(basket[fruits[start]] == 0){
//                     basket.erase(fruits[start]);
//                 }
//                 start++;
//             }
//             maxLen = max(maxLen, end - start + 1);
//         }

//         return maxLen;
//     }
// };


class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                if (--basket[fruits[left]] == 0) basket.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};



// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         if (fruits.size() < 2) return fruits.size();
//         int l = 0, r = 0;
//         while (r < fruits.size() && fruits[r] == fruits[l]) r++;
//         if (r == fruits.size()) return fruits.size();
//         int basket1 = fruits[l], basket2 = fruits[r], maxSize = (r - l) + 1;
//         for (r++; r < fruits.size(); r++) {
//             if (fruits[r] == basket1 || fruits[r] == basket2) {
//                 maxSize = max(maxSize, (r - l) + 1);
//             }
//             else {
//                 for (int i = r - 1; i >= l; i--) {
//                     if (fruits[i] != fruits[r - 1]) {
//                         l = i + 1;
//                         basket1 = fruits[l];
//                         basket2 = fruits[r];
//                         break;
//                     }
//                 }
//             }
//         }
//         return maxSize;
//     }
// };