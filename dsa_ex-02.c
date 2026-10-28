#include <stdio.h>

#define MAX 100

// Function to display array elements
void traverse(int arr[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element
int insert(int arr[], int n, int pos, int value)
{
    int i;

    if (n >= MAX)
    {
        printf("Array is full. Cannot insert.\n");
        return n;
    }

    if (pos < 0 || pos > n)
    {
        printf("Invalid position.\n");
        return n;
    }

    for (i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;

    printf("Element inserted successfully.\n");
    return n + 1;
}

// Function to delete an element
int deleteElement(int arr[], int n, int pos)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty. Nothing to delete.\n");
        return n;
    }

    if (pos < 0 || pos >= n)
    {
        printf("Invalid position.\n");
        return n;
    }

    for (i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully.\n");
    return n - 1;
}

int main()
{
    int arr[MAX];
    int n, choice, pos, value;
    int i;

    printf("Enter number of elements (0-%d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX)
    {
        printf("Invalid number of elements!\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\n========== ARRAY OPERATIONS ==========\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);

            printf("Enter value to insert: ");
            scanf("%d", &value);

            n = insert(arr, n, pos, value);
            traverse(arr, n);
            break;

        case 2:
            printf("Enter position to delete (0 to %d): ", n - 1);
            scanf("%d", &pos);

            n = deleteElement(arr, n, pos);
            traverse(arr, n);
            break;

        case 3:
            traverse(arr, n);
            break;

        case 4:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}