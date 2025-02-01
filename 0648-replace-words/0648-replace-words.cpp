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

    void insert(string str){
        TrieNode* temp = root;
        for(char c: str) {
            int idx = c-'a';
            if(temp->children[idx] == nullptr) temp->children[idx] = new TrieNode();
            temp = temp->children[idx];
        }
        temp->isComplete = true;
    }

    bool searchWord(string word) {
        TrieNode* temp = root;
        for(char c: word){
            int idx = c-'a';
            if(temp->children[idx] == nullptr) return false;
            temp = temp->children[idx];
        }
        return temp->isComplete;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(string str: dictionary) t.insert(str);

        vector<string> words;
        int n=sentence.length();
        string word="";
        for(int r=0; r<n; r++) {
            if(sentence[r]==' ') {
                cout<<word<<endl;
                words.push_back(word);
                word="";
            } else {
                word+=sentence[r];
            }
        }
        words.push_back(word);

        for(int i=0; i<words.size(); i++) {
            string str="";
            for(int j=0; j<words[i].length(); j++) {
                str += words[i][j];
                if(t.searchWord(str)) {
                    cout<<str<<" ";
                    words[i] = str;
                    break;
                }
            }
        }

        string ans="";
        for(string word: words){
            ans += word;
            ans += " ";
        }
        ans.pop_back();

        return ans;
    }
};