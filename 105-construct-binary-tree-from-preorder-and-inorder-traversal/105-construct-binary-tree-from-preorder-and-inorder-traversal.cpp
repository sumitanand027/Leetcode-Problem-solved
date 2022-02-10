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
    
    TreeNode * buildTree( vector<int> &p, int preS , int preE  , int inS , int inE , map<int,int> &mp  ) {
        if( preS > preE || inS > inE ) return NULL;
        
        TreeNode * root = new TreeNode( p[preS] );
        int ele = mp[ root -> val ];
        int nEle = ele - inS;
        
        root -> left = buildTree( p , preS + 1 , preS + nEle  , inS , ele - 1 , mp  );
        root -> right = buildTree( p , preS + nEle + 1 , preE  , ele + 1 , inE , mp );
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preS = 0, preE = preorder.size() - 1, inS = 0, inE = inorder.size() - 1;
        map< int, int > mp;
        for( int i = 0; i <= inE; i++ )
        {
            mp[ inorder[i] ] = i;
        }
        
        return buildTree( preorder, preS, preE, inS, inE, mp );
    }
    
};



