
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int first = -1;
        int low = 0, high = n - 1;

        // Find first occurrence
        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (nums[guess] == target) {
                first = guess;
                high = guess - 1;
            } 
            else if (nums[guess] < target) {
                low = guess + 1;
            } 
            else {
                high = guess - 1;
            }
        }

        if (first == -1) {
            return {};
        }

        vector<int> ans;

        // Collect all target indices
        for (int i = first; i < n && nums[i]==target ; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};
