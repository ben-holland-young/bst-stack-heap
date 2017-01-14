/*
 * =====================================================================================
 *
 *       Filename:  binary_search_tree_imp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/01/2017 23:32:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode(); //Or malloc in c
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root, int data) {
    if(root == NULL) { //empty 
        root = GetNewNode(data);
    }

    else if (data <= root->data) {
        root->left = Insert(root->left,data);
    }

    else {
        root->right = Insert(root->right, data);
    }

    return root;
}
bool Search(BstNode* root, int data) {
    if(root == NULL) return false;
    if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left,data);
    else return Search(root->right,data);
}
int main() {
   BstNode* root; //Pointer to root node
   root = NULL; //Sets tree as empty
   //Empty tree
   root = Insert(root,15);
   root = Insert(root, 10);
   root = Insert(root, 20);
   int number;
   cout<<"enter number to search\n";
   cin>>number;
   if( Search(root,number) == true) cout<<"Found\n";
   else cout<<"Not Found\n";
}
