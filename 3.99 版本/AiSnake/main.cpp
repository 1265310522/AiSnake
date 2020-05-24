#include "GameSetting.h"

void Map::DrawMap()
{
	// x �Ŀ��÷�ΧΪ 1 - 50
	// y �Ŀ��÷�ΧΪ 1 - 38 
	system("cls");
	int i, j;
	// ��ӡ�ϱ߽��ͼ
	for (i = 0; i < BasicSetting::windows_width; i++)
		cout << "#";
	cout << endl;
	// ��ӡ�м��ͼ
	for (i = 0; i < BasicSetting::windows_height - 2; i++) // �ϱ߽���±߽�֮�������
	{
		for (j = 0; j < BasicSetting::windows_width; j++) // �м�����ÿһ�е���Ϣ
		{
			if (i == 13 && j >= BasicSetting::windows_width - 29) // ��ʮ������ʮһ�п�ʼ��ӡ "#"
			{
				cout << "#";
				continue;
			}
			if (j == 0 || j == BasicSetting::windows_width - 29 || j == BasicSetting::windows_width - 1) // ÿһ�е����ұ߽���Ϣ
			{
				cout << "#";
			}
			else // ��������
				cout << " ";
		}
		cout << endl;
	}
	// ��ӡ�±߽��ͼ
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
	cout << "��ǰ�ٶȵȼ�: " << "1" << endl;
	gotoxy(BasicSetting::windows_width - 22, 4);
	cout << "��ǰ��Ϸ����: " << "0" << endl;
}

void Map::DrawGameInfo(bool model)
{
	gotoxy(BasicSetting::windows_width - 22, 8);
	if(!model)
		cout << "��ǰ��Ϸģʽ: " << "���" << endl;
	else
		cout << "��ǰ��Ϸģʽ: " << "Ai " << endl;
	gotoxy(BasicSetting::windows_width - 22, 10);
	cout << "��ʷ��߷���: " << 0 << endl;

	gotoxy(BasicSetting::windows_width - 22, 16);
	cout << "��Ϸ����˵����" << endl;
	gotoxy(BasicSetting::windows_width - 25, 18);
	cout << "W����: ��    S����: ��" << endl;
	gotoxy(BasicSetting::windows_width - 25, 20);
	cout << "A����: ��    D����: ��" << endl;
	gotoxy(BasicSetting::windows_width - 25, 22);
	cout << "    �ո��: ��ͣ   " << endl;

	gotoxy(BasicSetting::windows_width - 22, 25);
	cout << "������Ϸ�ٶȣ�" << endl;
	gotoxy(BasicSetting::windows_width - 22, 27);
	cout << "С���� + : �ӿ�" << endl;
	gotoxy(BasicSetting::windows_width - 22, 29);
	cout << "С���� - : ����" << endl;
	gotoxy(BasicSetting::windows_width - 25, 31);
	cout << "�� R ������Ϸ�����ٶ�" << endl;

	gotoxy(BasicSetting::windows_width - 22, 34);
	cout << "����: �����" << endl;
	gotoxy(BasicSetting::windows_width - 22, 36);
	cout << "�汾: 1.0" << endl;
}

bool Map::DrawChoiceInfo() // ѡ����Ϸģʽ
{
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 5);
	cout << "��ѡ����Ϸģʽ��" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 3);
	cout << "1. �ֶ�����ģʽ" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 - 1);
	cout << "2. AI����ģʽ" << endl;
	gotoxy(BasicSetting::windows_width / 2 - 10, BasicSetting::windows_height / 2 + 1);
	cout << "����������ѡ��-> ";
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
	cout << "��Ϸ�����������ˣ�" << endl;;
	gotoxy(BasicSetting::windows_width / 2 - 20, BasicSetting::windows_height / 2 - 3);
	cout << "���ĵ÷�Ϊ��" << Score << endl;
}

