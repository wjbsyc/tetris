#pragma once

#include "resource.h"

//函数声明
void checkComplite();  //查看一行是否能消去  采用从上往下的消法，消去一行后把上面的每行都往下移，但是我感觉效率有点低，以后看能不能有点改进
void drawBlocked(HDC hdc);      //绘制当前已经存在砖块的区域
void DrawBackGround(HDC hdc);       //绘制背景
void outPutBoxInt(int num);     //自定义的弹窗函数  用于调试
void outPutBoxString(TCHAR str[1024]);
void setRandomT();      //随机生成一个方块用作下一次掉落
void init_game();       //初始化
void fillBlock();       //到达底部后填充矩阵
void RotateTeris(BOOL bTeris[4][4]);        //旋转矩阵
void DrawTeris(HDC mdc);    //绘制正在下落的方块 
void drawNext(HDC hdc); //绘制下一个将要掉落的方块
void drawScore(HDC hdc);    //绘制分数
void drawCompleteParticle(int line);

int RandomInt(int _min, int _max);       //获取一个随机int
int CheckValide(int curPosX, int curPosY, BOOL bCurTeris[4][4]);   //给定一个矩阵，查看是否合法
int selectDiffculty(HWND hWnd, int dif);
int selectLayOut(HWND hWnd, int layout);

//常量声明
const int BORDER_X = 5;
const int BORDER_Y = 5;
const int SCREEN_LEFT_X = 300 + BORDER_X;
const int SCREEN_Y = 600 + BORDER_Y;
const int SCREEN_RIGHT_X = 200 + BORDER_X ;
const int SCREEN_X = SCREEN_LEFT_X + SCREEN_RIGHT_X;
const BOOL state_teris[][4][4] =
{
	{ { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,0,0,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 0,0,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,0,0 },{ 1,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,1 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } },
	{ { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } }
};



//全局变量声明
bool g_hasBlocked[50][50];
RECT rc_left, rc_right, rc_right_top, rc_right_bottom, rc_main;
int g_speed = 300;
int t_speed = 300;
BOOL bCurTeris[4][4];
BOOL bNextCurTeris[4][4];
int curPosX, curPosY;
int rd_seed = 1995421;
int tPre = 0, tCur;
int GAME_STATE = 0;
int GAME_SCORE = 0;
int GAME_DIFF = 1;
int NUM_X = 10;
int NUM_Y = 20;
int BLOCK_SIZE = 30;