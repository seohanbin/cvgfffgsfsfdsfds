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
	printf("1. ��ȭ��ȣ �Է�\n");
	printf("2. print all data\n");
	printf("3. search\n");
	printf("4. delete\n");
	printf("5. Quit\n");
	//printf("�ڷ� �Ѽ�: %d\n", numOfData);
	printf("---------------------\n");
	printf("SELECT >> ");
}

/* ��    ��: void ShowPhoneInfo(phoneData phone)
* ��    ��: �̸��� ��ȭ��ȣ ���� ���.
* ��    ȯ: void.
*
*/
void ShowPhoneInfo(phoneData phone)
{
	printf("���������������������������������� \n");
	printf("�� �� �̸�: %s \n", phone.name);
	printf("�� �� ��ȭ��ȣ: %s \n", phone.phoneNum);
	printf("���������������������������������� \n\n");
}

/*fn: void ShowPhoneInfoByPtr(phoneData* pPhone)
role: show phone ptr
return: 
*/

void ShowPhoneInfoByPtr(phoneData* pPhone)
{
	printf("������������PTR������������������ \n");
	printf("�� �� �̸�: %s \n", pPhone->name);
	printf("�� �� ��ȭ��ȣ: %s \n", pPhone->phoneNum);
	printf("���������������������������������� \n\n");
}

/*end of file*/