void Food::CreatFood(vector<P>& snake)
{
	P_food.x = rand() % (BasicSetting::windows_width - 30) + 1; // x �ķ�ΧΪ 1-50
	P_food.y = rand() % (BasicSetting::windows_height - 2) + 1; // y �ķ�ΧΪ 1-38
	vector<P>::iterator i; // ������
	for (i = snake.begin(); i != snake.end(); i++) // ������
	{
		if ((*i).x == P_food.x && (*i).y == P_food.y) // ����ߺ�ʳ���ص�
		{
			P_food.x = rand() % (BasicSetting::windows_width - 30) + 1; // x �ķ�ΧΪ 1-51
			P_food.y = rand() % (BasicSetting::windows_height - 2) + 1; // y �ķ�ΧΪ 1-39
			i = snake.begin(); // ����������ָ����ͷ�����½��б���
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
	//������ɫΪǳ��ɫ
	setColor(10, 0);
	// Ϊ�˽�ʡЧ�ʣ�����̰���ߵĹ��ɣ�����ֻ��Ҫ��ӡ��ͷ��ɾ����β
	vector<P>::iterator i;
	i = body.begin(); // ͨ���������ҵ���ͷ����ӡ
	gotoxy((*i).x, (*i).y);
	cout << "*";
	setColor(7, 0);
}

void Snake::CleanSnake()
{
	//������ɫΪǳ��ɫ
	setColor(10, 0);
	vector<P>::iterator i;
	i = body.end() - 1; // ͨ���������ҵ���β��end ���ص��ǵ�ǰ�������һ��Ԫ�ص���һλ����Ҫ -1 ��ɾ��
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
	this->GetPath(food); // ���ҵ�·��
	if (this->isGameOver)
		return;
	P N_head; // �µ���ͷ����
	while (!this->path.empty())
	{
		if (_kbhit())
		{
			GetKbHit();
		}
		N_head = this->path.front(); // ���ض��еĵ�һ������
		this->body.insert(body.begin(), N_head); // ���������λ��ѹ��������λ����Ϊ�µ���ͷ
		this->path.pop(); // ������������Ϣ
		CleanSnake(); // ��ɾ����β
		if (this->IsEatFood(food)) // �ж��Ƿ�Ե�ʳ��
		{
			food.CreatFood(body); // ����Ե�ʳ��,�½�ʳ��
			this->score++; // �÷� + 1		
			gotoxy(BasicSetting::windows_width - 22, 4);
			cout << "��ǰ��ҷ���: " << this->score << endl; // ��ӡ����	
			food.DrawFood();
		}
		else
		{
			body.pop_back(); // ɾ�����һ��Ԫ��
		}

		if (!this->isTurn) // ��δ�����ֶ��ٶȵ���ģʽʱ
			GetLevel(); // �ж���Ϸ�ٶȵȼ�
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
		DrawSnake(); // ��ӡ��
		SnakeSleep(this->level); // �ȴ�ˢ��
		if (this->IsHitBody())
			this->isGameOver = true; // ײ������������Ϸ

		if (this->IsHitWall())
			this->isGameOver = true; // ײ��ǽ��������Ϸ

		if (this->isGameOver == true) // �����Ϸ����,������ú���
			return;
	}
}

void Snake::SnakeMove(Food& food)
{

	// �ж��Ƿ��а�������
	if (_kbhit() || this->direction == STOP)
	{
		GetKbHit();
	}
		
	Move(food); // �ƶ��ߵ�����

	CleanSnake(); // ��ɾ����β
	if (this->IsEatFood(food))
	{
		food.CreatFood(body); // ����Ե�ʳ��,�½�ʳ��
		this->score++; // �÷� + 1		
		gotoxy(BasicSetting::windows_width - 22, 4);
		cout << "��ǰ��ҷ���: " << this->score << endl; // ��ӡ����	
		food.DrawFood();
	}
	else
	{		
		body.pop_back(); // ɾ�����һ��Ԫ��
	}

	if (!this->isTurn) // ��δ�����ֶ��ٶȵ���ģʽʱ
		GetLevel(); // �ж���Ϸ�ٶȵȼ�
	gotoxy(BasicSetting::windows_width - 22, 6);
	cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
	DrawSnake(); // ��ӡ��
	SnakeSleep(this->level); // �ȴ�ˢ��
	

	if (this->IsHitBody())
		this->isGameOver = true; // ײ������������Ϸ

	if (this->IsHitWall())
		this->isGameOver = true; // ײ��ǽ��������Ϸ

	if (this->isGameOver == true) // �����Ϸ����,������ú���
		return;



}

void Snake::Move(Food& food)
{
	P N_head = this->body.front(); // ������ͷ��λ�ø��ƶ����λ��

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
	this->body.insert(body.begin(), N_head); // ���ƶ����λ��ѹ��������λ����Ϊ�µ���ͷ
}

void Snake::GetKbHit()
{
	char state = _getch();  // ��ȡ�ļ�����Ϣ

	if (state == ' ') // ����û����¿ո�����ͣ 
	{
		while (1)
		{
			char temp = _getch(); // �����ж��û�����ͣʱ�Ĳ���
			if (temp == ' ')
				break;
			else if (temp == 'R' || temp == 'r') // ������������Ϸ�ٶ�
			{
				this->isTurn = false;
				GetLevel();
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
			}
			else if (temp == '+')
			{
				this->isTurn = true; // �����ֶ��ٶȵ��ڻ���
				if (this->level < 10) // ��ߵȼ�Ϊ 10 ��
					this->level++;
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
			}
			else if (temp == '-') // ��͵ȼ�Ϊ 1 ��
			{
				this->isTurn = true; // �����ֶ��ٶȵ��ڻ���
				if (this->level > 1) // ��͵ȼ�Ϊ 1 ��
					this->level--;
				gotoxy(BasicSetting::windows_width - 22, 6);
				cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
			}
		}
	}
	else if (state == 'R' || state == 'r') {
		this->isTurn = false;
		GetLevel();
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
	}
	else if (state == '+')
	{
		this->isTurn = true; // �����ֶ��ٶȵ��ڻ���
		if (this->level < 10) // ��ߵȼ�Ϊ 10 ��
			this->level++;
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
	}
	else if (state == '-') // ��͵ȼ�Ϊ 1 ��
	{
		this->isTurn = true; // �����ֶ��ٶȵ��ڻ���
		if (this->level > 1) // ��͵ȼ�Ϊ 1 ��
			this->level--;
		gotoxy(BasicSetting::windows_width - 22, 6);
		cout << "��ǰ�ٶȵȼ�: " << this->level << endl;
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
		switch (state) // ������ڶ����ֽ��ж�
		{
		case 72:
			if (this->direction == DOWN)
				break;
			this->direction = UP;
			break; // ��
		case 80:
			if (this->direction == UP)
				break;
			this->direction = DOWN;
			break; // ��
		case 75:
			if (this->direction == RIGHT)
				break;
			this->direction = LEFT;
			break; // ��
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
	BFS Ai(this->body); // �����вι����ʼ��ͼ
	if (Ai.FindPath(food))
	{
		this->path = Ai.GetPath(food); // �õ�·��
		this->path.pop(); // ������һ��Ԫ�أ���ͷ��
	}
	else
	{
		this->isGameOver = true;
	}
	
}

bool BFS::FindPath(Food& food)
{
	queue<P> tmp; // ������ʱ���д���ڵ�
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
			if (now.x == food.P_food.x && now.y == food.P_food.y)
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

void BFS::InitMap(vector<P>& snake)
{
	// ��ǽ���Ϊ 1 ����ʾ�ýڵ㲻�ɷ��ʣ�
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
				bfs_map[i][j] = 0; // �����ڵ�ɷ���
			}
		}
	}

	// ���߱��Ϊ 1 ����ʾ�ýڵ㲻�ɷ��ʣ�
	vector<P>::iterator i;
	for (i = snake.begin(); i != snake.end(); i++)
	{
		this->bfs_map[(*i).x][(*i).y] = 1;
	}

	this->head = snake.front(); // �õ���ͷ��λ��

	// ����һ����ά�������ڴ洢���ڵ���Ϣ
	this->bfs_father = new P * [BasicSetting::windows_width - 28];
	for (int i = 0; i < BasicSetting::windows_width - 28; i++)
	{
		this->bfs_father[i] = new P[BasicSetting::windows_height];
	}

	// �ڸ��ڵ�ͼ�б�ǳ���ͷ��λ��
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
		Game.GameInit(); // ��ʼ����Ϸ����
		Map map;
		model = map.DrawChoiceInfo();
		map.DrawMap(); // ��ӡ��ͼ
		map.DrawScore(); // ��ӡ�÷���Ϣ
		map.DrawGameInfo(model); // ��ӡ��Ϸ��Ϣ
		Snake snake;
		snake.isAi = model; // ��Ϸģʽ

		Food food(snake.body); // �����вι���

		while (!snake.isGameOver)
		{
			if (!snake.isAi)
				snake.SnakeMove(food); // �ߵ��ƶ�
			else
				snake.AiMove(food); // Ai �ߵ��ƶ�
		}

		map.GameOver(snake.score); // ��Ϸ������ʾ

		if (snake.score > snake.record) //��ȡ��߷�
			WriteScore(snake.score);

		// ��ӡ�Ƿ����¿�ʼ��Ϸ����ʾ
		gotoxy(BasicSetting::windows_width / 2 - 34, BasicSetting::windows_height / 2 + 3);
		cout << "���¿�ʼ ���� 0\t  \t�˳���Ϸ ���� 1" << endl;

		// ����ѡ��Ϊ�˱��ⰴ���������������²������жϣ�������ѭ���н��У�
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

		// ��ʱ���ø��������������������ǰ��Ϸ
		// ��Ȼ���¿�ʼ��Ϸ����Ҫ��ʼ���ߣ���Ϊ��ͼ����Ϸ��Ϣ���䣩
		// ���ǻ��ڸ���֮����໥�����ԣ��ʶ�������Ϸ���г�ʼ�����������䶯��С
	}
	return EXIT_SUCCESS;
}