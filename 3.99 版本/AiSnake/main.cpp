#include "GameSetting.h"

void Map::DrawMap()
{
	// x 的可用范围为 1 - 50
	// y 的可用范围为 1 - 38 
	system("cls");
	int i, j;
	// 打印上边界地图
	for (i = 0; i < BasicSetting::windows_width; i++)
		cout << "#";
	cout << endl;
	// 打印中间地图
	for (i = 0; i < BasicSetting::windows_height - 2; i++) // 上边界和下边界之间的区域
	{
		for (j = 0; j < BasicSetting::windows_width; j++) // 中间区域每一行的信息
		{
			if (i == 13 && j >= BasicSetting::windows_width - 29) // 第十四行五十一列开始打印 "#"
			{
				cout << "#";
				continue;
			}
			if (j == 0 || j == BasicSetting::windows_width - 29 || j == BasicSetting::windows_width - 1) // 每一行的左右边界信息
			{
				cout << "#";
			}
			else // 其余区域
				cout << " ";
		}
		cout << endl;
	}
	// 打印下边界地图
	for (i = 0; i < BasicSetting::windows_width; i++)
		cout << "#";
}

void Map::DrawScore()
{
	gotoxy(BasicSetting::windows_width - 22 + 14, 6);
	cout << "  ";
	gotoxy(BasicSetting::windows_width - 22 + 14, 4);
	cout << "  ";
	gotoxy(BasicSetting::windows_width - 22, 6);
	cout << "当前速度等级: " << "1" << endl;
	gotoxy(BasicSetting::windows_width - 22, 4);
	cout << "当前游戏分数: " << "0" << endl;
}

void Map::DrawGameInfo(bool model)
{
	gotoxy(BasicSetting::windows_width - 22, 8);
	if(!model)
		cout << "当前游戏模式: " << "玩家" << endl;
	else
		cout << "当前游戏模式: " << "Ai " << endl;
	gotoxy(BasicSetting::windows_width - 22, 10);
	cout << "历史最高分数: " << 0 << endl;

	gotoxy(BasicSetting::windows_width - 22, 16);
	cout << "游戏操作说明：" << endl;
	gotoxy(BasicSetting::windows_width - 25, 18);
	cout << "W、↑: 上    S、↓: 下" << endl;
	gotoxy(BasicSetting::windows_width - 25, 20);
	cout << "A、←: 左    D、→: 右" << endl;
	gotoxy(BasicSetting::windows_width - 25, 22);
	cout << "    空格键: 暂停   " << endl;

	gotoxy(BasicSetting::windows_width - 22, 25);
	cout << "调节游戏速度：" << endl;
	gotoxy(BasicSetting::windows_width - 22, 27);
	cout << "小键盘 + : 加快" << endl;
	gotoxy(BasicSetting::windows_width - 22, 29);
	cout << "小键盘 - : 减慢" << endl;
	gotoxy(BasicSetting::windows_width - 25, 31);
	cout << "按 R 返回游戏本身速度" << endl;

	gotoxy(BasicSetting::windows_width - 22, 34);
	cout << "作者: 邓皓文" << endl;
	gotoxy(BasicSetting::windows_width - 22, 36);
	cout << "版本: 1.0" << endl;
}

bool Map::DrawChoiceInfo() // 选择游戏模式
{
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 5);
	cout << "请选择游戏模式：" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 3);
	cout << "1. 手动操作模式" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 1);
	cout << "2. AI智能模式" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 + 1);
	cout << "请输入您的选择-> ";
	while (1)
	{
		char choice = _getch();
		if (choice == '1')
			return false;
		else if (choice == '2')
			return true;
	}
	
}

void Map::GameOver(int Score)
{
	setColor(12, 0);
	gotoxy(BasicSetting::windows_width / 2 - 20, BasicSetting::windows_height / 2 - 5);
	cout << "游戏结束，您输了！" << endl;;
	gotoxy(BasicSetting::windows_width / 2 - 20, BasicSetting::windows_height / 2 - 3);
	cout << "您的得分为：" << Score << endl;
}

