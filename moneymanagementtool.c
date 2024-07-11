#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[100];
    char email[100];
    char phone[20];
    char modeOfPayment[20];
};

int displayDetails(struct data *ptr, int n)
{
    int f;
    char name[20];
    printf("Enter the name of the member to fetch details: ");
    scanf("%s", &name);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(name, ptr->name) == 0)
        {
            printf("Name of the member %d is %s\n", i + 1, ptr->name);

            printf("Email of the member %d is %s\n", i + 1, ptr->email);

            printf("Phone of the member %d is %s\n", i + 1, ptr->phone);

            printf("Mode of payment of the member %d is %s\n", i + 1, ptr->modeOfPayment);
        }
        ptr++;
    }
    printf("Do you want to continue for another event?  Enter 1 for YES  \nEnter 0 to exit:\n");
    scanf("%d", &f);
    return f;
}

void billcalc(char groupname[][100], int total, int n, int paid[])
{
    int option, i, ptg;

    do
    {
        printf("Please enter your choice : \n");
        printf("Enter 1 for equally splitting \n");
        printf("2 for unequal splitting ,\n");
        printf("3 for percentage share, :");
        scanf("%d", &option);
    } while (option != 1 && option != 2 && option != 3);
    if (option == 1)
    {
        int avg;
        printf("You have chosen to split equally ! \n");
        avg = (total / n);
        printf("Each person owes %d amount \n", avg);
    }
    else if (option == 2)
    {
        int unqamt[n];
        check(groupname, unqamt, n, total);
    }
    else if (option == 3)
    {
        int ptgamt[n];
        ptgcheck(groupname, total, n, 100, ptgamt);
    }
}

void check(char name[][100], int paid[], int n, int total)
{
    int i, sum, x;

    i = 0;
    sum = 0;
    x = 0;
    while (i < n - 1)
    {
        printf("How much did %s pay \n?", name[i]);
        scanf("%d", &paid[i]);

        sum = sum + paid[i];
        if (paid[i] <= total && sum <= total)
        {
            i = i + 1;
            if (sum == total)
            {
                x = i;
                i = n;
            }
        }
        else
        {
            sum = sum - paid[i];
        }
    }
    if (x > 0)
    {
        for (i = x; i <= n - 1; i++)
        {
            paid[i] = 0;
            printf("%s pays %d \n", name[i], paid[i]);
        }
    }
    else
    {
        paid[n - 1] = total - sum;
        printf("%s pays %d \n", name[n - 1], paid[n - 1]);
    }
}

void ptgcheck(char name[][100], int total2, int n, int total, int paid[])
{
    int i, sum, x;

    i = 0;
    sum = 0;
    x = 0;
    while (i < n - 1)
    {
        printf("Enter the percentage share of %s : \n", name[i]);
        scanf("%d", &paid[i]);
        sum = sum + paid[i];

        if (paid[i] <= total && sum <= total)
        {
            printf("%s's percentage share is %d \n", name[i], paid[i]);
            float shareAmount = paid[i] * ((float)total2 / 100);
            printf("%s's share amount is %.2f \n", name[i], shareAmount);
            i = i + 1;
            if (sum == total)
            {
                x = i;
                i = n;
            }
            sum = sum - paid[i];
        }
    }
    if (x > 0)
    {
        for (i = x; i < n - 1; i++)
        {
            paid[i] = 0;
            printf("%s's percentage share is %d \n", name[i], paid[i]);
            printf("%s's \% share amount is %d\n", name[i], (paid[i] * total2) / 100);
        }
        paid[n - 1] = total - sum;
        printf("%s's percentage share is %d\n", name[n - 1], paid[n - 1]);
        printf("%s's \% share amount is %d\n", name[n - 1], (paid[n - 1] * total2) / 100);
    }
}

