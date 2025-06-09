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
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
          vector<vector<string>> grid;
    height(grid,root);
    int r = 0, c = grid[0].size()-1;
    dfs(grid,root,0,r,c);
    return grid;    
    }
private:
    inline void height(vector<vector<string>>& grid, TreeNode *n) {
    queue<TreeNode *> q;
    q.push(n);
    int level = 0;
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            TreeNode *curr = q.front(); q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        level++;
    }
    cout << "row: " << level << "\n";
    cout << "column: " << (int) pow(2, level + 1) -1 << "\n";
    grid = vector<vector<string>>(level, vector<string>((int) pow(2, level) -1));
}

void dfs(vector<vector<string>>& grid, TreeNode *n, int row, int left, int right) {
    if (!n || left > right || row >= grid.size()) return;
    int mid = (right + left) / 2;
    grid[row][mid] = to_string(n->val);
    dfs(grid,n->left,row+1,left,mid-1);
    dfs(grid,n->right,row+1,mid+1,right);
}
};