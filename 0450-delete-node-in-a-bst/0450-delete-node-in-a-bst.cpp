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
    // Helper function to handle deletion logic
    TreeNode* helper(TreeNode* root) {
        // Step 5: Handle cases with 0 or 1 child
        if (root->left == NULL)
            return root->right; // Return right child (could be NULL)
        else if (root->right == NULL)
            return root->left; // Return left child

        // Step 6: Handle node with two children
        TreeNode* rightchild = root->right;
        // Find rightmost node in left subtree
        TreeNode* leftRight = findLastRight(root->left);
        // Attach right subtree to rightmost node of left subtree
        leftRight->right = rightchild;
        // Return left subtree as new root
        return root->left;
    }

    // Step 7: Find the rightmost node (largest in subtree)
    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Step 1: Handle empty tree
        if (!root)
            return NULL;
        
        // Step 2: Check if root is the target
        if (root->val == key)
            return helper(root);
        
        // Step 3: Iteratively search for target node
        TreeNode* dummy = root; // Keep reference to original root
        while (root != NULL) {
            if (root->val > key) {
                // Step 4: Check left child
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                // Step 4: Check right child
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};