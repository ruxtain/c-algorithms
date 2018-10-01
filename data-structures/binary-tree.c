// @Date:   2018-10-01 20:18:47
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left, *right;
} node;

node* new(int value) {
    node *n = (node *)malloc(sizeof(node));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

void insert(node** root, node* child) {
        // 如果 *root 也就是根节点的指针为空，那么让指向根节点的指针指向 child
        // 让这个 child 作为 root
        if(!*root)
            *root = child;

        // 如果 child 的值小于或者等于 root 的值，那么我把它放在 root 的左边
        // 不是直接放，而是递归地放，递归的结束条件是遇到一个没有任何子节点的节点，即叶子
        else if(child->value <= (*root)->value)
            insert(&((*root)->left), child);     
        else
            insert(&((*root)->right), child);    
}


// 先序遍历
// [ visit, left, right ] 
void pre(node * n){
    printf("%d ", n->value);
    if(n->left) pre(n->left);
    if(n->right) pre(n->right);
}

// 后序遍历
void post(node * n){
    printf("%d ", n->value);
    if(n->right) pre(n->right);
    if(n->left) pre(n->left);
}

int main() {

    int nums[10] = {5, 1, 3, 8, 6, 9, 2, 4, 7, 0};

    /*
    树大概长这样：

               5
             /   \
            1     8
           / \   /  \
          0   3  6   9
             / \  \
            2   4  7
    */

    node *root = NULL;
    for (int i=0; i<10; i++) {
        node *child = new(nums[i]);
        insert(&root, child);    
    }
    pre(root);
    printf("\n");
    post(root);
    printf("\n");
    return 0;
}