class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;

        int l = 0;
        int r = l + k - 1;
        int sum = 0;

        for(int i = l; i <= r; i++){
            sum += arr[i];
        }

        while(r < n){
            if(sum >= k * threshold){
                count++;
            }

            sum -= arr[l];
            l++;
            r++;

            if(r < n){
                sum += arr[r];
            }
        }

        return count;
    }
};