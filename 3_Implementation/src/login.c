int login( long int username, long int password)
{   int a=0;
   /* printf("%ld %ld",username,password);
    getch();*/
    //if(strcmp(username,105305)==0 && strcmp(password,105305)==0)
    if( (username == 105305 )&&(password == 105305) )
    {   a=1;
        return a;
        a=0;

    }
    else
    {
        a=0;
        return a;
    }

    /*int a=0;
	int i=0;
  char username[10];//c=' ';
    char password[10];//code[10];
    //char user[10]="user";
    //char pass[10]="pass";
    do
    {
       printf("        Welcome To Rental Vehicle Service       \n");
        printf("    Enter the Username and Password to login    \n");
        printf("Enter the username:\n");
        scanf("%s",&username);
        printf("Enter the password:\n");
        scanf("%s",&password);
		if(strcmp(username,"105305")==0 && strcmp(password,"105305")==0)
        {
            printf("        You are Successfully logged in      \n");
            printf("        Welcome To Rental Vehicle Service       \n");
            a=1;
            return a;

            getch();//holds the screen
            break;
        }
        else
        {
           printf("     Sorry, Login unsuccessful    \n");
            i++;
        }


    }while(i<=2);

    if(i>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        getch();

    }
		system("cls");*/
}
