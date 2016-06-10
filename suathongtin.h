
void suathongtin(MYSQL *conn)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	system("cls");
	while(1)
	{
		printf("\tSua thong tin.\nNhap ma san pham can sua: ");
		char ma[30] = "";
		
		fflush(stdin);
		scanf("%[^\n]s", ma);
		char q[50] ="";
		strcpy(q, "select * from product where masanpham = '");
		strcat(q, ma);
		strcat(q, "'");
		mysql_query(conn, q);
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if ( row==NULL )
		{
			printf("\nMa khong dung.\n1. Nhap lai.\nKhac: Tro ve menu");
			int choise_ = 0;
			fflush(stdin);
			scanf("%d", choise_);
			if (!(choise_ == 1))
			{
				return ;
			}
			
		}
		else 
		{
			printf("Thong tin san pham can sua:\nTen san pham: %s\nMa san pham: %s\nGia tien: %s\nSo luong trong kho: %s\nMo ta: %s", row[0], row[1], row[2], row[3], row[4]);
			char ten_moi[30], ma_moi[30], mota_moi[300];
			int soluong, giatien;
			printf("\nBo trong neu khong can thay doi.");
			printf("\nNhap lai thong tin\nTen moi: ");
			fflush(stdin);
			scanf("%[^\n]s", ten_moi);
			printf("\nMa moi: ");
			fflush (stdin);
			scanf("%[^\n]s", ma_moi);
			
			printf("\nMo ta moi: ");
			fflush(stdin);
			scanf("%[^\n]s", mota_moi);
			char q_check[100] = "";
			strcpy(q_check, "select * from product where masanpham = '");
			strcat(q_check, ma_moi);
			strcat(q_check, "'");
			
			mysql_query(conn, q_check);
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			if (row!=NULL)
			{
				printf("\nMa moi trung voi ma san pham khac.\n1. Nhap lai\tKhac: Tro ve menu chinh\nLua chon: ");
				int choise2 = 0;
				fflush(stdin);
				scanf("%d", choise2);
				if (!(choise2 == 1))
				{
					return ;
				}
			}
			else
			{
				//UPDATE product set tensanpham = 'ten san pham 1', masanpham = 'ma san pham 1' WHERE masanpham = 'sp1'
				char q_update[200] = "";
				strcpy(q_update, "update product set tensanpham = '");
				strcat(q_update, ten_moi);
				strcat(q_update, "', masanpham = '");
				strcat(q_update, ma_moi);
				strcat(q_update, "', mota = '");
				strcat(q_update, mota_moi);
				strcat(q_update, "where masanpham = '");
				strcat(q_update, ma_moi);
				strcat(q_update, "'");
				int query;
				query = mysql_query(conn, q_update);
				if (query == 1)
				{
					printf("\nError, khong thay doi duoc.");
				}
				else 
				{
					printf("\nThay doi thanh cong");
				}
			}		
		}
	}	
}
