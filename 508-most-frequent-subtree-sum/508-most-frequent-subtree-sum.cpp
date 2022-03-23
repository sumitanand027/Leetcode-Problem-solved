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
    
    unordered_map< int , int > m;
  
    int helper( TreeNode * cur ) {
        if( cur == NULL )
            return 0;
        
        int l = helper( cur -> left );
        int r = helper( cur -> right );
        
        int sum = l + r + cur -> val;
        
        m[ sum ]++;
        
        return sum;        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        helper( root );
        
        unordered_map< int , vector<int> > freq;
        
        for( auto sum : m ) {
            freq[ sum.second ].push_back( sum.first );
        }
        
        vector<int> ans;
        
        int mx = 0;
        
        for( auto a : freq ) {
            if( mx < a.first ) {
                mx = a.first;
                ans = a.second;
            }    
        }
        return ans;
    }
};






