class Solution {
public:

       int ans=0;
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
         int n=nums.size();
      
        unordered_map<int,int>f;
            f[0]=1;
        

        for(int i=0;i<n;i++){
              sum+=nums[i];
              int ques=(sum-k);
              int freq=f[ques];
                ans+=freq;
                f[sum]++;
        }

        return ans;
    }
};