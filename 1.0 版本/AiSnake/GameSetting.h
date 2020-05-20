#pragma once

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<vector>
using namespace std;

class Food;

// gotoxy(x,y) : 将光标移动到 x 行 y 列
void gotoxy(SHORT x, SHORT y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

//设置颜色 
void setColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

typedef struct Point {
	int x;
	int y;
}P;

class BasicSetting {

public:
	// 设置游戏窗口大小
	static const int windows_height = 40;
	static const int windows_width = 80;
public:
	static void GameInit()
	{
		char buffer[32];
		sprintf_s(buffer, "mode con cols=%d lines=%d", windows_width, windows_height);
		system(buffer); // 通过字符串的形式来控制控制台的大小
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
		CursorInfo.bVisible = false; //隐藏控制台光标
		SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
		srand((unsigned int)time(0)); //初始化随机数种子
	}
};

class Map {
public:
	static void DrawMap(); // 打印地图

	static void GameOver(int Score); // 游戏结束

	static void DrawScore(); // 打印分数	

	static void DrawGameInfo(); // 打印游戏说明
};


class Snake {
public:
	friend class Food; // 友元类
	Snake()
	{
		Head.x = rand() % (BasicSetting::windows_width - 30) + 1; // x 的范围为 1-50
		Head.y = rand() % (BasicSetting::windows_height - 2) + 1; // y 的范围为 1-38
		body.push_back(Head); // 将蛇头压入容器内
		level = 1; // 默认等级为 1 级
		isTurn = false; // 默认关闭手动速度调节机制
		score = 0; // 默认为零分
		isGameOver = false; // 默认游戏未结束
		direction = STOP; // 默认蛇头不动
		DrawSnake(); // 打印蛇
	}
public:
	// 对外接口
	// 类成员变量
	vector<P> body; // 存储蛇
	bool isGameOver; // 判断游戏是否结束
	int score; // 分数——吃的食物个数

public:

	// 对外接口
	// 类成员函数

	void SnakeMove(Food& food); // 调用蛇的移动

private:

	// 枚举各个方向
	enum Direction {
		UP = 8,
		DOWN = 2,
		LEFT = 4,
		RIGHT = 6,
		STOP = 0,
	};

	// 枚举各速度等级所需要达到的分数
	enum {
		level_1 = 1,
		level_2 = 2,
		level_3 = 4,
		level_4 = 6,
		level_5 = 10,
		level_6 = 16,
		level_7 = 26,
		level_8 = 42,
		level_9 = 68,
		level_10 = 110,
	};

	// 私有变量
	// 类成员变量
	P Head; // 蛇头
	int direction; // 蛇的移动方向
	int level; // 蛇的速度等级，等级越高，速度越快
	bool isTurn; // 是否手动改变游戏速度，若手动改变游戏速度，则关闭自动调节速度机制

private:
	// 私有函数
	// 类成员函数
	bool IsEatFood(Food& food); // 是否吃到食物
	bool IsHitWall(); // 是否撞到墙
	bool IsHitBody(); // 是否撞到身体
	void Move(Food& food); // 蛇的移动
	void GetKbHit(); // 获得方向
	void GetLevel(); // 获得此时的速度等级
	void SnakeSleep(int level); // 刷新率
	void DrawSnake(); // 打印蛇身
	void CleanSnake(); // 清楚蛇身
};


class Food {
public:
	Food(vector<P>& snake)
	{
		CreatFood(snake);
		DrawFood(); // 打印食物
	}

private:
	// 私有变量
	// 类成员变量
	friend class Snake; // 友元类
	P P_food;
public:
	// 对外接口
	// 类成员函数

private:
	// 私有函数
	void CreatFood(vector<P>& snake);
	void DrawFood(); // 打印食物

};