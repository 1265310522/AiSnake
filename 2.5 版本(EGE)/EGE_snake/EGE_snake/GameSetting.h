#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <Windows.h> 
#include <Mmsystem.h>
#include <graphics.h>
#pragma comment(lib,"winmm.lib")
void DrawRscore(int rscore);
void DrawTime(double time);
void DrawMusic(int type);
void PlayMusic(MUSIC& music, int type, bool play,bool type_change);



void GetImage(); // 获得图片

static const int Windows_width = 900; // 设置宽
static const int Windows_height = 680; // 设置高

typedef struct Point {
	int x;
	int y;
}P;

class Food;

class Map {

public:
	friend class EgeSetting;
	void DrawMap(); // 打印地图
};

// 枚举各速度等级所需要达到的分数
enum score_of_level {
	level_1 = 1,
	level_2 = 3,
	level_3 = 9,
	level_4 = 18,
	level_5 = 27,
	level_6 = 54,
	level_7 = 108,
	level_8 = 216,
	level_9 = 512,
	level_10 = 1024,
};

// 枚举各个方向
enum direction {
	UP = 8,
	DOWN = 2,
	LEFT = 4,
	RIGHT = 6,
	STOP = 0,
};

class Food
{

public:
	Food(std::vector<P>& snake);
	int food_type = 0; // 食物种类
	P pos_of_food; // 食物坐标
	void CreatFood(std::vector<P>& snake);
	void DrawFood(); // 打印食物

};

class Snake {

public:
	Snake();
	std::vector<P> body; // 存储蛇信息

public:
	void PlayerMove(Food& food, double starttime, MUSIC& music); // 玩家模式移动
	void AiMove(Food& food, double starttime, MUSIC& music); // Ai模式移动
	void InitDirection(double starttime); // 初始化移动方向
	void GameOver(); // 游戏结束
	bool isGameOver; // 是否死亡
	int score; // 分数
	int music_num; // 音乐选择
	bool is_music_change; // 是否调整音乐
	bool type_change; // 是否切换音乐
	bool is_music_play; // 是否播放音乐
	bool isAi;
	std::queue<P> AI_path; // AI 的路径信息
private:
	void DrawSnake(); // 打印蛇头
	void CleanSnake(); // 删除蛇尾
	void GetDirection(double starttime, MUSIC& music); // 获得移动的方向
	void Getlevel(); // 获得速度等级
	void Check_of_Die(); // 死亡检测
	bool Check_of_Food(Food& food); // 食物检测
	void Snake_of_Sleep(); // 刷新率
	void GetDirection_Stop(double starttime, MUSIC& music); // 停止移动
	void GetPath(Food& food); // 得到路径
	void Get_AI_Direction(); // 找到 AI 的运动方向

private:
	int level; // 蛇移动的快慢等级	
	int direction; // 运行方向
	bool isEatFood; // 是否吃到食物
	bool speedModel; // 速度模式(false 为 自动, true 为 手动)
};




class BFS {

public:
	BFS(std::vector<P>& snake);
	~BFS();
	bool FindPath(Food& food); // 找到路径（包含无用的信息）
private:
	friend class Snake;
	P head; // 存储蛇头的位置
	std::queue<P> path; // 存储路径
	int bfs_map[35][30]; // 二维数组存储
	P** bfs_father; // 用二维数组存储父节点
private:
	void InitMap(std::vector<P>& snake);
	std::queue<P> GetPath(Food& food); // 得到路径（剔除无用的信息）
	void GetPath_action(P& pos);
};