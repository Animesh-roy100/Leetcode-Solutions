class TextEditor {
private:
    stack<char> left, right;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c: text) left.push(c);
    }
    
    int deleteText(int k) {
        int count=0;
        while(!left.empty() and k--) {
            left.pop();
            count++;
        }
        return count;
    }
    
    string cursorLeft(int k) {
        while(k-- and !left.empty()) {
            int c = left.top();
            left.pop();
            right.push(c);
        }

        string lastChars="";
        int len=0;
        while(len < 10 and !left.empty()) {
            lastChars += left.top();
            left.pop();
            len++;
        }

        reverse(lastChars.begin(), lastChars.end());
        for(char c : lastChars) left.push(c);

        cout<<"cursorLeft: "<<lastChars<<endl;
        return lastChars;
    }
    
    string cursorRight(int k) {
        while(k-- and !right.empty()) {
            int c = right.top();
            right.pop();
            left.push(c);
        }

        string lastChars="";
        int len=0;
        while(len < 10 and !left.empty()) {
            lastChars += left.top();
            left.pop();
            len++;
        }

        reverse(lastChars.begin(), lastChars.end());
        for(char c : lastChars) left.push(c);
        cout<<"cursorRight: "<<lastChars<<endl;
        return lastChars;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */