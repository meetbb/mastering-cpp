#include <stdio.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

void traverse(struct ListNode *head) {
    struct ListNode *curr = head;
    for (curr = head; curr != nullptr; curr = curr->next)
    {
        printf("%d", curr->data);
    }
    
}