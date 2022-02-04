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
    
    void traversal ( map< int, map< int, multiset<int> > > &m, int x, int y, TreeNode * root ) {
        if( root == NULL ) return;
        
        m[x][y].insert( root -> val );
        traversal( m, x - 1 , y + 1, root -> left );
        traversal( m, x + 1 , y + 1, root -> right );
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map< int, map< int, multiset<int> > > m;
        
        traversal( m, 0, 0, root );
        
        vector< vector<int> > ans;
        
        cout << m.size() << endl;
        
        for( auto a : m ) 
        {
            vector<int> col;
            for( auto b : a.second ) 
            {
                for( auto c : b.second ) {
                    cout << c << " ";
                    col.push_back( c );
                }
            }
            ans.push_back( col );
        }
        return ans;
    }
};







