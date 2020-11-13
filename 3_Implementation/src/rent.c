#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
struct details{
  int vehiclenumber;
  char name;
  char aadhaarnumber;
  char address;
  char phonenumber;
  char emailid;
}s;
int rents(int vehiclenumber,char name,char address,char aadhaarnumber,char phonenumber,char emailid )
{   //system("cls");
    //int vehiclenumber,
    int a;
    int b = 0;
    FILE *fp;
    fp = fopen("rent", "a");
    //add:
    /*printf("\n\n\tEnter the vehicle number you want to book: ");
    scanf("%d",&vehiclenumber);*/
    a = available(vehiclenumber);
    if(a==0)
    {
        s.vehiclenumber = vehiclenumber;
        s.name= name;
        s.address = address;
        s.aadhaarnumber = aadhaarnumber;
        s.phonenumber = phonenumber;
        s.emailid = emailid;
        b=1;
        return b;
    }
    else
    {   b=0;
        return b;
        /*printf("This vehicle number already exits");
        goto add;*/
    }
/*
    printf("\n\n\tEnter your name: ");
    scanf("%s",&s.name);
    printf("\n\n\tEnter your Aadhaar Number: ");
    scanf("%s",&s.aadhaarnumber);
    printf("\n\n\tEnter your address: ");
    scanf("%s",&s.address);
    printf("\n\n\tEnter your Phone number: ");
    scanf("%s",&s.phonenumber);
    printf("\n\n\tEnter your Emailid: ");
    scanf("%s",s.emailid);*/
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}
