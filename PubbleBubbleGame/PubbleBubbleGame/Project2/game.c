/*
모듈의 기능 : 게임
(버블 쏘기 버블 개수 검사 등)
버전 : v3.4
개발자 : 송유헌
최종수정일 2018.6.7
*/
#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include"game.h"
int ga_game(void)//게임
{
	int stage = 1;
	int score = 0;
	int stagetest;//다음 스테이지로 넘어갈 때 검사할 용도
	int adjustpos = 0;//공 멈출 때 조정하기 위해
	int ga_i, ga_j;//반복문 돌릴 때 쓸 것
	int ga_move = 0;
	int ga_count = 0;
	
	int ga_x_move;
	int stage_xpos, stage_ypos;//상단 바 내려오게 할 때
	int ga_xpos = 3, ga_ypos = 2;//x좌표y좌표
	int nownum;//현재 색에 대한 숫자 enum COLOR에 해당하는 것
	int nextnum;//다음 색에 대한 숫자 enum COLOR에 해당하는 것
	POS pos[8] = { { 3,13 },{ 9,13 },{ 15,13 },{ 21,13 },{ 27,13 },{ 33,13 },{ 39,13 },{ 45,13 } };
	POS ShootPos = { 24,21 };
	char key;
	int x1 = 25, x2 = 25, x3 = 26, y1 = 18, y2 = 19, y3 = 20;
	int stage1[15][48] =//1단계
	{
		{ 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 },
	{ YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE },
	{ 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 },

	{ 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0 },
	{ GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK },
	{ 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0 },

	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0,0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,  YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },

	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 },
	{ PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK, GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE },
	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 },

	{ 0 },
	{ 0 },
	{ 0 }
	};
	int stage2[15][48] =//2단계
	{
		{ 0,PINK,PINK,PINK,PINK,0 , 0,PINK,PINK,PINK,PINK,0 , 0,PINK,PINK,PINK,PINK,0 ,  0,BLUE,BLUE,BLUE,BLUE,0 , 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0 ,0,YELL,YELL,YELL,YELL,0 },
	{ PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0, 0,PINK,PINK,PINK,PINK,0, 0,BLUE,BLUE,BLUE,BLUE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0 ,0,YELL,YELL,YELL,YELL,0 },

	{ 0,BLUE,BLUE,BLUE,BLUE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,YELL,YELL,YELL,YELL,0 },
	{ BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK, PINK,PINK,PINK,PINK,PINK,PINK, YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,BLUE,BLUE,BLUE,BLUE,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,PINK,PINK,PINK,PINK,0, 0,YELL,YELL,YELL,YELL,0 },

	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 },
	{ BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE, YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL ,YELL,YELL,YELL,YELL,YELL,YELL ,GREE,GREE,GREE,GREE,GREE,GREE,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE },
	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 ,0,GREE,GREE,GREE,GREE,0 },

	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE, YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ 0 },
	{ 0 },
	{ 0 }
	};
	int stage3[15][48] =//3단계
	{
		{ 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0 },
	{ YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK },
	{ 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0 },

	{ 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK, YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0,  0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },

	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK, },
	{ BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE, YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE, PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK },
	{ 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0 ,0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0 ,0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK, },

	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ PINK,PINK,PINK,PINK,PINK,PINK ,PINK,PINK,PINK,PINK,PINK,PINK ,GREE,GREE,GREE,GREE,GREE,GREE ,GREE,GREE,GREE,GREE,GREE,GREE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE ,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE, YELL,YELL,YELL,YELL,YELL,YELL, YELL,YELL,YELL,YELL,YELL,YELL },
	{ 0,PINK,PINK,PINK,PINK,0 ,0,PINK,PINK,PINK,PINK,0, 0,GREE,GREE,GREE,GREE,0, 0,GREE,GREE,GREE,GREE,0, 0,BLUE,BLUE,BLUE,BLUE,0 ,0,BLUE,BLUE,BLUE,BLUE,0, 0,YELL,YELL,YELL,YELL,0, 0,YELL,YELL,YELL,YELL,0 },
	{ 0 },
	{ 0 },
	{ 0 }
	};
	int now[3][6] = { 0 };//현재 쏠 공에 대한 것 0으로 초기화. 이후에 숫자 받을 것임
	int next[3][6] = { 0 };//다음 쏠 공에 대한 것 0으로 초기화. 이후에 숫자 받을 것임
	srand((unsigned)time(NULL));


	while (1)
	{
		printline(stage);//겉에 선들이랑 
		stagetest = stage;
		for (ga_j = 0; ga_j < 8; ga_j++)
			pos[ga_j].ga_ypos = 13;

		ShootPos.ga_xpos = 24;
		ShootPos.ga_ypos = 21;
		do//맨처음에 첫 공의 색을 랜덤으로 받음 이후에 한 번 쏜 다음에는 next에 있는거 받음
		{
			nownum = rand() % 5 + GREE;
		} while (nownum == 12);
		for (ga_j = 1; ga_j < 5; ga_j++)
			now[0][ga_j] = nownum;
		for (ga_j = 0; ga_j < 6; ga_j++)
			now[1][ga_j] = nownum;
		for (ga_j = 1; ga_j < 5; ga_j++)
			now[2][ga_j] = nownum;

		do//다음에 쏠 공 랜덤을 받음.
		{
			nextnum = rand() % 5 + GREE;
		} while (nextnum == 12);
		for (ga_j = 1; ga_j < 5; ga_j++)
			next[0][ga_j] = nextnum;
		for (ga_j = 0; ga_j < 6; ga_j++)
			next[1][ga_j] = nextnum;
		for (ga_j = 1; ga_j < 5; ga_j++)
			next[2][ga_j] = nextnum;

		while (stage == stagetest)
		{
			ShootPos.ga_xpos = 24;
			ShootPos.ga_ypos = 21;
			ga_xpos = 3;
			ga_ypos = 2;
			stage_xpos = 3;
			stage_ypos = 2;
			adjustpos = 0;
			if (stage == 1)//1단계일경우
			{
				if (stage_ypos != 2)
				{
					ga_gotoxy(3, stage_ypos);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					printf("================================================");
				}

				printstage(stage1, &stage_xpos, &stage_ypos, 15, 48);//stage1출력
			}
			if (stage == 2)//2단계일경우
			{
				if (stage_ypos != 2)
				{
					ga_gotoxy(3, stage_ypos-1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					printf("================================================");
				}
				printstage(stage2, &stage_xpos, &stage_ypos, 15, 48);//stage2출력
			}
			if (stage == 3)//3단계일경우
			{
				if (stage_ypos != 2)
				{
					ga_gotoxy(3, stage_ypos-1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
					printf("================================================");
				}
				printstage(stage3, &stage_xpos, &stage_ypos, 15, 48);//stage3출력
			}

			ga_xpos = 3;
			ga_ypos = 20;
			ga_gotoxy(ga_xpos, ga_ypos);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("N E X T\n");
			ga_ypos++;
			printball(next, &ga_xpos, &ga_ypos, 3, 6);//다음공 출력

			ga_xpos = 26;
			ga_ypos = 18;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
			ga_gotoxy(3, ga_ypos - 1);
			printf("================================================");

			ga_ypos = 21;
			ga_xpos = 24;

			ga_gotoxy(ga_xpos, ga_ypos);
			printball(now, &ga_xpos, &ga_ypos, 3, 6);//현재 공 출력

			do
			{
				ga_gotoxy(x1, y1);
				printf("♠");
				ga_gotoxy(x2, y2);
				printf("♠");
				ga_gotoxy(x3, y3);
				printf("♠");

				key = _getch();

				if (key == 27)//esc눌렀을 경우
				{
					//일시정지 화면 표시
					key = getch();
				}
				ga_gotoxy(x1, y1);
				printf(" ");
				ga_gotoxy(x2, y2);
				printf(" ");
				ga_gotoxy(x3, y3);
				printf(" ");

				move_arrow_key(key, &x1, &x2, &x3);
			} while (key != ' ');//스페이스 누르면 쏘기!
			/*ga_count++;*/
			
			ga_x_move = x1 - x3;
			ga_ypos = 21;
			ga_xpos = 24;

			while (ga_move == 0)//쏘기!!
			{
				adjustpos++;
				for (ga_i = 0; ga_i < 3; ga_i++)//원래 꺼 지우고
				{
					ga_gotoxy(ShootPos.ga_xpos, ShootPos.ga_ypos);
					for (ga_j = 0; ga_j < 6; ga_j++)
						printf(" ");
					ShootPos.ga_ypos++;
				}
				ShootPos.ga_ypos -= 6;

				for (ga_i = 0; ga_i < abs(ga_x_move); ga_i++)//벽에 부딪힐 때 방향 바꾸기
				{
					if (ShootPos.ga_xpos >= 45)//오른벽
						ga_x_move = -ga_x_move;

					else if (ShootPos.ga_xpos <= 3)//왼벽
						ga_x_move = -ga_x_move;

					if (ga_x_move > 0)
						ShootPos.ga_xpos++;
					else
						ShootPos.ga_xpos--;
				}
				if (adjustpos >= 4)
					ShootPos.ga_xpos = ShootPos.ga_xpos - ga_x_move;
					
				for (ga_i = 0; ga_i < 8; ga_i++)//공 제자리 찾음
				{
					if (ShootPos.ga_xpos == pos[ga_i].ga_xpos)
					{						
						if (ShootPos.ga_ypos <= pos[ga_i].ga_ypos)
						{
							ga_move++;//멈출곳 찾으면 증가
							ShootPos.ga_ypos = pos[ga_i].ga_ypos + 1;
							printball(now, &ShootPos.ga_xpos, &ShootPos.ga_ypos, 3, 6);
							ShootPos.ga_ypos -= 3;
							if (ShootPos.ga_ypos >= 17)
								break;
							if (stage == 1)//1단계일경우 공 붙임
								attachstage(stage1, ShootPos.ga_xpos, ShootPos.ga_ypos, nownum);

							if (stage == 2)//2단계일경우
								attachstage(stage2, ShootPos.ga_xpos, ShootPos.ga_ypos, nownum);

							if (stage == 3)//3단계일경우
								attachstage(stage3, ShootPos.ga_xpos, ShootPos.ga_ypos, nownum);
							pos[ga_i].ga_ypos += 3;
						}
						break;
					}
				}
				if (ga_move == 0)
				{
					printball(now, &ShootPos.ga_xpos, &ShootPos.ga_ypos, 3, 6);//쏘는 공 출력	
					ShootPos.ga_ypos -= 3;
					Sleep(100);
				}

			}
			if (stage == 1)
				score += popball(stage1, ShootPos, nownum, pos);
			else if (stage == 2)
				score += popball(stage2, ShootPos, nownum, pos);
			else if (stage == 3)
				score += popball(stage3, ShootPos, nownum, pos);
			
			for (ga_i = 0; ga_i < 8; ga_i++)//뿌신 것들보다 아래있는것들 다 없앰(메달린 거)
			{
				
				for (ga_j = (pos[ga_i].ga_ypos + 1); ga_j <= 14; ga_j += 3)
				{
					if (stage == 1)
					{
						ga_xpos = pos[ga_i].ga_xpos;
						ga_ypos = ga_j;
						if (stage1[ga_ypos - 2][ga_xpos - 2] != 0)
							attachstage(stage1, ga_xpos, ga_ypos, 0);					
					}
					else if (stage == 2)
					{
						ga_xpos = pos[ga_i].ga_xpos;
						ga_ypos = ga_j;
						if (stage2[ga_ypos - 2][ga_xpos - 2] != 0)
							attachstage(stage2, ga_xpos, ga_ypos, 0);
						
					}
					else
					{
						ga_xpos = pos[ga_i].ga_xpos;
						ga_ypos = ga_j;
						if (stage3[ga_ypos - 2][ga_xpos - 2] != 0)						
							attachstage(stage3, ga_xpos, ga_ypos, 0);					
					}
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHIT);
			ga_gotoxy(63, 16);
			printf("%d", score);
			ga_move = 0;

			if (cleartest(pos) == 1)//스테이지 클리어 시
			{
				
				stage++;
				system("cls");
				printf("W I N\n");
				Sleep(1000);
				break;

				if (stage == 4)//모든 스테이지 클리어 시
				{
					Sleep(1000);
					system("cls");
					printf("C O N G R A T U L A T I O N\n");
					return score;
				}
			}
			for (ga_i = 0; ga_i < 8; ga_i++)
			{
				if (pos[ga_i].ga_ypos >= 17 || ShootPos.ga_ypos >= 17)//버블이 하단에 닿을 경우
				{
					Sleep(1000);
					system("cls");
					printf("L O S E\n");
					return score;
				}
			}
			nownum = nextnum;//쏠 공 next에 있는거 받아옴
			for (ga_j = 1; ga_j < 5; ga_j++)
				now[0][ga_j] = nownum;
			for (ga_j = 0; ga_j < 6; ga_j++)
				now[1][ga_j] = nownum;
			for (ga_j = 1; ga_j < 5; ga_j++)
				now[2][ga_j] = nownum;

			do//next꺼 새로 받음
			{
				nextnum = rand() % 5 + GREE;
			} while (nextnum == 12);
			for (ga_j = 1; ga_j < 5; ga_j++)
				next[0][ga_j] = nextnum;
			for (ga_j = 0; ga_j < 6; ga_j++)
				next[1][ga_j] = nextnum;
			for (ga_j = 1; ga_j < 5; ga_j++)
				next[2][ga_j] = nextnum;
			
			//if (ga_count % 5 == 0)//5번쏠때마다 아래로 내려옴
			//{
			//	stage_ypos+=3;
			//	for (ga_i = 0; ga_i < 8; ga_i++)
			//		pos[ga_i].ga_ypos += 3;
			//}
		}
	}

	/*
	(1)선 넘었나?
	종료
	if(ShootPos.ga_ypos>=18||POS[i].ga_ypos>=18)//=넘거나 닿으면
	{
	ShootPos.ga_ypos>=18//이면 LOSE//ShootPos.ga_ypos가 =에 닿거나 넘거나
	POS[i].ga_ypos>=18이면 LOSE//Pos[i].ga_ypos가 =에 닿거나 넘거나
	system("cls");
	printline(새로만든거 전체 네모);
	printf("LOSE");
	printf("SCORE : ");
	
	//공들이 내려올 때
	횟수를 정해서 일정 횟수가 되면 공들이 내려오게함
	*/

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHIT);
	ga_gotoxy(1, 25);
}

void ga_gotoxy(int x, int y)//좌표 이동
{
	COORD Pos = { x - 1,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void printline(int stage)//겉에 테두리랑 오른쪽에 있는 것들 출력
{
	unsigned a = 0xa6, b[12], i;
	int ga_xpos = 3;
	int ga_ypos = 1;
	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;

	ga_gotoxy(1, ga_ypos);
	printf("%c%c", a, b[3]);
	for (i = 0, ga_xpos = 3; i < 70; i += 2, ga_xpos += 2)
	{
		ga_gotoxy(ga_xpos, ga_ypos);
		printf("%c%c", a, b[1]);
	}
	ga_gotoxy(51, ga_ypos);
	printf("%c%c", a, b[4]);
	ga_gotoxy(53, ga_ypos);
	printf("%c%c", a, b[3]);
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("%c%c", a, b[4]);
	ga_ypos++;

	for (i = 2; i < 24; i++)
	{
		ga_gotoxy(1, ga_ypos);
		printf("%c%c", a, b[2]);
		ga_gotoxy(51, ga_ypos);
		printf("%c%c", a, b[2]);
		ga_gotoxy(53, ga_ypos);
		printf("%c%c", a, b[2]);
		ga_gotoxy(73, ga_ypos);
		printf("%c%c", a, b[2]);
		ga_ypos++;
	}

	ga_gotoxy(1, ga_ypos);
	printf("%c%c", a, b[6]);
	for (i = 0, ga_xpos = 3; i < 70; i += 2, ga_xpos += 2)
	{
		ga_gotoxy(ga_xpos, ga_ypos);
		printf("%c%c", a, b[1]);
	}
	ga_gotoxy(51, ga_ypos);
	printf("%c%c", a, b[5]);
	ga_gotoxy(53, ga_ypos);
	printf("%c%c", a, b[6]);
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("%c%c", a, b[5]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	ga_gotoxy(55, 3);
	printf("P U Z Z L E");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREE);
	ga_gotoxy(58, 5);
	printf("B U B B L E");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PINK);
	ga_gotoxy(60, 7);
	printf("    G A M E");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	ga_xpos = 58;
	ga_ypos = 11;
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("S  T  A  G  E");
	ga_ypos++;
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("☞         ☜");
	ga_gotoxy(ga_xpos + 6, ga_ypos);
	printf("%d", stage);
	ga_ypos = 15;
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("S  C  O  R  E");
	ga_ypos++;
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("☞         ☜");

	ga_ypos = 19;
	ga_gotoxy(ga_xpos - 1, ga_ypos);
	printf("일지정지 : ESC");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHIT);
	ga_ypos = 22;
	ga_gotoxy(ga_xpos, ga_ypos);
	printf("Producted by");
	ga_gotoxy(ga_xpos, ga_ypos + 1);
	printf("-Dream Team-");
}



void printstage(int arr[][48], int *xpos, int *ypos, int row, int col)//stage출력
{
	int i, j;
	ga_gotoxy(*xpos, *ypos);
	for (i = 0; i < row; i++)
	{
		ga_gotoxy(*xpos, *ypos);
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == YELL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == GREE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == BLUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == PINK)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == 0)
				printf(" ");
		}
		(*ypos)++;
	}
}

