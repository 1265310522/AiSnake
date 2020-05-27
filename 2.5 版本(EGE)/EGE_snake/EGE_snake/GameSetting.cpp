#include "GameSetting.h"

PIMAGE game_start; // ��Ϸ��ʼͼƬ
PIMAGE game_help; // ��Ϸ����ͼƬ
PIMAGE game_leaderboard; // ���а�ͼƬ
PIMAGE game_over; // ��Ϸ����ͼƬ
PIMAGE wall; // ǽ��ͼƬ
PIMAGE empty; // �յص�ͼƬ
PIMAGE food_tomato; // ����ʳ���ͼƬ
PIMAGE food_mushroom; // Ģ��ʳ���ͼƬ
PIMAGE food_hamburger; // ������ʳ���ͼƬ
PIMAGE snake_body; // ����ͼƬ
PIMAGE snake_head_up; // ��ͷ����
PIMAGE snake_head_down; // ��ͷ����
PIMAGE snake_head_left; // ��ͷ����
PIMAGE snake_head_right; // ��ͷ����


void DrawMusic(int type)
{
	char str[200];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "΢���ź�");
	if (type == 1)
		sprintf(str, "        ��ǰ���֣�Jo Blankenburg - Memento        ");
	else if (type == 2)
		sprintf(str, "                  ��ǰ���֣����� - ����֮��                  ");
	else if (type == 3)
		sprintf(str, "   ��ǰ���֣�����(�Ƥ���) - �뤤�����h�����ա�");
	outtextrect(100, 615, 680, 645, str);
}

void DrawGameInfo()
{
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(22, 0, "΢���ź�");
	xyprintf(710, 260, "        ��Ϸ˵��      ");
	xyprintf(710, 285, "        W���� : ��     ");
	xyprintf(710, 310, "        S���� : ��     ");
	xyprintf(710, 335, "        A���� : ��     ");
	xyprintf(710, 360, "        D���� : ��     ");
	xyprintf(710, 385, "        +  : ����    ");
	xyprintf(710, 410, "         -  : ����     ");
	xyprintf(710, 435, "       �ո� : ��ͣ    ");
	xyprintf(710, 460, "       R : �����ٶ�   ");
	xyprintf(710, 485, "      Q : ��һ������   ");
	xyprintf(710, 510, "       E : ��һ������   ");
	xyprintf(710, 535, "       Y : ��ʼ����   ");
	xyprintf(710, 560, "       N : ֹͣ����   ");
	xyprintf(710, 605, "       ���� : �����  ");
	xyprintf(710, 635, "          �汾 : 2.5    ");

}

void DrawModel(bool model)
{
	setbkcolor(EGERGB(240, 255, 240));
	setfont(25, 0, "΢���ź�");
	setcolor(BLACK);
	if (!model)
		outtextrect(715, 35, 815, 75, "��ǰģʽ�����");
	else
		outtextrect(715, 35, 815, 75, "��ǰģʽ��AI");
}

void DrawLevel(int level)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��ǰ�ٶȵȼ���%d  ", level);
	outtextrect(715, 75, 815, 115, str);
}

void DrawScore(int score)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��ǰ��Ϸ�÷֣�%d", score);
	outtextrect(715, 115, 815, 155, str);
}

void DrawRscore(int rscore)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "�����Ϸ�÷֣�%d", rscore);
	outtextrect(715, 155, 815, 195, str);
}

void DrawTime(double time)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��Ϸʱ�䣺%d", (int)time);
	outtextrect(715, 195, 815, 235, str);
}

void PlayMusic(MUSIC& music, int type, bool play)
{
	if (type == 1)
		music.OpenFile("Jo Blankenburg - Memento.mp3");
	else if (type == 2)
		music.OpenFile("���� - ����֮��.mp3");
	else if (type == 3)
		music.OpenFile("���� (�Ƥ���) - �뤤�����h�����ա�.mp3");
	DrawMusic(type);
	if (play)
		music.Play(); // ��������
	else
		music.Stop(); // ֹͣ����
}


void GetImage()
{
	wall = newimage();
	food_tomato = newimage();
	food_mushroom = newimage();
	food_hamburger = newimage();
	empty = newimage();
	snake_body = newimage();
	snake_head_up = newimage();
	snake_head_down = newimage();
	snake_head_left = newimage();
	snake_head_right = newimage();
	game_start = newimage();
	game_help = newimage();
	game_over = newimage();
	game_leaderboard = newimage();

	getimage(game_start, "gamestart.png");
	getimage(game_help, "help.png");
	getimage(game_over, "gameover.png");
	getimage(game_leaderboard, "leaderboard");
	getimage(wall, "Carrot.png");
	getimage(food_tomato, "fanqie.png");
	getimage(food_mushroom, "mushroom.png");
	getimage(food_hamburger, "hanbao.png");
	getimage(empty, "white.png");
	getimage(snake_body, "snakeBody.jpg");
	getimage(snake_head_up, "snakeHeadUp.png");
	getimage(snake_head_down, "snakeHeadDown.png");
	getimage(snake_head_left, "snakeHeadLeft.png");
	getimage(snake_head_right, "snakeHeadRight.png");

}

