#pragma once

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;

class Food;


// ����·������������
int Dirx[4] = { 0,0,-1,1 };
int Diry[4] = { -1,1,0,0 };


void WriteScore(int Score) // ��¼��߷���
{
	ofstream OutFile;
	OutFile.open("Score.txt"); // �򿪷����ļ���
	OutFile << Score << endl; // ¼�����
	OutFile.close(); // �ر��ļ���
}

int ReadScore() // ��ȡ��߷���
{
	int score = 0; // ����
	ifstream ReadFile;
	ReadFile.open("Score.txt"); // ���ļ���
	ReadFile >> score; // ��ȡ����
	ReadFile.close(); // �ر��ļ���
	return score;
}


// gotoxy(x,y) : ������ƶ��� x �� y ��
void gotoxy(SHORT x, SHORT y) {
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

//������ɫ 
void setColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ
}

typedef struct Point {
	int x;
	int y;
}P;

class BasicSetting {

public:
	// ������Ϸ���ڴ�С
	static const int windows_height = 40;
	static const int windows_width = 80;
public:
	static void GameInit()
	{
		char buffer[32];
		sprintf_s(buffer, "mode con cols=%d lines=%d", windows_width, windows_height);
		system(buffer); // ͨ���ַ�������ʽ�����ƿ���̨�Ĵ�С
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
		CursorInfo.bVisible = false; //���ؿ���̨���
		SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
		srand((unsigned int)time(0)); //��ʼ�����������
	}
};

class Map {
public:
	static void DrawMap(); // ��ӡ��ͼ

	static void GameOver(int Score); // ��Ϸ����

	static void DrawScore(); // ��ӡ����	

	static void DrawGameInfo(bool model); // ��ӡ��Ϸ˵��

	bool DrawChoiceInfo(); // ѡ����Ϸģʽ
};


class Snake {

public:
	friend class Food; // ��Ԫ��
	Snake()
	{
		Head.x = rand() % (BasicSetting::windows_width - 30) + 1; // x �ķ�ΧΪ 1-50
		Head.y = rand() % (BasicSetting::windows_height - 2) + 1; // y �ķ�ΧΪ 1-38
		body.push_back(Head); // ����ͷѹ��������
		level = 1; // Ĭ�ϵȼ�Ϊ 1 ��
		isTurn = false; // Ĭ�Ϲر��ֶ��ٶȵ��ڻ���
		score = 0; // Ĭ��Ϊ���
		isAi = false; // Ĭ��Ϊ���ģʽ
		isGameOver = false; // Ĭ����Ϸδ����
		direction = STOP; // Ĭ����ͷ����
		record = ReadScore();
		gotoxy(BasicSetting::windows_width - 22, 10);
		cout << "��ʷ��߷���: " << record << endl; // ��ӡ��߷�
		DrawSnake(); // ��ӡ��
	}
public:
	// ����ӿ�
	// ���Ա����
	vector<P> body; // �洢��
	bool isGameOver; // �ж���Ϸ�Ƿ����
	int score; // ���������Ե�ʳ�����
	int record; // ��ʷzuigaof
	bool isAi; // �Ƿ��� Ai ģʽ

public:

	// ����ӿ�
	// ���Ա����

	void SnakeMove(Food& food); // �����ߵ��ƶ�
	void AiMove(Food& food); // ���� AI �ߵ��ƶ�
private:

	// ö�ٸ�������
	enum Direction {
		UP = 8,
		DOWN = 2,
		LEFT = 4,
		RIGHT = 6,
		STOP = 0,
	};

	// ö�ٸ��ٶȵȼ�����Ҫ�ﵽ�ķ���
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

	// ˽�б���
	// ���Ա����
	P Head; // ��ͷ
	int direction; // �ߵ��ƶ�����
	int level; // �ߵ��ٶȵȼ����ȼ�Խ�ߣ��ٶ�Խ��
	bool isTurn; // �Ƿ��ֶ��ı���Ϸ�ٶȣ����ֶ��ı���Ϸ�ٶȣ���ر��Զ������ٶȻ���
	queue<P> path; // ���·���Ķ���

private:
	// ˽�к���
	// ���Ա����
	bool IsEatFood(Food& food); // �Ƿ�Ե�ʳ��
	bool IsHitWall(); // �Ƿ�ײ��ǽ
	bool IsHitBody(); // �Ƿ�ײ������
	void Move(Food& food); // �ߵ��ƶ�
	void GetKbHit(); // ��÷���
	void GetLevel(); // ��ô�ʱ���ٶȵȼ�
	void SnakeSleep(int level); // ˢ����
	void DrawSnake(); // ��ӡ����
	void CleanSnake(); // �������
	void GetPath(Food& food); // �õ�·��
};


class Food {
public:
	Food(vector<P>& snake)
	{
		CreatFood(snake);
		DrawFood(); // ��ӡʳ��
	}
private:
	// ˽�б���
	// ���Ա����
	friend class Snake; // ��Ԫ��
	friend class BFS; // ��Ԫ��
	P P_food;
public:
	// ����ӿ�
	// ���Ա����
private:
	// ˽�к���
	void CreatFood(vector<P>& snake);
	void DrawFood(); // ��ӡʳ��

};


class BFS {

public:
	BFS(vector<P>& snake)
	{
		InitMap(snake);
	}
	bool FindPath(Food& food); // �ҵ�·�����������õ���Ϣ��
private:
	friend class Snake;
	P head; // �洢��ͷ��λ��
	queue<P> path; // �洢·��
	int bfs_map[BasicSetting::windows_width - 28][BasicSetting::windows_height]; // ��ά����洢
	P** bfs_father; // �ö�ά����洢���ڵ�
private:
	void InitMap(vector<P>& snake);
	queue<P> GetPath(Food& food); // �õ�·�����޳����õ���Ϣ��
	void GetPath_action(P& pos);
};