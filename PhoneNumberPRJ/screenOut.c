/* name : screenOut.c  ver 1.0
content : Function definition fon console output
Implementation : SHB

Last modified 2015
*/

#include "common.h"
#include "phoneData.h"

/* func : void ShowMenu(void)
role : menu print for select
return : void
*/

void ShowMenu(void)
{
	system("cls");	//stdlib.h

	printf("---------menu--------\n");
	printf("1. 전화번호 입력\n");
	printf("2. print all data\n");
	printf("3. search\n");
	printf("4. delete\n");
	printf("5. Quit\n");
	//printf("자료 총수: %d\n", numOfData);
	printf("---------------------\n");
	printf("SELECT >> ");
}

/* 함    수: void ShowPhoneInfo(phoneData phone)
* 기    능: 이름과 전화번호 정보 출력.
* 반    환: void.
*
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("┏━━━━━━━━━━━━━━━━ \n");
	printf("┃ ▶ 이름: %s \n", phone.name);
	printf("┃ ▶ 전화번호: %s \n", phone.phoneNum);
	printf("┗━━━━━━━━━━━━━━━━ \n\n");
}

/*end of file*/