void Food::CreatFood(vector<P>& snake)
{
	P_food.x = rand() % (BasicSetting::windows_width - 30) + 1; // x 的范围为 1-50
	P_food.y = rand() % (BasicSetting::windows_height - 2) + 1; // y 的范围为 1-38
	vector<P>::iterator i; // 迭代器
	for (i = snake.begin(); i != snake.end(); i++) // 遍历蛇
	{
		if ((*i).x == P_food.x && (*i).y == P_food.y) // 如果蛇和食物重叠
		{
			P_food.x = rand() % (BasicSetting::windows_width - 30) + 1; // x 的范围为 1-51
			P_food.y = rand() % (BasicSetting::windows_height - 2) + 1; // y 的范围为 1-39
			i = snake.begin(); // 矫正迭代器指向蛇头，重新进行遍历
		}
	}
}

void Food::DrawFood()
{
	setColor(12, 0);
	gotoxy(this->P_food.x, this->P_food.y);
	cout << "@";
	setColor(7, 0);
}

void Snake::DrawSnake()
{
	//设置颜色为浅绿色
	setColor(10, 0);
	// 为了节省效率，根据贪吃蛇的规律，我们只需要打印蛇头，删除蛇尾
	vector<P>::iterator i;
	i = body.begin(); // 通过迭代器找到蛇头，打印
	gotoxy((*i).x, (*i).y);
	cout << "*";
	setColor(7, 0);
}

void Snake::CleanSnake()
{
	//设置颜色为浅绿色
	setColor(10, 0);
	vector<P>::iterator i;
	i = body.end() - 1; // 通过迭代器找到蛇尾（end 返回的是当前容器最后一个元素的下一位，故要 -1 ）删除
	gotoxy((*i).x, (*i).y);
	cout << " ";
	setColor(7, 0);
}

bool Snake::IsEatFood(Food& food)
{
	P H = body.front();
	if (H.x == food.P_food.x && H.y == food.P_food.y)
		return true;
	else
		return false;
}

bool Snake::IsHitWall()
{
	P H = body.front();
	if (H.x == 0 || H.x == BasicSetting::windows_width - 29 || H.y == 0 || H.y == BasicSetting::windows_height - 1)
		return true;
	else
		return false;
}

bool Snake::IsHitBody()
{
	P H = body.front();
	vector<P>::iterator i;
	for (i = body.begin() + 1; i != body.end(); i++)
	{
		if (H.x == (*i).x && H.y == (*i).y)
			return true;
	}
	return false;
}

void Snake::AiMove(Food& food)
{
	this->GetPath(food); // 先找到路径
	if (this->isGameOver)
		return;
	P N_head; // 新的蛇头坐标
	while (!this->path.empty())
	{
		if (_kbhit())
		{
			GetKbHit();
		}
		N_head = this->path.front(); // 返回队列的第一个坐标
		this->body.insert(body.begin(), N_head); // 将该坐标的位置压入数组首位，成为新的蛇头
		this->path.pop(); // 弹出该坐标信息
		CleanSnake(); // 先删除蛇尾
		if (this->IsEatFood(food)) // 判断是否吃到食物
		{
			food.CreatFood(body); // 如果吃到食物,新建食物
			this->score++; // 得分 + 1		
			gotoxy(BasicSetting::windows_width - 22, 4);
			cout << "当前玩家分数: " << this->score << endl; // 打印分数	
			food.DrawFood();
		}
		else
		{
			body.pop_back(); // 删除最后一个元素
		}

		if (!this->isTurn) // 当未开启手动速度调节模式时
			GetLevel(); // 判断游戏速度等级
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "当前速度等级: " << this->level << endl;
		DrawSnake(); // 打印蛇
		SnakeSleep(this->level); // 等待刷新
		if (this->IsHitBody())
			this->isGameOver = true; // 撞到蛇身，结束游戏

		if (this->IsHitWall())
			this->isGameOver = true; // 撞到墙，结束游戏

		if (this->isGameOver == true) // 如果游戏结束,则结束该函数
			return;
	}
}

