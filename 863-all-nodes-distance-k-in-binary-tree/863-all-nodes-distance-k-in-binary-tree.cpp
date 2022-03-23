/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map < TreeNode* , TreeNode * > parent;
        
        queue< TreeNode * > q;
        q.push( root );
        
        while( !q.empty() )
        {
            TreeNode * cur = q.front();
            q.pop();
            
            if( cur -> left )
            {
                parent[ cur -> left ] = cur;    
                q.push( cur -> left );
            }
            
            if( cur -> right ) 
            {
                parent[ cur -> right ] = cur;
                q.push( cur -> right );
            }
            
        }
        
        
        vector<int> ans;
        unordered_set< TreeNode * > visited;
        visited.insert( target );
        dfs( target , k , parent , ans , visited );
        
        return ans;
    }
    
    void dfs( TreeNode * cur , int k , unordered_map< TreeNode * , TreeNode * > parent , vector<int> &ans , unordered_set< TreeNode *> &visited )
    {
        if( cur == NULL )return;
        
        if( k == 0 ) {
            ans.push_back( cur -> val );
            return;
        }
        
        if( visited.find( parent[ cur ] ) == visited.end() ) {
            visited.insert( parent[cur] );
            dfs( parent[cur] , k -1 , parent , ans , visited );
        }
        
        if( visited.find( cur -> left ) == visited.end() ) {
            visited.insert( cur -> left );
            dfs(cur -> left , k -1 , parent , ans , visited );
        }
        if( visited.find( cur -> right ) == visited.end() ) {
            visited.insert( cur -> right );
            dfs( cur -> right , k -1 , parent , ans , visited );
        }
        
    }
};





