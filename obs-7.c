#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int id;
    struct Node *next;
};
struct Node *head = NULL;
void freeLinkedList()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
}
struct Node *createNode(int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}
void insertBeginning(int id)
{
    struct Node *newNode = createNode(id);
    newNode->next = head;
    head = newNode;
}
void traverse()
{
    struct Node *temp = head;
    printf("Roster: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->id);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    insertBeginning(100);
    insertBeginning(200);
    traverse();
    return 0;
}
