#include <stdio.h>
#include <string.h>

#define EMPLOYEE_FILE "data/employee.txt"
#define SALES_TARGET_FILE "data/sales_target.txt"
#define SALES_TARGETS_FILE "data/sales_targets.txt"
#define SALES_HISTORY_FILE "data/sales_history.txt"
#define SALES_HISTORIES_FILE "data/sales_histories.txt"

typedef struct
{
    char name[20];
    int age;
    char employee_id[10];
    char gender[10];
    int salary;
} Employee;

Employee employee;

typedef struct
{
    char employee_id[10];
    char month[10];
    int amount;
} SalesTarget;

SalesTarget sales_target;

typedef struct
{
    char employee_id[10];
    char month[10];
    int amount;
} SalesHistory;

SalesHistory sales_history;

typedef struct
{
    char employee_id[10];
    char month[10];
    int target;
    int sale;
    float selling_rate;

} SalesTargetHistory;

typedef struct
{
    char *employee_id;
    char *month;
    float rate;

} SellingRate;

SellingRate selling_rate;

int main()
{
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
            displaySalesTarget();
            break;

        case '3':
            displaySalesHistory();
            break;
        case '4':
            displayBestEmployee();
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

void generateTarget()
{
    FILE *file;
    file = fopen(SALES_TARGET_FILE, "a");
    if (file == NULL)
    {
        printf("Something went wrong!\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%s", sales_target.employee_id);
    printf("\nEnter Target Month: ");
    scanf("%s", sales_target.month);
    printf("\nEnter Target Amount: ");
    scanf("%d", &sales_target.amount);
    fprintf(file, "%s\t\t%s\t\t%d\n", sales_target.employee_id, sales_target.month, sales_target.amount);
    fclose(file);
    displaySalesTarget();
}

void generateHistory()
{
    FILE *file;
    file = fopen(SALES_HISTORY_FILE, "a");
    if (file == NULL)
    {
        printf("Something went wrong!\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%s", sales_history.employee_id);
    printf("\nEnter History Month: ");
    scanf("%s", sales_history.month);
    printf("\nEnter History Amount: ");
    scanf("%d", &sales_history.amount);
    fprintf(file, "%s\t\t%s\t\t%d\n", sales_history.employee_id, sales_history.month, sales_history.amount);
    fclose(file);
    displaySalesHistory();
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
    fclose(file);
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
        displayEmployee();
    }
}

void displaySalesTarget()
{
    FILE *file;
    file = fopen(SALES_TARGET_FILE, "r");

    if (file == NULL)
    {
        printf("Error in reading or does not exist the file '%s'", SALES_TARGET_FILE);
        return;
    }
    else
    {
        tableStart("SALES TARGET LIST START");
        printf("\nEMPLOYEE_ID\t\tMONTH\t\tAMOUNT\n");
        border();
        while (fscanf(file, "%s\t\t%s\t\t%d\n", sales_target.employee_id, sales_target.month, &sales_target.amount) != EOF)
        {
            printf("\n%s\t\t\t%s\t\t%d\n", sales_target.employee_id, sales_target.month, sales_target.amount);
            border();
        }
        tableStart("SALES TARGET LIST END");
    }
    fclose(file);
    printf("\n\n1. Add Target\n2. Back To Main Menu\nYour Choice: ");
    char choice;
    choice = getche();

    system("cls");

    switch (choice)
    {
    case '1':
        generateTarget();
        break;
    case '2':
        menu();
        break;
    default:
        printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
        displaySalesTarget();
    }
}

void displaySalesHistory()
{
    FILE *file;
    file = fopen(SALES_HISTORY_FILE, "r");

    if (file == NULL)
    {
        printf("Error in reading or does not exist the file '%s'", SALES_HISTORY_FILE);
        return;
    }
    else
    {
        tableStart("SALES HISTORY LIST START");
        printf("\nEMPLOYEE_ID\t\tMONTH\t\tAMOUNT\n");
        border();
        while (fscanf(file, "%s\t\t%s\t\t%d\n", sales_history.employee_id, sales_history.month, &sales_history.amount) != EOF)
        {
            printf("\n%s\t\t\t%s\t\t%d\n", sales_history.employee_id, sales_history.month, sales_history.amount);
            border();
        }
        tableStart("SALES HISTORY LIST END");
    }
    printf("\n\n1. Add History\n2. Back To Main Menu\nYour Choice: ");
    char choice;
    choice = getche();

    system("cls");

    switch (choice)
    {
    case '1':
        generateHistory();
        break;
    case '2':
        menu();
        break;
    default:
        printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
        displaySalesHistory();
    }
}

void displayBestEmployee()
{
    int choice;
    printf("\nSelect the month\n\n1. January\n2. February\n3. March\n4. April\n5. May\n6. June\n7. July\n8. August\n9. September\n10. October\n11. November\n12. December\n13. Back To Main Menu\nYour choice: ");
    scanf("%d", &choice);
    system("cls");

    char *month;
    switch (choice)
    {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    case 13:
        menu();
        break;
    default:
        printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
        displayBestEmployee();
    }
    findMonthWiseTargetAndHistory(month);
}

void findMonthWiseTargetAndHistory(char *month[])
{
    int historyCount;
    getTargets(month);
    historyCount = getHistories(month);
    calculateBestEmployee(historyCount);
    printf("\n\n1. Again Calculate\n2. Back To Main Menu\nYour Choice: ");
    char choice;
    choice = getche();

    system("cls");
    switch (choice)
    {
    case '1':
        displayBestEmployee();
        break;
    case '2':
        menu();
        break;
    default:
        printf("\n\n\t\t---------- Wrong Choice -----------\n\n");
        displayBestEmployee();
    }
}

void getTargets(char *month[])
{
    FILE *file, *targets;
    file = fopen(SALES_TARGET_FILE, "r");
    targets = fopen(SALES_TARGETS_FILE, "w");

    if (file == NULL)
    {
        printf("Error in reading or does not exist the file '%s'", SALES_TARGET_FILE);
        return;
    }
    else
    {
        while (fscanf(file, "%s\t\t%s\t\t%d\n", sales_target.employee_id, sales_target.month, &sales_target.amount) != EOF)
        {
            if (strcmp(sales_target.month, month) == 0)
            {
                fprintf(targets, "%s\t\t%s\t\t%d\n", sales_target.employee_id, sales_target.month, sales_target.amount);
            }
        }
    }

    fclose(file);
    fclose(targets);
}

int getHistories(char *month[])
{
    FILE *file, *histories;
    file = fopen(SALES_HISTORY_FILE, "r");
    histories = fopen(SALES_HISTORIES_FILE, "w");
    int i = 0;
    if (file == NULL)
    {
        printf("Error in reading or does not exist the file '%s'", SALES_HISTORY_FILE);
        return;
    }
    else
    {
        while (fscanf(file, "%s\t\t%s\t\t%d\n", sales_history.employee_id, sales_history.month, &sales_history.amount) != EOF)
        {
            if (strcmp(sales_target.month, month) == 0)
            {
                fprintf(histories, "%s\t\t%s\t\t%d\n", sales_history.employee_id, sales_history.month, sales_history.amount);
                i++;
            }
        }
    }

    fclose(file);
    fclose(histories);

    return i;
}

void calculateBestEmployee(int historyCount)
{
    if (historyCount > 0)
    {
        FILE *histories, *targets;
        histories = fopen(SALES_HISTORIES_FILE, "r");
        targets = fopen(SALES_TARGETS_FILE, "r");

        SalesTargetHistory sales_target_history[historyCount];

        if (histories == NULL || targets == NULL)
        {
            printf("Error in reading or does not exist the file '%s' or '%s'", SALES_HISTORIES_FILE, SALES_TARGETS_FILE);
            return;
        }
        else
        {
            int i = 0;
            while (fscanf(histories, "%s\t\t%s\t\t%d\n", sales_target_history[i].employee_id, sales_target_history[i].month, &sales_target_history[i].sale) != EOF)
            {
                i++;
            }

            int j = 0;
            selling_rate.rate = 0.0;

            while (fscanf(targets, "%s\t\t%s\t\t%d\n", sales_target_history[j].employee_id, sales_target_history[j].month, &sales_target_history[j].target) != EOF)
            {
                sales_target_history[j].selling_rate = sales_target_history[j].sale / (float)sales_target_history[j].target;

                if (sales_target_history[j].selling_rate > selling_rate.rate)
                {
                    selling_rate.rate = sales_target_history[j].selling_rate;
                    selling_rate.employee_id = sales_target_history[j].employee_id;
                    selling_rate.month = sales_target_history[j].month;
                }

                j++;
            }

            tableStart("TARGET AND SALES LIST START");
            printf("\nEMPLOYEE_ID\t\tMONTH\t\tTARGET\t\tSALE\t\tSELLING_RATE\n");
            border();

            for (int k = 0; k < i; k++)
            {
                printf("\n%s\t\t\t%s\t\t%d\t\t%d\t\t%.2f\n", sales_target_history[k].employee_id, sales_target_history[k].month, sales_target_history[k].target, sales_target_history[k].sale, sales_target_history[k].selling_rate);
                border();
            }
            tableStart("TARGET AND SALES LIST END");

            printf("\n\n\n\t\t\t Congratulation! %s is the best employee of %s\n\n\n", selling_rate.employee_id, selling_rate.month);
        }
    }
    else
    {
        printf("\n\t\tRelated data not found!\n");
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
