#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int foodToken;
    struct Node *next;
};

struct Node *rear = NULL; /* rear points to last node; rear->next is front */

void enqueue(int token)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->foodToken = token;
    if (rear == NULL)
    {
        newNode->next = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    printf("Token %d issued\n", token);
}

void dequeue()
{
    if (rear == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node *front = rear->next;
    printf("Token %d served\n", front->foodToken);

    if (front == rear)
        rear = NULL;
    else
        rear->next = front->next; // Link the rear to the next node of front
    free(front);
}

void display()
{
    if (rear == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node *temp = rear->next;
    printf("Pending Tokens: ");
    do
    {
        printf("%d ", temp->foodToken);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    enqueue(4);
    display();
    return 0;
}
