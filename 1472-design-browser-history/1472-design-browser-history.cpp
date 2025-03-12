struct Listnode {
    string s;
    Listnode* next;
    Listnode(string str) : s(str), next(nullptr) {}
};

class BrowserHistory {
private:
    unordered_map<int, Listnode*> mp;
    Listnode* curr;
    int size;
    int curr_size;

public:
    BrowserHistory(string homepage) {
        curr = new Listnode(homepage);
        mp[0] = curr;
        size = 0;
        curr_size = 0;
    }
    
    void visit(string url) {
        // Clear forward history by cutting off the list after current node
        Listnode* new_node = new Listnode(url);
        curr->next = new_node;
        curr = new_node;
        curr_size++;
        // Update the size to the current index, discarding forward history
        size = curr_size;
        mp[size] = curr;
    }
    
    string back(int steps) {
        int target = curr_size - steps;
        if (target < 0) {
            target = 0;
        }
        curr_size = target;
        curr = mp[curr_size];
        return curr->s;
    }
    
    string forward(int steps) {
        int target = curr_size + steps;
        if (target > size) {
            target = size;
        }
        curr_size = target;
        curr = mp[curr_size];
        return curr->s;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */