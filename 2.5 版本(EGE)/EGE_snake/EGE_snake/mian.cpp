#include "GameSetting.h"
#include <fstream>

using namespace std;

mouse_msg msg = { 0 };

extern PIMAGE game_start; // ��Ϸ��ʼͼƬ
extern PIMAGE game_help; // ��Ϸ����ͼƬ
extern PIMAGE game_leaderboard; // ���а�ͼƬ

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

void PlageGame(); // ��Ϸ��ʼ
void Menu(); // �˵�

int main()
{

	// ��ʼ������
	initgraph(Windows_width, Windows_height);
	setcaption("̰����");

	// ��ʼ��ͼƬ
	GetImage();

	Menu();

	closegraph();

	return 0;
}

enum flag {
	playgame = 0,
	help = 1,
	leaderboard = 2,
	quit = 3,
};

int mouse(int x1, int y1, int x2, int y2)   //�ж���(x1,y1)(x2,y2)���η�Χ�ڵ������ 
{
	if (msg.x > x1 && msg.x<x2 && msg.y > y1 && msg.y < y2 && (int)msg.is_down() == 1 && (int)msg.is_left() == 1)
		return 1;
	return 0;
}

void Menu()
{
	int flag = 0;
	bool is_quie = false;
	while (!is_quie)
	{
		putimage(0, 0, game_start);
		for (; is_run(); delay_fps(60))
		{
			while (mousemsg())
			{
				msg = getmouse();
			}
			if (mouse(50,220,350,290))
			{
				flag = playgame;
				break;
			}
			else if (mouse(50, 320, 350, 390))
			{
				flag = leaderboard;
				break;
			}
			else if (mouse(50, 420, 350, 490))
			{
				flag = help;
				break;
			}
			else if (mouse(50, 520, 350, 590))
			{
				flag = quit;
				break;
			}
		}

		switch (flag)
		{
		case playgame:
			PlageGame();
			getch();
			break;
		case help:
			putimage(0, 0, game_help);
			getch();
			break;
		case leaderboard:
			putimage(0, 0, game_leaderboard);
			getch();
			break;
		case quit:
			is_quie = true;
			break;
		}
	}
}

void PlageGame()
{

	// ����
	MUSIC music;

	// ��ͼ��Ϣ
	Map map;
	map.DrawMap();
	// ��ȡ��߷���
	DrawRscore(ReadScore());

	// ����
	Snake snake;

	// ʳ����
	Food food(snake.body);

	double starttime = fclock();
	PlayMusic(music, snake.music_num, snake.is_music_play);
	DrawMusic(1);
	while (!snake.isGameOver)
	{
		if (snake.is_music_change)
		{
			PlayMusic(music, snake.music_num, snake.is_music_play);
			snake.is_music_change = false;
		}
		snake.PlayerMove(food, starttime, music);
	}

	snake.GameOver();

	// д����߷�
	if (snake.score > ReadScore())
		WriteScore(snake.score);

	music.Close(); // �ر�����
}