void Map::DrawMap()
{
	for (int i = 0; i <= Windows_height; i = i + 20)
	{
		for (int j = 0; j <= Windows_width; j = j + 20)
		{
			if (i == 0 || i == Windows_height - 100 || i == Windows_height - 20)
			{
				putimage(j, i, wall);
			}
			else if (j == 0 || j == Windows_width - 220 || j == Windows_width - 20)
			{
				putimage(j, i, wall);
			}
			else if (j >= 700 && i == Windows_height - 440)
			{
				putimage(j, i, wall);
			}
			else
			{
				putimage(j, i, empty);
			}
		}
	}
}



Snake::Snake()
{
	P tmp_of_rand;
	tmp_of_rand.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
	tmp_of_rand.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
	P head;
	head.x = tmp_of_rand.x * 20;
	head.y = tmp_of_rand.y * 20;
	body.push_back(head);
	this->isEatFood = false;
	this->isGameOver = false;
	this->direction = STOP;
	this->speedModel = false;
	this->score = 0;
	this->level = 1;
	this->music_num = 1;
	this->is_music_play = true;
	this->is_music_change = false;
	this->is_music_play = true;
	this->isAi = false;
	DrawSnake();
}

void Snake::DrawSnake()
{
	P head = this->body.front();

	if (this->direction == STOP)
		putimage(head.x, head.y, snake_head_up);

	switch (this->direction)
	{
	case UP:
		putimage(head.x, head.y, snake_head_up);
		break;
	case DOWN:
		putimage(head.x, head.y, snake_head_down);
		break;
	case LEFT:
		putimage(head.x, head.y, snake_head_right);
		break;
	case RIGHT:
		putimage(head.x, head.y, snake_head_left);
		break;
	}

	if (this->body.size() > 1)
	{
		std::vector<P>::iterator it;
		it = this->body.begin() + 1;
		putimage((*it).x, (*it).y, snake_body);

	}
}

void Snake::CleanSnake()
{
	P tail = this->body.back(); // �����β��Ϣ
	putimage(tail.x, tail.y, empty); // ɾ����β(��ӡ�յ�ͼƬ)
}



void Snake::PlayerMove(Food& food, double starttime, MUSIC& music)
{
	DrawModel(isAi);
	DrawLevel(level);
	DrawScore(score);
	double nowtime = fclock();
	double time = nowtime - starttime;
	DrawTime(time);
	DrawGameInfo();
	if (this->direction == STOP)
		InitDirection(starttime);

	P N_head = body.front();  // �õ���ͷ��Ϣ

	if (kbmsg()) // ����а�������
	{
		if (GetAsyncKeyState(key_space) && 0x8000) // ����Ϊ �ո�� ʱ
		{
			GetDirection_Stop(starttime, music);
		}
		else
			GetDirection(starttime, music);
	}

	switch (this->direction)
	{
	case UP:
		N_head.y -= 20;
		break;
	case DOWN:
		N_head.y += 20;
		break;
	case LEFT:
		N_head.x -= 20;
		break;
	case RIGHT:
		N_head.x += 20;
		break;
	default:
		break;
	}

	body.insert(body.begin(), N_head); // ���ƶ����λ��ѹ��������λ����Ϊ�µ���ͷ

	Check_of_Die(); // �������

	if (Check_of_Food(food))
	{
		if (food.food_type == 1)
			score++;
		else if (food.food_type == 2)
			score += 2;
		else
			score += 3;
		DrawScore(score);
		food.CreatFood(body);
		food.DrawFood();
	}
	else
	{
		this->CleanSnake();
		body.pop_back(); // ɾ����β
	}

	this->DrawSnake();
	if (!this->speedModel)
		this->Getlevel();
	this->Snake_of_Sleep();

}

