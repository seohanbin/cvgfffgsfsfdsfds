/* Name: phoneFunc.c  ver 1.1
* Content: ��ȭ��ȣ ��Ʈ�� �Լ�.
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];

/* ��    ��: void InputPhoneData(void)
* ��    ��: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����.
* ��    ȯ: void.
*
*/
void InputPhoneData(void)
{//����
	phoneData data;

	if (numOfData >=LIST_NUM)
	{
		puts("�޸� ����");
		return;
	}//����ó��
	

	printf("�̸�: "); gets(data.name);
	printf("����: "); gets(data.phoneNum); 

	phoneList[numOfData] = (phoneData*)malloc(sizeof(phoneData));
	*phoneList[numOfData] = data;
	numOfData++;

	puts("�Է¿Ϸ�");

}

/* ��    ��: void ShowAllData(void)
* ��    ��: ����� ������ ��ü ���.
* ��    ȯ: void.
*
*/
void ShowAllData(void)
{//����
	int i = 0;
	for ( i = 0; i < numOfData; i++)
	{
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	printf("��³�. �ڷ��Ѽ�: %d\n",numOfData);
}

/*�Լ� phoneData FindData()
��� ã��
��ȯ phoneData
*/
phoneData* FindData()
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	phoneData trash;
	// trash.name = "none"; trash.phoneNum = "none";
	strcpy(trash.name, "none");
	strcpy(trash.phoneNum, "none");

	fputs("�̸� �Է�: ", stdout);
	gets(nameforsearch);

	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			return phoneList[i]; //�������� �����Ƿ� �ٷθ���
		}
	}
	if (i == numOfData)
	{
		puts("�ش� �̸�����");
		return &trash; //�ǹ̾��� ������ȯ
	}
}

/*�Լ� void SearchData()
��� ã�����
��ȯ void
*/
void SearchData()
{
	//ShowPhoneInfo( FindData() );
	ShowPhoneInfoByPtr( FindData() );
}

/* �Լ� void DeleteData()
��� delete
��ȯ void
*/

void DeleteData()
{
	int i = 0;
	int switcher = 0;

	char nameforsearch[NAME_LEN];
	printf("������ �̸�: ");
	gets(nameforsearch);

	for ( i = 0; i < numOfData; i++)
	{
		if ( strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			numOfData--;
			for (; i < numOfData; i++)
			{
				phoneList[i] = phoneList[i + 1];
			}
			puts("�����Ϸ�");
			return;
		}

	}
	puts("�ش��̸�����");
	return;

}

/* end of file */