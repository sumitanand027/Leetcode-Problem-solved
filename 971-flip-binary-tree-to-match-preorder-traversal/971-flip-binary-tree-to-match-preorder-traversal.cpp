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
    
    bool helper( TreeNode * cur , int &i , vector<int> &v , vector<int> &ans )
    {
        if( cur == NULL )  
            return true;
        
        if( cur -> val != v[i++] ) return false;
        
        if( cur -> left && cur -> left -> val != v[i] ) {
            ans.push_back( cur -> val );
            return helper( cur -> right , i , v , ans ) && helper( cur -> left , i , v , ans );
        } else {
            return helper( cur -> left , i , v , ans ) && helper( cur -> right , i , v , ans );
        }
        
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int i = 0;
        
        if( helper( root , i , voyage , ans ) )
            return ans;
        
        return {-1};
    }
};