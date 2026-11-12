class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n= nums.size();

        int res=0;

        for(int i=0;i<n;i++){
            int increase=1;
            int j= i+1;

            while(j<n && nums[j]>nums[j-1]){
                increase++;
                j++;
            }

             j=i+1;
            int decrease=1;
            while(j<n && nums[j]<nums[j-1]){
               decrease++;
               j++;
            }

            res=max({res,increase,decrease});
        }

        return res;
    }
};