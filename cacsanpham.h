#include <conio.h>
void cacsanpham(MYSQL *conn)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	char q[30] = "select * from product";
	mysql_query(conn, q);
	res = mysql_store_result(conn);
	if( row = mysql_fetch_row(res) )
	{
		system("cls");
		printf("Cac san pham trong kho.");
		int index = 1;
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
		printf("\nChua co san pham trong kho.");
	}
	printf("\n\nNhan phim bat ky de quay lai Menu\n");
	getch();
}
