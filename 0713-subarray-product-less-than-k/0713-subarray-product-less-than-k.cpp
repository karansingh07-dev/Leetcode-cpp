class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
if(k<=1){
    return 0;
}

        int n= nums.size();
        int i=0;
        int j=0;
      //  int count=0;
        int product=1;
        int res=0;
        while(j<n){
            product=product*nums[j];

            while(product>=k){
                product/=nums[i];
                i++;
            }

            res+=(j-i+1);
            j++;
        }

        return res;
        
    }
};