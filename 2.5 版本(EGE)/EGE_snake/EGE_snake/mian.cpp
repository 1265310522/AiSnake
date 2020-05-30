#include "GameSetting.h"
#include <algorithm> // vector 自定义排序

using namespace std;

mouse_msg msg = { 0 };

extern PIMAGE game_start; // 游戏开始图片
extern PIMAGE game_help; // 游戏帮助图片
extern PIMAGE game_leaderboard; // 排行榜图片
extern PIMAGE game_model; // 模式图片

vector<L> read; // 存储历史记录

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
		return true; // 停止读取
	else
		return false; // 继续读取

}

bool Comp(const L& max, const L& min)
{
	return max.score > min.score;
}
void Drawleaderboard()
{
	ifstream ReadFile;
	ReadFile.open("leaderboard.txt"); // 打开文件夹
	while (!ReadLeaderboard(ReadFile));
	getbkcolor(game_leaderboard);
	setbkmode(TRANSPARENT);
	setbkcolor(getbkcolor(game_leaderboard));
	//设置背景颜色为
	setcolor(GREEN);
	setfont(30, 0, "微软雅黑");
	sort(read.begin(), read.end(), Comp);
	outtextrect(250, 30, 350, 60, "排名");
	outtextrect(350, 30, 450, 60, "姓名");
	outtextrect(450, 30, 550, 60, "分数");
	outtextrect(550, 30, 650, 60, "时间");
	vector<L>::iterator it;
	char time[20];
	char leader[10];
	char score[4];
	int i = 1;
	int num = 0;
	for (it = read.begin(); it != read.end(); it++,i++)
	{
		sprintf(leader, "第%d名", i);
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


void WriteScore(int Score) // 记录最高分数
{
	ofstream OutFile;
	OutFile.open("Score.txt"); // 打开分数文件夹
	OutFile << Score << endl; // 录入分数
	OutFile.close(); // 关闭文件夹
}

int ReadScore() // 读取最高分数
{
	int score = 0; // 分数
	ifstream ReadFile;
	ReadFile.open("Score.txt"); // 打开文件夹
	ReadFile >> score; // 读取分数
	ReadFile.close(); // 关闭文件夹
	return score;
}



void PlageGame(); // 游戏开始
void Menu(); // 菜单

int main()
{

	// 初始化画布
	initgraph(Windows_width, Windows_height);
	setcaption("贪吃蛇");

	// 初始化图片
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

int mouse(int x1, int y1, int x2, int y2)   //判断在(x1,y1)(x2,y2)矩形范围内单机左键 
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
	// 模式选择
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
	// 音乐
	MUSIC music;

	// 地图信息
	Map map;
	map.DrawMap();
	// 读取最高分数
	DrawRscore(ReadScore());

	// 蛇类
	Snake snake;
	snake.isAi = model;

	// 食物类
	Food food(snake.body);

	double starttime = fclock();
	PlayMusic(music, snake.music_num, snake.is_music_play, snake.type_change);
	snake.type_change = false;
	DrawMusic(1);
	
	// 进入游戏
	
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

	// 写入最高分
	if (snake.score > ReadScore())
		WriteScore(snake.score);

	music.Close(); // 关闭音乐
}