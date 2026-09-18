/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    void createMapping(vector<int> in, map<int, int> &nodeToIndex, int n){
        for(int i=0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
  
    Node* solve(vector<int> &in, vector<int> &post, int &index, 
        int inStart, int inEnd, int n, map<int, int> &nodeToIndex){
        
        //base case
        if(index < 0 || inStart > inEnd){
            return NULL;
        }
        
        int ele = post[index--];
        Node* root = new Node(ele);
        int pos = nodeToIndex[ele];
        
        root->right = solve(in, post, index, pos+1, inEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inStart, pos-1, n, nodeToIndex);
        
        
        return root;
    }
    
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        
        int n = postorder.size();
        int index = n-1;
        
        int inStart = 0;
        int inEnd = n-1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        
        Node* ans = solve(inorder, postorder, index, inStart, inEnd, n, nodeToIndex);
        return ans;
    }
};