void Snake::SnakeMove(Food& food)
{

	// 判断是否有按键按下
	if (_kbhit() || this->direction == STOP)
	{
		GetKbHit();
	}
		
	Move(food); // 移动蛇的坐标

	CleanSnake(); // 先删除蛇尾
	if (this->IsEatFood(food))
	{
		food.CreatFood(body); // 如果吃到食物,新建食物
		this->score++; // 得分 + 1		
		gotoxy(BasicSetting::windows_width - 22, 4);
		cout << "当前玩家分数: " << this->score << endl; // 打印分数	
		food.DrawFood();
	}
	else
	{		
		body.pop_back(); // 删除最后一个元素
	}

	if (!this->isTurn) // 当未开启手动速度调节模式时
		GetLevel(); // 判断游戏速度等级
	gotoxy(BasicSetting::windows_width - 22, 6);
	cout << "当前速度等级: " << this->level << endl;
	DrawSnake(); // 打印蛇
	SnakeSleep(this->level); // 等待刷新
	

	if (this->IsHitBody())
		this->isGameOver = true; // 撞到蛇身，结束游戏

	if (this->IsHitWall())
		this->isGameOver = true; // 撞到墙，结束游戏

	if (this->isGameOver == true) // 如果游戏结束,则结束该函数
		return;



}

void Snake::Move(Food& food)
{
	P N_head = this->body.front(); // 返回蛇头的位置给移动后的位置

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
	this->body.insert(body.begin(), N_head); // 将移动后的位置压入数组首位，成为新的蛇头
}

void Snake::GetKbHit()
{
	char state = _getch();  // 读取的键盘信息

	if (state == ' ') // 如果用户按下空格，则暂停 
	{
		while (1)
		{
			char temp = _getch(); // 用于判断用户在暂停时的操作
			if (temp == ' ')
				break;
			else if (temp == 'R' || temp == 'r') // 返回正常的游戏速度
			{
				this->isTurn = false;
				GetLevel();
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "当前速度等级: " << this->level << endl;
			}
			else if (temp == '+')
			{
				this->isTurn = true; // 开启手动速度调节机制
				if (this->level < 10) // 最高等级为 10 级
					this->level++;
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "当前速度等级: " << this->level << endl;
			}
			else if (temp == '-') // 最低等级为 1 级
			{
				this->isTurn = true; // 开启手动速度调节机制
				if (this->level > 1) // 最低等级为 1 级
					this->level--;
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "当前速度等级: " << this->level << endl;
			}
		}
	}
	else if (state == 'R' || state == 'r') {
		this->isTurn = false;
		GetLevel();
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "当前速度等级: " << this->level << endl;
	}
	else if (state == '+')
	{
		this->isTurn = true; // 开启手动速度调节机制
		if (this->level < 10) // 最高等级为 10 级
			this->level++;
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "当前速度等级: " << this->level << endl;
	}
	else if (state == '-') // 最低等级为 1 级
	{
		this->isTurn = true; // 开启手动速度调节机制
		if (this->level > 1) // 最低等级为 1 级
			this->level--;
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "当前速度等级: " << this->level << endl;
	}
	else if (state == 'w' || state == 'W')
	{
		if (this->direction == DOWN)
			this->direction = DOWN;
		else
			this->direction = UP;
	}
	else if (state == 's' || state == 'S')
	{
		if (this->direction == UP)
			this->direction = UP;
		else
			this->direction = DOWN;
	}
	else if (state == 'a' || state == 'A')
	{
		if (this->direction == RIGHT)
			this->direction = RIGHT;
		else
			this->direction = 'a';
	}
	else if (state == 'd' || state == 'D')
	{
		if (this->direction == LEFT)
			this->direction = LEFT;
		else
			this->direction = RIGHT;
	}
	else if (state == -32)
	{
		state = _getch();
		switch (state) // 方向键第二个字节判断
		{
		case 72:
			if (this->direction == DOWN)
				break;
			this->direction = UP;
			break; // 上
		case 80:
			if (this->direction == UP)
				break;
			this->direction = DOWN;
			break; // 下
		case 75:
			if (this->direction == RIGHT)
				break;
			this->direction = LEFT;
			break; // 左
		case 77:
			if (this->direction == LEFT)
				break;
			this->direction = RIGHT;
			break;
		}
	}
}

