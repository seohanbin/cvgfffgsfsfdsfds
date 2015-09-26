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
	int i;

	if (numOfData >=LIST_NUM)
	{
		puts("메모리 부족");
		return;
	}//예외처리
	

	printf("이름: "); gets(data.name);
	printf("전번: "); gets(data.phoneNum); 


	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(data.name, phoneList[i]->name) == 0 && strcmp(data.phoneNum, phoneList[i]->phoneNum) == 0)
		{
			puts("이미 입력된 데이터입니다");
			system("pause");
			return;
		}
	}


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
phoneData* FindData() //메모리 유수. 폐기
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	phoneData* trash;
	trash = (phoneData*)malloc(sizeof(phoneData));
	// trash.name = "none"; trash.phoneNum = "none";
	strcpy(trash->name, "none");
	strcpy(trash->phoneNum, "none");

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
		return trash; //의미없는 정보반환
	}
}//폐기

/*함수 void SearchData()
기능 찾아출력
반환 void
*/
void SearchData()
{
	int i = 0;
	char nameforsearch[NAME_LEN];
	int index = 0;

	fputs("이름 입력: ", stdout);
	gets(nameforsearch);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			index++;
		}
	}

	if (index == 0)//예외
	{
		puts("해당 이름없음");
		return;
	}
	printf("동일인: %d\n", index);
}

/* 함수 void DeleteData()
기능 delete
반환 void
*/

void DeleteData()
{
	int i = 0;

	int delindex[LIST_NUM];
	int index = 0;
	int deltarget;

	char nameforsearch[NAME_LEN];
	printf("삭제할 이름: ");
	gets(nameforsearch);

	for ( i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			delindex[index] = i;
			index++;
		}
	}
	index--;//1개일때 마지막 인덱스를 최초(0) 인덱스로

	if (index==0)//결과1개
	{
		free(phoneList[delindex[index]]);//메모리 유수 방지
		for (i = delindex[index]; i < numOfData; i++)
		{
			phoneList[i] = phoneList[i + 1];
		}
		puts("삭제완료");
		numOfData--;
		return;
	}
	
	else if (index > 0)//결과 다수
	{

		for ( i = 0; i <= index; i++)
		{
			printf("삭제대상번호: %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[delindex[i]]);
		}
		fputs("삭제대상 선택: ", stdout);
		scanf("%d", &deltarget);
		deltarget--;//index로 쓰기 위함
		while (getchar() != '\n');
		


		free(phoneList[delindex[deltarget]]);//메모리 유수 방지
		
		for (i = delindex[deltarget]; i < numOfData; i++)
		{
			phoneList[i] = phoneList[i + 1];
		}


		puts("삭제완료");
		numOfData--;
		return;
	}
	else//결과 없음
	{
		puts("해당이름없음");
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
	puts("리스트 저장");
	system("pause");
}

void LoadDataFromFile()
{
	int i;
	FILE* fp;
	fp = fopen("whitepages.dat", "rb");

	if (fp==NULL)
	{
		puts("저장된 파일 없음");
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
	puts("로드됨");
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
	printf("수정할 이름: ");
	gets(nameforsearch);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(nameforsearch, phoneList[i]->name) == 0)
		{
			editindex[index] = i;
			index++;
		}
	}
	index--;//1개일때 마지막 인덱스를 최초(0) 인덱스로

	if (index == 0)//결과1개
	{
		phoneList[editindex[index]];//수정대상

		printf("변경할 전화번호는?");
		gets(edittothis);
		strcpy(phoneList[editindex[index]], edittothis);
		
		puts("수정완료");
		
		return;
	}

	else if (index > 0)//결과 다수
	{

		for (i = 0; i <= index; i++)
		{
			printf("수정대상번호: %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[editindex[i]]);
		}
		fputs("삭제대상 선택: ", stdout);
		scanf("%d", &edittarget);
		edittarget--;//index로 쓰기 위함
		while (getchar() != '\n');

		printf("변경할 전화번호는?");
		gets(edittothis);
		strcpy(phoneList[editindex[edittarget]], edittothis);

		puts("수정완료");
		return;
	}
	else//결과 없음
	{
		puts("해당이름없음");
		return;
	}
}

/* end of file */