
char * nhapPassWord(){//hung bang con tro char
	printf("PassWord: ");
	fflush(stdin);
	char ch, pwd[20];
	int i = 0;
	while(1){
		ch = getch();
		if (ch == 13)//enter
		{
			pwd[i] = '\0';
			break;
		}
		else if (ch == 8)//backspace
		{
			if (i > 0)
			{
				printf("\b \b");
				i--;
			}
			
		}
		else 
		{
			pwd[i++] = ch;
			printf("*");
		}
	}//end while
	return pwd;
}

bool checkHacker(char * user, char * pwd);
bool dangNhap(MYSQL * conn, char *u)
{
	bool login = false;
	char user[20];
	char *pwd; 
	while(1)
	{
		printf ("\nUser: "); fflush(stdin); scanf("%s", user);
		pwd = nhapPassWord();
		//if (checkHacker(user, pwd))
		//{
		//	printf("This program is very security. Plase don't hack!");
		//}
		//else
		//{
			MYSQL_RES *res;
			MYSQL_ROW row;
			char q[100] = "select username from users where username = '";
			strcat(q, user);
			strcat(q, "' and password = '");
			strcat(q, pwd);
			strcat(q, "'");
			//printf("\n%s", q);
			mysql_query(conn, q);
			res = mysql_store_result(conn);

			try
			{
				printf("\nTruoc query");
				row = mysql_fetch_row(res);
				printf("\nSau query");
			}
			catch(char * c)
			{
				row = NULL;
				printf("\nError: %s", c);
			}		
			
			if (row==NULL)
			{
				printf("\nUser hoac Password sai.");
			}
			else
			{
				strcpy(user, row[0]);
				strcpy(u, user);
				
				system("cls");		
				printf("Login Success");
				Sleep(1000);
				login = true;
				break;
			}
		//}
	}
	return login;
}

bool checkHacker(char * user, char * pwd)
{
	int lenUser = strlen(user), lenPwd = strlen(pwd);
	int index = 0;
	if (lenUser > 5)
	{
		for(index = 0; index < lenUser - 1; index ++)
		{
			if (user[index] == 39) //"'"
			{
				int i = index;
				for (i = index; i < lenUser - 2; i++)
				{
					if ((user[index]=='-')&&(user[index +1]=='-') || (user[index]==';'))
					{	
						printf ("\nHacker Deteced.");
						return true;
					}
				}
			}
		}	
	}
	
	if (lenPwd > 5)
	{
		for(index = 0; index < lenPwd - 1; index ++)
		{
			if (pwd[index]==39) //"'"
			{
				int i = index;
				for (i = index; i < lenPwd - 2; i++)
				{
					if ((pwd[index]=='-')&&(pwd[index +1]=='-') || (pwd[index]==';'))
					{	
						printf ("\nHacker Deteced.");
						return true;
					}
				}
			}
		}	
	}
	
	return false;
}
