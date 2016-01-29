#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "sanpham.h"
void themsanphammoi(MYSQL *conn)
{
	//sanpham sp;

	system("cls");
	printf("\tTHEM SAN PHAM.");
	while (1)
	{
		char ten[100], ma[20], mota[200];//khaoi bao sp moi
		int soluong, giatien;
		printf("\nTen san pham: ");
		fflush(stdin);
		scanf("%[^\n]s", ten);
		
		printf("\nMa san pham: ");
		fflush(stdin);
		scanf("%[^\n]s", ma);
		
		printf("\nGia tien: ");
		fflush(stdin);
		scanf("%d", &giatien);
		
		printf("\nSo luong: ");
		fflush(stdin);
		scanf("%d", &soluong);
		
		printf("\nMo ta: ");
		fflush(stdin);
		scanf("%[^\n]s", mota);
		printf ("\nBan co muon luu vao du lieu?\n1: Dong y\t\tKhac: Khong luu\nLua chon: ");
		
		int choise;
		fflush(stdin);
		scanf("%d", &choise);
		char soluongstring[10], giatienstring[10];
		itoa(soluong, soluongstring, 10);
		itoa(giatien, giatienstring, 10);
		if (choise == 1)
		{
			char q[400] = "insert into product values ('";
			strcat(q, ten); //('ten
			strcat(q, "', '"); //('ten', '
			strcat(q, ma);
			strcat(q, "', '");// ma', '
			strcat(q, giatienstring);
			strcat(q, "', '");
			strcat(q, soluongstring); //soluong
			strcat(q, "', '");
			strcat(q, mota);
			strcat(q, "')");
			int r;
			printf("\nCac thong tin vua nhap: %s, %s, %s, %s, %s", ten, ma, giatienstring, soluongstring, mota);
			if (strcmp(ma, ""))
			{
				r = mysql_query(conn, q);
			}
			else
			{
				r = 2;
			}
			if (r==1){
				printf("\nCo loi khi them san pham, xem lai thong tin nhap vao.");
				printf("\nTen va ma Ma san pham khong duoc de trong.");
			}
			else
			{
				printf("\nThem thanh cong");
			}
		}
		printf("\nTiep tuc them san pham?\n1. Tiep\t\tKhac: Tro lai menu chinh.\nLua chon: ");
		fflush(stdin);
		int choise_new;
		scanf("%d", &choise_new);
		if (choise_new != 1)
		{
			return ;
		}
	}
}
