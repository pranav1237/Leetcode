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
