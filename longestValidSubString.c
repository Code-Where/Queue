#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    char data;
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

char *enqueue(node **rear, node **front, char value)
{
    node *nn;
    nn = (node *)malloc(sizeof(node));
    if (isFull(nn))
    {
        return NULL;
    }
    nn->data = value;
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
    return &(nn->data);
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
    else
    {
        (*front) = temp->next;
    }
    free(temp);
    return 1;
}

int longValidSubstr(char str[]){
    int count = 0, i;
    node *rear = NULL, *front = NULL;

    for (i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            enqueue(&rear, &front, str[i]);
        }
        else if (str[i] == ')')
        {
            if (dequeue(&rear, &front))
            {
                count += 2;
            }
        }
    }
    while(!isEmpty)
    {
        dequeue(&rear, &front);
    }
    return count;
}

int main()
{
    char substr[20];

    printf("Enter Paranthesis Substring\n");
    gets(substr);

    printf("length of the longest valid parenthesis substring %s is %d", substr, longValidSubstr(substr));
    return 0;
}