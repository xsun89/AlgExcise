#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

class BTree{
private:
    Node* root;
    void Insert(int value, Node* leaf);
    void PrintTree(Node* leaf);
    void ReverseTree(Node* leaf);
    void ReverseTreeUseQueue(Node* leaf);
public:
    BTree();
    ~BTree();
    void Insert(int value);
    void PrintTree();
    void ReverseTree();

};

BTree::BTree() {
    root = NULL;
}

BTree::~BTree() { }

void BTree::PrintTree() {
    if(root == NULL){
        cout << "empty";
    }else{
        PrintTree(root);
    }
}

void BTree::PrintTree(Node *leaf) {
    if(leaf == NULL){
        return;
    }
    cout << leaf->val << endl;
    PrintTree(leaf->left);
    PrintTree(leaf->right);
}
void BTree::Insert(int value) {
    if(root != NULL){
        Insert(value, root);
    }else{
        root = new Node();
        root->val = value;
        root->left = NULL;
        root->right = NULL;
    }
}

void BTree::Insert(int value, Node *leaf) {
    if(value < leaf->val){
       if(leaf->left != NULL){
           Insert(value, leaf->left);
       }else{
           leaf->left = new Node();
           leaf->left->val = value;
           leaf->left->left = NULL;
           leaf->left->right = NULL;
       }
    }else{
        if(leaf->right != NULL){
            Insert(value, leaf->right);
        }else{
            leaf->right = new Node();
            leaf->right->val = value;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

void BTree::ReverseTree() {
    if(root == NULL){
        return;
    }else{
        //ReverseTree(root);
        ReverseTreeUseQueue(root);
    }
}

void BTree::ReverseTree(Node *leaf) {
    if(leaf == NULL){
        return;
    }
    ReverseTree(leaf->left);
    ReverseTree(leaf->right);
    Node* tmp = leaf->right;
    leaf->right = leaf->left;
    leaf->left = tmp;
}

void BTree::ReverseTreeUseQueue(Node *leaf) {
    queue<Node*> tmpqueue;
    tmpqueue.push(leaf);
    while(!tmpqueue.empty()){
        Node* tmp = tmpqueue.front();
        tmpqueue.pop();
        if(tmp->right != NULL){
            tmpqueue.push(tmp->right);
        }
        if(tmp->left != NULL){
            tmpqueue.push(tmp->left);
        }
        swap(tmp->left, tmp->right);
    }

}
int main() {
    BTree tree;
    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(7);
    tree.Insert(1);
    tree.Insert(3);
    tree.Insert(6);
    tree.Insert(9);
    tree.PrintTree();

    tree.ReverseTree();
    cout << "after reverse" << endl;
    tree.PrintTree();
    return 0;
}