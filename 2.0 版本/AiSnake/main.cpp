#include "GameSetting.h"

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