void printball(int arr[][6], int *xpos, int *ypos, int row, int col)//공 출력
{
	int i, j;
	ga_gotoxy(*xpos, *ypos);
	for (i = 0; i < row; i++)
	{
		ga_gotoxy(*xpos, *ypos);
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == YELL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == GREE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == BLUE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == PINK)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), arr[i][j]);
				printf("■");
				j++;
			}
			else if (arr[i][j] == 0)
				printf(" ");
		}
		(*ypos)++;
	}
}

void attachstage(int arr[][48], int xpos, int ypos, int nownum)//공 쏘고 배열에 복사
{
	int ga_j;
	for (ga_j = 1; ga_j < 5; ga_j++)
		arr[ypos - 2][xpos - 3 + ga_j] = nownum;
	for (ga_j = 0; ga_j < 6; ga_j++)
		arr[ypos - 1][xpos - 3 + ga_j] = nownum;
	for (ga_j = 1; ga_j < 5; ga_j++)
		arr[ypos][xpos - 3 + ga_j] = nownum;
}

int cleartest(POS pos[])//다 뿌셨는지 검사
{
	int i;
	int count = 0;

	for (i = 0; i < 8; i++)
	{
		if (pos[i].ga_ypos != 1)
			count++;
	}

	if (count == 0)
		return 1;
	else
		return 0;
}

