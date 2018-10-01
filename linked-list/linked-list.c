#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} NODE;

void traverse(NODE *head); // 遍历链表并打印
void append(NODE** pHead, int num); // 添加元素到末尾
int search(NODE *head, int num); // 查找元素是否存在
void delete(NODE **pHead, int num);

int main(void) {
    NODE *head = NULL; // 有这个头指针就能定位整个链表，初始值设置为 NULL 空指针

    int num;
    while (1) {

        scanf("%d", &num);                        // -1 表示结束
        if (num == -1) break;
        append(&head, num);
    };
    
    printf("%s\n", "这是你刚刚输入的链表：");
    traverse(head);

    int del_num = 1;
    delete(&head, del_num);
    
    int find_num = 9;
    int found = search(head, find_num);
    if (found) {
        printf("我找到了数字 %d\n", find_num);        
    } else {
        printf("我没有找到数字 %d\n", find_num);
    };
    printf("这是删除元素 %d 后的链表：\n", del_num);
    traverse(head);
    return 0;
}


void append(NODE** pHead, int num) 
{
        NODE *p = (NODE*)malloc(sizeof(NODE));    // 制作新的节点
        p->value = num;
        p->next = NULL;
        NODE *last = *pHead;               
        if (last) {
            while (last->next) {
                last = last->next;
            }
            last->next = p;
        } else {
            *pHead = p;           
        };
}

void traverse(NODE *head) 
{
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int search(NODE *head, int num)
{
    NODE* p;
    for (p=head; p; p=p->next) {
        if (num == p->value) {
            return 1;
        }
    }
    return 0;
}

void delete(NODE **pHead, int num)
{
    NODE *q;
    NODE *p;
    for (q=NULL, p=*pHead; p; q=p, p=p->next) {
        if (p->value == num) {
            if (q) { // 凡是出现 -> 都需要考虑指针为空的情况
                q->next = p->next;    
            } else {     // q 是 NULL 说明我第一项就是要删除的元素
                *pHead = p->next;
            }
            free(p);
            break;
        }
    }
}








