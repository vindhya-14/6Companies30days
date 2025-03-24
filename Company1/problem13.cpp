class Solution{
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> child;
        vector<string> list;
    };
    
    TrieNode* root;
    TrieNode* p;
    
    void insert(string s){
        TrieNode* p = root;
        for (char c : s) {
            if (p->child[c] == NULL) p->child[c] = new TrieNode();
            p = p->child[c];
            p->list.push_back(s);
        }
    }   
    
    vector<string> query(char c){
        if (p == NULL || p->child[c] == NULL) {
            p = NULL;
            return {"0"};
        }
        
        p = p->child[c];
        return p->list;
    }
    
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        root = new TrieNode();
        p = root;
        
        for (int i = 0; i < n; ++i){
            insert(contact[i]);
        }
        
        
        vector<vector<string>> ans;
        for (int i = 0; i < s.length(); ++i){
            vector<string> list = query(s[i]);
            sort(list.begin(), list.end());
            list.erase(unique(list.begin(), list.end()), list.end());
            ans.push_back(list);
        }
        
        return ans;
    }
};