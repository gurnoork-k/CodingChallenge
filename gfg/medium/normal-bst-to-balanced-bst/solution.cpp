/* BST Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root-> left, in);
        in.push_back(root-> data);
        inorder(root-> right, in);
        
    }
    
    Node* inorderToBst(int s, int e, vector<int> in){
        if(s>e) return NULL;
        
        int mid = (s+e)/2;
        Node* root = new Node(in[mid]);
        root-> left = inorderToBst(s, mid-1, in);
        root-> right = inorderToBst(mid+1, e, in);
        return root;
    }
    
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        return inorderToBst(0, n-1, in);
        
    }
};