int popball(int arr[][48], POS ShootPos, int nownum, POS pos[8])//3개 이상인지 검사 후 뿌심
{
	int count = 0;
	int i, k;
	POS test;
	stack* atop = NULL;//같은 것들 담아놔서 팝하면서 그 근처 것들 검사하기위해(ex미로 탐색)
	stack* btop = NULL;//같은 것들 담아놈

	test = ShootPos;
	push(&atop, test);

	test = pop(&atop);
	push(&btop, test);
	count++;
	arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시

	while (1)
	{
		if (ShootPos.ga_xpos == 3)//왼쪽 벽에 붙어있는 공이면
		{
			test.ga_ypos -= 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)//같은 색의 공이면
			{
				push(&atop, test);//위
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
			test.ga_xpos += 6;
			test.ga_ypos += 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//오
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
		}
		else if (ShootPos.ga_xpos == 45)//오른 벽에 붙어있는 공이면
		{
			test.ga_xpos -= 6;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//왼
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
			test.ga_xpos += 6;
			test.ga_ypos -= 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//위
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
		}
		else//나머지 공
		{
			test.ga_xpos -= 6;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//왼
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
			test.ga_xpos += 6;
			test.ga_ypos -= 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//위				
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
			test.ga_xpos += 6;
			test.ga_ypos += 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//오
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}
			test.ga_xpos -= 6;
			test.ga_ypos += 3;
			if (arr[test.ga_ypos - 2][test.ga_xpos - 2] == nownum)
			{
				push(&atop, test);//아래
				arr[test.ga_ypos - 2][test.ga_xpos - 2] = 1;//이미 검사한 거 표시
			}

		}

		if (atop)//stack a 비지 않았으면
		{
			test = pop(&atop);
			push(&btop, test);
			count++;
		}
		else
		{
			if (count >= 3)//3개 이상이면
			{
				for (k = 0; k < count; k++)
				{
					test = pop(&btop);
					for (i = 0; i < 8; i++)
					{
						if (test.ga_xpos == pos[i].ga_xpos)
						{
							if (test.ga_ypos < pos[i].ga_ypos)
							{
								if (test.ga_ypos == 1)
									pos[i].ga_ypos = test.ga_ypos;
								else
									pos[i].ga_ypos = test.ga_ypos-1;
							}
							attachstage(arr, test.ga_xpos, test.ga_ypos, 0);//지우기
						}
					}
					
				}

				return count * 500;//공하나당 500점
			}
			else
			{
				while (btop)//3개보다 적으면,btop!!=NULL
				{
					test = pop(&btop);
					arr[test.ga_ypos - 2][test.ga_xpos - 2] = nownum;//원래대로 돌림
				}
			}
			break;
		}

	}
	return 0;
}
void push(stack** top, POS item) {
	stack* temp;
	temp = (stack *)malloc(sizeof(stack));
	temp->link = *top;
	temp->data = item;
	*top = temp;
}
POS pop(stack** top) {
	stack* temp = *top;
	POS popValue;

	popValue = temp->data;
	*top = temp->link;
	free(temp);
	return popValue;
}
