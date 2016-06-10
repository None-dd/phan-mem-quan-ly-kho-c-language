
void timkiem(MYSQL *conn)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	system("cls");
	printf("\tTim kiem.");
	while(1)
	{
		printf("\nNhap tu khoa can tim kiem: ");
		char key[30];
		fflush(stdin);
		scanf("%30[^\n]", key);
		char q[250] = "";
		strcpy(q, "select * from product where tensanpham like '%");
		strcat(q, key);
		strcat(q, "%' or masanpham like '%");
		strcat(q, key);
		
		strcat(q, "%' or giatien like '%");
		strcat(q, key);
		
		strcat(q, "%' or soluong like '%");
		strcat(q, key);                    
		strcat(q, "%' or mota like '%");
		strcat(q, key);
		strcat(q, "%'");
		//printf("%s", q);
		mysql_query(conn, q);
		res = mysql_store_result(conn);
		int index = 1;
		printf("\nSTT\tTen\t\t\Ma\tSo luong\t\Mo ta");
		while (row = mysql_fetch_row(res))
		{
			printf("\n%d\t%s\t\%s\t%s\t\t%s", index, row[0], row[1], row[3], row[4], row[5]);
			index++;
		}

		if (index==1)
		{
			printf("\nKhong co ket qua tim kiem.");
		}
		printf("\n------------------------------------------------");
		printf("\n1. Tim kiem tiep\tKhac: Tro ve menu\nLua chon: ");
		int choise = 0;
		fflush(stdin);
		scanf("%d", &choise);
		if (choise != 1)
		{
			return ;
		}
	}
}