void Snake::GetLevel()
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

void Snake::SnakeSleep(int level)
{
	switch (level)
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

void Snake::GetPath(Food& food)
{
	BFS Ai(this->body); // 调用有参构造初始地图
	if (Ai.FindPath(food))
	{
		this->path = Ai.GetPath(food); // 得到路径
		this->path.pop(); // 弹出第一个元素（蛇头）
	}
	else
	{
		this->isGameOver = true;
	}
	
}

bool BFS::FindPath(Food& food)
{
	queue<P> tmp; // 创建临时队列储存节点
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
			if (now.x == food.P_food.x && now.y == food.P_food.y)
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

void BFS::InitMap(vector<P>& snake)
{
	// 将墙标记为 1 （表示该节点不可访问）
	for (int i = 0; i < BasicSetting::windows_width - 28; i++)
	{
		for (int j = 0; j < BasicSetting::windows_height; j++)
		{
			if (i == 0 || i == BasicSetting::windows_width - 29 )
			{
				this->bfs_map[i][j] = 1;
			}
			else if (j == 0 || j == BasicSetting::windows_height - 1 )
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
	vector<P>::iterator i;
	for (i = snake.begin(); i != snake.end(); i++)
	{
		this->bfs_map[(*i).x][(*i).y] = 1;
	}

	this->head = snake.front(); // 得到蛇头的位置

	// 申请一个二维数组用于存储父节点信息
	this->bfs_father = new P * [BasicSetting::windows_width - 28];
	for (int i = 0; i < BasicSetting::windows_width - 28; i++)
	{
		this->bfs_father[i] = new P[BasicSetting::windows_height];
	}

	// 在父节点图中标记出蛇头的位置
	bfs_father[this->head.x][this->head.y].x = -1;
	bfs_father[this->head.x][this->head.y].y = -1;

}

queue<P> BFS::GetPath(Food& food)
{
	P pos;
	pos.x = food.P_food.x;
	pos.y = food.P_food.y;

	this->GetPath_action(pos);

	return this->path;
}

void BFS::GetPath_action(P& pos)
{
	if(this->bfs_father[pos.x][pos.y].x != -1 && this->bfs_father[pos.x][pos.y].y != -1)
		GetPath_action(bfs_father[pos.x][pos.y]);
	this->path.push(pos);
}

int main()
{	
	bool isAgain = false;
	while (!isAgain)
	{
		bool model;
		setColor(7, 0);
		BasicSetting Game;
		Game.GameInit(); // 初始化游戏界面
		Map map;
		model = map.DrawChoiceInfo();
		map.DrawMap(); // 打印地图
		map.DrawScore(); // 打印得分信息
		map.DrawGameInfo(model); // 打印游戏信息
		Snake snake;
		snake.isAi = model; // 游戏模式

		Food food(snake.body); // 调用有参构造

		while (!snake.isGameOver)
		{
			if (!snake.isAi)
				snake.SnakeMove(food); // 蛇的移动
			else
				snake.AiMove(food); // Ai 蛇的移动
		}

		map.GameOver(snake.score); // 游戏结束提示

		if (snake.score > snake.record) //读取最高分
			WriteScore(snake.score);

		// 打印是否重新开始游戏的提示
		gotoxy(BasicSetting::windows_width / 2 - 34, BasicSetting::windows_height / 2 + 3);
		cout << "重新开始 —— 0\t  \t退出游戏 —— 1" << endl;

		// 进行选择（为了避免按下其他按键而导致不进行判断，故在死循环中进行）
		while (1)
		{
			char tmp = _getch();
			if (tmp == '0')
			{
				isAgain = false;
				break;
			}
			else if (tmp == '1')
			{
				isAgain = true;
				break;
			}
		}

		// 此时调用各类的析构函数，结束当前游戏
		// 虽然重新开始游戏仅需要初始化蛇（因为地图与游戏信息不变）
		// 但是基于各类之间的相互依赖性，故对整个游戏进行初始化对整体代码变动最小
	}
	return EXIT_SUCCESS;
}