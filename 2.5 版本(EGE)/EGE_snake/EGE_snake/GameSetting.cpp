#include "GameSetting.h"

PIMAGE game_start; // ��Ϸ��ʼͼƬ
PIMAGE game_help; // ��Ϸ����ͼƬ
PIMAGE game_leaderboard; // ���а�ͼƬ
PIMAGE game_over; // ��Ϸ����ͼƬ
PIMAGE game_model; // �յص�ͼƬ
PIMAGE wall; // ǽ��ͼƬ
PIMAGE empty; // �յص�ͼƬ
PIMAGE tree; // �ϰ����ͼƬ
PIMAGE food_tomato; // ����ʳ���ͼƬ
PIMAGE food_mushroom; // Ģ��ʳ���ͼƬ
PIMAGE food_hamburger; // ������ʳ���ͼƬ
PIMAGE snake_body; // ����ͼƬ
PIMAGE snake_head_up; // ��ͷ����
PIMAGE snake_head_down; // ��ͷ����
PIMAGE snake_head_left; // ��ͷ����
PIMAGE snake_head_right; // ��ͷ����

// ����·������������
int Dirx[4] = { 0,-1,0,1 };
int Diry[4] = { -1,0,1,0 };

void DrawMusic(int type)
{
	char str[200];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "΢���ź�");
	if (type == 1)
		sprintf(str, "                   ��ǰ���֣�Mich - Skyland               ");
	else if (type == 2)
		sprintf(str, "                  ��ǰ���֣����� - ����֮��                  ");
	else if (type == 3)
		sprintf(str, "   ��ǰ���֣�����(�Ƥ���) - �뤤�����h�����ա�  ");
	else if (type == 4)
		sprintf(str, "        ��ǰ���֣�Jo Blankenburg - Memento        ");
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
		outtextrect(710, 35, 815, 75, "��ǰģʽ�����");
	else
		outtextrect(710, 35, 815, 75, "��ǰģʽ��AI");
}

void DrawLevel(int level)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��ǰ�ٶȵȼ���%d  ", level);
	outtextrect(710, 75, 815, 115, str);
}

void DrawScore(int score)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��ǰ��Ϸ�÷֣�%d", score);
	outtextrect(710, 115, 815, 155, str);
}

void DrawRscore(int rscore)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "�����Ϸ�÷֣�%d", rscore);
	outtextrect(710, 155, 815, 195, str);
}

void DrawTime(double time)
{
	char str[20];
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(BLACK);
	setfont(25, 0, "΢���ź�");
	sprintf(str, "��Ϸʱ�䣺%d", (int)time);
	outtextrect(710, 195, 815, 235, str);
}

