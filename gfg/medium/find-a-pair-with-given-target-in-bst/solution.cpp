/* Binary Tree Node Structure
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
    void inorder(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        inorder(root-> left, ans);
        ans.push_back(root-> data);
        inorder(root-> right, ans);

    }
    
    bool findTarget(Node *root, int target) {
        // code here.
        vector<int> ans;
        inorder(root, ans);
        
        int n = ans.size();
        int i = 0;
        int j = n-1;
        int sum = 0;
        bool flag = false;
        
        while(i < j){
            sum = ans[i] + ans[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                flag = true;
                break;
            }
            
        }
        return flag;
    }
};