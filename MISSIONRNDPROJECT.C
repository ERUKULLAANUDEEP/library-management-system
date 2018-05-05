#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
struct id
{
    int idnum;
    struct book *ptr;
};
 struct id *id1;
struct book
{
char bookname[25];
struct book *next;
};
struct book *head;
int main()
{
    int ch,j=1,i=0,k=0;
    while(i<1)
    {
        printf("_");

        i++;
        }
      SetColor(12);
          printf("\t\t\tTHIS PROJECT IS IMPLEMENTED USING FILES\n");
          printf("\t\t\tNOTE:MAKE SURE YOUR CAPSLOCK IS OFF\n");
   SetColor(15);
    printf("\t\t\t1.ADMIN INFORMATION\n");
    printf("\t\t\t2.PROJECT INFORMATION\n");
    printf("\t\t\t3.ACCESSING PROJECT\n");
    printf("\t\tenter your choice...\n");
     scanf("%d",&ch);
    switch(ch)
    {
        case 1:admininfo();
        break;
        case 2:projectinfo();
        break;
        case 3:library(j);
        break;

    }

}
    void library(int j)
    {
        int ch,i;
        clrscr();
        printf("\t\t\t\t1.LIBRARIAN VIEW\n");
        printf("\t\t\t\t2.STUDENT PURPOSE\n");
        printf("\t\t\t\t\tenter your choice..");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:librarianview();
            break;
            case 2:studentpurpose(j);
            break;
        }
    }
    void studentpurpose(int j)
    {
         char password[8], c,user[10];
    char permpassword[8]="akhil";
   int index = 0,i;
    char username[8]="anudeep";
        printf("\t\t\tUSERNAME:");
        scanf("%s",user);
        printf("\n\t\t\tPASSWORD:_");
       {
   while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       password[index++] = c;
       putch('*');
   }
   password[index] = '\0';

        if(strcmp(password,permpassword)==0&&(strcmp(user,username)==0))
        {
            printf("ACCESS GRANTED");
            clrscr();
            librarymanagement();
            return 0;
        }
        else{
                if(j!=4)
                {
            printf("\n\t\t\tACCESS DENIED\n\t\twant to try again press 1 if not press 0\n\t\t");
            scanf("%d",&i);
                }
            if(i==1)
            {
                j++;
                if(j==4)
                {
                    printf("your access is temporarily denied close and try again");
                    return 0;
                }
                else
                {
                library(j);
                }
            }
            else
            {
                return 0;
            }
        }
    }
    }
    void clrscr()
    {
        system("cls");
    }
    void admininfo()
    {
        int ch;
        FILE *fp;
        char info[50];
        fp=fopen("admininfo.txt","r");
        while(!feof(fp))
        {
            fscanf(fp,"%s",info);
            fflush(stdin);
            printf("%s ",info);
        }
        fclose(fp);
        theme();

    }
