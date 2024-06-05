class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> common_chars(26, INT_MAX);
        
        for (auto &word: words) {
            vector<int> word_count(26, 0);
            for (char c : word) {
                word_count[c-'a']++;
            }
            
            for(int i=0; i<26; i++) {
                common_chars[i] = min(common_chars[i], word_count[i]);
            }
        }
        
        for (int i=0; i<26; i++) {
            while(common_chars[i]--) {
                char c = i + 'a';
                string s = string(1, c);
                cout << s;
                ans.push_back(s);
            }
        }
        return ans;
    }
};