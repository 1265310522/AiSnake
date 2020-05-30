#include "GameSetting.h"
#include <algorithm> // vector �Զ�������

using namespace std;

mouse_msg msg = { 0 };

extern PIMAGE game_start; // ��Ϸ��ʼͼƬ
extern PIMAGE game_help; // ��Ϸ����ͼƬ
extern PIMAGE game_leaderboard; // ���а�ͼƬ
extern PIMAGE game_model; // ģʽͼƬ

vector<L> read; // �洢��ʷ��¼

bool ReadLeaderboard(std::ifstream& ReadFile)
{
	L tmp;
	ReadFile >> tmp.name;
	ReadFile >> tmp.score;
	ReadFile >> tmp.year;
	ReadFile >> tmp.month;
	ReadFile >> tmp.day;
	ReadFile >> tmp.hour;
	ReadFile >> tmp.min;
	ReadFile >> tmp.sec;

	read.push_back(tmp);
	if (ReadFile.peek() == EOF)
		return true; // ֹͣ��ȡ
	else
		return false; // ������ȡ

}

bool Comp(const L& max, const L& min)
{
	return max.score > min.score;
}
void Drawleaderboard()
{
	ifstream ReadFile;
	ReadFile.open("leaderboard.txt"); // ���ļ���
	while (!ReadLeaderboard(ReadFile));
	getbkcolor(game_leaderboard);
	setbkmode(TRANSPARENT);
	setbkcolor(getbkcolor(game_leaderboard));
	//���ñ�����ɫΪ
	setcolor(GREEN);
	setfont(30, 0, "΢���ź�");
	sort(read.begin(), read.end(), Comp);
	outtextrect(250, 30, 350, 60, "����");
	outtextrect(350, 30, 450, 60, "����");
	outtextrect(450, 30, 550, 60, "����");
	outtextrect(550, 30, 650, 60, "ʱ��");
	vector<L>::iterator it;
	char time[20];
	char leader[10];
	char score[4];
	int i = 1;
	int num = 0;
	for (it = read.begin(); it != read.end(); it++,i++)
	{
		sprintf(leader, "��%d��", i);
		sprintf(time,"%02d-%02d-%02d %02d:%02d:%02d",(*it).year, (*it).month, (*it).day, (*it).hour, (*it).min, (*it).sec);
		sprintf(score, "%d", (*it).score);
		outtextrect(250, 30 + (i * 50), 350, 60 + (i * 50), leader);
		outtextrect(350, 30 + (i * 50), 450, 60 + (i * 50), (*it).name);
		outtextrect(450, 30 + (i * 50), 550, 60 + (i * 50), score);
		outtextrect(550, 30 + (i * 50), 650, 60 + (i * 50), time);
		num++;
		if (num == 9)
		{
			break;
		}
	}
	ReadFile.close();
}


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
		putimage(0, 0, 900, 680, game_start, 0, 0, 900, 680);

		for (; is_run() ; delay_fps(60))
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
			putimage(0, 0,900,680, game_help, 0, 0, 900, 680);
			getch();
			break;
		case leaderboard:
			putimage(0, 0, 900, 680, game_leaderboard, 0, 0, 900, 680);	
			Drawleaderboard();
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
	// ģʽѡ��
	srand(unsigned(time(0)));
	bool model = false;
	putimage(0, 0, game_model);
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (mouse(310, 150, 660, 250))
		{
			model = false;
			break;
		}
		if (mouse(310, 450, 660, 540))
		{
			model = true;
			break;
		}
	}
	// ����
	MUSIC music;

	// ��ͼ��Ϣ
	Map map;
	map.DrawMap();
	// ��ȡ��߷���
	DrawRscore(ReadScore());

	// ����
	Snake snake;
	snake.isAi = model;

	// ʳ����
	Food food(snake.body);

	double starttime = fclock();
	PlayMusic(music, snake.music_num, snake.is_music_play, snake.type_change);
	snake.type_change = false;
	DrawMusic(1);
	
	// ������Ϸ
	
	while (!snake.isGameOver)
	{
		if (snake.is_music_change)
		{
			PlayMusic(music, snake.music_num, snake.is_music_play,snake.type_change);
			snake.is_music_change = false;
			snake.type_change = false; 
		}
		if (music.GetPlayStatus() == MUSIC_MODE_STOP && snake.is_music_play == true)
			music.Play(0);
		if (!snake.isAi)
			snake.PlayerMove(food, starttime, music);
		else
			snake.AiMove(food, starttime, music);
	}

	// x:20-320;y:240-460
	snake.GameOver();

	// д����߷�
	if (snake.score > ReadScore())
		WriteScore(snake.score);

	music.Close(); // �ر�����
}