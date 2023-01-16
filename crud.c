#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student
{
    char first_name[20];
    char last_name[20];
    int npm;
    char Class[10];
    char vill[30];
    char noTelp[14];
};

void main()
{
    int choice;

    while (choice != 5)
    {
        printf("\t\t\t=====UK PENCAK SILAT GUNADARMA 2022=====");
        printf("\n\n\n\t\t\t\t     1. Add Student\n");
        printf("\t\t\t\t     2. Students Records\n");
        printf("\t\t\t\t     3. Search Student\n");
        printf("\t\t\t\t     4. Delete Student\n");
        printf("\t\t\t\t     5. Exit\n");
        printf("\t\t\t\t    _____________________\n");
        printf("\t\t\t\t    Pilih angka [1-5] : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            addstudent();
            system("cls");

            break;
        case 2:
            system("cls");
            studentrecord();
            printf("\n\t\t\t\t  press any key to exit..... \n");
            getch();
            system("cls");

            break;
        case 3:
            system("cls");
            searchstudent();
            printf("\n\t\t\t\t  Press any key to exit.......\n");
            getch();
            system("cls");

            break;
        case 4:
            system("cls");
            delete ();
            printf("\n\t\t\t\tPress any key to exit.......\n");
            getch();
            system("cls");

            break;
        case 5:
            system("cls");
            printf("\n\t\t\t\tThank you, for used this software.\n\n");
            getch();
            exit(0);
            break;
        default:
            system("cls");
            printf("\n\t\t\t\t\tEnter a valid number\n\n");
            printf("\t\t\t\tPress any key to continue.......");
            getch();
            system("cls");
            break;
        }
    }
    getch();
}

void addstudent()
{

    char another;
    FILE *fp;
    int n, i;
    struct student info;
    do
    {
        system("cls");
        printf("\t\t\t\t---------Add Students Info=======\n\n\n");
        fp = fopen("information.text", "a");
        system("cls");

        printf("\n\t\t\tEnter First Name    : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\tEnter Last Name     : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\tEnter NPM [8 digit] : ");
        scanf("%d", &info.npm);
        printf("\n\t\t\tEnter Class         : ");
        scanf("%s", &info.Class);
        printf("\n\t\t\tEnter Address       : ");
        scanf("%s", &info.vill);
        printf("\n\t\t\tEnter Phone Number  : ");
        scanf("%s", &info.noTelp);
        printf("\n\t\t\t______________________________\n");

        if (fp == NULL)
        {
            fprintf(stderr, "can't open file");
        }
        else
        {
            printf("\t\t\tRecord stored successfuly\n");
        }

        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);

        printf("\t\t\tYou want to add another record?(y/n) : ");

        scanf("%s", &another);

    } while (another == 'y' || another == 'Y');
}

void studentrecord()
{

    FILE *fp;

    struct student info;
    fp = fopen("information.text", "r");

    printf("\t\t\t\t*********STUDENTS RECORD********\n\n\n");

    if (fp == NULL)
    {

        fprintf(stderr, "can't open file\n");
        exit(0);
    }
    else
    {
        printf("\t\t\t\tRecords :\n");
        printf("\t\t\t\t___________\n");
    }

    while (fread(&info, sizeof(struct student), 1, fp))
    {
        printf("\n\t\t\t\tStudent Name  : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\tNPM           : %d", info.npm);
        printf("\n\t\t\t\tClass         : %s", info.Class);
        printf("\n\t\t\t\tVillage/City  : %s", info.vill);
        printf("\n\t\t\t\tPhone Number  : %s", info.noTelp);
        printf("\n\t\t\t\t________________________________\n");
    }
    fclose(fp);
}

void searchstudent()
{
    struct student info;
    FILE *fp;
    int npm, found = 0;

    fp = fopen("information.text", "r");
    printf("\t\t\t\t@@@@@@@@@ SEARCH STUDENTS RECORD @@@@@@@@@\n\n\n");
    printf("\t\t\tEnter NPM  : ");
    scanf("%d", &npm);

    while (fread(&info, sizeof(struct student), 1, fp) > 0)
    {
        if (info.npm == npm)
        {
            found = 1;
            printf("\n\n\t\t\tStudent Name : %s %s", info.first_name, info.last_name);
            printf("\n\t\t\tNPM            : %d", info.npm);
            printf("\n\t\t\tClass          : %s", info.Class);
            printf("\n\t\t\tAddress        : %s", info.vill);
            printf("\n\t\t\tPhone Number   : %s", info.noTelp);
            printf("\n\t\t\t______________________________________\n");
        }
    }

    if (!found)
    {
        printf("\n\t\t\tRecord not found\n");
        printf("\n\t\t\t\tMake sure your NPM is correct ... \n");
        getch();
        system("cls");
        searchstudent();
    }

    fclose(fp);
}

void delete()
{
    struct student info;
    FILE *fp, *fp1;

    int found = 0;
    int npm;

    printf("\t\t\t\t---------DELETE STUDENTS RECORD---------\n\n\n");
    fp = fopen("information.text", "r");
    fp1 = fopen("temp.text", "w");
    printf("\t\t\t\tEnter NPM : ");
    scanf("%d", &npm);
    if (fp == NULL)
    {
        fprintf(stderr, "can't open file\n");
        exit(0);
    }

    while (fread(&info, sizeof(struct student), 1, fp))
    {
        if (info.npm == npm)
        {

            found = 1;
        }
        else
        {
            fwrite(&info, sizeof(struct student), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if (!found)
    {
        printf("\n\t\t\tRecord not found\n");
        printf("\n\t\t\t\tMake sure your NPM is correct ... \n");
        getch();
        system("cls");
        delete ();
    }
    if (found)
    {
        remove("information.text");
        rename("temp.text", "information.text");

        printf("\n\t\t\t\tRecord deleted succesfully\n");
    }
}
