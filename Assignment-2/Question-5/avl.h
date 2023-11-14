#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <cmath>
using namespace std;

struct node{
    int** matrix;
    node* left;
    node* right;
    int key;
    int height;
    node() {left = nullptr; right = nullptr; height = 0;}
};

class avl{
private:
    int s0 = pow(2,20);
    int s1 = pow(2,19) + pow(2,20);
    int s2 = pow(2,18) + pow(2,17);
    int num_nodes;
    int num_insertions;
    int num_deletions;

    node* root;
    node* insertPrivate(node* ptr, int key){
        int remainder = key%3;
        if(ptr == nullptr){
            num_insertions++;
            node* ptr = createLeaf(key);
            num_nodes++;
            if(remainder == 0)
                ptr = initMatrix(ptr, size0);
            else if(remainder == 1)
                ptr = initMatrix(ptr, size1);
            else if(remainder == 2)
                ptr = initMatrix(ptr, size2);
        }
        else if(key > ptr->key){
            ptr->right = insertPrivate(ptr->right, key);
            if(getHeight(ptr->left) - getHeight(ptr->right) == 2){
                if(key < ptr->left->key)
                    ptr = singleRightRotate(ptr);
                else
                    ptr = doubleLeftRotate(ptr);
            }
        }
        else if(key < ptr->key){
            ptr->left = insertPrivate(ptr->left, key);
            if(getHeight(ptr->left) - getHeight(ptr->right) == 2){
                if(key < ptr->right->key)
                    ptr = singleLeftRotate(ptr);
                else
                    ptr = doubleRightRotate(ptr);
            }
        }

        ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
        return ptr;
    }
    node* removePrivate(node* root, int key){
        if(root == nullptr)
            return root;
        if(key < root->key){
            root->left = removePrivate(root->left, key);
        }
        else if(key > root->key){
            root->right = removePrivate(root->right, key);
        }
        else{
            if((root->left == nullptr) || (root->right == nullptr)){
                node* temp = root->left ? root->left:root->right;
                if(temp == nullptr){
                    temp = root;
                    root = nullptr;
                }
                else{
                    *root = *temp;
                }
                delete temp;
            }
            else{
                node* temp = getMinNode(root->right);
                root->key = temp->key;
                root->right = removePrivate(root->right, temp->key);
            }
            num_deletions++;
            num_nodes--;
        }
        if(root == nullptr)
            return root;
        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);
        if(balance > 1 && getBalance(root->left) >= 0)
            return singleRightRotate(root);
        if(balance > 1 && getBalance(root->left) < 0)
            return doubleRightRotate(root);
        if(balance < -1 && getBalance(root->right) <= 0)
            return singleLeftRotate(root);
        if(balance < -1 && getBalance(root->right) > 0)
            return doubleLeftRotate(root);
        return root;
    }
    int getMinPrivate(node* root){
        node* cur = root;
        if(root == nullptr){
            return -1;
        }
        while(cur->left != nullptr){
            cur = cur->left;
        }
        return cur->key;
    }
    node* getMinNode(node* root){
        node* cur = root;
        if(root == nullptr){
            return -1;
        }
        while(cur->left != nullptr){
            cur = cur->left;
        }
        return cur;
    }
    int getHeight(node* ptr) {return ptr->height;}
    int getBalance(node* ptr){
        if(ptr == nullptr)
            return 0;
        return getHeight(ptr->left) - getHeight(ptr->right);
    }
    node* singleLeftRotate(node* &ptr){
        node* n = ptr->right;
        ptr->right = n->left;
        n->left = ptr;
        ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
        n->height = max(getHeight(n->left), ptr->height) + 1;
        return n;
    }
    node* singleRightRotate(node* &ptr){
        node* n = ptr->left;
        ptr->left = n->right;
        n->right = ptr;
        ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
        n->height = max(getHeight(n->left), ptr->height) + 1;
        return n;
    }
    node* doubleLeftRotate(node* &ptr){
        ptr->right = singleRightRotate(ptr->right);
        return singleLeftRotate(ptr);
    }
    node* doubleRightRotate(node* &ptr){
        ptr->left = singleLeftRotate(ptr->left);
        return singleRightRotate(ptr);
    }
    node* initMatrix(node* ptr, int size){
        ptr->matrix = new int*[size];
        for(int i = 0; i < size; i++){
            ptr->matrix[i] = new int[size];
            for(int j = 0; j<size; j++){
                ptr->matrix[i][j] = 1;
            }
        }
        return ptr;
    }
public:
    avl() {root = nullptr; num_nodes = num_insertions = num_deletions = 0;}
    ~avl() {}
    node* createLeaf(int key){
        node* newnode = new node();
        newnode->key = key;
        return newnode;
    }
    void insert(int key) {root = insertPrivate(root, key);}
    void remove(int key) {root = removePrivate(root, key);}
    void display() {displayPrivate(root);}
    int min() {return getMinPrivate(root);}
    node* minNode() {return getMinNode(root);}
    int count() {return num_nodes;}
}

