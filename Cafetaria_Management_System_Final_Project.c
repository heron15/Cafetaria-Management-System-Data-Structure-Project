#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 50
typedef struct foodItem FoodItem;
typedef struct order_hist orderHis;

struct foodItem
{
    int indexNum;
    char disNam[SIZE];
    double price;
    FoodItem *adress;
};

FoodItem *head;

double total_income = 0.0;
int cus_id = 1;
int today_customer = 0;

struct order_hist
{
    int customer_id;
    int item[10][2];
    double amount;
    char date[SIZE];
    orderHis *adress1;
};

orderHis *head1;

void insert(int index, char itemName[], double price)
{
    FoodItem *temp = (FoodItem *)malloc(sizeof(FoodItem));
    temp->indexNum = index;
    strcpy(temp->disNam, itemName);
    temp->price = price;
    temp->adress = NULL;

    if (temp == NULL)
    {
        head = temp;
    }
    else
    {
        temp->adress = head;
        head = temp;
    }
}
void display()
{
    printf("\n                  -------------                     \n");
    printf("_______________________MENU____________________________________\n");
    printf("                  -------------                       \n");

    printf("\nIndex---------------Item Name-------------------------price\n");
    FoodItem *temp = head;
    while (temp != NULL)
    {
        printf("\n  %d------------------%s----------------------%.2lf tk\n", temp->indexNum, temp->disNam, temp->price);
        temp = temp->adress;
    }
    printf("_______________________________________________________________\n\n");
}

void order()
{
    int a[10][2];
    int n, i = 0, j = 0;

    do
    {
        printf("\nPleaze enter the FOOD ID NUMBER OF ITEM AND ITS QUENTITY:\n");

        for (i = 0; i < 2; i++)
        {
            scanf("%d", &a[j][i]);
        }
        j++;
        printf("\nYou want more item?\n\n===========\n| 1. Yes. |\n| 2. No.  |\n===========\n");
        printf("\nChose a option: ");
        scanf("%d", &n);
    } while (n == 1);

    getchar();
    double total_amount = 0.0;
    char name[SIZE];
    char date[SIZE];
    printf("\nEnter name: ");
    gets(name);
    printf("Enter Date: ");
    gets(date);

    printf("\n                      ========\n");
    printf("----------------------| BILL |---------------------");
    printf("\n                      ========\n");

    printf("\n  Name: %s\n", name);
    printf("  Date: %s\n", date);

    int k = 0;
    for (k = 0; k < j; k++)
    {
        FoodItem *temp = head;
        while (temp->indexNum != a[k][0])
        {
            temp = temp->adress;
        }
        printf("\n  %d--------%s--------%d-------%.2lf\n", temp->indexNum, temp->disNam, a[k][1], (a[k][1] * (temp->price)));
        total_amount += (a[k][1] * (temp->price));
    }

    printf("\n___________________________________________________\n\n");
    printf("  Total payable amount is:------------%.2lf\n", total_amount);
    printf("\n---------------------------------------------------\n");

    orderHis *temp2 = (orderHis *)malloc(sizeof(orderHis));
    temp2->amount = total_amount;
    temp2->customer_id = cus_id++;
    strcpy(temp2->date, date);

    int p, s;

    for (p = 0; p < j; p++)
    {
        for (s = 0; s < 2; s++)
        {
            temp2->item[p][s] = a[p][s];
        }
    }
    if (head1 == NULL)
    {
        head1 = temp2;
    }
    else
    {
        temp2->adress1 = head1;
        head1 = temp2;
    }
    today_customer++;
    total_income += total_amount;
}

void display_his()
{
    printf("\n                      -----------------");
    printf("\n----------------------| Order History |-------------------------");
    printf("\n                      -----------------\n");

    printf("\n   serial no-----------------date---------------Total Amount\n");

    orderHis *temp = head1;

    while (temp != NULL)
    {
        printf("\n      %d-------------------%s------------------%.2lf\n", temp->customer_id, temp->date, temp->amount);
        temp = temp->adress1;
    }
    printf("\n----------------------------------------------------------------\n\n");
}

int main()
{
    printf("\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  \n");
    printf("\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ \n");
    printf("\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ \n");
    printf("\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| \n");

    insert(1, "Burger-----", 80.00);
    insert(2, "Pizza------", 90.00);
    insert(3, "Hot Coffee-", 30.00);
    insert(4, "Cold Coffee", 50.00);
    insert(5, "Tea--------", 15.00);
    insert(6, "Sandwich---", 70.00);

    int n;

    do
    {
        printf("\n===================");
        printf("\n| 1. Food Part    |\n| 2. Adimin Panel |\n| 3. Exit         |\n");
        printf("===================\n");
        printf("\nChose a option: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("");
            int ex;

            do
            {
                int m;
                printf("\n==================");
                printf("\n| 1. Food List   |\n| 2. Order Foood |\n");
                printf("==================\n");
                printf("\nChose a option: ");
                scanf("%d", &m);

                switch (m)
                {
                case 1:
                    display();
                    break;

                case 2:
                    order();
                    break;

                default:
                    printf("\nWrong option select!!\n");
                    break;
                }
                printf("\n================");
                printf("\n| 1. Food Part |\n| 2. Main Menu |\n");
                printf("================\n");
                printf("\nChose a option: ");
                scanf("%d", &ex);
            } while (ex == 1);
            break;

        case 2:
            printf("\n");
            int e;
            char username[SIZE];
            char password[SIZE];

            printf("Enter Username: ");
            scanf("%s", username);
            printf("Enter Password: ");
            scanf("%s", password);

            if ((strcmp(username, "heron") && strcmp(password, "1234")) == 0)
            {
                do
                {
                    printf("\n======================================\n");
                    printf("| 1. Add new dish.                   |\n");
                    printf("| 2. Today total income.             |\n");
                    printf("| 3. Today total number of customer. | \n");
                    printf("| 4. List of item.                   |\n");
                    printf("| 5. Order history.                  |\n");
                    printf("======================================\n");

                    int cn;

                    printf("\nChose a option: ");
                    scanf("%d", &cn);

                    switch (cn)
                    {

                    case 1:
                        printf(" ");
                        char itn[SIZE];
                        double pri;
                        int ind;

                        getchar();
                        printf("\nEnter item name: ");
                        gets(itn);
                        printf("Enter item price: ");
                        scanf("%lf", &pri);
                        printf("Enter item index Number: ");
                        scanf("%d", &ind);

                        insert(ind, itn, pri);
                        break;

                    case 2:
                        printf("\n____________________________________\n\n");
                        printf("|   Today total income: %.2lf    |\n", total_income);
                        printf("____________________________________\n");
                        break;

                    case 3:
                        printf("\n____________________________________\n\n");
                        printf("|   Today total customer: %d    |\n", today_customer);
                        printf("____________________________________\n");
                        break;

                    case 4:
                        display();
                        printf("\n");
                        break;

                    case 5:
                        display_his();
                        break;

                    default:
                        printf("\nWrong Option choses!!");
                        break;
                    }

                    printf("\n====================\n");
                    printf("| 1. Admine Panel. |\n");
                    printf("| 2. Main Menu.    |\n");
                    printf("====================\n");

                    printf("\nChose a option: ");
                    scanf("%d", &e);

                } while (e == 1);
            }
            else
            {
                printf("\nWrong Password and Username!!\n");
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\nWrong option select!!\n");
            break;
        }

    } while (n != 3);

    return 0;
}
