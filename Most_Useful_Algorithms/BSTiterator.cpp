// link to problem:- https://leetcode.com/problems/binary-search-tree-iterator/



//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//class that has to be implemented
class BSTIterator {
    
    stack<TreeNode*>st;
    
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        auto node= st.top();
        st.pop();
        if(node->right) pushAllLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void  pushAllLeft(TreeNode* root){
        
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
