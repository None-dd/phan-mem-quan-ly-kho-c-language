void themtaikhoan(MYSQL *conn)
{
	printf("\nThem tai khoan moi.");
	printf("\nUsername: ");
	fflush(stdin);
	char u_new[20], *p_new, *p_renew;
	fflush(stdin);
	scanf("%[^\n]s", u_new);
	p_new = nhapPassWord();
	printf("\nNhap lai ");
	p_renew = nhapPassWord();
	printf("\n%s", p_new);
	printf("\n%s", p_renew);
	if (strcmp(p_new, p_renew))
	{
		printf("\nNhap lai mat khau khong dung.");
		getch();
		return;
	}
	if (!strcmp(p_new, p_renew))
	{
		MYSQL_RES *res;
		char q[100];
		strcpy(q, "insert into users (username, password, privilege) values ('");
		strcat(q, u_new);
		strcat(q, "', '");
		strcat(q, p_new);
		strcat(q, "', '1')");
		if(!mysql_query(conn, q))
		{
			printf("\nThem thanh cong");
		}
		else
		{
			printf("\nThem that bai");
			printf("Error %d: %s", mysql_errno(conn), mysql_error(conn));
		}
	}
	getch();
	return;
}

int xoataikhoan(MYSQL *conn, char * user)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	printf("\nXoa tai khoan.");
	printf("\nUsername can xoa: ");
	fflush(stdin);
	char u_new[20], *p_new;
	fflush(stdin);
	scanf("%[^\n]s", u_new);
	printf("\nPassword cua Username can xoa: ");
	p_new = nhapPassWord();
	
	char q[100];
	strcpy(q, "delete from users where username='");
	strcat(q, u_new);
	strcat(q, "' and '");
	strcat(q, p_new);
	strcat(q, "'");
	char q_check[100];
	strcpy(q_check, "select username from users where username='");
	strcat(q_check, u_new);
	strcat(q_check, "' and password='");
	strcat(q_check, p_new);
	strcat(q_check, "'");
	
	mysql_query(conn, q_check);
	res = mysql_store_result(conn);
	try
	{
		row = mysql_fetch_row(res);
	}
	catch(char *c)
	{
		row = NULL;
	}
	if (row)
	{
		if(!mysql_query(conn, q))
		{
			printf("\nXoa thanh cong.");
			if (!strcmp(user, u_new))
			{
				printf("\nBan vua xoa tai khoan dang login, ban phai dang nhap lai vao chuong trinh.");
				getch();
				return 1;
			}
		}
		else 
		{
			printf("\nXoa khong thanh cong. Xem tai Username va Password.");
		}
	}
	else {
		printf("\nXoa khong thanh cong. Xem tai Username va Password.");
	}

	getch();
	return 0;
}

void doimatkhau(MYSQL *conn, char * u)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	char q_check[100], *p_old, *p_new, *p_renew;
	char  q_update[100];
	printf("\nNhap mat khau cu.");
	p_old = nhapPassWord();
	printf("%s", p_old);
	strcpy(q_check, "select username from users where username='");
	strcat(q_check, u);
	strcat(q_check, "' and password='");
	strcat(q_check, p_old);
	strcat(q_check, "'");
	
	mysql_query(conn, q_check);
	res = mysql_store_result(conn);
	try
	{
		row = mysql_fetch_row(res);
	}
	catch(char *c)
	{
		row= NULL;
	}
	
	if(row)
	{
		printf("\nNhap mat khau moi.");
		p_new = nhapPassWord();
		printf("\nNhap lai mat khau moi.");
		p_renew = nhapPassWord();
		
		if (!strcmp(p_old, p_renew))
		{
			strcpy(q_update, "update users set password='");
			strcat(q_update, p_new);
			strcat(q_update, "' where username='");
			strcat(q_update, u);
			strcat(q_update, "'");
			if (!mysql_query(conn, q_update))
			{
				printf("\nThay doi thanh cong.");
				getch();
			}
			else
			{
				printf("Thay doi that bai.");
				printf("Error %d: %s", mysql_errno(conn), mysql_error(conn));
				getch();
			}
		}
		else
		{
			printf("\nNhap lai mat khau moi khong dung.");
			getch();
		}
	}
	else 
	{
		printf("\nSai mat khau cu.");
		getch();
		return ;
	}
}

int taikhoan(MYSQL *conn, char *user)
{
	
	while(1)
	{
		system("cls");
		printf("\nTai khoan: %s", user);
		printf("\n\t1. Them tai khoan.\n\
	2. Xoa tai khoan.\n\
	3. Doi mat khau.\n\
	Khac: Tro ve Menu.\n\Lua chon: ");
		int choise = 0;
		fflush(stdin);
		scanf("%d", &choise);
		if (choise==1)
		{
			themtaikhoan(conn);
		}
		else if (choise==2)
		{
			if (xoataikhoan(conn, user) == 1)//check xoa tai khoan dang dang nhap hay ko: 1 la xoa tai khoan dang dang nhap
			{
				return 1;
			}
		}
		else if (choise==3)
		{
			doimatkhau(conn, user);
		}
		else 
		{
			return 0;
		}
	}
}
