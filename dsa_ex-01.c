#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    int n, i, choice;
    struct Employee *emp;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    if (emp == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input employee details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &(emp + i)->id);

        printf("Name: ");
        scanf("%s", (emp + i)->name);

        printf("Salary: ");
        scanf("%f", &(emp + i)->salary);
    }

    // Menu
    do
    {
        printf("\n===== Employee Record Menu =====\n");
        printf("1. Display All Employees\n");
        printf("2. Search Employee by ID\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Salary");
            printf("---------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%-10d %-20s %-10.2f\n",
                       (emp + i)->id,
                       (emp + i)->name,
                       (emp + i)->salary);
            }
            break;

        case 2:
        {
            int searchId, found = 0;

            printf("Enter Employee ID to search: ");
            scanf("%d", &searchId);

            for (i = 0; i < n; i++)
            {
                if ((emp + i)->id == searchId)
                {
                    printf("\nEmployee Found\n");
                    printf("ID     : %d\n", (emp + i)->id);
                    printf("Name   : %s\n", (emp + i)->name);
                    printf("Salary : %.2f\n", (emp + i)->salary);

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Employee with ID %d not found.\n", searchId);
            }

            break;
        }

        case 3:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free(emp);

    return 0;
}