void projectinfo()
{
    FILE *fa;
    char pro[50];
    SetColor(1);
    fa=fopen("projectinfo.txt","r");
    while(!feof(fa))
    {
        fscanf(fa,"%s",pro);
        fflush(stdin);
        printf("%s ",pro);
    }
    SetColor(15);
    fclose(fa);
     SetColor(4);
    printf("WAIT UNTIL PAGE GETS LOADED..");
    SetColor(15);
    Sleep(10000);

    clrscr();
    theme();
}
void theme()
{
    int ch,j=1;

    printf("\n\t\t\t1.ADMIN INFORMATION\n");
    printf("\t\t\t2.PROJECT INFORMATION\n");
    printf("\t\t\t3.ACCESSING PROJECT\n");
    printf("\t\tenter your choice...\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:admininfo();
        break;
        case 2:projectinfo();
        break;
        case 3:library(j);
        break;

    }
}
void librarymanagement()
{
    int ch,i,j,k;
     SetColor(9);
    for(i=15; i>=1; --i)
    {
        for(j=0; j < 15-i; ++j)
            printf("    ");

        for(j=i; j <= 2*i-1; ++j)
            printf("*   ");

        for(j=0; j < i-1; ++j)
            printf("*   ");

        printf("\n");
    }
    printf("********************************************************************************************************************\n");
    printf("\t\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM\n");
      printf("********************************************************************************************************************\n");

    printf("\t\t\t\t\t\t\t1.ISSUING\n");
    printf("\t\t\t\t\t\t\t2.RETURNING\n");
    printf("\t\t\t\t\t\t\t3.SEARCHING BASED ON BOOK\n");
    printf("\t\t\t\t\t\t\t4.VIEWING BOOKS ISSUED TO IDNUMBERS\n");
    printf("\t\t\t\t\t\t\t5.SEARCHING BASED ON IDNUMBERS\n");
    printf("\t\t\t\t\t\t\t6.MAIN MENU\n");
    printf("\t\t\t\t\t\t\t7.EXIT\n");
    printf("\n\n\t\t\t\t\t\t\tENTER YOUR CHOICE:");
    scanf("%d",&ch);
    SetColor(15);
    if(ch==1)
    {
        issuing();
    }
    if(ch==2)
    {
       returning();
    }
    if(ch==3)
    {
        searchingbasedonbook();
    }
    if(ch==4)
    {
        viewingidnums();
    }
    if(ch==5)
    {
        searchingbasedonidnums();
    }
    if(ch==6)
    {
        library(0);
    }
    else
    {
        exit(0);
    }
}
void issuing()
{
    int n,data;
    FILE *fd;
    fd=fopen("anu.txt","a");
    id1=(struct id *)malloc(sizeof(struct id));
    SetColor(13);
    printf("enter idnum:");
    SetColor(15);
    scanf("%d",&data);
    SetColor(13);
    printf("ENTER HOW MANY BOOKS:\n");
    SetColor(15);
    scanf("%d",&n);
    fprintf(fd,"%d\t",n);

    insertion(n,fd);
    idnumattach(data);
    printf("ISSUED SUCCESSFULLY\n");
    fclose(fd);
     SetColor(12);
     printf("wait until menu page is loaded..");
    SetColor(15);
    Sleep(3000);
    clrscr();
librarymanagement();
    return 0;
}
void insertion(int n,FILE *fa)
{
    //FILE *fa;
   // fa=fopen("anu.txt","a");
    struct book *newbook,*temp;
    struct id *temp2;
    char data[25],i=2;
    head=(struct book *)malloc(sizeof(struct book));
     SetColor(12);
    printf("\\t\t\tNOTE:GIVE BOOKNAMES ALONG WITH REFERENCEID EXCLUDINGSPACEPARANTHESIS IN BETWEEN\n");
     SetColor(13);
    printf("BOOKNAME:");
    scanf("%s",head->bookname);
    fprintf(fa,"%s\t",head->bookname);
    head->next=NULL;
    temp=head;

    while(i<=n)
    {
        newbook=(struct book*)malloc(sizeof(struct book));
        SetColor(13);
         printf("BOOKNAME:");
         scanf("%s",newbook->bookname);
        fprintf(fa,"%s\t",newbook->bookname);
         newbook->next=NULL;
         temp->next=newbook;
         temp=temp->next;
         i++;
    }
    id1->ptr=head;
     fprintf(fa,"\n",newbook->bookname);
fclose(fa);
SetColor(15);
}
void idnumattach(int data)
{
    FILE *fa;
     fa=fopen("hater.txt","a");
    struct id *id1;
    id1=(struct id *)malloc(sizeof(struct id));
    id1->idnum=data;
    id1->ptr=head;
    //head=id1;
   // temp2 = head;
       printf("%d\n",id1->idnum);
       fprintf(fa,"%d\n",id1->idnum);
        while(id1->ptr!= NULL)
        {
            printf("%s\n", id1->ptr->bookname);
            id1->ptr =id1->ptr->next;
        }
fclose(fa);
}
void returning()
{
    FILE *fp,*fa,*fc;
    int id,fileid,idrow,i=0,j=0,noofbooks;
    char book[25],retbook[25];
    SetColor(13);
    printf("IDNUMBER:");
    SetColor(15);
    scanf("%d",&id);
    fp=fopen("hater.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&fileid);
        if(fileid==id)
        {
            idrow=i;
            break;
        }
        i++;
    }
    fclose(fp);
   // idrow=0;
    printf("i=%d",idrow);
    SetColor(13);
    printf("\nBOOKNAME:");
    SetColor(15);
    scanf("%s",retbook);
    fa=fopen("anu.txt","r");
    fc=fopen("anudwwp.txt","w");
    while(!feof(fa))
    {
        if(idrow==j)
        {
        fscanf(fa,"%d",&noofbooks);
        fprintf(fc,"%d",noofbooks);
        fprintf(fc,"\t");
        while(noofbooks>=1)
        {
            fscanf(fa,"%s",book);
            if(strcmp(retbook,book)==0)
            {
                noofbooks=noofbooks-1;
                fscanf(fa,"%s",book);
            }
            fprintf(fc,"%s",book);
            fprintf(fc,"\t");
            noofbooks--;
        }
          fprintf(fc,"\n");
        }
        else
        {

        fscanf(fa,"%d",&noofbooks);
        fprintf(fc,"%d",noofbooks);
        fprintf(fc,"\t");
        while(noofbooks>=1)
        {
            fscanf(fa,"%s",book);
             fprintf(fc,"%s",book);
             fprintf(fc,"\t");
            noofbooks--;
        }
          fprintf(fc,"\n");

    }
    j++;

}
fclose(fa);
fclose(fc);
remove("anu.txt");
rename("anudwwp.txt","anu.txt");
SetColor(12);
     printf("wait until menu page is loaded..");
    SetColor(15);
    Sleep(3000);
clrscr();
    librarymanagement();
}

