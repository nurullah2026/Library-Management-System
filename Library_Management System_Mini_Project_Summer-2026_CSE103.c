#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>

struct User
{
    char id[50];
    char username[50];
    char department[50];
    char phone[50];
    char password[50];
};

struct Book
{
    char id[50];
    char title[50];
    char name1[50];
    char name2[50];
    int quantity;
};

struct borrow_book
{
    char userid[50];
    char bookid[50];
    char title[50];
    char name1[50];
    char name2[50];
};

struct Request
{
    char userid[50];
    char title[50];
    char name1[50];
    char name2[50];
};

void admin();
void adminmenu();
void addabook();
void deleteabook();
void viewborrowedbooks();
void viewbookrequests();
void userinfo();
void deleteauser();
void viewallbooksadmin();
void searchabookadmin();

void user();
void usersignup();
void userlogin();
void usermenu();
void viewallbooksuser();
void searchabookuser();
void borrowabook();
void returnabook();
void requestforabook();

void MENU();
void amenu();
void umenu();

int main()
{
    printf("\n\n\n\t\t\t--------WELCOME TO LIBRARY MANAGEMENT SYSTEM--------\n");
    printf("\t\t\t1. ADMIN\n");
    printf("\t\t\t2. USER\n");
    printf("\t\t\t3. EXIT\n");
    printf("\t\t\tENTER YOUR CHOICE: ");
    char a; scanf(" %c",&a);
    switch(a)
    {
        case '1':
            admin();
            break;
        case '2':
            user();
            break;
        case '3':
            exit(0);
        default:
            printf("\n\t\t\tINVALID INPUT. PLEASE TRY AGAIN.\n");
            MENU();
    }
    return 0;
}
void admin()
{
    printf("\n\n\n\t\t\t---------------WELCOME TO ADMIN LOG IN--------------\n");
    char admin1[]="ADNAN";
    char admin2[]="SHEIKH";
    char admin3[]="FAHIMA";
    char admin4[]="TALHA";
    char admin5[]="PRETHA";
    char password[]="1234";
    int found=0;
    printf("\t\t\tENTER USERNAME: ");
    char tadmin[50]; scanf(" %s",tadmin);
    printf("\t\t\tENTER PASSWORD: ");
    char tpassword[50]; scanf(" %s",tpassword);
    if( strcmp(tpassword,password)==0 && ( strcmp(tadmin,admin1)==0 || strcmp(tadmin,admin2)==0 || strcmp(tadmin,admin3)==0 || strcmp(tadmin,admin4)==0 || strcmp(tadmin,admin5)==0) )
    {
        found=1;
        printf("\t\t\tADMIN LOG IN SUCCESSFUL. PLEASE CONTINUE.\n");
        adminmenu();
    }
    else if(found==0)
    {
        printf("\t\t\tINVALID USERNAME OR PASSWORD. PLEASE TRY AGAIN.\n");
        main();
    }
}
void MENU()
{
    main();
}
void user()
{
    printf("\n\n\n\t\t\t----------------WELCOME TO USER HOME----------------\n");
    printf("\t\t\t1. SIGN UP.\n");
    printf("\t\t\t2. LOG IN.\n");
    printf("\t\t\t3. GO BACK.\n");
    printf("\t\t\tENTER YOUR CHOICE: ");
    char a; scanf(" %c",&a);
    switch(a)
    {
        case '1':
            usersignup();
            break;
        case '2':
            userlogin();
            break;
        case '3':
            main();
            break;
        default:
            printf("\t\t\tINVALID INPUT. PLEASE TRY AGAIN.\n");
            main();
    }
}
void usersignup()
{
    printf("\n\t\t\t(WARNING: USE CAPITAL LETTERS ONLY!)\n");
    struct User a;
    FILE *usersignup = fopen("User_Sign_Up_Info.txt","a");
    printf("\n\n\n\t\t\t------------WELCOME TO USER REGISTRATION------------\n");
    printf("\t\t\tENTER USER ID: ");
    char id[50]; scanf(" %s",a.id);
    printf("\t\t\tENTER USER NAME: ");
    char username[50]; scanf(" %s",a.username);
    printf("\t\t\tENTER USER DEPARTMENT: ");
    char department[50]; scanf(" %s",a.department);
    printf("\t\t\tENTER USER PHONE NUMBER: ");
    char phone[50]; scanf(" %s",a.phone);
    printf("\t\t\tENTER USER PASSWORD: ");
    char password[50]; scanf(" %s",a.password);
    fprintf(usersignup,"%s %s %s %s %s\n",a.id,a.username,a.department,a.phone,a.password);
    fclose(usersignup);
    printf("\t\t\tUSER SIGN UP SUCCESSFUL. PLEASE LOG IN TO CONTINUE.\n");
    userlogin();
}
void userlogin()
{
    struct User a;
    FILE *userlogin = fopen("User_Sign_Up_Info.txt","r");
    printf("\n\n\n\t\t\t---------------WELCOME TO USER LOG IN---------------\n");
    printf("\t\t\tENTER USERNAME: ");
    char username[50]; scanf("%s",username);
    printf("\t\t\tENTER PASSWORD: ");
    char password[50]; scanf("%s",password);
    if( userlogin== NULL )
    {
        printf("\t\t\tPLEASE SIGN UP TO CONTINUE.\n");
        usersignup();
    }
    int found = 0;
    while( fscanf(userlogin,"%s %s %s %s %s\n",a.id,a.username,a.department,a.phone,a.password) == 5 )
    {
        if( strcmp(username,a.username)==0 && strcmp(password,a.password)==0 )
        {
            found=1;
            fclose(userlogin);
            printf("\t\t\tUSER LOG IN SUCCESSFUL. PLEASE CONTINUE.\n");
            usermenu();
        }
    }
    if(found==0)
    {
        fclose(userlogin);
        printf("\t\t\tINVALID USERNAME OR PASSWORD. PLEASE TRY AGAIN.\n");
        user();
    }
}
void adminmenu()
{
    printf("\n\n\n\t\t\t---------------WELCOME TO ADMIN PANEL---------------\n");
    printf("\t\t\t1. VIEW ALL BOOKS\n");
    printf("\t\t\t2. SEARCH A BOOK\n");
    printf("\t\t\t3. ADD A BOOK\n");
    printf("\t\t\t4. DELETE A BOOK\n");
    printf("\t\t\t5. VIEW BORROWED BOOKS\n");
    printf("\t\t\t6. VIEW BOOK REQUESTS\n");
    printf("\t\t\t7. USER INFORMATION\n");
    printf("\t\t\t8. DELETE A USER\n");
    printf("\t\t\t9. LOG OUT\n");
    printf("\t\t\tENTER YOUR CHOICE: ");
    char a; scanf(" %C",&a);
    switch(a)
    {
        case '1':
            viewallbooksadmin();
            break;
        case '2':
            searchabookadmin();
            break;
        case '3':
            addabook();
            break;
        case '4':
            deleteabook();
            break;
        case '5':
            viewborrowedbooks();
            break;
        case '6':
            viewbookrequests();
            break;
        case '7':
            userinfo();
            break;
        case '8':
            deleteauser();
            break;
        case '9':
            printf("\n\t\t\t\t        LOGGING OUT AS ADMIN.\n");
            main();
            break;
        default:
            printf("\n\t\t\t\t        INVALID INPUT. PLEASE TRY AGAIN.\n");
            amenu();
    }

}
void amenu()
{
    adminmenu();
}
void usermenu()
{
    printf("\n\n\n\t\t\t----------------WELCOME TO USER PANEL---------------\n");
    printf("\t\t\t1. VIEW ALL BOOKS\n");
    printf("\t\t\t2. SEARCH A BOOK\n");
    printf("\t\t\t3. BORROW A BOOK\n");
    printf("\t\t\t4. RETURN A BOOK\n");
    printf("\t\t\t5. REQUEST FOR A BOOK\n");
    printf("\t\t\t6. LOG OUT\n");
    printf("\t\t\tENTER YOUR CHOICE: ");
    char a; scanf(" %c", &a);
    while(1)
    {
        switch(a)
        {
        case '1':
            viewallbooksuser();
            break;
        case '2':
            searchabookuser();
            break;
        case '3':
            borrowabook();
            break;
        case '4':
            returnabook();
            break;
        case '5':
            requestforabook();
            break;
        case '6':
            printf("\n\t\t\t\t        LOGGING OUT AS USER.\n");
            main();
            break;
        default:
            printf("\t\t\t      INVALID INPUT. PLEASE TRY AGAIN.\n");
            umenu();
        }
    }
}
void umenu()
{
    usermenu();
}
void viewallbooksadmin()
{
    struct Book a;
    FILE *bookinfo = fopen("Book_Info.txt", "r");
    if (bookinfo == NULL)
    {
        printf("\n\t\t\tNO BOOKS ARE AVAILABLE.\n");
        adminmenu();
    }
    printf("\n\n\n\t\t\t------------------BOOK INFORMATION------------------\n");
    int b=0;
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        b++;
        printf("\n\t\t\t->BOOK-%d:\n",b);
        printf("\t\t\t  BOOK ID: %s\n",a.id);
        printf("\t\t\t  BOOK TITLE: %s\n",a.title);
        printf("\t\t\t  BOOK AUTHOR: %s %s\n",a.name1, a.name2);
        printf("\t\t\t  BOOK QUANTITY: %d\n",a.quantity);
    }
    if(b==0)
    {
        printf("NO BOOKS ARE AVAILABLE.\n");
    }
    fclose(bookinfo);
    adminmenu();
}
void viewallbooksuser()
{
    struct Book a;
    FILE *bookinfo = fopen("Book_Info.txt", "r");
    if (bookinfo == NULL)
    {
        printf("\n\t\t\tNO BOOKS ARE AVAILABLE.\n");
        usermenu();
    }
    printf("\n\n\n\t\t\t------------------BOOK INFORMATION------------------\n");
    int b=0;
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        b++;
        printf("\n\t\t\t->BOOK-%d:\n",b);
        printf("\t\t\t  BOOK ID: %s\n",a.id);
        printf("\t\t\t  BOOK TITLE: %s\n",a.title);
        printf("\t\t\t  BOOK AUTHOR: %s %s\n",a.name1, a.name2);
        printf("\t\t\t  BOOK QUANTITY: %d\n",a.quantity);
    }
    if(b==0)
    {
        printf("NO BOOKS ARE AVAILABLE.\n");
    }
    fclose(bookinfo);
    usermenu();
}
void searchabookadmin()
{
    struct Book a;
    char temp[50];
    int found = 0;
    FILE *bookinfo = fopen("Book_Info.txt", "r");
    if (bookinfo == NULL)
    {
        printf("\t\t\tNO BOOKS ARE AVAILABLE.\n");
        adminmenu();
    }
    printf("\n\t\t\t(WARNING: PLEASE USE CAPITAL LETTERS ONLY)\n\n\t\t\t-------------------SEARCHING BOOK-------------------\n\n\t\t\tEnter Book Title to search: ");
    scanf("%s", temp);
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        if (strcmp(a.title, temp) == 0)
        {
            found = 1;
            printf("\n\t\t\t\t--------BOOK FOUND--------\n");
            printf("\t\t\tBOOK ID: %s\n\t\t\tBOOK TITLE: %s\n\t\t\tBOOK AUTHOR: %s %s\n\t\t\tAVAILABLE QUANTITY: %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
            break;
        }
    }
    fclose(bookinfo);
    if (found==0)
    {
        printf("\t\t\tBook not found.\n");
    }
    adminmenu();
}
void searchabookuser()
{
    struct Book a;
    char temp[50];
    int found = 0;
    FILE *bookinfo = fopen("Book_Info.txt", "r");
    if (bookinfo == NULL)
    {
        printf("\t\t\tNO BOOKS ARE AVAILABLE.\n");
        usermenu();
    }
    printf("\n\t\t\t(WARNING: PLEASE USE CAPITAL LETTERS ONLY)\n\n\t\t\t-------------------SEARCHING BOOK-------------------\n\n\t\t\tEnter Book Title to search: ");
    scanf("%s", temp);
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        if (strcmp(a.title, temp) == 0)
        {
            found = 1;
            printf("\n\t\t\t\t--------BOOK FOUND--------\n");
            printf("\t\t\tBOOK ID: %s\n\t\t\tBOOK TITLE: %s\n\t\t\tBOOK AUTHOR: %s %s\n\t\t\tAVAILABLE QUANTITY: %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
            break;
        }
    }
    fclose(bookinfo);
    if (found==0)
    {
        printf("\t\t\tBook not found.\n");
    }
    usermenu();
}
void addabook()
{
    struct Book a;
    FILE *bookinfo = fopen("Book_Info.txt", "a");
    if (bookinfo == NULL)
    {
        printf("\t\t\tSYSTEM ERROR. PLEASE TRY AGAIN.\n");
        adminmenu();
    }
    printf("\n\t\t\t(WARNING: USE CAPITAL LETTERS ONLY!)\n");
    printf("\n\n\t\t\t----------------------ADD BOOK----------------------\n");
    printf("\t\t\tENTER BOOK ID: ");
    scanf("%s", a.id);
    printf("\t\t\tENTER BOOK TITLE: ");
    scanf("%s", a.title);
    printf("\t\t\tENTER AUTHORS FIRST NAME: ");
    scanf("%s", a.name1);
    printf("\t\t\tENTER AUTHORS LAST NAME: ");
    scanf("%s", a.name2);
    printf("\t\t\tENTER QUANTITY: ");
    scanf("%d", &a.quantity);
    fprintf(bookinfo, "%s %s %s %s %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
    printf("\n\t\t\tBOOK ADDED SUCCESSFULLY.\n");
    fclose(bookinfo);
    adminmenu();
}
void deleteabook()
{
    struct Book a; int found=0;
    FILE *bookinfo = fopen("Book_Info.txt","r");
    FILE *temp = fopen("Temp.txt","a");
    if(bookinfo==NULL || temp==NULL)
    {
        printf("\t\t\tSYSTEM ERROR. PLEASE TRY AGAIN.\n");
        adminmenu();
    }
    printf("\n\t\t\t(WARNING: USE CAPITAL LETTERS ONLY!)\n");
    printf("\n\n\t\t\t--------------------DELETE BOOK---------------------\n");
    printf("\t\t\tENTER BOOK ID TO REMOVE: ");
    char id[50]; scanf("%s",id);
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        if (strcmp(a.id, id) == 0)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%s %s %s %s %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
        }
    }
    fclose(bookinfo);
    fclose(temp);
    remove("Book_Info.txt");
    rename("Temp.txt", "Book_Info.txt");
    if (found==0)
    {
        printf("\t\t\tBOOK NOT FOUND. PLEASE ENTER A VALID BOOK ID.\n");
    }
    else
    {
        printf("\t\t\tBOOK REMOVED SUCCESSFULLY.\n");
    }
    adminmenu();
}
void userinfo()
{
    struct User a;
    FILE *userinfo = fopen("User_Sign_Up_Info.txt", "r");
    if (userinfo == NULL)
    {
        printf("\n\t\t\tNO USER INFORMATION CURRENTLY AVAILABLE.\n");
        adminmenu();
    }
    printf("\n\n\n\t\t\t---------------------ALL USERS----------------------\n");
    int b=0;
    while (fscanf(userinfo, "%s %s %s %s %s", a.id, a.username, a.department, a.phone, a.password) == 5)
    {
        b++;
        printf("\n\t\t\t->USER-%d:\n",b);
        printf("\t\t\t  USER ID: %s\n",a.id);
        printf("\t\t\t  USER NAME: %s\n",a.username);
        printf("\t\t\t  USER DEPARTMENT: %s\n",a.department);
        printf("\t\t\t  USER PHONE NUMBER: %s\n",a.phone);
    }
    if(b==0)
    {
        printf("\n\t\t\tNo user found\n");
    }
    fclose(userinfo);
    adminmenu();
}
void deleteauser()
{
    struct User a; int found=0;
    FILE *userinfo = fopen("User_Sign_Up_Info.txt","r");
    FILE *temp = fopen("Temp.txt","a");
    if(userinfo==NULL || temp==NULL)
    {
        printf("\t\t\tSYSTEM ERROR. PLEASE TRY AGAIN.\n");
        adminmenu();
    }
    printf("\n\n\t\t\t--------------------DELETE BOOK---------------------\n");
    printf("\t\t\tENTER USER ID TO REMOVE: ");
    char id[50]; scanf("%s",id);
    while (fscanf(userinfo, "%s %s %s %s %s\n", a.id, a.username, a.department, a.phone, &a.password) == 5)
    {
        if (strcmp(a.id, id) == 0)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "%s %s %s %s %s\n", a.id, a.username, a.department, a.phone, &a.password);
        }
    }
    fclose(userinfo);
    fclose(temp);
    remove("User_Sign_Up_Info.txt");
    rename("Temp.txt", "User_Sign_Up_Info.txt");
    if (found==0)
    {
        printf("\t\t\tUSER NOT FOUND. PLEASE ENTER A USER BOOK ID.\n");
    }
    else
    {
        printf("\t\t\tUSER REMOVED SUCCESSFULLY.\n");
    }
    adminmenu();
}
void borrowabook()
{
    struct Book a;
    struct borrow_book b;
    printf("\n\n\n\t\t\t-------------------BORROW A BOOK--------------------\n");
    printf("\t\t\tENTER USER ID: ");
    scanf(" %s", b.userid);
    printf("\t\t\tENTER BOOK ID TO BORROW: ");
    scanf(" %s", b.bookid);
    FILE *bookinfo = fopen("Book_Info.txt", "r");
    FILE *temp = fopen("temp.txt", "a");
    FILE *BORROW = fopen("Borrow_Info.txt", "a");
    if (bookinfo == NULL || BORROW == NULL || temp==NULL)
    {
        printf("\t\t\tSYSTEM ERROR. PLEASE TRY AGAIN.\n");
        adminmenu();
    }
    int found=0;
    while (fscanf(bookinfo, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
    {
        if (strcmp(a.id, b.bookid) == 0)
        {
            found = 1;
            if (a.quantity > 0)
            {
                a.quantity--;
                fprintf(BORROW, "%s %s %s %s %s\n", b.userid, b.bookid, a.title, a.name1, a.name2);
                printf("\t\t\tSUCCESS: YOU BORROWED '%s'. REMAINING STOCK: %d\n", a.title, a.quantity);
            }
            else
            {
                printf("\t\t\tSORRY: '%s' IS CURRENTLY OUT OF STOCK.\n", a.title);
            }
        }
        fprintf(temp, "%s %s %s %s %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
    }
    fclose(BORROW);
    fclose(bookinfo);
    fclose(temp);
    remove("Book_Info.txt");
    rename("temp.txt", "Book_Info.txt");
    if (found==0)
    {
        printf("\t\t\tERROR: BOOK ID %s IS NOT FOUND IN THE LIBRARY.\n", b.bookid);
    }
    usermenu();
}

void viewborrowedbooks()
{
    struct Book a;
    struct borrow_book b;
    FILE *borrow = fopen("Borrow_Info.txt","r");
    if(borrow==NULL)
    {
        printf("\n\t\t\tNO RECORDS ARE AVAILABLE.\n");
        adminmenu();
    }
    int c=0;
    printf("\n\n\t\t\t-----------------BORROW INFORMATION-----------------\n");
    while( fscanf(borrow, "%s %s %s %s %s\n",b.userid, b.bookid, a.title, a.name1, a.name2) == 5 )
    {
        c++;
        printf("\n\t\t\t->BOOK-%d:\n",c);
        printf("\t\t\t  USER ID: %s\n",b.userid);
        printf("\t\t\t  BOOK ID: %s\n",b.bookid);
        printf("\t\t\t  BOOK TITLE: %s\n",a.title);
        printf("\t\t\t  BOOK AUTHOR: %s %s\n",a.name1, a.name2);
    }
    if(c==0)
    {
        printf("\n\t\t\tNO RECORDS ARE AVAILABLE.\n");
    }
    fclose(borrow);
    adminmenu();
}
void returnabook()
{
    struct Book a;
    struct borrow_book b;
    int foundInBorrow = 0;
    printf("\n\n\n\t\t\t-------------------RETURN A BOOK--------------------\n");
    printf("\t\t\tENTER USER ID: ");
    char userID[50]; scanf("%s", userID);
    printf("\t\t\tENTER BOOK ID TO RETURN: ");
    char bookID[50]; scanf("%s", bookID);
    FILE *BORROW = fopen("Borrow_Info.txt", "r");
    FILE *btemp = fopen("btemp.txt", "w");
    if (BORROW == NULL || btemp == NULL)
    {
        printf("\t\t\tERROR: NO RECORD FOUND.\n");
        usermenu();
    }
    while (fscanf(BORROW, "%s %s %s %s %s\n",b.userid, b.bookid, b.title, b.name1, b.name2) == 5)
    {
        if (strcmp(userID, b.userid) == 0 && strcmp(bookID, b.bookid) == 0)
        {
            foundInBorrow = 1;
            fprintf(btemp, "%s %s %d\n", userID, bookID, a.quantity);
        }
    }
    fclose(BORROW);
    fclose(btemp);
    remove("Borrow_Info.txt");
    rename("btemp.txt", "Borrow_Info.txt");
    if (foundInBorrow==0)
    {
        printf("\t\t\tERROR: NO ACTIVE RECORD FOUND FOR USER ID %s & BOOK ID %s.\n", userID, bookID);
        usermenu();
    }
    FILE *BI = fopen("Book_Info.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    int bookFound = 0;
    if( BI==NULL || temp==NULL )
    {
        printf("\t\t\tSYSTEM ERROR. PLEASE TRY AGAIN.\n");
    }
    else
    {
        while (fscanf(BI, "%s %s %s %s %d", a.id, a.title, a.name1, a.name2, &a.quantity) == 5)
        {
            if (strcmp(a.id, bookID) == 0)
            {
                bookFound = 1;
                a.quantity++;
                printf("\t\t\tSUCCESS: BOOK '%s' RETURNED. UPDATED STOCK: %d\n", a.title, a.quantity);
            }
            fprintf(temp, "%s %s %s %s %d\n", a.id, a.title, a.name1, a.name2, a.quantity);
        }
        fclose(BI);
        fclose(temp);
        remove("Book_Info.txt");
        rename("temp.txt", "Book_Info.txt");
    }
    if (bookFound==0)
    {
        printf("\t\t\tWARNING: BORROW RECORD CLEARED, BUT BOOK WAS NOT FOUNF IN MASTER LIBRARY.\n");
    }
    usermenu();
}
void requestforabook()
{
    struct Request a;
    FILE *REQ = fopen("Requested_Books.txt", "a");
    if (REQ == NULL )
    {
        printf("\t\t\tSystem Error! Unable to open request file.\n");
        usermenu();
    }
    printf("\n\t\t\t(WARNING: USE CAPITAL LETTERS ONLY!)\n");
    printf("\n\n\n\t\t\t-----------------REQUEST A NEW BOOK-----------------\n");
    printf("\t\t\tENTER USER ID: ");
    scanf("%s", a.userid);
    printf("\t\t\tENTER BOOK TITLE (SINGLE WORD): ");
    scanf("%s", a.title);
    printf("\t\t\tENTER AUTHORS FIRST NAME: ");
    scanf("%s", a.name1);
    printf("\t\t\tENTER AUTHORS LAST NAME: ");
    scanf("%s", a.name2);
    fprintf(REQ,"%s %s %s %s\n",a.userid,a.title,a.name1,a.name2);
    fclose(REQ);
    printf("\n\t\t\tREQUEST SUBMITTED SUCCESSFULLY.\n");
    usermenu();
}
void viewbookrequests()
{
    struct Request a;
    FILE *requestinfo = fopen("Requested_Books.txt","r");
    if(requestinfo==NULL)
    {
        printf("\n\t\t\tNO BOOKS ARE AVAILABLE.\n");
    }
    printf("\n\t\t\t----------------REQUEST INFORMATION-----------------\n");
    int b=0;
    while( fscanf( requestinfo,"%s %s %s %s", a.userid, a.title, a.name1, a.name2) == 4)
    {
        b++;
        printf("\n\t\t\t->BOOK-%d:\n",b);
        printf("\t\t\t  USER ID: %s\n",a.userid);
        printf("\t\t\t  BOOK TITLE: %s\n",a.title);
        printf("\t\t\t  BOOK AUTHOR: %s %s\n",a.name1, a.name2);
    }
    if(b==0)
    {
        printf("\n\t\t\tNO BOOKS ARE AVAILABLE.\n");
    }
    fclose(requestinfo);
    adminmenu();
}
