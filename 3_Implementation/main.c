/**
* @file main.c
*/

/**
* Header files are first included to do the basic input and output operations.
*/

#include <stdio.h>
#include <stdlib.h>
//#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include "testlogin.h"
/**
* Structure is created to store the required details.
*/

struct details{
  int vehiclenumber;
  char name[20];
  char aadhaarnumber[15];
  char address[20];
  char phonenumber[10];
  char emailid[20];
}s;

/**
*First the user enters the userid and password and the details are checked using the login function.
*/
int login(int username, int password)
{

	int i=0;
    do
    {
		if(username==105305&& password==105305)
        {
            return 1;
            break;
        }
        else
        {
            i++;
            return 2;
        }


    }while(i<=2);

    if(i>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        //getch();

    }
		system("cls");
}
/**
*This function is used to positioning the details while viewing the records.
*/

void gotoxy(int x, int y)
{
	COORD CR;
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}
/**
*This function is used to check whether the given vehicle number is present in the records.
*/
int available(int vn)
{
    FILE *fp;
    fp = fopen("rent", "r");
    while (!feof(fp))
    {
        fread(&s, sizeof(s), 1, fp);

        if (vn == s.vehiclenumber)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
/**
*This function is used to add all the given data to the records.
*/
int rents(int vehiclenumber,char nam[10],char address[10],char aadhaarnumber[10],char phonenumber[10],char emailid[10] )
{   system("cls");
    int ad;
    FILE *fp;
    fp = fopen("rent", "a");

    ad = available(vehiclenumber);
    if(ad==0)
    {

        s.vehiclenumber=vehiclenumber;
        strcpy(s.name, nam);
        strcpy(s.address, address);
        strcpy(s.aadhaarnumber, aadhaarnumber);
        strcpy(s.phonenumber, phonenumber);
        strcpy(s.emailid, emailid);
        fwrite(&s, sizeof(s), 1, fp);
        fclose(fp);
        return 1;
    }
    else
    {
      // fclose(fp);
       return 2;
    }
}
/**
*This function is used to view the records.
*/

int view()
{   int j=9;
    system("cls");
    FILE *fp1;
    fp1 = fopen("rent", "r");
    gotoxy(1,6);
	printf("Vehicle Number ");
	gotoxy(15,6);
	printf("  NAME ");
	gotoxy(30,6);
    printf("Address ");
	gotoxy(45,6);
    printf("Aadhar Number ");
	gotoxy(60,6);
	printf("Phone Number ");
	gotoxy(75,6);
	printf("EMAIL ");
	gotoxy(100,6);

    while (fread(&s, sizeof(s), 1, fp1))
    {
        gotoxy(1,j);
		printf("%d",s.vehiclenumber);
		gotoxy(16,j);
		printf("  %s",s.name);
		gotoxy(31,j);
		printf("%s",s.address);
		gotoxy(46,j);
		printf("%s",s.aadhaarnumber);
		gotoxy(61,j);
		printf("%s",s.phonenumber);
		gotoxy(75,j);
		printf("%s\n",s.emailid);
		gotoxy(101,j);
		j++;
    }
    printf("\n");
   // getch();
    return 1;
    fclose(fp1);
}


/**
*This function is used to edit the details of the vehicle from the records.
*/
int edit(int vn,char nam[10],char address[10],char aadhaarnumber[10],char phonenumber[10],char emailid[10] )
{
    int av;
    FILE *fpt;
    FILE *fpo;
    int d;
    av = available(vn);
    printf("%d",av);
    if (av == 0)
    {
        return 2;
    }
    else
    {
        fpo = fopen("rent", "r");
        fpt = fopen("temp", "w");
        while (fread(&s, sizeof(s), 1, fpo))
        {
            d = s.vehiclenumber;
            if (d != vn)
                fwrite(&s, sizeof(s), 1, fpt);
            else
            {   s.vehiclenumber=vn;
                strcpy(s.name, nam);
                strcpy(s.address, address);
                strcpy(s.aadhaarnumber, aadhaarnumber);
                strcpy(s.phonenumber, phonenumber);
                strcpy(s.emailid, emailid);
                fwrite(&s, sizeof(s), 1, fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo = fopen("rent", "w");
        fpt = fopen("temp", "r");
        while (fread(&s, sizeof(s), 1, fpt))
        {
            fwrite(&s, sizeof(s), 1, fpo);
        }
        fclose(fpo);
        fclose(fpt);
        return 1;
    }
}
/**
*This function is used to search the particular from the records.
*/
int search(int v)
{
    int  present;
    present = available(v);
    if (present == 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
*This function is used to delete the details of vehicle from the records.
*/
int delet(int v)
{
     FILE *fpo;
     FILE *fpt;
     int d;
     if (available(v) == 0)
      {
       return 2;
      }
     else
     {
          fpo = fopen("rent", "r");
          fpt = fopen("temp", "w");
          while (fread(&s, sizeof(s), 1, fpo))
          {
               d = s.vehiclenumber;
               if (d != v)
               fwrite(&s, sizeof(s), 1, fpt);
          }
          fclose(fpo);
          fclose(fpt);
          fpo = fopen("rent", "w");
          fpt = fopen("temp", "r");
          while (fread(&s, sizeof(s), 1, fpt))

                fwrite(&s, sizeof(s), 1, fpo);

          fclose(fpo);
          fclose(fpt);
          return 1;
     }

}

/*
void cases()
{    system("cls");
//    char customername;
	int choice;
	while (1)      // INFINITE LOOP
	{   system("cls");
	    printf("\n\n\t\tEnter the choice you want to perform");
	    printf("\n\n\n Rent a vehicle          ----Press 1");
	    printf("\n\n View the rental records ----Press 2");
	    printf("\n\n Edit the rental records ----Press 3");
	    printf("\n\n Search the rental record----Press 4");
	    printf("\n\n Delete the rental record----Press 5");
	    printf("\n\n Exit                    ----Press 6");
	    printf("\n\n Enter your choice = ");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1:
                rent();
                break;
            case 2:
                view();
                break;
            case 3:
                edit();
                break;
            case 4:
                search();
                break;
            case 5:
                delete();
                break;
            case 6:
				system("cls");
				exit(0);
				break;
            default:
                system("cls");
				printf("Invalid Choice");
				printf("\n Press any key to continue");
				getch();
        }




	}
}*/
/**
*This main function is used handle the file and call test function.
*/
int main()   //MAIN FUNCTION
{   FILE *fp;
    fp = fopen("rent", "w");
    fclose(fp);
    test_main();

}