void PlayMusic(MUSIC& music, int type, bool play, bool type_change)
{
	if (type_change)
	{
		if (type == 1)
			music.OpenFile("Mich - Skyland.mp3");			
		else if (type == 2)
			music.OpenFile("���� - ����֮��.mp3");
		else if (type == 3)
			music.OpenFile("���� (�Ƥ���) - �뤤�����h�����ա�.mp3");
		else if(type==4)
			music.OpenFile("Jo Blankenburg - Memento.mp3");
		DrawMusic(type);
	}
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
	head.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
	head.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
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
	P tail = this->body.back(); // �����β��Ϣ
	putimage(tail.x*20, tail.y*20, empty); // ɾ����β(��ӡ�յ�ͼƬ)
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

	body.insert(body.begin(), N_head); // ���ƶ����λ��ѹ��������λ����Ϊ�µ���ͷ

	Check_of_Die(); // �������

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
	char name[10];
	inputbox_getline("ID", "����������ID", name, 10);
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
	BFS Ai(this->body); // �����вι����ʼ��ͼ

	if (Ai.FindPath(food.pos_of_food))
	{
		std::vector<P> fock_body(body);  // ����������
		std::queue<P> fock_path; // ����·��
		fock_path = Ai.GetPath(food); // �õ�����·��
		fock_path.pop(); // ������ͷ

		// �ɳ������߳�ʳ��
		while (!fock_path.empty())
		{
			P N_head; 
			N_head = fock_path.front(); 
			fock_body.insert(fock_body.begin(), N_head);
			fock_body.pop_back();
			fock_path.pop(); 
		}

		Ai.InitMap(fock_body); // ��ʼ����ͼ����
		if (Ai.FindPath(fock_body.back())) // ����ʳ������ҵ���β
		{
			Ai.InitMap(this->body); // ��ʼ����ͼ����
			Ai.FindPath(food.pos_of_food);
			this->AI_path = Ai.GetPath(food);
			this->AI_path.pop();
		}
		else // ������Ҳ�����β
		{
			Ai.InitMap(body); // ��ʼ����ͼ����
			if (Ai.FindPath(body.back())) // ����ܷ��ҵ����ڵ���β
			{
				// �ڸ��ڵ�ͼ�б�ǳ���ͷ��λ��			
				Ai.InitMap(body); // ��ʼ����ͼ����
				Ai.DFS_tail(body.front(), body.back());
				while (!Ai.path.empty())
				{
					Ai.path.pop();
				}
				Ai.dfs_father[body.front().x][body.front().y].x = -1;
				Ai.dfs_father[body.front().x][body.front().y].y = -1;
				this->AI_path = Ai.GetdfsPath(body.back()); // �õ�·��				
			}
			else
			{
				P head = this->body.front(); // �õ���ͷ
				P next;
				Ai.InitMap(this->body); // ˢ�µ�ͼ��Ϣ
				for (int i = 0; i < 4; i++)
				{
					next.x = head.x + Dirx[i];
					next.y = head.y + Diry[i];

					if (Ai.bfs_map[next.x][next.y] == 1) // �����һ���ڵ㲻�ɷ��ʣ���������ѭ��
						continue;
					else
					{
						P O_head = this->body.front(); // �õ���ͷ
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
						this->body.insert(body.begin(), next); // ���������λ��ѹ��������λ����Ϊ�µ���ͷ
						return;
					}
				}
				// ��⵽�ĸ����򶼲����ƶ�ʱ
				this->isGameOver = true;
			}
		}
	}
	else
	{
		Ai.InitMap(body); // ��ʼ����ͼ����
		if (Ai.FindPath(body.back())) // ����ܷ��ҵ����ڵ���β
		{
			// �ڸ��ڵ�ͼ�б�ǳ���ͷ��λ��			
			Ai.InitMap(body); // ��ʼ����ͼ����
			Ai.DFS_tail(body.front(), body.back());		
			while (!Ai.path.empty())
			{
				Ai.path.pop();
			}
			Ai.dfs_father[body.front().x][body.front().y].x = -1;
			Ai.dfs_father[body.front().x][body.front().y].y = -1;
			this->AI_path = Ai.GetdfsPath(body.back()); // �õ�·��				
		}
		else
		{
			P head = this->body.front(); // �õ���ͷ
			P next;
			Ai.InitMap(this->body); // ˢ�µ�ͼ��Ϣ
			for (int i = 0; i < 4; i++)
			{
				next.x = head.x + Dirx[i];
				next.y = head.y + Diry[i];

				if (Ai.bfs_map[next.x][next.y] == 1) // �����һ���ڵ㲻�ɷ��ʣ���������ѭ��
					continue;
				else
				{
					P O_head = this->body.front(); // �õ���ͷ
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
					this->body.insert(body.begin(), next); // ���������λ��ѹ��������λ����Ϊ�µ���ͷ
					return;
				}
			}
			// ��⵽�ĸ����򶼲����ƶ�ʱ
			this->isGameOver = true;
		}
	}
}

void Snake::Get_AI_Direction()
{
	P N_head; // �µ���ͷ����
	N_head = this->AI_path.front(); // ���ض��еĵ�һ������
	P O_head; // ԭ������ͷ
	O_head = body.front(); // ����ԭ������ͷ��Ϣ
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
	tree.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
	tree.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
	std::vector<P>::iterator it; // ������
	bool is_food_ok = false;
	bool is_snake_ok = false;
	while (1)
	{
		if (tree.x == food.pos_of_food.x && tree.y == food.pos_of_food.y)
		{
			tree.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
			tree.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
		}

		for (it = body.begin(); it != body.end(); it++) // ������
		{
			if ((*it).x == tree.x && (*it).y == tree.y) // ����ߺ��ϰ����ص�
			{
				tree.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
				tree.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
				it = body.begin(); // ����������ָ����ͷ�����½��б���
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

	this->GetPath(food); // ���ҵ�·��

	if (!this->AI_path.empty())
	{
		while (!this->AI_path.empty())
		{
			if (kbmsg()) // ����а�������
			{
				if (GetAsyncKeyState(key_space) && 0x8000) // ����Ϊ �ո�� ʱ
				{
					GetDirection_Stop(starttime, music);
				}
				else
					GetDirection(starttime, music);
			}
			P N_head; // �µ���ͷ����
			N_head = this->AI_path.front(); // ���ض��еĵ�һ������
			Get_AI_Direction();
			this->body.insert(body.begin(), N_head); // ���������λ��ѹ��������λ����Ϊ�µ���ͷ
			this->AI_path.pop(); // ������������Ϣ
			CleanSnake(); // ��ɾ����β
			if (Check_of_Food(food)) // �ж��Ƿ�Ե�ʳ��
			{
				score++;
				DrawScore(score);
				food.CreatFood(body);
				food.DrawFood();
			}
			else
			{
				body.pop_back(); // ɾ�����һ��Ԫ��
			}

			if (!this->speedModel) // ��δ�����ֶ��ٶȵ���ģʽʱ
				Getlevel(); // �ж���Ϸ�ٶȵȼ�
			DrawLevel(level);
			DrawSnake(); // ��ӡ��
			Snake_of_Sleep(); // �ȴ�ˢ��

			if (this->isGameOver == true) // �����Ϸ����,������ú���
				return;
		}
	}
	else
	{
		if (this->isGameOver == true) // �����Ϸ����,������ú���
			return;

		if (kbmsg()) // ����а�������
		{
			if (GetAsyncKeyState(key_space) && 0x8000) // ����Ϊ �ո�� ʱ
			{
				GetDirection_Stop(starttime, music);
			}
			else
				GetDirection(starttime, music);
		}

		CleanSnake(); // ��ɾ����β
		body.pop_back(); // ɾ�����һ��Ԫ��
		DrawSnake(); // ��ӡ��
		Snake_of_Sleep(); // �ȴ�ˢ��

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
	time(&t); // ��ȡUnixʱ�����
	lt = localtime(&t); // תΪʱ��ṹ��
	char str[50];
	
	setbkcolor(EGERGB(240, 255, 240));
	setcolor(EGERGB(191, 293, 255));
	setfont(30, 0, "΢���ź�");
	sprintf(str, "������%s", name);	
	outtextrect(20, 320, 240, 360, str);
	sprintf(str, "�÷֣�%d", score);
	outtextrect(20, 360, 240, 400, str);
	sprintf(str, "ʱ�䣺%02d-%02d-%02d %02d:%02d:%02d", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
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
	pos_of_food.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
	pos_of_food.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
	std::vector<P>::iterator it; // ������
	for (it = snake.begin(); it != snake.end(); it++) // ������
	{
		if ((*it).x == pos_of_food.x && (*it).y == pos_of_food.y) // ����ߺ�ʳ���ص�
		{
			pos_of_food.x = rand() % (33) + 1; // x �ķ�ΧΪ 1-33
			pos_of_food.y = rand() % (26) + 1; // y �ķ�ΧΪ 1-26
			it = snake.begin(); // ����������ָ����ͷ�����½��б���
		}
	}
}

void Food::DrawFood()
{
	int tmp = rand() % 100 + 1;
	int food = 0;

	// ����ʳ��ĳ��ָ��ʷֱ�Ϊ 20%��30%��50%
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
	
	// ����һ����ά�������ڴ洢���ڵ���Ϣ
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
	// �ͷ��ڴ�ռ�
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
	std::queue<P> tmp; // ������ʱ���д���ڵ�
	tmp.push(this->head); // ����ͷ����
	P father; // ��Ÿ��ڵ�
	P now; // ��ǰ�ڵ�
	while (!tmp.empty()) // �����в�Ϊ��ʱ������ִ��
	{
		father = tmp.front(); // �Ӷ�����ȡ�����ڵ�
		tmp.pop(); // �������ڵ�

		for (int i = 0; i < 4; i++)
		{
			// �õ��ƶ����������Ϣ
			now.x = father.x + Dirx[i];
			now.y = father.y + Diry[i];

			// ����Ե�ʳ����ýڵ�ѹ��·��������
			if (now.x == endpos.x && now.y == endpos.y)
			{
				// �ڸýڵ��ϴ洢���ڵ���Ϣ
				this->bfs_father[now.x][now.y].x = father.x;
				this->bfs_father[now.x][now.y].y = father.y;
				return true;
			}
			// ����ýڵ�Ϊ���ɷ��ʽڵ㣬�������˴�ѭ��
			if (bfs_map[now.x][now.y] == 1)
				continue;

			// ����������߶�������
			bfs_map[now.x][now.y] = 1; // ���ýڵ���Ϊ���ɷ��ʽڵ�
			tmp.push(now); // Ȼ�󽫸ýڵ�ѹ����ʱ������

			// �ڸýڵ��ϴ洢���ڵ���Ϣ
			this->bfs_father[now.x][now.y].x = father.x;
			this->bfs_father[now.x][now.y].y = father.y;
		}
	}
	return false;
}

void BFS::InitMap(std::vector<P>& snake)
{
	// ��ǽ���Ϊ 1 ����ʾ�ýڵ㲻�ɷ��ʣ�
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
				bfs_map[i][j] = 0; // �����ڵ�ɷ���
			}
		}
	}

	// ���߱��Ϊ 1 ����ʾ�ýڵ㲻�ɷ��ʣ�
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
