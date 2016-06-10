#include <stdio.h>
#include <conio.h>

char * nhapPassWord(){//hung bang con tro char
	printf ("PassWord: ");
	char ch, pwd[20];
	while(1){
		ch = getch();
		if (ch == 13)//enter
		{
			pwd[i] = '\0';
			break;
		}
		else if (ch == 8)//backspace
		{
			printf("\b \b");
			i--;
		}
		else 
		{
			pwd[i++] = ch;
			printf("*");
		}
	}//end while
	return pwd;
}
