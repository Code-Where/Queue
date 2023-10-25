#include <stdio.h>
#include <conio.h>

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

int enqueue(int queue[], int size, int rear, int value)
{
    if (isFull(rear, size))
    {
        return -1;
    }
    rear++;
    queue[rear] = value;
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
    int queue[10], i = -1, j = -1, check, val;
    char choice;
    do
    {
        printf("Press 1: For Enqueue\nPress 2: For Dequeue\nPress 3: Peek the Queue\nPress 4: Exit\n\n");
        choice = getch();
        if (choice == '1')
        {
            printf("Enter Value to insert\n");
            scanf("%d", &val);
            check = enqueue(queue, 10, i, val);
            if (check == -1)
                printf("Queue is full\n");
            else
            {
                printf("%d inserted to Queue\n", val);
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
                printf("%d is the frontmost element of Queue\n", queue[check]);
            }
        }
        else if (choice == '4')
            printf("Exiting From Program.....\n");
        else
            printf("Invalid Menu Option\n");
    } while (choice != '4');

    return 0;
}