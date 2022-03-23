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
public:
    
    vector<int> nodes;
    int cur = 0;
    
    BSTIterator(TreeNode* root) {
        inorder( root );     
    }
    
    void inorder( TreeNode * cur ) {
        if( cur == NULL )return;
        
        inorder( cur -> left );
        nodes.push_back( cur -> val );
        inorder( cur -> right );        
    }
    
    int next() {
        return nodes[cur++];
    }
    
    bool hasNext() {
        if( cur < nodes.size() ) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */