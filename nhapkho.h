void nhapkho(MYSQL *conn)
{
	system("cls");
	printf("\tNhap kho.");
	char ma[30] = "";
	MYSQL_RES *res;
	MYSQL_ROW row;
	while(1)
	{
		printf("\nNhap ma san pham: ");
		fflush(stdin);
		scanf("%[^\n]s", ma);
		char q[100] = "";
		strcpy(q, "select * from product where masanpham = '");
		strcat(q, ma);
		strcat(q, "'");
		mysql_query(conn, q);
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row)
		{
			printf("Thong tin san pham can sua:\nTen san pham: %s\nMa san pham: %s\nGia tien: %s\nSo luong trong kho: %s\nMo ta: %s", row[0], row[1], row[2], row[3], row[4]);
			printf("\nSo luong nhap kho: ");
			int soluong_trongkho = atoi(row[3]), soluong_xuatkho = 0;
			
			fflush(stdin);
			scanf("%d", &soluong_xuatkho);
			if (1==0)
			{
				printf("\n Kho khong co du so luong ban yeu cau");
			}
			else
			{
				
				soluong_trongkho += soluong_xuatkho;
				printf("\nTong: %d", soluong_trongkho);
				char q_xuatkho[100];
				strcpy(q_xuatkho, "update product set soluong = '");
				char sl[5];
				itoa(soluong_trongkho, sl, 10);
				strcat(q_xuatkho,  sl);
				strcat(q_xuatkho, "' where masanpham = '");
				strcat(q_xuatkho, ma);
				strcat(q_xuatkho, "'");
				if (!mysql_query(conn, q_xuatkho))
				{
					printf("\nThanh cong.\n1: Tiep\tKhac: Tro ve Menu\nLua chon: ");
					int choise = 0;
					fflush(stdin);
					scanf("%d", choise);
					if (!(choise == 1))
					{
						return ;
					}
				}
				
			}
		}
		else
		{
			printf("\nMa san pham khong ton tai.\n1. Nhap lai\tKhac: Tro lai Menu\nLua chon: ");
			int choise = 0;
			fflush(stdin);
			scanf("%d", choise);
			if (!(choise == 1))
			{
				return ;
			}
		}
	}
	
}
