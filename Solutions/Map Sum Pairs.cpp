class Node {
public:
    Node(int value) : sum(value), end(false) {}
    Node* GetNext(char c) {
        if (nxt.count(c)) {
            return nxt[c];
        }
        return nullptr;
    }
    void SetNext(char c, Node* nxt_) {
        nxt[c] = nxt_;
    }
    int GetSum() {
        return sum;
    }
    void SumValue(int value) {
        sum += value;
    }
    void SetEnd(bool flag) {
        end = flag;
    }
    bool GetEnd() {
        return end;
    }
private:
    int sum;
    unordered_map<char, Node*> nxt;
    bool end;
};

class Trie {
public:
    Trie() {
        root = new Node(0);
    }
    void AddString(const string& word, int value) {
        Node* cur = root;
        for (const char& c : word) {
            if (!cur->GetNext(c)) {
                cur->SetNext(c, new Node(0));
            }
            cur = cur->GetNext(c);
            cur->SumValue(value);
        }
        cur->SetEnd(true);
    }
    int GetSumPrefix(const string& prefix) {
        Node* cur = root;
        for (const char& c : prefix) {
            if (!cur->GetNext(c)) {
                return 0;
            }
            cur = cur->GetNext(c);
        }
        return cur->GetSum();
    }
    bool Exists(const string& word, int& result) {
        Node* cur = root;
        for (const char& c : word) {
            if (!cur->GetNext(c)) {
                return false;
            }
            cur = cur->GetNext(c);
        }
        result = cur->GetSum();
        return cur->GetEnd();
    }
private:
    Node* root;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    Trie* trie;
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        int result = 0;
        if (trie->Exists(key, result)) {
            trie->AddString(key, -result);
        }
        trie->AddString(key, val);
    }
    
    int sum(string prefix) {
        return trie->GetSumPrefix(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
