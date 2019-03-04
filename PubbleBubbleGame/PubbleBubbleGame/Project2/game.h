/*
	모듈의 기능 : 게임
	(버블 쏘기 버블 개수 검사 등)
	버전 : v3.4
	개발자 : 송유헌
	최종수정일 2018.6.7
*/
#pragma once
#include"xcvsdfsdf.h"
#ifndef GAME
#define GAME
extern int ga_score;
typedef struct {
	int ga_xpos;
	int ga_ypos;
}POS;//나중에 3개이상인지 검사할 때 쓸 것, 쏘는 공 멈출 때 이용
typedef struct _stack {//스택
	POS data;
	struct _stack* link;
}stack;
int ga_game(void);//게임
void ga_gotoxy(int x, int y);
void printline(int stage);//테두리랑 오른쪽 화면
void printstage(int arr[][48], int *xpos, int *ypos, int row, int col);//스테이지출력
void printball(int arr[][6], int *xpos, int *ypos, int row, int col);//공출력
void attachstage(int arr[][48], int xpos, int ypos, int nownum);//공 쏘고 함수에 복사;
int cleartest(POS pos[]);//다 뿌셨는지 검사
int popball(int arr[][48], POS ShootPos, int nownum, POS pos[8]);//3개 이상인지 검사 후 뿌심
enum COLOR { GREE = 10, BLUE, RED, PINK, YELL, WHIT };//GREE초록색,BLUE파란색,RED빨간색,PINK분홍색WHIT흰색
void push(stack** top, POS item);
POS pop(stack** top);
#endif