class TrieNode {
public:
    bool isComplete;
    TrieNode* children[26];

    TrieNode() {
        isComplete = false;
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &str){
        TrieNode* temp = root;
        for(char c: str) {
            int idx = c-'a';
            if(temp->children[idx] == nullptr) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->isComplete = true;
    }

    bool searchWord(string &word) {
        TrieNode* temp = root;
        for(char c: word){
            int idx = c-'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        return temp->isComplete;
    }

    string findPrefix(string &word) {
        TrieNode* temp = root;
        string prefix="";
        for(char c: word) {
            int idx = c-'a';
            if(temp->children[idx] == nullptr) return word;
            temp = temp->children[idx];

            prefix += c;
            if(temp->isComplete) return prefix;
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(string word: dictionary) t.insert(word);

        string ans, word;
        for(char c: sentence){
            if(c == ' ') {
                ans += t.findPrefix(word);
                ans += ' ';
                word = "";
            } else word+=c;
        }
        ans += t.findPrefix(word);

        return ans;

        // vector<string> words;
        // int n=sentence.length();
        // string word="";
        // for(int r=0; r<n; r++) {
        //     if(sentence[r]==' ') {
        //         cout<<word<<endl;
        //         words.push_back(word);
        //         word="";
        //     } else {
        //         word+=sentence[r];
        //     }
        // }
        // words.push_back(word);

        // for(int i=0; i<words.size(); i++) {
        //     string str="";
        //     for(int j=0; j<words[i].length(); j++) {
        //         str += words[i][j];
        //         if(t.searchWord(str)) {
        //             cout<<str<<" ";
        //             words[i] = str;
        //             break;
        //         }
        //     }
        // }

        // string ans="";
        // for(string word: words){
        //     ans += word;
        //     ans += " ";
        // }
        // ans.pop_back();

        // return ans;
    }
};