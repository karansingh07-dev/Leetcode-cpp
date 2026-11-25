class Solution {
public:

    typedef long long ll;
    int n;

    ll solve(int idx, vector<int>& nums, bool flag, vector<vector<ll>>& dp) {

        if(idx >= n)
            return 0;

        if(dp[idx][flag] != -1)
            return dp[idx][flag];

        // Skip current element
        ll skip = solve(idx + 1, nums, flag, dp);

        // Take current element
        ll val = nums[idx];

        if(flag == false) {
            val = -val;
        }

        ll take = val + solve(idx + 1, nums, !flag, dp);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        n = nums.size();

        vector<vector<ll>> dp(n, vector<ll>(2, -1));

        return solve(0, nums, true, dp);
    }
};