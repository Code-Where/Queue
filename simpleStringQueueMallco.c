#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>
struct Node
{
    char data[20];
    struct Node *next;
};
typedef struct Node node;

int isEmpty(node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

char *enqueue(node **rear, node **front, char value[])
{
    node *nn;
    nn = (node *)malloc(sizeof(node));
    if (isFull(nn))
    {
        return NULL;
    }
    strcpy(nn->data, value);
    nn->next = NULL;
    if (isEmpty(*front))
    {
        *front = nn;
    }
    else
    {
        (*rear)->next = nn;
    }
    *rear = nn;
    return (nn->data);
}

int dequeue(node **rear, node **front)
{
    node *temp;
    if (isEmpty(*front))
    {
        return 0;
    }
    temp = (*front);
    if ((*front) == (*rear))
    {
        *front = *rear = NULL;
    }
    else{
        (*front) = temp -> next;
    }
    free(temp);
    return 1;
}

char *peek(node *front)
{
    if (isEmpty(front))
    {
        return NULL;
    }
    return (front->data);
}

int main()
{
    node *front = NULL, *rear = NULL;
    char choice, val[20];

    do
    {
        printf("Press 1: For Enqueue\nPress 2: For Dequeue\nPress 3: Peek the Queue\nPress 4: Exit\n\n");
        choice = getch();
        if (choice == '1')
        {
            printf("Enter Value to insert\n");
            gets(val);

            if (enqueue(&rear, &front, val) == NULL)
                printf("Queue is full\n");
            else
            {
                printf("%s inserted to Queue\n", val);
            }
        }
        else if (choice == '2')
        {
            if (dequeue(&rear, &front))
            {
                printf("Dequeue Successfull\n");
            }
            else
            {
                printf("Queue is Empty\n");
            }
        }
        else if (choice == '3')
        {
            if (peek(front) == NULL)
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("%s is the frontmost element of Queue\n", peek(front));
            }
        }
        else if (choice == '4')
            printf("Exiting From Program.....\n");
        else
            printf("Invalid Menu Option\n");

    } while (choice != '4');

    while (front != NULL)
    {
        dequeue(&rear, &front);
    }

    return 0;
}