void Snake::InitDirection(double starttime)
{
	while (1)
	{
		double nowtime = fclock();
		double time = nowtime - starttime;
		DrawTime(time);
		if (GetAsyncKeyState('A') || GetAsyncKeyState('a'))
		{
			if (this->direction != RIGHT)
				this->direction = LEFT;
			break;
		}
		else if (GetAsyncKeyState('D') || GetAsyncKeyState('d'))
		{
			if (this->direction != LEFT)
				this->direction = RIGHT;
			break;
		}
		else if (GetAsyncKeyState('W') || GetAsyncKeyState('w'))
		{
			if (this->direction != DOWN)
				this->direction = UP;
			break;
		}
		else if (GetAsyncKeyState('S') || GetAsyncKeyState('s'))
		{
			if (this->direction != UP)
				this->direction = DOWN;
			break;
		}
		else if (GetAsyncKeyState(key_up))
		{
			if (this->direction != DOWN)
				this->direction = UP;
			break;
		}
		else if (GetAsyncKeyState(key_down))
		{
			if (this->direction != UP)
				this->direction = DOWN;
			break;
		}
		else if (GetAsyncKeyState(key_left))
		{
			if (this->direction != RIGHT)
				this->direction = LEFT;
			break;
		}
		else if (GetAsyncKeyState(key_right))
		{
			if (this->direction != LEFT)
				this->direction = RIGHT;
			break;
		}
	}
}

void Snake::GameOver()
{
	putimage(0, 0, game_over);
}

void Snake::GetDirection_Stop(double starttime, MUSIC& music)
{
	while (1)
	{
		double nowtime = fclock();
		double time = nowtime - starttime;
		DrawTime(time);
		Sleep(300);
		if (GetAsyncKeyState(VK_ADD)) // ����ΪС�����ϵ� + ʱ
		{
			this->speedModel = true;
			if (this->level < 10)
				this->level++;
			DrawLevel(level);
		}
		else if (GetAsyncKeyState(VK_SUBTRACT)) // ����ΪС�����ϵ� - ʱ
		{
			this->speedModel = true;
			if (this->level > 1)
				this->level--;
			DrawLevel(level);
		}
		else if (GetAsyncKeyState('R') || GetAsyncKeyState('r'))
		{
			this->speedModel = false;
			Getlevel();
			DrawLevel(level);
		}
		else if (GetAsyncKeyState('Q') || GetAsyncKeyState('q'))
		{
			//is_music_change = true;
			if (this->music_num > 1)
				this->music_num--;
			else
				this->music_num = 3;
			PlayMusic(music, music_num, is_music_play);
		}
		else if (GetAsyncKeyState('E') || GetAsyncKeyState('e'))
		{
			//is_music_change = true;
			if (this->music_num < 3)
				this->music_num++;
			else
				this->music_num = 1;
			PlayMusic(music, music_num, is_music_play);
		}
		else if (GetAsyncKeyState('Y') || GetAsyncKeyState('y'))
		{
			//is_music_change = true;
			is_music_play = true;
			PlayMusic(music, music_num, is_music_play);
		}
		else if (GetAsyncKeyState('N') || GetAsyncKeyState('n'))
		{
			//is_music_change = true;
			is_music_play = false;
			PlayMusic(music, music_num, is_music_play);
		}
		else if (GetAsyncKeyState(key_space) && 0x8000)
		{
			break;
		}
	}

}

void Snake::GetDirection(double starttime, MUSIC& music)
{

	if (GetAsyncKeyState('A') || GetAsyncKeyState('a'))
	{
		if (this->direction != RIGHT)
			this->direction = LEFT;
	}
	else if (GetAsyncKeyState('D') || GetAsyncKeyState('d'))
	{
		if (this->direction != LEFT)
			this->direction = RIGHT;
	}
	else if (GetAsyncKeyState('W') || GetAsyncKeyState('w'))
	{
		if (this->direction != DOWN)
			this->direction = UP;
	}
	else if (GetAsyncKeyState('S') || GetAsyncKeyState('s'))
	{
		if (this->direction != UP)
			this->direction = DOWN;
	}
	else if (GetAsyncKeyState('Q') || GetAsyncKeyState('q'))
	{
		is_music_change = true;
		if (this->music_num > 1)
			this->music_num--;
		else
			this->music_num = 3;
	}
	else if (GetAsyncKeyState('E') || GetAsyncKeyState('e'))
	{
		is_music_change = true;
		if (this->music_num < 3)
			this->music_num++;
		else
			this->music_num = 1;
	}
	else if (GetAsyncKeyState('Y') || GetAsyncKeyState('y'))
	{
		is_music_change = true;
		is_music_play = true;
	}
	else if (GetAsyncKeyState('N') || GetAsyncKeyState('n'))
	{
		is_music_change = true;
		is_music_play = false;
	}
	else if (GetAsyncKeyState(key_up))
	{
		if (this->direction != DOWN)
			this->direction = UP;
	}
	else if (GetAsyncKeyState(key_down))
	{
		if (this->direction != UP)
			this->direction = DOWN;
	}
	else if (GetAsyncKeyState(key_left))
	{
		if (this->direction != RIGHT)
			this->direction = LEFT;
	}
	else if (GetAsyncKeyState(key_right))
	{
		if (this->direction != LEFT)
			this->direction = RIGHT;
	}
	else if (GetAsyncKeyState('R') || GetAsyncKeyState('r'))
	{
		this->speedModel = false;
		Getlevel();
		DrawLevel(level);
	}
	else if (GetAsyncKeyState(VK_ADD)) // ����ΪС�����ϵ� + ʱ
	{
		this->speedModel = true;
		if (this->level < 10)
			this->level++;
		DrawLevel(level);
	}
	else if (GetAsyncKeyState(VK_SUBTRACT)) // ����ΪС�����ϵ� - ʱ
	{
		this->speedModel = true;
		if (this->level > 1)
			this->level--;
		DrawLevel(level);
	}
}

