
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
         int ans = 0;
        for (int i = 0; i < n; i++) {
            if (operations[i] == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.push(a);
            

                st.push(a + b);
            }
            else if (operations[i] == "D") {
                int score = 2 * st.top();
                st.push(score);
            }
            else if (operations[i] == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
            }
        }

      

        while (!st.empty()) {
            ans += st.top();
            st.pop();
            
        }

        return ans;
    }
};
