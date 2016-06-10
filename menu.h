#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "themsanphammoi.h"
#include "cacsanpham.h"
#include "suathongtin.h"
#include "timkiem.h"
#include "xuatkho.h"
#include "nhapkho.h"
#include "taikhoan.h"
#include "chitietsanpham.h"
int menu(MYSQL * conn, char * user)// return 0 neu khong thoat, 1 neu logout, 2 la continue
{
	system("cls");
	printf ("\tMANAGEMENT STORE");
	printf("\nSelect Choise.");
	printf("\n\t1. Tat ca cac san pham\n\
	2. Them san pham moi.\n\
	3. Chi tiet san pham.\n\
	4. Sua thong tin san pham\n\
	5. Tim kiem\n\
	6. Xuat kho.\n\
	7. Nhap kho.\n\
	8. Tai khoan.\n\
	9. Log out.\n\
	10. Thoat.");
	printf("\nLua chon: ");
	int con = 2;//co tiep tuc lap khong
	int choise = 11;
	
	fflush(stdin);
	scanf("%d", &choise);
	switch (choise)
	{
		case 1://select 1 show all
			cacsanpham(conn);
			con = 2;
			break;
		case 2://them san pham moi
			themsanphammoi(conn);
			con = 2;
			break;
		case 3://chi tiet san pham
			chitietsanpham(conn);
			con = 2;
			break;
		case 4://sua thong tin san pham
			suathongtin(conn);
			con = 2;
			break;
		case 5://tim kiem
			timkiem(conn);
			con = 2;
			break;
		case 6://xuat kho
			xuatkho(conn);
			con = 2;
			break;
		case 7://nhap kho
			nhapkho(conn);
			con = 2;
			break;
		case 8://tai khoan
			if (taikhoan(conn, user) == 1)
			{
				con = 1;
			}
			break;
		case 9://log out
			con = 1;
			break;
		case 10://thoat
			con = 0;
			break;
		default:
			con=2;
			printf("\nKhong co trong lua chon | Not in Menu.");
			Sleep(1000);
			break;
	}

	return con;
}
