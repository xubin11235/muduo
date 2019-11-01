#include <string.h>
#include <stdio.h>

class Node {
public:
    int data;
    Node* next;
    Node(int a);
};

Node::Node(int a):data(a), next(NULL) {
}

void insert_head(Node** list, Node* node) {
    node->next = *list;
    *list = node;
    return;
}

void insert_tail(Node** list, Node* node) {
    Node** tmp;
    for (tmp = list; *tmp != NULL; tmp = &(*tmp)->next) {
    }

    *tmp = node;
    return;
}

void* query(Node** list, int a) {
    Node** tmp;
    for (tmp = list; *tmp != NULL; tmp = &(*tmp)->next) {
        if ((*tmp)->data == a) {
            return *tmp;
            // del directly
            *tmp = (*tmp)->next;
        }
    }

    return NULL;
}

void del(Node** list, void* p) {
    Node** tmp;
    for (tmp = list; *tmp != NULL; tmp = &(*tmp)->next) {
        if (*tmp == p) {
            *tmp = (*tmp)->next;
            return;
        }
    }
    return;
}

void print(Node** list) {
    Node** tmp;
    for (tmp=list; *tmp != NULL; tmp = &(*tmp)->next) {
        printf("%d\n", (*tmp)->data);
    }
    return;
}

int test_link() {
    Node* head = NULL;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    printf("%p\n", node2);
    insert_head(&head, node1);
    insert_head(&head, node2);
    print(&head);

    Node* node3 = new Node(3);
    insert_tail(&head, node3);
    print(&head);

    void* q = query(&head, 2);
    printf("%p\n", q);

    del(&head, q);
    print(&head);

    return 0;
}

/*
 * 双向循环列表
 * 双向如果不是循环，则head的next更改完了，还要改head的prev
 * 双向循环列表是要带头的
 */
class Queue {
public:
    int data;
    Queue* prev;
    Queue* next;
    Queue(int a);
};

Queue::Queue(int a):data(a) {
}

void insert_head(Queue* head, Queue* node) {
    node->prev = head;
    head->next->prev = node;
    node->next = head->next;
    head->next = node;
    return;
}

void insert_tail(Queue* head, Queue* node) {
    head->prev->next = node;
    node->next = head;
    node->prev = head->prev;
    head->prev = node;
    return;
}

void remove(Queue* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = NULL;
    node->next = NULL;
}

bool is_empty(Queue* head) {
    return head->prev == head;
}

void init(Queue* head) {
    head->prev = head;
    head->next = head;
}

void print(Queue* queue) {
    Queue* tmp = NULL;
    /*
     * 这样写是标准的错误！！！
     * 这样会打印头节点的无效信息，头节点是没有有效数据的
     */
    /*
    for (tmp = queue; tmp->next != queue; tmp = tmp->next) {
        printf("%d\n", tmp->data);
    }
     */

    for (tmp = queue->next; tmp != queue; tmp = tmp->next) {
        printf("%d\n", tmp->data);
    }
    printf("print ok\n");
}

void test_queue() {
    printf("test queue\n");
    Queue *queue = new Queue(0);
    init(queue);

    Queue* node = new Queue(1);
    insert_head(queue, node);
    print(queue);

    Queue* node2 = new Queue(2);
    insert_head(queue, node2);
    print(queue);

    Queue* node3 = new Queue(3);
    insert_tail(queue, node3);
    print(queue);

    remove(node2);
    print(queue);

    remove(node);
    print(queue);

    remove(node3);
    print(queue);
}

int main() {
    test_link();
    test_queue();
}