// doubly linked list
class Node {
public:
    Node* prev;
    Node* next;
    string url;
    Node(string url){
        prev = nullptr;
        next = nullptr;
        this->url = url;
    }
};
class BrowserHistory1 {
public:
    Node* dummy = new Node("");
    Node* cur;
    BrowserHistory(string homepage) {
        Node* root = new Node(homepage);
        dummy->next = root;
        cur = root;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        while(cur->prev && steps){
            cur = cur->prev;
            --steps;
        }
        return cur->url;
    }
    
    string forward(int steps) {
        while(cur->next && steps){
            cur = cur->next;
            --steps;
        }
        return cur->url;
    }
};
// vector
class BrowserHistory2 {
public:
    vector<string> history;
    int idx;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        idx = 0;
    }
    
    void visit(string url) {
        if(history.size() > idx + 1){
            // current page is not the last page
            // delete all pages after it
            history.erase(history.begin() + idx + 1, history.end());
        }
        history.push_back(url);
        ++idx;
    }
    
    string back(int steps) {
        steps = steps <= idx ? steps : idx;
        idx -= steps;
        return history[idx];
    }
    
    string forward(int steps) {
        steps = (steps <= history.size() - idx - 1) ? steps : history.size() - idx - 1;
        idx += steps;
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */