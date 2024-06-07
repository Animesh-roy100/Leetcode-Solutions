class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> dict;
        for(string str: dictionary) {
            dict[str]++;
        }
        vector<string> words;
        string s = "";
        for(int i=0; i<sentence.length(); i++) {
            if(sentence[i] == ' ') {
                words.push_back(s);
                s = "";
            } else {
                s += sentence[i];
            }
        }
        words.push_back(s);
        s = "";
        
        for(int i=0; i<words.size(); i++)  {
            for (int j=0; j<words[i].length(); j++) {
                string str = words[i].substr(0, j);
                if(dict.find(str) != dict.end()) {
                    words[i] = str;
                }
            }
        }
        
        string ans = "";
        ans += words[0];
        for (int i=1; i<words.size(); i++) {
            ans += " ";
            ans += words[i];
        }
        
        return ans;
    }
};