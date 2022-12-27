#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

typedef struct user 
{
   char name[20];
   int dd,mm,yyyy;
   char uname[10];
   char passwd[10]; 
   int wallet;
}detail;
void signup();
void login();
void nextfunction(char name[20]);
void searchtrain();
int main()
{   
    int opt;
    while(1){
    printf("::::::::::::::::Welcome to KB travels:::::::::::::::::");
    printf("\n\t1.Sign up\n\t2.Log in\n\t3.Exit\n");
    printf("Choose an Option :");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        signup();
        break;
        case 2:
        login();
        break;
        case 3:
        break;
    }   
    } 
}
void signup()
{
    detail user,tmp;
    FILE *fp;
    int flag=0;
    fp=fopen("user.dat","ab+");
    printf("Enter Full Name :");
    fflush(stdin);
    gets(user.name); 
    printf("Enter Date Of Birth (dd/mm/yyyy):");
    scanf("%d/%d/%d",&user.dd,&user.mm,&user.yyyy);
    printf("Enter UserName :");
    fflush(stdin);
    gets(user.uname);
    printf("Enter Password :");
    gets(user.passwd);
    while(fread(&tmp,sizeof(user),1,fp)!=0)
    {
        if(strcmp(user.uname,tmp.uname)==0)
        {
            printf("User Already Exist...\n");
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        fwrite(&user,sizeof(user),1,fp);
        fclose(fp);
    }
}

void login()
{
    FILE *fp;
    fp=fopen("user.dat","rb");
    detail user;
    char uname[10],passwd[10];
    int flag=0;
    char ask;
    printf("Enter User Name :");
    fflush(stdin);
    gets(uname);
    printf("Enter Password :");
    gets(passwd);
    while(fread(&user,sizeof(user),1,fp)!=0)
    {
        if(strcmp(user.uname,uname)==0 && strcmp(user.passwd,passwd)==0)
        {   
            flag=1;
            system("cls");
            nextfunction(user.name);
        }
    }
    if(flag==0)
    {
        printf("Do You Want to signup (y/n) ? ");
        scanf("%c",&ask);
        if(ask=='y')
        {
            signup();
        }
        else
        {
            exit(0);
        }
    }
}


void nextfunction(char name[20])
{   
    int opt;
    printf("++++++++++++++++++++++++++++++++++++++Welcome To KB Travels+++++++++++++++++++++++++++++++\n\n");
    printf("Welcome %s,It's Nice To See You Here\n",name);
    printf("\t1.Search Train\n\t2.Book Train\n\t3.Cancel Train\n\t4.Exit\n");
    printf("Choose An Option :");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        searchtrain();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        default:
        printf("Wrong Input\n");
        exit(0);
    }
}

void searchtrain()
{
    FILE *fp;
    ad train,tmp;
    fp = fopen("train.dat", "rb");
    char bname[10], arname[10];
    int i=0;

    printf("Availbale Stations are :\n\n");
    while(fread(&train,sizeof(train),1,fp)!=0)
    {
        while(fread(&tmp,sizeof(tmp),1,fp)!=0)
        {
            if(strcmp(train.bst,tmp.bst)!=0 || strcmp(train.arst,tmp.arst)!=0)
            {
                continue;
            }
            else
            {
                printf("%s\t%s\n",train.bst,train.arst);
            }
        }
    }
    fclose(fp);
    fp = fopen("train.dat", "rb");
    printf("\nEnter Boarding Station :");
    fflush(stdin);
    gets(bname);
    printf("Enter Arrival Station :");
    gets(arname);
    printf("   Train Name\t\tTrain Number\tFrom\t\tTo\t\tDistance\tFare\n");
    while (fread(&train, sizeof(train), 1, fp) != 0)
    {
        if (strcmp(train.bst, bname) == 0 && strcmp(train.arst, arname) == 0)
        {   i++;
            printf("%d. %-23s%-14d%-16s%-19s%-15d%-7d\n",i, train.tname, train.tnum, train.bst, train.arst,train.dist,train.dist*5);
            printf("%-40c%2d:%-13d",' ',train.btm[0],train.btm[1]);
            printf("%d:%d\n",train.artm[0],train.artm[1]);
            printf("\n");
        }
    }
    printf("\n\n");
}