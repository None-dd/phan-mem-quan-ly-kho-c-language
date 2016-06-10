#include "connect.h"
#include "printString.h"
#include "dangnhap.h"
#include <windows.h>
#include "menu.h"
int main(int argc, char** argv) {
	system("cls");
	system("color 0c");
	printf ("Start Connect to database, plase wait ...");
	Sleep(1000);
	MYSQL *conn = connect2data();
	char user[20];
	while (1) 
	{
		Sleep(500);
		system("cls");
		system("color");
		int continuE = 2;
		printTittle();
		dangNhap(conn, user);

		system("cls");
		system("color");
		while (1)
		{
			int con = 2;
			con = menu(conn, user);
			if (con == 0)//con ==true: tiep tuc vong lap
			{
				continuE = 0;
				break;
			}
			else if (con == 1)
			{
				break;
			}
		}
		if (continuE == 0)
		{
			break;
		}
	}
	system("cls");
	printf("TAM BIET;");
	getch();
	return 0;
}
