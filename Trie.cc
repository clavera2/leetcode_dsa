#define BEGIN_OF_WORD '0'
#define END_OF_WORD '\0'

struct Node {
    char data;
    std::unordered_map<char,Node *> children;

    Node(char d) : data(d) {}

    void insert(char d) {
        children[d] = new Node(d);
    }

    bool contains(char d) {
        return children.count(d) != 0;
    }
};

class Trie {
 Node *head; //pointer to the node having BEGIN_OF_WORD
public:
    Trie() : head(new Node(BEGIN_OF_WORD)) {}

    void insert(std::string s) {
        if (s.size() == 0) return;
        Node *current = head;
        for (int i = 0; i < s.size(); i++) {
            if (!current->contains(s[i])) {
                current->insert(s[i]);
            }
            current = current->children[s[i]];
        }

        if (!current->contains(END_OF_WORD)) {
            //add end of word node
            current->insert(END_OF_WORD);
        }
    }

    bool search(std::string word) {
        Node *current = head;
        for (int i = 0; i < word.size(); i++) {
            if (!current->contains(word[i])) return false;
            current = current->children[word[i]];
        }
        if (!current->contains(END_OF_WORD)) return false;
        return true;
    }

    bool startsWith(std::string prefix) {
        //like search but does not account for END_OF_WORD
        Node *current = head;
        for (char c : prefix) {
            if (!current->contains(c)) return false;
            current = current->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */