class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count =0;
         int mid=nums[n/2];
        for(int i=0;i<n/2;i++){
           
           count+=abs(nums[i]-mid); 
           count+=abs(nums[n-i-1]-mid);
           
        }
        return count;
    }
};