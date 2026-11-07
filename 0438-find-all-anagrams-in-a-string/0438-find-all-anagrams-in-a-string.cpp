
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char,int> mp;
        unordered_map<char,int> window;

        int n = s.size();
        int k = p.size();

        vector<int> res;

        // Store frequency of pattern
        for(int i = 0; i < k; i++) {
            mp[p[i]]++;
        }

        int left = 0;

        for(int right = 0; right < n; right++) {

            // Add current character
            window[s[right]]++;

            // Maintain window size k
            if(right - left + 1 > k) {

                window[s[left]]--;

                if(window[s[left]] == 0) {
                    window.erase(s[left]);
                }

                left++;
            }

            // Compare frequencies
            if(right - left + 1 == k) {

                if(window == mp) {
                    res.push_back(left);
                }
            }
        }

        return res;
    }
};
