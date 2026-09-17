/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
private: 
    int findPosition(vector<int> &inorder, int ele, int n){
        for(int i=0; i< n; i++){
            if(inorder[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index, int inStart, int inEnd, int n){
        //base case
        if(index >= n || inStart > inEnd){
            return NULL;
        }
        
        int ele = preorder[index++];
        Node* root = new Node(ele);
        int pos = findPosition(inorder, ele, n);
        
        root-> left = solve(inorder, preorder, index,inStart, pos-1, n);
        root-> right = solve(inorder, preorder, index, pos+1, inEnd, n);
        
        return root;
        
    }
  public:
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0;
        int n = inorder.size();
        Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};