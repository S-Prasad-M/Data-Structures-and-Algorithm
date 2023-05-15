//Reference: https://www.codewithharry.com/videos/data-structures-and-algorithms-in-hindi-82/
// (❁´◡`❁)(❁´◡`❁)(❁´◡`❁)(❁´◡`❁)
// 🎶🎶🎶🎶🎶🎶🎶🎶🎶🎶🎶🎶🎶🎶
// U_U U_U U_U U_U U_U U_U U_U U_U U_U 
#include<stdio.h>
#include<conio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int getBalanceFactor(struct Node* node){
    if(node==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct Node* createNode(int num){
    struct Node* head = (struct Node *) malloc(sizeof(struct Node));
    node->data = num;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node* node){
    if(node==NULL){
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* insert(struct Node* node, int key){
    if (node == NULL)
        return  createNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}
void main(){
    
}