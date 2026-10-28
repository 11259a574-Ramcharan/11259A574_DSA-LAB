
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *rear = NULL;

/* Insert an element into the circular queue */
void enqueue(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = val;

    if (rear == NULL) {
        newNode->next = newNode;
        rear = newNode;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued to circular queue.\n", val);
}

/* Remove an element from the circular queue */
void dequeue(void) {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *front = rear->next;
    printf("%d dequeued from circular queue.\n", front->data);

    if (front == rear) {
        rear = NULL;
    } else {
        rear->next = front->next;
    }

    free(front);
}

/* Display queue elements */
void display(void) {
    if (rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = rear->next;

    printf("Circular Queue elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

int main(void) {
    int choice, val;

    do {
        printf("\n--- Circular Queue (Linked List) Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");

                if (scanf("%d", &val) != 1) {
                    printf("Invalid value.\n");
                    while (getchar() != '\n');
                    break;
                }

                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    /* Free any remaining nodes */
    while (rear != NULL) {
        struct Node *front = rear->next;

        if (front == rear) {
            free(front);
            rear = NULL;
        } else {
            rear->next = front->next;
            free(front);
        }
    }

    return 0;
}
