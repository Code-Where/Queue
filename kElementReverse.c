#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct Node
{
    int data;
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

int *enqueue(node **rear, node **front, int value, int *size)
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
    (*size)++;
    return &(nn->data);
}

int dequeue(node **rear, node **front, int *size)
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
    (*size)--;
    free(temp);
    return 1;
}

int *peek(node *front)
{
    if (isEmpty(front))
    {
        return NULL;
    }
    return &(front->data);
}

void rev(int k, int i, node **rear, node **front, int *size){
    int val;
    if (i!=k)
    {
        val = *peek(*front);
        dequeue(rear, front, size);
        rev(k, i+1, rear, front, size);
        enqueue(rear, front, val, size);
    }
}

void revKElements(int k, node **rear, node **front, int *size){
    rev(k, 0, rear, front, size);
    int i;
    for (i = 0; i < (*size)-k; i++)
    {
        int val = *peek((*front));
        dequeue(rear, front, size);
        enqueue(rear, front, val, size);
    }
}
void traverse(node *front){
    node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    node *front = NULL, *rear = NULL;
    int size = 0, val, k;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter Value to Enqueue\n");
        scanf("%d", &val);
        enqueue(&rear, &front, val, &size);
    }
    do
    {
        printf("Enter the value of k\n");
        scanf("%d", &k);
    }while(k < 1 || k > 10);
    
    printf("Queue Before reversing\n");
    traverse(front);

    printf("\n");

    revKElements(k, &rear, &front, &size);
    printf("Queue After reversing\n");
    traverse(front);

    for (int i = 0; i < 10; i++)
    {
        dequeue(&rear, &front, &size);
    }
    
    return 0;
}