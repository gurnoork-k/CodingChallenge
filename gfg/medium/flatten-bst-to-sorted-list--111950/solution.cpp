/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    Node* prev = NULL;
    
    void inorder(Node* root){
        
        if(root == NULL){
            return;
        }

        inorder(root-> left);
        
        if(prev != NULL){
            prev -> right = root;
        }
         
        root-> left = NULL;
        prev = root;
        
        inorder(root-> right);

    }
    
    Node *flattenBST(Node *root) {
    //     // code here
    //     while(root != NULL){
    //         if(root-> left != NULL){
    //             Node* prev = root-> left;
    //             while(prev -> right != NULL){
    //                 prev = prev -> right;
    //             }
    //         }
    //         else{
    //             prev = NULL;
    //         }
    //     }
        
    //     while(root != NULL){
    //         if(root-> right != NULL){
    //             Node* succ = root-> right;
    //             while(succ -> left != NULL){
    //                 succ = succ -> left;
    //             }
    //         }
    //         else{
    //             succ = NULL;
    //         }
    //     }
        
    //     prev-> right = root;
    //     root-> right = succ;
        
        prev = NULL;
        Node* curr = root;
        while (curr->left != NULL) curr = curr->left;

        inorder(root);
        return curr;
        
    }
};