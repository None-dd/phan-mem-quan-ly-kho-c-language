void chitietsanpham(MYSQL *conn)
{
	system("cls");
	printf("\tCHI TIET SAN PHAM");
	while (1)
	{
		MYSQL_RES *res;
		MYSQL_ROW row;
		char q[100], key[20];
		printf("\nNhap ma san pham: ");
		fflush(stdin);
		scanf("%20[^\n]", key);
		strcpy(q, "select * from product where masanpham like '%");
		strcat(q, key);
		strcat(q, "'");
		
		mysql_query(conn, q);
		res = mysql_store_result(conn);
		int index = 1;
		if( row = mysql_fetch_row(res) )
		{
			printf("\nSTT\tTen\t\tMa\tGia tien\tSo luong\tMo ta");
			do
			{
				printf("\n%d\t%s\t\%s\t%s\t\t%s\t%s", index, row[0], row[1], row[2], row[3], row[4]);
				index++;
				try
				{
					row = mysql_fetch_row(res);
				}
				catch (char *c)
				{
					row = NULL;
				}
			}
			while (row);
		}
		else 
		{
			printf("\nChua ma sanpham nay trong kho.");
		}
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
