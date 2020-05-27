#pragma once
#pragma once
#include <iostream>
#include <vector>
#include<windows.h> 
#include<Mmsystem.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")
void DrawRscore(int rscore);
void DrawTime(double time);
void DrawMusic(int type);
void PlayMusic(MUSIC& music, int type, bool play);



void GetImage(); // ���ͼƬ

static const int Windows_width = 900; // ���ÿ�
static const int Windows_height = 680; // ���ø�

typedef struct Point {
	int x;
	int y;
}P;

class Food;

class Map {

public:
	friend class EgeSetting;
	void DrawMap(); // ��ӡ��ͼ
};

// ö�ٸ��ٶȵȼ�����Ҫ�ﵽ�ķ���
enum score_of_level {
	level_1 = 1,
	level_2 = 3,
	level_3 = 9,
	level_4 = 18,
	level_5 = 27,
	level_6 = 54,
	level_7 = 108,
	level_8 = 216,
	level_9 = 512,
	level_10 = 1024,
};

// ö�ٸ�������
enum direction {
	UP = 8,
	DOWN = 2,
	LEFT = 4,
	RIGHT = 6,
	STOP = 0,
};

class Food
{

public:
	Food(std::vector<P>& snake);
	int food_type = 0; // ʳ������
	P pos_of_food; // ʳ������
	void CreatFood(std::vector<P>& snake);
	void DrawFood(); // ��ӡʳ��

};

class Snake {

public:
	Snake();
	std::vector<P> body; // �洢����Ϣ

public:
	void PlayerMove(Food& food, double starttime, MUSIC& music); // ���ģʽ�ƶ�
	void InitDirection(double starttime); // ��ʼ���ƶ�����
	void GameOver(); // ��Ϸ����
	bool isGameOver; // �Ƿ�����
	int score; // ����
	int music_num; // ����ѡ��
	bool is_music_change; // �Ƿ��л�����
	bool is_music_play; // �Ƿ񲥷�����
	bool isAi;
private:
	void DrawSnake(); // ��ӡ��ͷ
	void CleanSnake(); // ɾ����β
	void GetDirection(double starttime, MUSIC& music); // ����ƶ��ķ���
	void Getlevel(); // ����ٶȵȼ�
	void Check_of_Die(); // �������
	bool Check_of_Food(Food& food); // ʳ����
	void Snake_of_Sleep(); // ˢ����
	void GetDirection_Stop(double starttime, MUSIC& music); // ֹͣ�ƶ�
	// void AiMove(); // Aiģʽ�ƶ�

private:
	int level; // ���ƶ��Ŀ����ȼ�	
	int direction; // ���з���
	bool isEatFood; // �Ƿ�Ե�ʳ��
	bool speedModel; // �ٶ�ģʽ(false Ϊ �Զ�, true Ϊ �ֶ�)
};




