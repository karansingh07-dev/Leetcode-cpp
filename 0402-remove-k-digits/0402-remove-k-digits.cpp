class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n = num.size();

        for (int i = 0; i < n; i++) {

            while(!st.empty()&& k>0&& st.back()>num[i]){
                st.pop_back();
                k--;
            }
            // Hint: remove larger digits from the end
            // while k > 0 and st.back() > num[i]

            st.push_back(num[i]);
            // Push the current digit
        }
            
        // If k is still greater than 0, remove from the end
             while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
              
        
          int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }
        st = st.substr(i);
        // Remove leading zeros

        
       

       
       
        // If empty, return "0"

        if(st.empty()){
            return "0";
        }

        return st;
    }
};