void split(int t1, int t2, int indneg[], int indpos[], int avgdiff[], char name[][100], char event[])
{
    printf("Entered the split function!\n");
    int pos, neg, x, y, k, m;

    printf("Expenditure details for %s\n", event);
    for (k = 0; k < t1; k++)
    {
        x = indneg[k];
        for (m = 0; m < t2; m++)
        {
            neg = avgdiff[x];
            y = indpos[m];
            pos = avgdiff[y];
            if (abs(neg) > pos)
            {
                printf("%s should give Rs. %d to %s .\n", name[x], pos, name[y]);
                avgdiff[x] = avgdiff[x] + pos;
                avgdiff[y] = 0;
            }
            else
            {
                printf("%s should give Rs. %d to %s .\n", name[x], abs(neg), name[y]);
                avgdiff[x] = 0;
                avgdiff[y] = avgdiff[y] + neg;
            }
        }
    }
}

int main()
{
    printf("Social Money Management System:\nPROJECT DONE BY:  S.MEENAKSHI\n");
    int n, total, i, flag, ch, t1, t2, k, m;
    double avg;
    int x, y, pos, neg, percent, mainch;
    do
    {
        printf("Enter the no. of members: ");
        scanf("%d", &n);
    } while (n < 1);

    struct data details[n];

    char event[20];
    char name[n][100];

    int paid[n], avgdiff[n], indpos[n], indneg[n], percentage[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the member:%d ", i + 1);
        scanf("%s", &name[i]);
        strcpy(details[i].name, name[i]);

        printf("Enter the email of the member:%d ", i + 1);
        scanf("%s", &details[i].email);

        printf("Enter the phone of the member:%d ", i + 1);
        scanf("%s", &details[i].phone);

        printf("Enter the mode of payment of the member:%d ", i + 1);
        scanf("%s", &details[i].modeOfPayment);
    }
    flag = 1;
    while (flag == 1)
    {
        printf("Enter the name of the occasion: ");
        scanf("%s", &event);
        printf("Enter the total amount: ");
        scanf("%d", &total);
        do
        {
            printf("Enter 1 for calculating the expenditure before paying the bill.\n");
            printf(" Enter 2 to split the bill among members after paying : \n");
            scanf("%d", &mainch);
        } while (mainch != 1 && mainch != 2);

        if (mainch == 1)
        {
            billcalc(name, total, n, paid);
        }
        else if (mainch == 2)
        {
            check(name, paid, n, total);

            do
            {
                printf("How do you want to split the bill?\n");
                printf("Enter: 1 to split equally , 2 to split by percentage :\n");

                scanf("%d", &ch);
            } while (ch != 1 && ch != 2);

            if (ch == 1)
            {
                t1 = 0;
                t2 = 0;
                avg = ((float)total / n);

                printf("Average contribution amount for each person : %f \n", avg);
                for (k = 0; k <= n - 1; k++)
                {
                    avgdiff[k] = paid[k] - avg;

                    if (avgdiff[k] < 0)
                    {
                        indneg[t1] = k;
                        t1 = t1 + 1;
                    }
                    else
                    {
                        if (avgdiff[k] > 0)
                        {
                            indpos[t2] = k;
                            t2 = t2 + 1;
                        }
                    }
                }
                printf("going to split /n");
                split(t1, t2, indneg, indpos, avgdiff, name, event);
            }

            else if (ch == 2)
            {
                ptgcheck(name, total, n, 100, percentage);
                t1 = 0;
                t2 = 0;

                for (k = 0; k <= n - 1; k++)
                {
                    avgdiff[k] = (int)(paid[k] - (double)(total * percentage[k]) / 100);
                    if (avgdiff[k] < 0)
                    {
                        indneg[t1] = k;
                        t1 = t1 + 1;
                    }
                    else if (avgdiff[k] > 0)
                    {
                        indpos[t2] = k;
                        t2 = t2 + 1;
                    }
                }

                split(t1, t2, indneg, indpos, avgdiff, name, event);
            }
        }
        printf("Do you want to continue for another event?  Enter 1 for YES  \nEnter 2 for fetching the details of the user\nEnter 3 to exit:\n");
        scanf("%d", &flag);
        if (flag == 2)
        {
            flag = displayDetails(details, n);
        }
    }

    printf("Thank-you\n");
    return 0;
}