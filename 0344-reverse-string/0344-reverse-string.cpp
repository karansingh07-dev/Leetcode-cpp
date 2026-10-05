class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            st.push(s[i]);
        }

        for (int i = 0; i < n; i++) {
            char c = st.top();
            st.pop();
            s[i] = c;
        }
    }
};