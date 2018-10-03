// @Date:   2018-10-03 18:14:38
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right; // 两个孩子
} Node;

// 把一棵树看成一个整体，用一个指向根结点的指针来表示一棵树
typedef struct tree {
    Node* root;
} Tree;

// 如果只是 Node* node 来定义的话，会存在栈里面，即局部变量，退出函数后就销毁了
void insert(Tree* tree, int data) {
    Node* node = malloc(sizeof(Node)); // 堆里面申请内存，退出函数不会销毁
    node->data = data;
    node->left = node->right = NULL;

    if (tree->root == NULL)
        tree->root = node;
    else {
        Node* temp = tree->root;  // 当前结点
        while (temp != NULL) {
            if (data < temp->data) { // 新结点比当前结点小，放入左边
                if (temp->left == NULL) { // 左结点为空直接放入
                    temp->left = node;
                    break;
                }
                else { // 左结点不为空，继续下一层的左结点推进
                    temp = temp->left; 
                }
            }
            else { // 新结点比当前结点大，放入右边
                if (temp->right == NULL) {
                    temp->right = node;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
        }
    }
}

// DLR
void preOrder(Node* node) { 
    if (node != NULL) {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// LDR
void inOrder(Node* node) { 
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

// LRD
void postOrder(Node* node) { 
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}

// 求树的深度；一个结点时，深度为1，以此类推
int get_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        int max = left_h;
        if (right_h > max) {
            max = right_h;
        }
        // 一个结点的时候 成立，那么递归就成立
        // 不要过度解决程序具体的步骤，其实是个入栈出栈的过程
        return max + 1; 
    }
}

// 求最大值
int get_max(Node* node) {
    if (node == NULL) {
        return -1;
    }
    else {
        int left_max = get_max(node->left);   // 左
        int right_max = get_max(node->right); // 右
        int mid_max = node->data;             // 中（当前）
        int max = left_max;
        if (right_max > max) 
            max = right_max;
        if (mid_max > max)
            max = mid_max;
        return max;
    }    
}

int main(void) {

    Tree tree;
    tree.root = NULL;

    int nums[5] = {3,1,4,5,2};
    for (int i=0; i<5; i++) {
        insert(&tree, nums[i]);
    }

    printf("前序遍历： ");
    preOrder(tree.root);
    printf("\n");
    printf("中序遍历： ");
    inOrder(tree.root);
    printf("\n");
    printf("后序遍历： ");
    postOrder(tree.root);
    printf("\n");    

    printf("树的深度：%d\n", get_height(tree.root));
    printf("树结点的最大值：%d\n", get_max(tree.root));
    return 0;
}









