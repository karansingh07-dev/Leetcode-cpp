class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        int m=words2.size();

        unordered_map<string,int>mp;

        for(int i=0;i<words1.size();i++){
            mp[words1[i]]++;
        }

        unordered_map<string,int>f;

        for(int i=0;i<words2.size();i++){
            f[words2[i]]++; 


        }
        int count=0;
        for(auto it : mp){
              if(it.second==1 && f[it.first]==1){
                count++;
              }
        }

        return count;
    }
};