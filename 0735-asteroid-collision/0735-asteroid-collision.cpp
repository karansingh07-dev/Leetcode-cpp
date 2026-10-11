
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            int asteroid = asteroids[i];

            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                int sum = asteroid + st.top();

                if (sum < 0) {
                    st.pop();
                }
                else if (sum == 0) {
                    st.pop();
                    asteroid = 0;
                    break;
                }
                else {
                    asteroid = 0;
                    break;
                }
            }

            if (asteroid != 0) {
                st.push(asteroid);
            }
        }

        vector<int> ans(st.size());

        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
