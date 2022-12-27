#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct admin
{
    char tname[20];
    int tnum;   
    char bst[10];
    char arst[10];
    int btm[2];
    int artm[2];
    int dist;
} ad;

const char username[10] = "Bapun235";
const char password[10] = "Bapun@123";

void addtrain();
void showtrain();
void removetrain();
void searchtrain();
int main()
{
    ad train;
    char uname[10], passwd[10];
    int choice;
    
    printf("\tEnter Username :");
    gets(uname);
    printf("\tEnter Password :");
    gets(passwd);
    while(1)
    {
    if (strcmp(uname, username) == 0 & strcmp(passwd, password) == 0)
    {
        printf(":::::::::::::::::::Welcome to KB Travels:::::::::::::::::::::\n\n");
        printf("\t1.Add Train\n\t2.Remove Train\n\t3.Show all Train\n\t4.SearchTrain\n\t5.Exit\n");
        printf("Choose an Option :");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            addtrain();
            break;
        case 2:
            removetrain();
            break;
        case 3:
            showtrain();
            break;
        case 4:
            searchtrain();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Input\n");
        }
    }
    else
    {
        printf("Sorry !! You are not authorised for this\n");
        exit(0);
    }
    }
}

void addtrain()
{
    ad train, temp;
    int flag=0;
    FILE *fp,*nm;
    char name[10];
    fp = fopen("train.dat", "ab+");
    printf("Enter Train Name :");
    fflush(stdin);
    gets(train.tname);
    printf("Enter Train Number :");
    scanf("%d", &train.tnum);
    while (fread(&temp, sizeof(temp), 1, fp) != 0)
    {
        if (train.tnum == temp.tnum)
        {
            printf("Sorry !! Train Already Exist ....\n");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Enter Boarding Station :");
        fflush(stdin);
        gets(train.bst);
        printf("Enter Arrival Station :");
        gets(train.arst);
        printf("Enter Distance Between Two Station :");
        scanf("%d",&train.dist);
        printf("Enter Boarding Time :\n");
        printf("Hour :");
        scanf("%d", &train.btm[0]);
        printf("Minute :");
        scanf("%d", &train.btm[1]);
        printf("Enter Arrival Time :\n");
        printf("Hour :");
        scanf("%d", &train.artm[0]);
        printf("Minute :");
        scanf("%d", &train.artm[1]);
        fwrite(&train, sizeof(train), 1, fp);
        fclose(fp);
    }
    printf("\n\n");
}

void showtrain()
{
    ad train;
    FILE *fp;
    fp = fopen("train.dat", "rb");
    printf("Train Name\tTrain Number\t\tFrom\t\tTo\n\n");
    while (fread(&train, sizeof(train), 1, fp) != 0)
    {
        printf("%-18s%-22d%-15s%-15s\n", train.tname, train.tnum, train.bst, train.arst);
    }
    printf("\n\n");
}

void removetrain()
{
    FILE *fp, *tmp;
    ad train;
    fp = fopen("train.dat", "rb+");
    tmp = fopen("temp.dat", "wb");
    int num;
    printf("Enter Train Number :");
    scanf("%d", &num);
    while (fread(&train, sizeof(train), 1, fp) != 0)
    {
        if (train.tnum == num)
        {
            printf("Train Removed Successfully\n");
        }
        else
        {
            fwrite(&train, sizeof(train), 1, tmp);
        }
    }
    fclose(fp);
    fclose(tmp);
    remove("train.dat");
    rename("temp.dat", "train.dat");
    printf("\n\n");
}

void searchtrain()
{
    FILE *fp;
    ad train;
    fp = fopen("train.dat", "rb");
    char bname[10], arname[10];
    printf("Enter Boarding Station :");
    fflush(stdin);
    gets(bname);
    printf("Enter Arrival Station :");
    gets(arname);
    printf("Train Name\tTrain Number\t\tFrom\t\tTo\n");
    while (fread(&train, sizeof(train), 1, fp) != 0)
    {
        if (strcmp(train.bst, bname) == 0 && strcmp(train.arst, arname) == 0)
        {
            printf("%-18s%-22d%-15s%-15s\n", train.tname, train.tnum, train.bst, train.arst);
        }
    }
    printf("\n\n");
}