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

int isFull(int rear, int size)
{
    if (rear == size)
    {
        return 1;
    }
    return 0;
}

int enqueue(char queue[10][20], int size, int rear, char value[])
{
    if (isFull(rear, size))
    {
        return -1;
    }
    rear++;
    strcpy(queue[rear], value);
    return rear;
}

int dequeue(int front, int rear)
{
    if (isEmpty(front, rear))
    {
        return -1;
    }
    front++;
    return front;
}

int peek(int front, int rear)
{
    if (isEmpty(front, rear))
    {
        return -1;
    }
    return front+1;
}

int main()
{
    char queue[10][20];
    int i = -1, j = -1, check;
    char choice, str[20];
    do
    {
        printf("Press 1: For Enqueue\nPress 2: For Dequeue\nPress 3: Peek the Queue\nPress 4: Exit\n\n");
        choice = getch();
        if (choice == '1')
        {
            printf("Enter String to insert\n");
            gets(str);
            check = enqueue(queue, 10, i, str);
            if (check == -1)
                printf("Queue is full\n");
            else
            {
                printf("%s inserted to Queue\n", str);
                i = check;
            }
        }
        else if (choice == '2')
        {
            check = dequeue(j, i);
            if (check == -1)
                printf("Queue is Empty\n");
            else
            {
                printf("Dequeue Successfull\n");
                j = check;
            }
        }
        else if (choice == '3')
        {
            check = peek(j, i);
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