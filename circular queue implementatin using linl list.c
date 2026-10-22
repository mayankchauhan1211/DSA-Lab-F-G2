
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;


void enqueue()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &temp->data);

    if(front == NULL)
    {
        front = rear = temp;
        temp->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }

    printf("Element inserted\n");
}


void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        printf("Deleted element: %d\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        printf("Deleted element: %d\n", front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != front);

    printf("\n");
}

int main()
{
    int ch;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exit\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }
    while(ch != 4);

    return 0;
}
