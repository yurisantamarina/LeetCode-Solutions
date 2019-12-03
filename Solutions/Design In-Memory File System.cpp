class TrieNode {
public:
    TrieNode() {
        
    }
    TrieNode(char letter_) {
        letter = letter_;
        content = "";
        is_file = false;
    }
    bool HasChild(char letter) {
        return children.count(letter) > 0;
    }
    TrieNode* GetChild(char letter) {
        return children[letter];
    }
    void CreateChild(char letter) {
        TrieNode* child = new TrieNode(letter);
        children[letter] = child;
    }
    const map<char, TrieNode*>* GetChildren() {
        return &children;
    }
    void AppendToFile(string& content_) {
        content.append(content_);
    }
    string GetContent() {
        return content;
    }
    char Char() {
        return letter;
    }
    bool IsFile() {
        return is_file;
    }
    void SetIsFile(bool flag) {
        is_file = flag;
    }
private:
    map<char, TrieNode*> children;
    char letter;
    string content;
    bool is_file;
};

class Trie{
public:
    Trie() {
        root = new TrieNode('/');
    }
    TrieNode* FindOrCreate(string& path) {
        if (path.back() != '/') {
            path += '/';
        }
        TrieNode* cur_node = root;
        for (char letter : path) {
            if (!cur_node->HasChild(letter)) {
                cur_node->CreateChild(letter);
            }
            cur_node = cur_node->GetChild(letter);
        }
        return cur_node;
    }
private:
    TrieNode* root;
};

class FileSystem {
public:
    FileSystem() {
        file_system = new Trie();
        string path("/");
        file_system->FindOrCreate(path);
    }
    
    string GetFileName(string& path) {
        string file_name = "";
        for (int i = path.size() - 2; path[i] != '/'; i--) {
            file_name.append(string(1, path[i]));
        }
        reverse(file_name.begin(), file_name.end());
        return file_name;
    }
    
    vector<string> ls(string path) {
        TrieNode* end_path = file_system->FindOrCreate(path);
        if (end_path->IsFile()) {
            return {GetFileName(path)};
        }
        vector<string> ls_result;
        string cur_path;
        FindSubDirectories(end_path, &cur_path, &ls_result);
        return ls_result;
    }
    
    void mkdir(string path) {
        file_system->FindOrCreate(path);
    }
    
    void addContentToFile(string filePath, string content) {
        TrieNode* end_path = file_system->FindOrCreate(filePath);
        end_path->SetIsFile(true);
        end_path->AppendToFile(content);
    }
    
    string readContentFromFile(string filePath) {
        TrieNode* end_path = file_system->FindOrCreate(filePath);
        return end_path->GetContent();
    }
private:
    Trie* file_system;
    void FindSubDirectories(TrieNode* cur_node, string* cur_path, vector<string>* ls_result) {
        if (cur_node->Char() == '/' && !cur_path->empty()) {
            ls_result->push_back(cur_path->substr(0, cur_path->size() - 1));
            return;
        }
        const map<char, TrieNode*>* const children = cur_node->GetChildren();
        for (const auto i : *children) {
            char letter = i.first;
            TrieNode* child = i.second;
            cur_path->append(string(1, letter));
            FindSubDirectories(child, cur_path, ls_result);
            cur_path->pop_back();
        }
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