void Snake::Getlevel()
{
	if (score <= level_1)
	{
		this->level = 1;
	}
	else if (score > level_1 && score <= level_2)
	{
		this->level = 2;
	}
	else if (score > level_2 && score <= level_3)
	{
		this->level = 3;
	}
	else if (score > level_3 && score <= level_4)
	{
		this->level = 3;
	}
	else if (score > level_4 && score <= level_5)
	{
		this->level = 4;
	}
	else if (score > level_5 && score <= level_6)
	{
		this->level = 5;
	}
	else if (score > level_6 && score <= level_7)
	{
		this->level = 6;
	}
	else if (score > level_7 && score <= level_8)
	{
		this->level = 7;
	}
	else if (score > level_8 && score <= level_9)
	{
		this->level = 8;
	}
	else if (score > level_9 && score <= level_10)
	{
		this->level = 9;
	}
	else {
		this->level = 10;
	}
}

bool Snake::Check_of_Food(Food& food)
{
	P head = this->body.front();
	if (head.x == food.pos_of_food.x && head.y == food.pos_of_food.y)
		return true;
	return false;
}

void Snake::Snake_of_Sleep()
{
	switch (this->level)
	{
	case 1:
		Sleep(200);
		break;
	case 2:
		Sleep(180);
		break;
	case 3:
		Sleep(160);
		break;
	case 4:
		Sleep(140);
		break;
	case 5:
		Sleep(120);
		break;
	case 6:
		Sleep(100);
		break;
	case 7:
		Sleep(80);
		break;
	case 8:
		Sleep(60);
		break;
	case 9:
		Sleep(40);
		break;
	case 10:
		Sleep(20);
		break;
	}
}

void Snake::Check_of_Die()
{
	P head = this->body.front();

	if (head.x == 0 || head.x == Windows_width - 220 || head.y == 0 || head.y == Windows_height - 100)
		this->isGameOver = true;

	std::vector<P>::iterator it;
	for (it = body.begin() + 1; it != body.end(); it++)
	{
		if (head.x == (*it).x && head.y == (*it).y)
		{
			this->isGameOver = true;
			break;
		}
	}
}


Food::Food(std::vector<P>& snake)
{
	CreatFood(snake);
	DrawFood();
}

void Food::CreatFood(std::vector<P>& snake)
{
	P tmp_of_rand;
	tmp_of_rand.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
	tmp_of_rand.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
	pos_of_food.x = tmp_of_rand.x * 20;
	pos_of_food.y = tmp_of_rand.y * 20;
	std::vector<P>::iterator it; // ������
	for (it = snake.begin(); it != snake.end(); it++) // ������
	{
		if ((*it).x == pos_of_food.x && (*it).y == pos_of_food.y) // ����ߺ�ʳ���ص�
		{
			tmp_of_rand.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
			tmp_of_rand.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
			pos_of_food.x = tmp_of_rand.x * 20;
			pos_of_food.y = tmp_of_rand.y * 20;
			it = snake.begin(); // ����������ָ����ͷ�����½��б���
		}
	}
}

void Food::DrawFood()
{
	int food = rand() % 3 + 1;
	switch (food)
	{
	case 1:
		putimage(pos_of_food.x, pos_of_food.y, food_mushroom);
		this->food_type = 1;
		break;
	case 2:
		putimage(pos_of_food.x, pos_of_food.y, food_tomato);
		this->food_type = 2;
		break;
	case 3:
		putimage(pos_of_food.x, pos_of_food.y, food_hamburger);
		this->food_type = 3;
		break;
	default:
		break;
	}
}
