
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {

        int n = nums.size();

        long long total = 0;

        for(int i = 0; i < n; i++) {
            total += nums[i];
        }

        long long ans = (target / total) * n;

        target = target % total;

        if(target == 0) {
            return ans;
        }

        long long sum = 0;
        int left = 0;
        int mini = INT_MAX;

        for(int right = 0; right < 2 * n; right++) {

            sum += nums[right % n];

            while(sum > target) {
                sum -= nums[left % n];
                left++;
            }

            if(sum == target) {
                mini = min(mini, right - left + 1);
            }
        }

        if(mini == INT_MAX) {
            return -1;
        }

        return ans + mini;
    }
};
