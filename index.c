#include <stdio.h>
#include <string.h>

#define MaxEmployees 5

typedef struct
{
    char name[20];
    int age;
    char employee_id[10];
    char gender[10];
    int salary;
}

employee;

employee employees[MaxEmployees];

int main()
{
    generateEmploy();

    char choice;
    while (1)
    {
        printf("\n1. Employee List\n2. Monthly Sales Target\n3. Monthly Sales History\n4. Best Employee\n5. Exit\nYour Choice: ");

        choice = getche();
        system("cls");

        switch (choice)
        {
        case '1':
            displayEmploy();
            break;
        case '2':

            break;

        case '3':

            break;
        case '4':

            break;
        case '5':
            exit(0);
        default:
            printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
        }
    }

    return 0;
}

void generateEmploy()
{
    employees[0] = (employee){"Meherab", 25, "EM001", "Male", 25000};
    employees[1] = (employee){"Sultana", 22, "EM002", "Female", 26000};
    employees[2] = (employee){"Alif", 24, "EM003", "Male", 24500};
    employees[3] = (employee){"Adity", 21, "EM004", "Female", 22000};
    employees[4] = (employee){"Dhiman", 23, "EM005", "Male", 25000};
}

void displayEmploy()
{
    tableStart("EMPLOYEE LIST START");
    printf("\nNAME\t\t\tID\t\tAGE\t\tGENDER\t\tSARALY\n");
    border();
    for (int i = 0; i < MaxEmployees; i++)
    {
        printf("\n%s\t\t\t%s\t\t%d\t\t%s\t\t%d\n",
               employees[i].name, employees[i].employee_id, employees[i].age, employees[i].gender, employees[i].salary);
        border();
    }
    tableStart("EMPLOYEE LIST END");
    printf("\n\n");
}
void border()
{
    printf("-------------------------------------------------------------------------------");
}

void tableStart(char level[20])
{
    printf("\n\n\t\t\t============= %s =============\n\n", level);
}
