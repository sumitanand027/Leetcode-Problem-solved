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
    
    void cnt( TreeNode * cur , int &ans , vector<int> fre )
    {
        if( cur == NULL ) {
            return;
        }
        
        fre[ cur -> val ]++;
        
        if( cur -> left == NULL && cur -> right == NULL ) {
            int odds = 0;
            for( int i = 0 ; i < 10 ; i++ ) {
                if( fre[i] % 2 == 1 ) odds++;
            }
            if( odds == 0 || odds == 1 )
                ans++;
            return;
        }
        
        cnt( cur -> left , ans , fre );
        cnt( cur -> right , ans , fre );
        
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> fre( 10 , 0 );
        cnt( root , ans , fre );
        
        return ans;
    }
};