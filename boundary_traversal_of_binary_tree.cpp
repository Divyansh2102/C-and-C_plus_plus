#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isleaf(TreeNode<int>*root){
    if(root->left==NULL && root->right==NULL)   return 1;
    return 0;
}
void leftb(TreeNode<int>*root,vector<int>&ans){
    TreeNode<int>*cur=root->left;
    while(cur){
        if(!isleaf(cur))    ans.push_back(cur->data);
        if(cur->left)   cur=cur->left;
        else    cur=cur->right;
    }
}
void leaf(TreeNode<int>*root,vector<int>&ans){
    if(isleaf(root)){
            ans.push_back(root->data);
            return;
    }
    if(root->left)  leaf(root->left,ans);
    if(root->right) leaf(root->right,ans);
}
void rightb(TreeNode<int>*root,vector<int>&ans){
    vector<int>temp;
    TreeNode<int>*cur=root->right;
    while(cur){
        if(!isleaf(cur))    temp.push_back(cur->data);
        if(cur->right)  cur=cur->right;
        else    cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--)   ans.push_back(temp[i]);

}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(root==NULL)  return ans;
    if(!isleaf(root))   ans.push_back(root->data);
    leftb(root,ans);
    leaf(root,ans);
    rightb(root,ans);
    return ans;
}