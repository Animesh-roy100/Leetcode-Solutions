class BrowserHistory {
public:
    stack<string> backURLs, forwardURLs;
    BrowserHistory(string homepage) {
        backURLs.push(homepage);
    }
    
    void visit(string url) {
        backURLs.push(url);
        while(!forwardURLs.empty()) {
            forwardURLs.pop();
        }
    }
    
    string back(int steps) {
        int backSize = backURLs.size();

        while(backSize-- > 1 and steps-- > 0) {
            string url = backURLs.top();
            backURLs.pop();
            forwardURLs.push(url);
        }
        return backURLs.top();
    }
    
    string forward(int steps) {
        while(steps-- and !forwardURLs.empty()) {
            string url = forwardURLs.top();
            forwardURLs.pop();
            backURLs.push(url);
        }

        return backURLs.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */