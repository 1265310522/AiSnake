#include "GameSetting.h"

PIMAGE game_start; // 游戏开始图片
PIMAGE game_help; // 游戏帮助图片
PIMAGE game_leaderboard; // 排行榜图片
PIMAGE game_over; // 游戏结束图片
PIMAGE game_model; // 空地的图片
PIMAGE wall; // 墙的图片
PIMAGE empty; // 空地的图片
PIMAGE tree; // 障碍物的图片
PIMAGE food_tomato; // 番茄食物的图片
PIMAGE food_mushroom; // 蘑菇食物的图片
PIMAGE food_hamburger; // 汉堡包食物的图片
PIMAGE snake_body; // 蛇身图片
PIMAGE snake_head_up; // 蛇头向上
PIMAGE snake_head_down; // 蛇头向下
PIMAGE snake_head_left; // 蛇头向左
PIMAGE snake_head_right; // 蛇头向右

// 定义路径，上下左右
int Dirx[4] = { 0,-1,0,1 };
int Diry[4] = { -1,0,1,0 };

void DrawMusic(int type)
{
	char str[200];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "微软雅黑");
	if (type == 1)
		sprintf(str, "                   当前音乐：Mich - Skyland               ");
	else if (type == 2)
		sprintf(str, "                  当前音乐：傅许 - 夏日之梦                  ");
	else if (type == 3)
		sprintf(str, "   当前音乐：天门(てんもん) - 想い出は遠くの日々  ");
	else if (type == 4)
		sprintf(str, "        当前音乐：Jo Blankenburg - Memento        ");
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
		outtextrect(710, 35, 815, 75, "当前模式：玩家");
	else
		outtextrect(710, 35, 815, 75, "当前模式：AI");
}

void DrawLevel(int level)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "当前速度等级：%d  ", level);
	outtextrect(710, 75, 815, 115, str);
}

void DrawScore(int score)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "当前游戏得分：%d", score);
	outtextrect(710, 115, 815, 155, str);
}

void DrawRscore(int rscore)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "最高游戏得分：%d", rscore);
	outtextrect(710, 155, 815, 195, str);
}

void DrawTime(double time)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑");
	sprintf(str, "游戏时间：%d", (int)time);
	outtextrect(710, 195, 815, 235, str);
}

void PlayMusic(MUSIC& music, int type, bool play, bool type_change)
{
	if (type_change)
	{
		if (type == 1)
			music.OpenFile("Mich - Skyland.mp3");			
		else if (type == 2)
			music.OpenFile("傅许 - 夏日之梦.mp3");
		else if (type == 3)
			music.OpenFile("天门 (てんもん) - 想い出は遠くの日々.mp3");
		else if(type==4)
			music.OpenFile("Jo Blankenburg - Memento.mp3");
		DrawMusic(type);
	}
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
	game_model = newimage();
	tree = newimage();

	getimage(game_start, "gamestart.png");
	getimage(game_model, "model.png");
	getimage(game_help, "help.png");
	getimage(game_over, "gameover.png");
	getimage(game_leaderboard, "leaderboard.png");
	getimage(wall, "Carrot.png");
	getimage(tree, "tree.png");
	getimage(food_tomato, "fanqie.png");
	getimage(food_mushroom, "mushroom.png");
	getimage(food_hamburger, "hanbao.png");
	getimage(empty, "white.png");
	getimage(snake_body, "snakeBody.jpg");
	getimage(snake_head_up, "snakeHeadUp.png");
	getimage(snake_head_down, "snakeHeadDown.png");
	getimage(snake_head_right, "snakeHeadRight.png");
	getimage(snake_head_left, "snakeHeadLeft.png");
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
	P head;
	head.x = rand() % (33) + 1; // x 的范围为 1-33
	head.y = rand() % (26) + 1; // y 的范围为 1-26
	body.push_back(head);
	this->isEatFood = false;
	this->isGameOver = false;
	this->direction = STOP;
	this->speedModel = false;
	this->score = 0;
	this->level = 1;
	this->music_num = 1;
	this->t = 0;
	this->is_music_play = true;
	this->is_music_change = false;
	this->is_music_play = true;
	this->type_change = true;
	this->isAi = true;
	DrawSnake();
}

