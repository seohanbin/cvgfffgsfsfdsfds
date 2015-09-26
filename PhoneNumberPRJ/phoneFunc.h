/* Name: phoneFunc.h  ver 1.0
* Content: 전화번호 컨트롤 함수 선언.
* Implementation: YSW
*
* Last modified 2008/01/01
*/
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);
phoneData* FindData();
void SearchData();
void DeleteData();
void StoreDataToFile();
void LoadDataFromFile();



#endif
/* end of file */