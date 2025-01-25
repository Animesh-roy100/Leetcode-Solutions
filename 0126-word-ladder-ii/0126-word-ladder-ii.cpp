class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return {}; // endWord not in wordList

        unordered_map<string, vector<string>> parent; // to reconstruct paths
        unordered_set<string> currentLevel, nextLevel;
        queue<string> q;
        q.push(beginWord);
        currentLevel.insert(beginWord);
        bool found = false;

        // BFS
        while (!q.empty() && !found) {
            int size = q.size();
            nextLevel.clear();
            while (size--) {
                string word = q.front();
                q.pop();
                string original = word;

                for (int i = 0; i < word.size(); ++i) {
                    char originalChar = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        if (word == endWord) found = true;
                        if (st.find(word) != st.end() && currentLevel.find(word) == currentLevel.end()) {
                            if (nextLevel.find(word) == nextLevel.end()) {
                                q.push(word);
                                nextLevel.insert(word);
                            }
                            parent[word].push_back(original); // track predecessors
                        }
                    }
                    word[i] = originalChar; // restore
                }
            }
            for (const string& word : nextLevel) st.erase(word); // remove processed words
            currentLevel = nextLevel;
        }

        if (!found) return {}; // no paths to endWord

        // Reconstruct paths
        vector<vector<string>> ans;
        vector<string> path = {endWord};
        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                reverse(path.begin(), path.end());
                ans.push_back(path);
                reverse(path.begin(), path.end());
                return;
            }
            for (const string& p : parent[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };
        dfs(endWord);
        return ans;
    }
};
