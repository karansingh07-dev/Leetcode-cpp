class Solution {
public:

    int n;

    int solve(vector<int>& nums, int i, int p,
              vector<vector<int>>& dp) {

        if(i >= n)
            return 0;

        if(p != -1 && dp[i][p] != -1)
            return dp[i][p];

        int take = 0;

        if(p == -1 || nums[p] < nums[i]) {
            take = 1 + solve(nums, i+1, i, dp);
        }

        int skip = solve(nums, i+1, p, dp);

        if(p != -1)
            return dp[i][p] = max(take, skip);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, 0, -1, dp);
    }
};