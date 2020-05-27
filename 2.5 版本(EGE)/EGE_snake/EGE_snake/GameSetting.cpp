#include "GameSetting.h"

PIMAGE game_start; // 游戏开始图片
PIMAGE game_help; // 游戏帮助图片
PIMAGE game_leaderboard; // 排行榜图片
PIMAGE game_over; // 游戏结束图片
PIMAGE wall; // 墙的图片
PIMAGE empty; // 空地的图片
PIMAGE food_tomato; // 番茄食物的图片
PIMAGE food_mushroom; // 蘑菇食物的图片
PIMAGE food_hamburger; // 汉堡包食物的图片
PIMAGE snake_body; // 蛇身图片
PIMAGE snake_head_up; // 蛇头向上
PIMAGE snake_head_down; // 蛇头向下
PIMAGE snake_head_left; // 蛇头向左
PIMAGE snake_head_right; // 蛇头向右


void DrawMusic(int type)
{
	char str[200];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "微软雅黑");
	if (type == 1)
		sprintf(str, "        当前音乐：Jo Blankenburg - Memento        ");
	else if (type == 2)
		sprintf(str, "                  当前音乐：傅许 - 夏日之梦                  ");
	else if (type == 3)
		sprintf(str, "   当前音乐：天门(てんもん) - 想い出は遠くの日々");
	outtextrect(100, 615, 680, 645, str);
}

void DrawGameInfo()
{
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(22, 0, "微软雅黑");
	xyprintf(710, 260, "        游戏说明      ");
	xyprintf(710, 285, "        W、↑ : 上     ");
	xyprintf(710, 310, "        S、↓ : 下     ");
	xyprintf(710, 335, "        A、← : 左     ");
	xyprintf(710, 360, "        D、→ : 右     ");
	xyprintf(710, 385, "        +  : 加速    ");
	xyprintf(710, 410, "         -  : 减速     ");
	xyprintf(710, 435, "       空格 : 暂停    ");
	xyprintf(710, 460, "       R : 正常速度   ");
	xyprintf(710, 485, "      Q : 上一首音乐   ");
	xyprintf(710, 510, "       E : 下一首音乐   ");
	xyprintf(710, 535, "       Y : 开始播放   ");
	xyprintf(710, 560, "       N : 停止播放   ");
	xyprintf(710, 605, "       作者 : 邓皓文  ");
	xyprintf(710, 635, "          版本 : 2.5    ");

}

void DrawModel(bool model)
{
	setbkcolor(EGERGB(240, 255, 240));
	setfont(25, 0, "微软雅黑");
	setcolor(BLACK);
	if (!model)
		outtextrect(715, 35, 815, 75, "当前模式：玩家");
	else
		outtextrect(715, 35, 815, 75, "当前模式：AI");
}

void DrawLevel(int level)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "当前速度等级：%d  ", level);
	outtextrect(715, 75, 815, 115, str);
}

void DrawScore(int score)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "当前游戏得分：%d", score);
	outtextrect(715, 115, 815, 155, str);
}

void DrawRscore(int rscore)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "最高游戏得分：%d", rscore);
	outtextrect(715, 155, 815, 195, str);
}

void DrawTime(double time)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "游戏时间：%d", (int)time);
	outtextrect(715, 195, 815, 235, str);
}

void PlayMusic(MUSIC& music, int type, bool play)
{
	if (type == 1)
		music.OpenFile("Jo Blankenburg - Memento.mp3");
	else if (type == 2)
		music.OpenFile("傅许 - 夏日之梦.mp3");
	else if (type == 3)
		music.OpenFile("天门 (てんもん) - 想い出は遠くの日々.mp3");
	DrawMusic(type);
	if (play)
		music.Play(); // 播放音乐
	else
		music.Stop(); // 停止播放
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
	tmp_of_rand.x = rand() % (33) + 1; // x 的范围为 1-33
	tmp_of_rand.y = rand() % (26) + 1; // y 的范围为 1-26
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
	P tail = this->body.back(); // 获得蛇尾信息
	putimage(tail.x, tail.y, empty); // 删除蛇尾(打印空地图片)
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

	P N_head = body.front();  // 得到蛇头信息

	if (kbmsg()) // 如果有按键按下
	{
		if (GetAsyncKeyState(key_space) && 0x8000) // 按键为 空格键 时
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

	body.insert(body.begin(), N_head); // 将移动后的位置压入数组首位，成为新的蛇头

	Check_of_Die(); // 死亡检测

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
		body.pop_back(); // 删除蛇尾
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
		if (GetAsyncKeyState(VK_ADD)) // 按键为小键盘上的 + 时
		{
			this->speedModel = true;
			if (this->level < 10)
				this->level++;
			DrawLevel(level);
		}
		else if (GetAsyncKeyState(VK_SUBTRACT)) // 按键为小键盘上的 - 时
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
	else if (GetAsyncKeyState(VK_ADD)) // 按键为小键盘上的 + 时
	{
		this->speedModel = true;
		if (this->level < 10)
			this->level++;
		DrawLevel(level);
	}
	else if (GetAsyncKeyState(VK_SUBTRACT)) // 按键为小键盘上的 - 时
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
	tmp_of_rand.x = rand() % (33) + 1; // x 的范围为 1-33
	tmp_of_rand.y = rand() % (26) + 1; // y 的范围为 1-26
	pos_of_food.x = tmp_of_rand.x * 20;
	pos_of_food.y = tmp_of_rand.y * 20;
	std::vector<P>::iterator it; // 迭代器
	for (it = snake.begin(); it != snake.end(); it++) // 遍历蛇
	{
		if ((*it).x == pos_of_food.x && (*it).y == pos_of_food.y) // 如果蛇和食物重叠
		{
			tmp_of_rand.x = rand() % (33) + 1; // x 的范围为 1-33
			tmp_of_rand.y = rand() % (26) + 1; // y 的范围为 1-26
			pos_of_food.x = tmp_of_rand.x * 20;
			pos_of_food.y = tmp_of_rand.y * 20;
			it = snake.begin(); // 矫正迭代器指向蛇头，重新进行遍历
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
