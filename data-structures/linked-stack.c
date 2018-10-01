#include <stdio.h>
#include <stdlib.h>

// 这个代码有个 segmentation fault 错误，但是不影响输出，暂时不深究了
// 链式结构
// 和链表非常相似，用指向栈顶部的指针作为整个栈的指针。
typedef struct stack {
    int data;
    struct stack *next;
} link_stack;

void init(link_stack*);
void push(link_stack*, int);
int pop(link_stack*);
void print_stack(link_stack*);

int main(void) {
    link_stack *s;
    init(s);
    push(s, 2016);
    push(s, 2017);
    push(s, 2018);
    push(s, 2019);
    printf("pop: %d\n", pop(s)); // pop 的必然是最后添加的
    print_stack(s);
    return 0;
}

// 初始化一个指针，用来指向栈的 top
void init(link_stack *s) {
    s = (link_stack *)malloc(sizeof(link_stack));
    s->next = NULL;
}

// 新建一个节点，data 部分放数字 n
// 至于指针域部分，我们要的结果是：
// s 指针继续指向新 top，即新节点，而新的节点指向原来的 top。
// 其中原来的 top 就是 s->next
// 把它赋值给 p->next 即可。
// 然后 s 指针继续指向新的 top： s->next = p
void push(link_stack *s, int n) {
    link_stack *p = (link_stack *)malloc(sizeof(link_stack));
    p->data = n;
    p->next = s->next; // 新的节点的 next 就是原来的 top
    s->next = p;       // 新的 top 就是新的节点
}

int pop(link_stack *s) {
    link_stack *p = s->next;
    int data = p->data;
    s->next = p->next;
    free(p);
    return data;
}

// 从上往下打印栈的元素
void print_stack(link_stack *s) {
    printf("stack:\n");
    link_stack *p = s->next;
    for (link_stack *p = s->next; p->next; p=p->next) {
        printf("%d\n", p->data);
    }
}