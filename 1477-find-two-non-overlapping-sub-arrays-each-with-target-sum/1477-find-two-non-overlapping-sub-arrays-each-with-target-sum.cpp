class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        int currSum = 0;
        int left = 0;
        int minLength = INT_MAX;
        int ans = INT_MAX;

        for(int right = 0; right < n; right++){
            currSum += arr[right];
            while(left <= right && currSum > target){
                currSum -= arr[left];
                left++;
            }
            if(currSum == target){
                int currLength = right - left + 1;
                if(left > 0 && best[left - 1] != INT_MAX){
                    ans = min(ans, currLength + best[left - 1]);
                }
                minLength = min(minLength, currLength);
            }
            best[right] = minLength;
        }   
        return ans == INT_MAX ? -1 : ans;
    }
};
