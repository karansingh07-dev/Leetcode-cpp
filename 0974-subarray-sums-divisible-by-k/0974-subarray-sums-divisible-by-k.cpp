class Solution {
public:

   int res=0;
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();

        int sum=0; 
     
        unordered_map<int,int>f;
        f[0]=1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int remain=sum%k;
            if(remain<0){
                remain=remain+k;
               
            }
              res+=f[remain];
                 f[remain]++;
               
        }

            return res;
    }
};