void Snake::DrawSnake()
{
	P head = this->body.front();

	if (this->direction == STOP)
		putimage(head.x*20, head.y*20, snake_head_up);

	switch (this->direction)
	{
	case UP:
		putimage(head.x*20, head.y*20, snake_head_up);
		break;
	case DOWN:
		putimage(head.x*20, head.y*20, snake_head_down);
		break;
	case LEFT:
		putimage(head.x*20, head.y*20, snake_head_left);
		break;
	case RIGHT:
		putimage(head.x*20, head.y*20, snake_head_right );
		break;
	}

	if (this->body.size() > 1)
	{
		std::vector<P>::iterator it;
		it = this->body.begin() + 1;
		putimage((*it).x*20, (*it).y*20, snake_body);

	}
}

void Snake::CleanSnake()
{
	P tail = this->body.back(); // 获得蛇尾信息
	putimage(tail.x*20, tail.y*20, empty); // 删除蛇尾(打印空地图片)
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
		N_head.y--;
		break;
	case DOWN:
		N_head.y++;
		break;
	case LEFT:
		N_head.x--;
		break;
	case RIGHT:
		N_head.x++;
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
		{
			score += 3;
			t++;
			if (t == 3)
			{
				DrawTree(food);
				t = 0;
			}
		}
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
	char name[10];
	inputbox_getline("ID", "请输入您的ID", name, 10);
	std::cin.get();
	putimage(0, 0, game_over);
	Draw_and_Write_GameOver(name);
}



void Snake::GetDirection_Stop(double starttime, MUSIC& music)
{
	while (1)
	{
		double nowtime = fclock();
		double time = nowtime - starttime;
		DrawTime(time);

		Sleep(200);
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
			type_change = true;
			if (this->music_num > 1)
				this->music_num--;
			else
				this->music_num = 4;
			PlayMusic(music, music_num, is_music_play , type_change);
		}
		else if (GetAsyncKeyState('E') || GetAsyncKeyState('e'))
		{
			type_change = true;
			if (this->music_num < 4)
				this->music_num++;
			else
				this->music_num = 1;
			PlayMusic(music, music_num, is_music_play,type_change);
		}
		else if (GetAsyncKeyState('Y') || GetAsyncKeyState('y'))
		{
			is_music_play = true;
			PlayMusic(music, music_num, is_music_play,type_change);
		}
		else if (GetAsyncKeyState('N') || GetAsyncKeyState('n'))
		{
			is_music_play = false;
			PlayMusic(music, music_num, is_music_play, type_change);
		}
		else if (GetAsyncKeyState(key_space) && 0x8000)
		{
			break;
		}
	}

}