void librarianview()
{
   passwordprotected();
    int select;
    int i,j,k=0;
    SetColor(9);
   for(i=1; i<=15; ++i, k=0)
    {
    for(j=1; j<=15-i; ++j)
        {
            printf("    ");
        }
        while(k != 2*i-1)
        {

            printf("*   ");
            ++k;
        }
        printf("\n");

    }
    SetColor(15);
    printf("\t\t\t\tWELCOME TO LIBRARY MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t\t1.LIST OF BOOKS IN LIBRARY\n");
    printf("\t\t\t\t\t2.ADD NEW BOOKS IN LIBRARY\n ");
    printf("\t\t\t\t\t3.MAIN MENU\n");
    printf("\t\t\t\t\t4.EXIT\n");
    SetColor(9);
    for(i=15; i>=1; --i)
    {
        for(j=0; j < 15-i; ++j)
            printf("    ");

        for(j=i; j <= 2*i-1; ++j)
            printf("*   ");

        for(j=0; j < i-1; ++j)
            printf("*   ");

        printf("\n");
    }
    SetColor(15);
    printf("\t\t\t\tenter your selection..");
     scanf("%d",&select);
    switch(select)
    {
    case 1:librarybooksinfo();
        break;
    case 2:addbookstolibrary();
        break;
    case 3:library(0);
        break;
        case 4:exit(0);
    }
}
void addbookstolibrary()
{
   FILE *fa;
   char *book=(char *)malloc(sizeof(char)*30);
   fa=fopen("libraryinfo.txt","a");
   printf("\t\t\tENTER THE NAME OF BOOK TO BE ADDED IN THE LIBRARY\n\t\t\t\t\t");
   scanf("%s",book);
   fprintf(fa,"\n%s",book);
   fclose(fa);
      SetColor(12);
     printf("wait until menu page is loaded..");
    SetColor(15);
    Sleep(3000);

    librarianview();

}
void librarybooksinfo()
{
    FILE *fa;
    char book[50];
    int i=0;
    fa=fopen("libraryinfo.txt","r");
    if(fa==NULL)
    {
        printf("FILE NOT FOUND");
    }
    else
    {
      //  SetColor(1);
    printf("\n\t\t\t\tTHESE ARE THE BOOKS IN LIBRARY\n\n");
    SetColor(15);
     while(!feof(fa))
     {
         fscanf(fa,"%s",book);
         printf("\t\t->%s\n",book);
           i++;
           /*if(i==3)
           {
               printf("\n\n");
               i=0;
           }*/
     }
    }
    fclose(fa);
    SetColor(12);
     printf("wait until menu page is loaded..");
    SetColor(15);
    Sleep(3000);

    librarianview();
}
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
void searchingbasedonbook()
{
    FILE *fp;
    int i=0,j=0,k=0,val;
    char str[25];
    char book[25];
    printf("\t\t\t\tBOOKNAME:");
    scanf("%s",str);
    //printf("java-%s",str);
    fp=fopen("anu.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&val);
       // printf("%d",val);
        while(val>=1)
        {
            fscanf(fp,"%s",book);
        if(strcmp(book,str)==0)
        {
             k++;
            findingidnum(i,&str);
            }
        val--;
        }
        i++;
        j++;
    }
    if(k==0)
    {
        printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        printf("\n\t\t\t\t\xDBTHIS BOOK IS NOT ISSUED\xDB");
         printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    }
   }

  void findingidnum(int i,char *str)
  {
      SetColor(6);
     FILE *fa;
     int id,j=0,m=0;
     char *bookname=(char *)malloc(sizeof(char)*25);
     fa=fopen("hater.txt","r");
     while(*str!='\0')
     {
         bookname[m]=*str;
         m++;
         str++;
     }
     bookname[m]='\0';
     while(!feof(fa))
     {
      fscanf(fa,"%d",&id);
      if(i==j)
      {
           printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
          printf("\t\t\t\t %s BOOK ISSUED TO IDNUMBER:%d\n",bookname,id);
      }

     j++;
     }
    //  printf("\n\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
     rewind(fa);
      SetColor(15);
      printf("wait till the page is loaded..");
    Sleep(3000);
    clrscr();
librarymanagement();
    return 0;
  }

