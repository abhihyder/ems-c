#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEE 5
#define EMPLOYEE_FILE "data/employee.txt"
#define SALES_TARGET_FILE "data/sales_target.txt"
#define SALES_HISTORY_FILE "data/sales_history.txt"
#define BEST_EMPLOYEE_FILE "data/sales_history.txt"

typedef struct
{
    char name[20];
    int age;
    char employee_id[10];
    char gender[10];
    int salary;
} Employee;

Employee employee;

int main()
{
    // generateEmployee();

    menu();

    return 0;
}

void menu()
{

    char choice;
    while (1)
    {
        printf("\n1. Employee List\n2. Monthly Sales Target\n3. Monthly Sales History\n4. Best Employee\n5. Exit\nYour Choice: ");

        choice = getche();
        system("cls");

        switch (choice)
        {
        case '1':
            displayEmployee();
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
}

void generateEmployee()
{
    FILE *file;
    file = fopen(EMPLOYEE_FILE, "a");
    if (file == NULL)
    {
        printf("Something went wrong!\n");
        return;
    }
    printf("Enter Employee Name: ");
    scanf("%s", employee.name);
    printf("\nEnter Employee ID: ");
    scanf("%s", employee.employee_id);
    printf("\nEnter Employee Age: ");
    scanf("%d", &employee.age);
    printf("\nEnter Employee Gender: ");
    scanf("%s", employee.gender);
    printf("\nEnter Employee Salary: ");
    scanf("%d", &employee.salary);
    fprintf(file, "%s\t\t\t%d\t\t%s\t\t%s\t\t%d\n", employee.name, employee.age, employee.employee_id, employee.gender, employee.salary);
    fclose(file);
    displayEmployee();
}

void displayEmployee()
{
    FILE *file;
    file = fopen(EMPLOYEE_FILE, "r");

    if (file == NULL)
    {
        printf("Error in reading or does not exist the file '%s'", EMPLOYEE_FILE);
        return;
    }
    else
    {
        tableStart("EMPLOYEE LIST START");
        printf("\nNAME\t\t\tID\t\tAGE\t\tGENDER\t\tSARALY\n");
        border();
        while (fscanf(file, "%s\t\t\t%d\t\t%s\t\t%s\t\t%d\n", employee.name, &employee.age, employee.employee_id, employee.gender, &employee.salary) != EOF)
        {
            printf("\n%s\t\t\t%s\t\t%d\t\t%s\t\t%d\n",
                   employee.name, employee.employee_id, employee.age, employee.gender, employee.salary);
            border();
        }
        tableStart("EMPLOYEE LIST END");
    }
    printf("\n\n1. Add Employee\n2. Back To Main Menu\nYour Choice: ");
    char choice;
    choice = getche();

    system("cls");

    switch (choice)
    {
    case '1':
        generateEmployee();
        break;
    case '2':
        menu();
        break;
    default:
        printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
    }
}
void border()
{
    printf("-------------------------------------------------------------------------------");
}

void tableStart(char level[20])
{
    printf("\n\n\t\t\t============= %s =============\n\n", level);
}