void Snake::GetPath(Food& food)
{
	BFS Ai(this->body); // 调用有参构造初始地图

	if (Ai.FindPath(food.pos_of_food))
	{
		std::vector<P> fock_body(body);  // 产生虚拟蛇
		std::queue<P> fock_path; // 虚拟路径
		fock_path = Ai.GetPath(food); // 得到虚拟路径
		fock_path.pop(); // 弹出蛇头

		// 派出虚拟蛇吃食物
		while (!fock_path.empty())
		{
			P N_head; 
			N_head = fock_path.front(); 
			fock_body.insert(fock_body.begin(), N_head);
			fock_body.pop_back();
			fock_path.pop(); 
		}

		Ai.InitMap(fock_body); // 初始化地图数据
		if (Ai.FindPath(fock_body.back())) // 吃完食物后能找的蛇尾
		{
			Ai.InitMap(this->body); // 初始化地图数据
			Ai.FindPath(food.pos_of_food);
			this->AI_path = Ai.GetPath(food);
			this->AI_path.pop();
		}
		else // 吃完后找不到蛇尾
		{
			Ai.InitMap(body); // 初始化地图数据
			if (Ai.FindPath(body.back())) // 检查能否找到现在的蛇尾
			{
				// 在父节点图中标记出蛇头的位置			
				Ai.InitMap(body); // 初始化地图数据
				Ai.DFS_tail(body.front(), body.back());
				while (!Ai.path.empty())
				{
					Ai.path.pop();
				}
				Ai.dfs_father[body.front().x][body.front().y].x = -1;
				Ai.dfs_father[body.front().x][body.front().y].y = -1;
				this->AI_path = Ai.GetdfsPath(body.back()); // 得到路径				
			}
			else
			{
				P head = this->body.front(); // 得到蛇头
				P next;
				Ai.InitMap(this->body); // 刷新地图信息
				for (int i = 0; i < 4; i++)
				{
					next.x = head.x + Dirx[i];
					next.y = head.y + Diry[i];

					if (Ai.bfs_map[next.x][next.y] == 1) // 如果下一个节点不可访问，跳过本次循环
						continue;
					else
					{
						P O_head = this->body.front(); // 得到蛇头
						int x = next.x - O_head.x;
						int y = next.y - O_head.y;
						if (x == Dirx[0] && y == Diry[0])
							direction = UP;
						else if (x == Dirx[1] && y == Diry[1])
							direction = DOWN;
						else if (x == Dirx[2] && y == Diry[2])
							direction = LEFT;
						else if (x == Dirx[3] && y == Diry[3])
							direction = RIGHT;
						this->body.insert(body.begin(), next); // 将该坐标的位置压入数组首位，成为新的蛇头
						return;
					}
				}
				// 检测到四个方向都不可移动时
				this->isGameOver = true;
			}
		}
	}
	else
	{
		Ai.InitMap(body); // 初始化地图数据
		if (Ai.FindPath(body.back())) // 检查能否找到现在的蛇尾
		{
			// 在父节点图中标记出蛇头的位置			
			Ai.InitMap(body); // 初始化地图数据
			Ai.DFS_tail(body.front(), body.back());		
			while (!Ai.path.empty())
			{
				Ai.path.pop();
			}
			Ai.dfs_father[body.front().x][body.front().y].x = -1;
			Ai.dfs_father[body.front().x][body.front().y].y = -1;
			this->AI_path = Ai.GetdfsPath(body.back()); // 得到路径				
		}
		else
		{
			P head = this->body.front(); // 得到蛇头
			P next;
			Ai.InitMap(this->body); // 刷新地图信息
			for (int i = 0; i < 4; i++)
			{
				next.x = head.x + Dirx[i];
				next.y = head.y + Diry[i];

				if (Ai.bfs_map[next.x][next.y] == 1) // 如果下一个节点不可访问，跳过本次循环
					continue;
				else
				{
					P O_head = this->body.front(); // 得到蛇头
					int x = next.x - O_head.x;
					int y = next.y - O_head.y;
					if (x == Dirx[0] && y == Diry[0])
						direction = UP;
					else if (x == Dirx[1] && y == Diry[1])
						direction = DOWN;
					else if (x == Dirx[2] && y == Diry[2])
						direction = LEFT;
					else if (x == Dirx[3] && y == Diry[3])
						direction = RIGHT;
					this->body.insert(body.begin(), next); // 将该坐标的位置压入数组首位，成为新的蛇头
					return;
				}
			}
			// 检测到四个方向都不可移动时
			this->isGameOver = true;
		}
	}
}

void Snake::Get_AI_Direction()
{
	P N_head; // 新的蛇头坐标
	N_head = this->AI_path.front(); // 返回队列的第一个坐标
	P O_head; // 原来的蛇头
	O_head = body.front(); // 返回原来的蛇头信息
	int x = N_head.x - O_head.x;
	int y = N_head.y - O_head.y;
	if (x == Dirx[0] && y == Diry[0])
		direction = UP;
	else if (x == Dirx[2] && y == Diry[2])
		direction = DOWN;
	else if (x == Dirx[1] && y == Diry[1])
		direction = LEFT;
	else if (x == Dirx[3] && y == Diry[3])
		direction = RIGHT;
}

