class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> need;
unordered_map<char, int> have;

for (char c : ransomNote) {
    need[c]++;
}

for (char c : magazine) {
    have[c]++;
}

for (auto i : need) {
    char c = i.first;
    int freqNeed = i.second;
    int freqHave = have[c];

    if (freqHave < freqNeed) {
        return false;
    }
}

return true;
    }
};