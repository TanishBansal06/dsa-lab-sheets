class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> result;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generate(start, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};