void Snake::CreatTree(Food& food)
{
	P tree;
	tree.x = rand() % (33) + 1; // x 的范围为 1-33
	tree.y = rand() % (26) + 1; // y 的范围为 1-26
	std::vector<P>::iterator it; // 迭代器
	bool is_food_ok = false;
	bool is_snake_ok = false;
	while (1)
	{
		if (tree.x == food.pos_of_food.x && tree.y == food.pos_of_food.y)
		{
			tree.x = rand() % (33) + 1; // x 的范围为 1-33
			tree.y = rand() % (26) + 1; // y 的范围为 1-26
		}

		for (it = body.begin(); it != body.end(); it++) // 遍历蛇
		{
			if ((*it).x == tree.x && (*it).y == tree.y) // 如果蛇和障碍物重叠
			{
				tree.x = rand() % (33) + 1; // x 的范围为 1-33
				tree.y = rand() % (26) + 1; // y 的范围为 1-26
				it = body.begin(); // 矫正迭代器指向蛇头，重新进行遍历
				is_snake_ok = false;
			}
			else
				is_snake_ok = true;
		}

		if (!(tree.x == food.pos_of_food.x && tree.y == food.pos_of_food.y))
			is_food_ok = true;

		if (is_snake_ok && is_food_ok)
			break;
	}
	if (!obstacle.empty())
		obstacle.insert(obstacle.begin(), tree);
	else
		obstacle.push_back(tree);
}

void Snake::DrawTree(Food& food)
{
	CreatTree(food);
	P first = obstacle.front();
	putimage(first.x*20, first.y*20, tree);
}

void Snake::AiMove(Food& food, double starttime, MUSIC& music)
{
	DrawModel(isAi);
	DrawLevel(level);
	DrawScore(score);
	double nowtime = fclock();
	double time = nowtime - starttime;
	DrawTime(time);
	DrawGameInfo();

	this->GetPath(food); // 先找到路径

	if (!this->AI_path.empty())
	{
		while (!this->AI_path.empty())
		{
			if (kbmsg()) // 如果有按键按下
			{
				if (GetAsyncKeyState(key_space) && 0x8000) // 按键为 空格键 时
				{
					GetDirection_Stop(starttime, music);
				}
				else
					GetDirection(starttime, music);
			}
			P N_head; // 新的蛇头坐标
			N_head = this->AI_path.front(); // 返回队列的第一个坐标
			Get_AI_Direction();
			this->body.insert(body.begin(), N_head); // 将该坐标的位置压入数组首位，成为新的蛇头
			this->AI_path.pop(); // 弹出该坐标信息
			CleanSnake(); // 先删除蛇尾
			if (Check_of_Food(food)) // 判断是否吃到食物
			{
				score++;
				DrawScore(score);
				food.CreatFood(body);
				food.DrawFood();
			}
			else
			{
				body.pop_back(); // 删除最后一个元素
			}

			if (!this->speedModel) // 当未开启手动速度调节模式时
				Getlevel(); // 判断游戏速度等级
			DrawLevel(level);
			DrawSnake(); // 打印蛇
			Snake_of_Sleep(); // 等待刷新

			if (this->isGameOver == true) // 如果游戏结束,则结束该函数
				return;
		}
	}
	else
	{
		if (this->isGameOver == true) // 如果游戏结束,则结束该函数
			return;

		if (kbmsg()) // 如果有按键按下
		{
			if (GetAsyncKeyState(key_space) && 0x8000) // 按键为 空格键 时
			{
				GetDirection_Stop(starttime, music);
			}
			else
				GetDirection(starttime, music);
		}

		CleanSnake(); // 先删除蛇尾
		body.pop_back(); // 删除最后一个元素
		DrawSnake(); // 打印蛇
		Snake_of_Sleep(); // 等待刷新

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
		type_change = true;
		if (this->music_num > 1)
			this->music_num--;
		else
			this->music_num = 4;
	}
	else if (GetAsyncKeyState('E') || GetAsyncKeyState('e'))
	{
		is_music_change = true;
		type_change = true;
		if (this->music_num < 4)
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
		Sleep(5);
		break;
	}
}

