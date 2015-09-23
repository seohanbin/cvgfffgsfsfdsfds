/* Name: phoneFunc.c  ver 1.1
* Content: 전화번호 컨트롤 함수.
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

/* 함    수: void InputPhoneData(void)
* 기    능: 전화번호 관련 데이터 입력 받아서 저장.
* 반    환: void.
*
*/
void InputPhoneData(void)
{//구현
	phoneData data;

	if (numOfData >=LIST_NUM)
	{
		puts("메모리 부족");
		return;
	}//예외처리
	

	printf("이름: "); gets(data.name);
	printf("전번: "); gets(data.phoneNum); 

	phoneList[numOfData] = (phoneData*)malloc(sizeof(phoneData));
	*phoneList[numOfData] = data;
	numOfData++;

	puts("입력완료");

}

/* 함    수: void ShowAllData(void)
* 기    능: 저장된 데이터 전체 출력.
* 반    환: void.
*
*/
void ShowAllData(void)
{//구현
	int i = 0;
	for ( i = 0; i < numOfData; i++)
	{
		//ShowPhoneInfo(phoneList[i]);
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	printf("출력끝. 자료총수: %d\n",numOfData);
}

/*함수 phoneData FindData()
기능 찾기
반환 phoneData
*/
phoneData* FindData()
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	phoneData trash;
	// trash.name = "none"; trash.phoneNum = "none";
	strcpy(trash.name, "none");
	strcpy(trash.phoneNum, "none");

	fputs("이름 입력: ", stdout);
	gets(nameforsearch);

	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			return phoneList[i]; //동명이인 없으므로 바로리턴
		}
	}
	if (i == numOfData)
	{
		puts("해당 이름없음");
		return &trash; //의미없는 정보반환
	}
}

/*함수 void SearchData()
기능 찾아출력
반환 void
*/
void SearchData()
{
	//ShowPhoneInfo( FindData() );
	ShowPhoneInfoByPtr( FindData() );
}

/* 함수 void DeleteData()
기능 delete
반환 void
*/

void DeleteData()
{
	int i = 0;
	int switcher = 0;

	char nameforsearch[NAME_LEN];
	printf("삭제할 이름: ");
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
			puts("삭제완료");
			return;
		}

	}
	puts("해당이름없음");
	return;

}

/* end of file */