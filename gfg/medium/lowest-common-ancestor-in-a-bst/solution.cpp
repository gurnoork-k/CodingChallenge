/* Structure of a Binary Search Tree node
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
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        // code here
        //base case
        
        if(root == NULL) return root;
        
        if(n1-> data < root-> data && n2-> data < root-> data){
            return findLCA(root-> left, n1, n2);
        }
        if(n1-> data > root-> data && n2-> data > root-> data){
            return findLCA(root-> right, n1, n2);
        }
        return root;
    }
};