void Snake::Check_of_Die()
{
	P head = this->body.front();

	if (head.x == 0 || head.x*20 == Windows_width - 220 || head.y == 0 || head.y*20 == Windows_height - 100)
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

	for (it = obstacle.begin(); it != obstacle.end(); it++)
	{
		if (head.x == (*it).x && head.y == (*it).y)
		{
			this->isGameOver = true;
			break;
		}
	}
}

void Snake::Draw_and_Write_GameOver(char* name)
{
	time_t t;
	struct tm* lt;
	time(&t); // 获取Unix时间戳。
	lt = localtime(&t); // 转为时间结构。
	char str[50];
	
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "微软雅黑");
	sprintf(str, "姓名：%s", name);	
	outtextrect(20, 320, 240, 360, str);
	sprintf(str, "得分：%d", score);
	outtextrect(20, 360, 240, 400, str);
	sprintf(str, "时间：%02d-%02d-%02d %02d:%02d:%02d", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
	outtextrect(20, 400, 300, 440, str);

	std::ofstream OutFile;
	OutFile.open("leaderboard.txt", std::ios::app);
	OutFile << name << std::endl;
	OutFile << score << std::endl;
	OutFile << lt->tm_year + 1900 << std::endl
			<< lt->tm_mon + 1 << std::endl
			<< lt->tm_mday << std::endl
			<< lt->tm_hour << std::endl
			<< lt->tm_min << std::endl
			<< lt->tm_sec << std::endl;
	OutFile.close();
}

Food::Food(std::vector<P>& snake)
{
	CreatFood(snake);
	DrawFood();
}

void Food::CreatFood(std::vector<P>& snake)
{
	P tmp_of_rand;
	pos_of_food.x = rand() % (33) + 1; // x 的范围为 1-33
	pos_of_food.y = rand() % (26) + 1; // y 的范围为 1-26
	std::vector<P>::iterator it; // 迭代器
	for (it = snake.begin(); it != snake.end(); it++) // 遍历蛇
	{
		if ((*it).x == pos_of_food.x && (*it).y == pos_of_food.y) // 如果蛇和食物重叠
		{
			pos_of_food.x = rand() % (33) + 1; // x 的范围为 1-33
			pos_of_food.y = rand() % (26) + 1; // y 的范围为 1-26
			it = snake.begin(); // 矫正迭代器指向蛇头，重新进行遍历
		}
	}
}

void Food::DrawFood()
{
	int tmp = rand() % 100 + 1;
	int food = 0;

	// 三种食物的出现概率分别为 20%、30%、50%
	if (tmp >= 1 && tmp < 20)
		food = 3;
	else if (tmp >= 20 && tmp < 50)
		food = 2;
	else
		food = 1;


	switch (food)
	{
	case 1:
		putimage(pos_of_food.x*20, pos_of_food.y*20, food_mushroom);
		this->food_type = 1;
		break;
	case 2:
		putimage(pos_of_food.x*20, pos_of_food.y*20, food_tomato);
		this->food_type = 2;
		break;
	case 3:
		putimage(pos_of_food.x*20, pos_of_food.y*20, food_hamburger);
		this->food_type = 3;
		break;
	default:
		break;
	}
}

BFS::BFS(std::vector<P>& snake)
{
	
	// 申请一个二维数组用于存储父节点信息
	this->bfs_father = new P * [35];
	for (int i = 0; i < 35; i++)
	{
		this->bfs_father[i] = new P[30];
	}


	dfs_father = new P * [35];
	for (int i = 0; i < 35; i++)
	{
		dfs_father[i] = new P[30];
	}

	InitMap(snake);
}

BFS::~BFS()
{
	// 释放内存空间
	for (int i = 0; i <35; i++)
	{
		delete[] bfs_father[i];
	}
	delete[] bfs_father;

	for (int i = 0; i < 35; i++)
	{
		delete[] dfs_father[i];
	}
	delete[] dfs_father;
}

