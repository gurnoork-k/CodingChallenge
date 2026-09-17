/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    Node* ans = NULL;
    int count = -1;

    int solve(Node* root, int node, int k) {
        if (root == NULL) return 0;

        if (root->data == node) {
            count = 0;
            return 1;
        }

        int left = solve(root->left, node, k);
        int right = solve(root->right, node, k);

        if (left || right) {
            count++;
            if (count == k && ans == NULL) {
                ans = root;
            }
            return 1;
        }

        return 0;
    }

  public:
    int kthAncestor(Node *root, int k, int node) {
        ans = NULL;
        count = -1;
        solve(root, node, k);
        return ans ? ans->data : -1;
    }
};