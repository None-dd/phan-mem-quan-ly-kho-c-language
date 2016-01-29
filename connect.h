#include <stdio.h>
#include <mysql.h>
#include <conio.h>

MYSQL* connect2data(){
char host_name[] = "localhost";
char *user_name = "root";
char *password = "";
char *db_name = "management_store";
unsigned int port_num = 3306;
char *socket_name = NULL;
unsigned int flags = 0;
	MYSQL *conn;
	conn = mysql_init(NULL);
	if(!(mysql_real_connect(conn, host_name, user_name, password, db_name, port_num, socket_name, flags))){
		printf ("\n\t\t\t\t******Connect database failre!*******\t\t\t");
		printf("\nError code [%d]: %s", mysql_errno(conn), mysql_error(conn));
		printf ("\nPROGRAME EXIT.");
		getch();
		exit(1);
	}
	else {
		printf("\nConnect Sucessful!");
		return conn;
	}
}
/*
* hàm query se tra ve  1 doi tuong res 
*/
/*
void query(MYSQL * conn, char * query){
	MYSQL_RES *res;
	MYSQL_ROW row;
	mysql_query(conn, query);
	res = mysql_store_result(conn);
	printf("\n");
	while (row = mysql_fetch_row(res)){
		printf("%s\t", row[0]);
	}
	mysql_free_result(res);

}
*/
void query(MYSQL * conn, char * query){
	MYSQL_RES *res;
	
	mysql_query(conn, query);
	res = mysql_store_result(conn);
}

void closeconnect(MYSQL * conn)
{
	mysql_close(conn);
}