void viewingidnums()
{
    FILE *fp;
    int id;
    fp=fopen("hater.txt","r");
    if(fp==NULL)
    {
        printf("FILE CANNOT BE OPENED");
    }
    else
    {
        printf("\t\t\tBOOKS ARE ISSUED TO THESE PERSONS WITH IDNUMBERS..\n\n");
     while(!feof(fp))
     {
         fscanf(fp,"%d",&id);
         printf("\t\t\t\t\tIDNUMBER:%d\n",id);
     }
      fclose(fp);
 SetColor(15);
 printf("wait till the page is loaded..");
    Sleep(3000);
    clrscr();
librarymanagement();
    return 0;

    }
}
void searchingbasedonidnums()
{
    SetColor(10);
    FILE *fp,*fa,*fc;
    int id,temp,i=1,j=1,temp2;
    char book[50];
    fp=fopen("hater.txt","r");
    printf("IDNUMBER:");
    SetColor(15);
    scanf("%d",&id);
    while(fp!=EOF)
    {

        fscanf(fp,"%d",&temp);
        if(temp==id)
        {

         break;
        }
        i++;
    }

    fa=fopen("anu.txt","r");
    if(fa==NULL)
    {
        printf("file not found");
    }
    while(!feof(fa))
    {
        SetColor(10);
        if(j==i)
        {
            fscanf(fa,"%d",&temp2);
              while(temp2>=1)
        {
            fscanf(fa,"%s",book);
            printf("%s\t",book);
            temp2--;
        }
        }
        fscanf(fa,"%d",&temp2);
        while(temp2>=1)
        {
            fscanf(fa,"%s",book);
            temp2--;
        }
        j++;

    }
     SetColor(15);
     SetColor(4);
     printf("wait till the page is loaded..");
    Sleep(3000);
    clrscr();
    SetColor(15);
librarymanagement();
    return 0;
}
void passwordprotected()
{
char password[8], c,user[10];
    char permpassword[10]="password";
   int index = 0,i;
    char username[8]="library";
        printf("\t\t\tUSERNAME:");
        scanf("%s",user);
        printf("\n\t\t\tPASSWORD:_");
       {
   while((c = getch()) != 13){
       if(index < 0)
           index = 0;
       if(c == 8){
           putch('\b');
           putch(NULL);
           putch('\b');
           index--;
       continue;
       }
       password[index++] = c;
       putch('*');
   }
   password[index] = '\0';

        if(strcmp(password,permpassword)==0&&(strcmp(user,username)==0))
        {
            printf("ACCESS GRANTED");
            return 0;
        }
        else{
            printf("access denied");
            clrscr();
            theme();
    }
       }
}


