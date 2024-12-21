class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string word: wordList) st.insert(word);
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            string word = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if(word == endWord) return count;
            
            for(int i=0; i<word.size(); i++) {
                string original = word;
                for(int j=0; j<26; j++) {
                    word[i] = j+'a';
                    if(st.find(word) != st.end()) {
                        q.push({word, count+1});
                        st.erase(word);
                    }
                }
                word = original;
            }
        }
        
        return 0;
    }
};