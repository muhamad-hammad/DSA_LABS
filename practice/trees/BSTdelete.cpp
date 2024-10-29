#include<iostream>
using namespace std;

struct TreeNode{
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

TreeNode* findMin(TreeNode* node){
    while(node->left!=NULL){
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode * root, int key){
    if(root == NULL){
        return NULL;
    } else if(key<root->key){
        root->left = deleteNode(root->left, key);
    } else if(key>root->key){
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);

    }
    return root;

}
void PostOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->key<<endl;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    deleteNode(root, 10);
    PostOrder(root);
    return 0;
}