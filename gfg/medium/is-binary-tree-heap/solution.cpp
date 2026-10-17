/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    int countNodes(Node* tree){
        if(tree == NULL){
            return 0;
        }
        int ans = 1 + countNodes(tree-> left ) + countNodes(tree-> right);
        return ans;
    }
  
    bool isCbt(Node* tree, int index, int count){
      if(tree == NULL){
          return true;
      }
      if(index > count){
          return false;
      }
      else{
          bool left = isCbt(tree-> left, 2*index, count);
          bool right = isCbt(tree-> right, 2*index+1, count);
          return (left && right); 
      }
    }
    
    bool isMaxOrder(Node* tree){
        //leaf node
        if(tree-> left == NULL && tree-> right == NULL){
            return true;
        }

        if(tree-> right == NULL){
            return(tree-> left -> data <= tree-> data);
        }
        else{
            bool l=  isMaxOrder(tree-> left);
            bool r = isMaxOrder(tree-> right);
            return (l && r && (tree-> left -> data <= tree-> data &&
                        tree-> right -> data <= tree-> data));
        }
    }
  
    bool isHeap(Node* tree) {
        // code here
        int index = 1;
        if(isCbt(tree, index, countNodes(tree)) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};