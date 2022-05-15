#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

struct person
{
    char name[100], address[500], email[250];
    long long int phone;
};

int getdata()
{
    struct person p;
    FILE *fp1;
    fp1 = fopen("phonebook.txt", "a");

    if (fp1 == NULL)
    {
        printf("File cannot be opened");
    }

    else
    {
        system("cls");
        printf("\nEnter the data:\n");
        printf("Enter name:");
        scanf("%s", &p.name);
        printf("Enter phone:");
        scanf("%lld", &p.phone);
        printf("Enter address:");
        scanf("%s", &p.address);
        printf("Enter email:");
        scanf("%s", &p.email);

        fprintf(fp1, "\nName: %s", p.name);
        fprintf(fp1, "\nphone: %lld ", p.phone);
        fprintf(fp1, "\naddress: %s", p.address);
        fprintf(fp1, "\nemail: %s", p.email);
    }

    fclose(fp1);
};

void display()
{
    FILE *f;
    char ch;
    f = fopen("phonebook.txt", "r");
    if (f == NULL)
    {
        printf("\nFile can't be open");
    }
    else
    {
        while ((ch = getc(f)) != EOF)
        {
            printf("%c", ch);
        }
    }
    fclose(f);
    getch();
};
void modify()
{
    struct person per1, per2;
    int f = 0, res;
    char nm[100], ch;
    FILE *fp1, *fp2;
    fp1 = fopen("phonebook.txt", "r+");
    fp2 = fopen("temp.txt", "a");
    printf("\nEnter Contact's Name to modify: ");
    scanf("%s", &nm);

    while (fscanf(fp1, "%s %lld %s %s", &per1.name, &per1.phone, &per1.address, &per1.email) != EOF)
    {
        res = strcmp(nm, per1.name);
        if (res == 0)
        {
            f = 1;
            printf("\nNEW DETAILS");
            printf("\nNew name: ");
            scanf("%s", &per2.name);
            printf("New phone number: ");
            scanf("%lld", &per2.phone);
            printf("New Address: ");
            scanf("%s", &per2.address);
            printf("New E-mail:");
            scanf("%s", &per2.email);
        }
    }
    fprintf(fp2, "\nName: %s", per2.name);
    fprintf(fp2, "\nphone:%lld ", per2.phone);
    fprintf(fp2, "\naddress:%s", per2.address);
    fprintf(fp2, "\nemail:%s", per2.email);

    if (f == 0)
        printf("\nRecord not found");

    else
        printf("\nRecord updated successfully");

    fclose(fp1);
    fclose(fp2);

    fp1 = fopen("phonebook.txt", "w"); // remove phonebook file
    fclose(fp1);

    fp1 = fopen("phonebook.txt", "a"); // rename temp file with phonebook.txt
    fp2 = fopen("temp.txt", "r");
    while ((ch = getc(fp2)) != EOF)
    {
        putc(ch, fp1);
    }
    fclose(fp1);
    fclose(fp2);
    fp1 = fopen("temp.txt", "w"); // remove temp file
    fclose(fp1);
};

void deleterecord()
{
    struct person p;
    FILE *f, *ft;
    int flag, res;
    char name[100], ch;
    f = fopen("phonebook.txt", "r+");
    if (f == NULL)
    {

        printf("CONTACT'S DATA NOT ADDED YET.");
    }
    else
    {
        ft = fopen("temp.txt", "a");
        if (ft == NULL)

            printf("file opening error");
        else

        {
            printf("\nEnter CONTACT'S NAME:");
            scanf("%s", &name);

            while (fscanf(f, "%s %lld %s %s", &p.name, &p.phone, &p.address, &p.email) != EOF)
            {
                res = strcmp(p.name, name);
                if (res == 0)
                {
                    flag = 1;
                }
            }
            fprintf(ft, "\nName: %s", p.name);
            fprintf(ft, "\nphone:%lld ", p.phone);
            fprintf(ft, "\naddress:%s", p.address);
            fprintf(ft, "\nemail:%s", p.email);

            if (flag == 0)
            {
                printf("NO CONACT'S RECORD TO DELETE.");
            }
            fclose(f);
            fclose(ft);

            f = fopen("phonebook.txt", "w"); // remove phonebook file
            fclose(f);

            f = fopen("phonebook.txt", "a"); // rename temp file with phonebook.txt
            ft = fopen("temp.txt", "r");
            while (fscanf(ft, "%s %lld %s %s", &p.name, &p.phone, &p.address, &p.email) != EOF)
            {
                fprintf(f, "\nName: %s", p.name);
                fprintf(f, "\nphone:%lld ", p.phone);
                fprintf(f, "\naddress:%s", p.address);
                fprintf(f, "\nemail:%s", p.email);
            }
            fclose(f);
            fclose(ft);
            f = fopen("temp.txt", "w"); // remove temp file
            fclose(f);
        }
    }
};

void searchrecord()
{
    struct person p;
    FILE *f;
    char name[100];
    int flag = 0, r;

    f = fopen("phonebook.txt", "r");
    printf("\nEnter name of person to search\n");
    scanf("%s", &name);
    while (fscanf(f, "%s %lld %s %s", &p.name, &p.phone, &p.address, &p.email) != EOF)
    {
        r = strcmp(p.name, name);
        if (r == 0)
        {
            flag = 1;
            printf("\n\tDetail Information About %s", name);
            printf("\nName:%s\nPhone no:%lld\naddress:%s\nE-mail:%s", p.name, p.phone, p.address, p.email);
        }
    }
    if (flag == 0)
        printf("record not found");
    fclose(f);
    getch();
};

void delay(int number_of_seconds)
{
    int milli_seconds = 250 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
};

void timer()
{
    int i;
    printf("\t");
    for (i = 0; i < 5; i++)
    {
        delay(1);
        printf("* ");
    }
    printf("\tConnecting to phonebook\t\t");
    for (i = 0; i < 5; i++)
    {
        delay(1);
        printf("* ");
    }
};

int main()
{
    int choice, size, i;
    do
    {
        
        printf("\nEnter choice \n1. Entering Persons record\n2. Displaying All Records\n3. Modifying Person Record\n4. Delete a record\n5. Search a record\n6. EXIT\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            timer();
            getdata();
        }

        break;
        case 2:
        {
            timer();
            display();
            getch();
        }
        break;
        case 3:
        {
            timer();
            modify();
            getch();
        }
        break;
        case 4:
        {
            timer();
            deleterecord();
            getch();
        }
        break;
        case 5:
        {
            timer();
            searchrecord();
            getch();
        }
        break;
        case 6:
        {
            printf("Exit");
        }
        break;
        default:
        {
            printf("Enter choice from 1 - 6");
        }
        }
    } while (choice != 6);
    return 0;
}