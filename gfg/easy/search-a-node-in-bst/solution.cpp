/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        //base case
        if(root == NULL){
            return false;

        }
        if(root -> data == key){
            return true;
        }

        if(root-> data > key){
            search(root-> left, key);
        }
        else{
            search(root-> right , key);
        }
    }
};