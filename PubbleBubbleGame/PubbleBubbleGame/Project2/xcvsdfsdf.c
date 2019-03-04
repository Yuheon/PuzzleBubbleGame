/*
모듈의 기능 : 화살표 움직이기
개발자 : 김성우
최종수정일
*/
#include"xcvsdfsdf.h"
void move_arrow_key(char key, int *x1, int *x2, int *x3)
{
	switch (key)
	{
	case 75:
		if (*x1 == 27)
		{
			*x1 = *x1 - 2;
			*x2 = *x2 - 2;
		}
		else if (*x1 < 7)
			break;
		else {
			*x1 = *x1 - 4;
			*x2 = *x2 - 3;
			*x3 = *x3 - 2;
		}
		break;
	case 77:
		if (*x1 == 25)
		{
			*x1 = *x1 + 2;
			*x2 = *x2 + 2;
		}
		else if (*x1 > 45)
			break;
		else {
			*x1 = *x1 + 4;
			*x2 = *x2 + 3;
			*x3 = *x3 + 2;
		}
		break;
	default:
		return;
	}

}