/*
READ ME
git started at 9.23

modified second



*/


/* Name : main.c  ver 1.0
content : main Function
Implementation : SHB

Last modified 2015
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"


enum{INPUT=1, SHOWALL, SEARCH, EDIT, DELETE, QUIT};

/* function : int main (void)
role : User selection process
return : 0 if normal termination
*/

int main(void)
{
	int inputMenu = 0;
	LoadDataFromFile();

	while (1)
	{
		ShowMenu();
		fputs("select : ", stdout);
		scanf("%d", &inputMenu);
		while (getchar() != '\n'); //오류없이 작동

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			StoreDataToFile();
			break;

		case SHOWALL:
			ShowAllData();
			StoreDataToFile();
			system("pause");
			break;

		case SEARCH:
			SearchData();
			system("pause");
			break;

		case EDIT:
			ChangePhoneData();
			StoreDataToFile();
			system("pause");
			break;

		case DELETE:
			DeleteData();
			StoreDataToFile();
			system("pause");
		}

		if (inputMenu==QUIT)
		{
			//puts(" 저장완료"); //필요액션이후바로바로저장됨..
			puts("--end--");
			break;
		}
	}
	return 0;
}

/*end of file*/