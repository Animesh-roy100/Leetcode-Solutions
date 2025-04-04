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

        return getLastChars();
    }
    
    string cursorRight(int k) {
        while(k-- and !right.empty()) {
            int c = right.top();
            right.pop();
            left.push(c);
        }

        return getLastChars();
    }

    string getLastChars() {
        stack<char> temp;
        string lastChars;
        int len=0;

        while(len<10 and !left.empty()) {
            temp.push(left.top());
            left.pop();
            len++;
        }

        while(!temp.empty()) {
            lastChars.push_back(temp.top());
            left.push(temp.top());
            temp.pop();
        }

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