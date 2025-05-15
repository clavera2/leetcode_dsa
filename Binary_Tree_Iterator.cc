/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *current; //initialized to current during construction.
    std::vector<int> _list;
    int current_index; //initialized to 0
public:
    BSTIterator(TreeNode *root) {
        this->current = root;
        populateList(this->current,this->_list);
        this->current_index = 0;
    }

    bool hasNext() {
        return current_index < _list.size();
    }

    int next() {
        int a = _list[current_index];
        current_index++;
        return a;
    }
private:
    void populateList(TreeNode* n, std::vector<int>& v) {
        //perform an inorder traversal
        if (!n) return;
        populateList(n->left, v);
        v.push_back(n->val);
        populateList(n->right,v);
    }

    /*
    template <typename T>
    bool operator !(T* t) {
        return t == nullptr;
    }

    */
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */