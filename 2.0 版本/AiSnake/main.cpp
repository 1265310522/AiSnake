#include "GameSetting.h"

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