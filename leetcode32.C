class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode* q = st.top(); st.pop();
            TreeNode* p = st.top(); st.pop();
            if(!p && !q) continue;
            if(!p || !q || p->val != q->val) return false;
            st.push(p->left);
            st.push(q->right);
            st.push(p->right);
            st.push(q->left);
        }
        return true;
    }
};