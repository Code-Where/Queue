#include <stdio.h>
#include <conio.h>
#include <string.h>

int isEmpty(int front, int rear)
{
    if (front == rear)
    {
        return 1;
    }
    return 0;
}

int isFull(int rear, int front, int size)
{
    if (front == rear+1 || (front == -1 && rear == size-1))
    {
        return 1;
    }
    return 0;
}

int enqueue(char queue[10][20], int size, int rear, int front, char value[])
{
    if (isFull(rear, front, size))
    {
        return -1;
    }
    rear++;
    rear %= size;
    strcpy(queue[rear], value);
    return rear;
}

int dequeue(int front, int rear, int size)
{
    if (isEmpty(front, rear))
    {
        return -1;
    }
    front++;
    front %= size;
    return front;
}

int peek(int front, int rear, int size)
{
    if (isEmpty(front, rear))
    {
        return -1;
    }
    return ((front+1)%size);
}

int main()
{
    int rear = -1, front = -1, check;
    char queue[10][20], val[20];
    char choice;
    do
    {
        printf("Press 1: For Enqueue\nPress 2: For Dequeue\nPress 3: Peek the Queue\nPress 4: Exit\n\n");
        choice = getch();
        if (choice == '1')
        {
            printf("Enter Value to insert\n");
            gets(val);
            check = enqueue(queue, 10, rear, front, val);
            if (check == -1)
                printf("Queue is full\n");
            else
            {
                printf("%s inserted to Queue\n", val);
                rear = check;
            }
        }
        else if (choice == '2')
        {
            check = dequeue(front, rear, 10);
            if (check == -1)
                printf("Queue is Empty\n");
            else
            {
                printf("Dequeue Successfull\n");
                front = check;
            }
        }
        else if (choice == '3')
        {
            check = peek(front, rear, 10);
            if (check == -1)
            {
                printf("Queue is Empty");
            }
            else
            {
                printf("%s is the frontmost element of Queue\n", queue[check]);
            }
        }
        else if (choice == '4')
            printf("Exiting From Program.....\n");
        else
            printf("Invalid Menu Option\n");
    } while (choice != '4');

    return 0;
}