bool BFS::FindPath(P& endpos)
{
	std::queue<P> tmp; // 创建临时队列储存节点
	tmp.push(this->head); // 将蛇头放入
	P father; // 存放父节点
	P now; // 当前节点
	while (!tmp.empty()) // 当队列不为空时，继续执行
	{
		father = tmp.front(); // 从队列中取出父节点
		tmp.pop(); // 弹出父节点

		for (int i = 0; i < 4; i++)
		{
			// 得到移动后的坐标信息
			now.x = father.x + Dirx[i];
			now.y = father.y + Diry[i];

			// 如果吃到食物，将该节点压入路径队列中
			if (now.x == endpos.x && now.y == endpos.y)
			{
				// 在该节点上存储父节点信息
				this->bfs_father[now.x][now.y].x = father.x;
				this->bfs_father[now.x][now.y].y = father.y;
				return true;
			}
			// 如果该节点为不可访问节点，则跳过此次循环
			if (bfs_map[now.x][now.y] == 1)
				continue;

			// 如果上述两者都不满足
			bfs_map[now.x][now.y] = 1; // 将该节点标记为不可访问节点
			tmp.push(now); // 然后将该节点压入临时队列中

			// 在该节点上存储父节点信息
			this->bfs_father[now.x][now.y].x = father.x;
			this->bfs_father[now.x][now.y].y = father.y;
		}
	}
	return false;
}

void BFS::InitMap(std::vector<P>& snake)
{
	// 将墙标记为 1 （表示该节点不可访问）
	for (int i = 0; i < 35; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (i == 0 || i == 34)
			{
				this->bfs_map[i][j] = 1;
			}
			else if (j == 0 || j == 29)
			{
				this->bfs_map[i][j] = 1;
			}
			else
			{
				bfs_map[i][j] = 0; // 其他节点可访问
			}
		}
	}

	// 将蛇标记为 1 （表示该节点不可访问）
	std::vector<P>::iterator i;
	for (i = snake.begin(); i != snake.end(); i++)
	{
		this->bfs_map[(*i).x][(*i).y] = 1;
	}

	this->head = snake.front();

	bfs_father[snake.front().x][snake.front().y].x = -1;
	bfs_father[snake.front().x][snake.front().y].y = -1;
}

std::queue<P> BFS::GetPath(Food& food)
{
	P pos;
	pos.x = food.pos_of_food.x;
	pos.y = food.pos_of_food.y;
	while (!this->path.empty())
	{
		this->path.pop();
	}

	this->GetPath_action(pos);

	return this->path;
}

void BFS::GetPath_action(P& pos)
{
	if (bfs_father[pos.x][pos.y].x != -1 && bfs_father[pos.x][pos.y].y != -1)
		GetPath_action(bfs_father[pos.x][pos.y]);
	this->path.push(pos);
}

bool BFS::DFS_tail(P& head,P& endpos)
{
	P now;
	bool tmp;
	for (int i = 0; i < 4; i++)
	{
		now.x = head.x + Dirx[i];
		now.y = head.y + Diry[i];
		if (now.x == endpos.x && now.y == endpos.y)
		{
			this->dfs_father[now.x][now.y].x = head.x;
			this->dfs_father[now.x][now.y].y = head.y;
			return true;
		}
		else if (this->bfs_map[now.x][now.y] == 1)
		{
			continue;
		}
		else
		{
			this->dfs_father[now.x][now.y].x = head.x;
			this->dfs_father[now.x][now.y].y = head.y;
			bfs_map[head.x][head.y] = 1;
			tmp = DFS_tail(now,endpos);
			if (tmp)
				return true;
		}
	}
	return false;
}

void BFS::GetdfsPath_action(P& endpos)
{

	if (this->dfs_father[endpos.x][endpos.y].x != -1 && this->dfs_father[endpos.x][endpos.y].y != -1)
	{
		P tmp;
		tmp.x = dfs_father[endpos.x][endpos.y].x;
		tmp.y = dfs_father[endpos.x][endpos.y].y;
		GetdfsPath_action(tmp);
	}

	this->path.push(endpos);
}

std::queue<P> BFS::GetdfsPath(P& endpos)
{
	this->GetdfsPath_action(endpos);
	return this->path;
}
