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
	int i;

	if (numOfData >=LIST_NUM)
	{
		puts("�޸� ����");
		return;
	}//����ó��
	

	printf("�̸�: "); gets(data.name);
	printf("����: "); gets(data.phoneNum); 


	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(data.name, phoneList[i]->name) == 0 && strcmp(data.phoneNum, phoneList[i]->phoneNum) == 0)
		{
			puts("�̹� �Էµ� �������Դϴ�");
			system("pause");
			return;
		}
	}


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
phoneData* FindData() //�޸� ����. ���
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	phoneData* trash;
	trash = (phoneData*)malloc(sizeof(phoneData));
	// trash.name = "none"; trash.phoneNum = "none";
	strcpy(trash->name, "none");
	strcpy(trash->phoneNum, "none");

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
		return trash; //�ǹ̾��� ������ȯ
	}
}//���

/*�Լ� void SearchData()
��� ã�����
��ȯ void
*/
void SearchData()
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	int index = 0;

	fputs("�̸� �Է�: ", stdout);
	gets(nameforsearch);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			index++;
		}
	}

	if (index == 0)//����
	{
		puts("�ش� �̸�����");
		return;
	}
	printf("������: %d\n", index);
}

/* �Լ� void DeleteData()
��� delete
��ȯ void
*/

void DeleteData()
{
	int i = 0;

	int delindex[LIST_NUM];
	int index = 0;
	int deltarget;

	char nameforsearch[NAME_LEN];
	printf("������ �̸�: ");
	gets(nameforsearch);

	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			delindex[index] = i;
			index++;
		}
	}
	index--;//1���϶� ������ �ε����� ����(0) �ε�����

	if (index==0)//���1��
	{
		free(phoneList[delindex[index]]);//�޸� ���� ����
		for (i = delindex[index]; i < numOfData; i++)
		{
			phoneList[i] = phoneList[i + 1];
		}
		puts("�����Ϸ�");
		numOfData--;
		return;
	}
	
	else if (index > 0)//��� �ټ�
	{

		for ( i = 0; i <= index; i++)
		{
			printf("��������ȣ: %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[delindex[i]]);
		}
		fputs("������� ����: ", stdout);
		scanf("%d", &deltarget);
		deltarget--;//index�� ���� ����
		while (getchar() != '\n');
		


		free(phoneList[delindex[deltarget]]);//�޸� ���� ����
		
		for (i = delindex[deltarget]; i < numOfData; i++)
		{
			phoneList[i] = phoneList[i + 1];
		}


		puts("�����Ϸ�");
		numOfData--;
		return;
	}
	else//��� ����
	{
		puts("�ش��̸�����");
		return;
	}
	
}


/*fn void StoreDataToFile()
role before exit save data
return  void
*/
void StoreDataToFile()
{
	int i;
	FILE* fp = fopen("whitepages.dat", "wb");
	
	fwrite(&numOfData, sizeof(int), 1, fp);
	for ( i = 0; i < numOfData; i++)
	{
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
		free(phoneList[i]);
	}
	
	fclose(fp);
	puts("����Ʈ ����");
	system("pause");
}

void LoadDataFromFile()
{
	int i;
	FILE* fp;
	fp = fopen("whitepages.dat", "rb");

	if (fp==NULL)
	{
		puts("����� ���� ����");
		system("pause");
		return;
	}

	fread(&numOfData, sizeof(int), 1, fp);
	for (i = 0; i < numOfData; i++)
	{
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
	puts("�ε��");
	system("pause");
}

/*fn 
role
return
*/
void ChangePhoneData()
{
	int i = 0;

	int editindex[LIST_NUM];
	int index = 0;
	int edittarget;
	char edittothis[NAME_LEN];

	char nameforsearch[NAME_LEN];
	printf("������ �̸�: ");
	gets(nameforsearch);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			editindex[index] = i;
			index++;
		}
	}
	index--;//1���϶� ������ �ε����� ����(0) �ε�����

	if (index == 0)//���1��
	{
		phoneList[editindex[index]];//�������

		printf("������ ��ȭ��ȣ��?");
		gets(edittothis);
		strcpy(phoneList[editindex[index]], edittothis);
		
		puts("�����Ϸ�");
		
		return;
	}

	else if (index > 0)//��� �ټ�
	{

		for (i = 0; i <= index; i++)
		{
			printf("��������ȣ: %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[editindex[i]]);
		}
		fputs("������� ����: ", stdout);
		scanf("%d", &edittarget);
		edittarget--;//index�� ���� ����
		while (getchar() != '\n');

		printf("������ ��ȭ��ȣ��?");
		gets(edittothis);
		strcpy(phoneList[editindex[edittarget]], edittothis);

		puts("�����Ϸ�");
		return;
	}
	else//��� ����
	{
		puts("�ش��̸�����");
		return;
	}
}

/* end of file */