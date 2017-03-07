#pragma once 
#define WALL_WITDH              10.0f
#define BLOCK_MAX			    36
#define BLOCK_TYPE			    6
#define BLOCK_HEIGHT		    80.0f
#define BLOCK_WITDH			    80.0f
#define PLAYER2_X_GAP		    640.0f
#define STAGE_SIDE			    70.0f
#define STATUS_SPASE		    160.0f
#define CENTER_GAP			    40.0f
#define SCREEN_HEIGHT		    960.0f
#define START_X_PLAYER1_BALL	290.0f
#define START_X_PLAYER2_BALL	990.0f
#define START_Y_PLAYER_BALL		700.0f
#define START_Y_PLAYER_BER      800.0f
#define START_X_PLAYER1_BER     310.1f
#define START_X_PLAYER2_BER		950.1f
#define START_DEGREE_BALL       90.0f
#define WITDH_BER               150.0f
#define HEIGHT_BLOCK			30.0f
#define MOVE_BER				4.9f
#define TIME_LEFT_X				600.0f
#define TIME_RIGHT_X			680.0f
#define TIME_Y					80.0f
#define COUNTDOWN_X				640.0f
#define COUNTDOWN_Y				680.0f
#define X_PLAYER1_PENALTY_TIME  320.0f
#define Y_PLAYER_PENALTY_TIME   680.0f
#define X_PLAYER_STACK          440.0f
#define Y_PLAYER_STACK          105.0f
#define X_STATUS_BARRIER        240.0f
#define X_STATUS_POISON			340.0f
#define Y_STATUS                105.0f
#define RESULT_X                640.0f
#define RESULT_Y                400.0f
#define RESULT_HOWTO_X          
#define TWO_SECOND              120
#define ONE_SECOND              60



//ブロックの種類
enum TYPE
{
	NORMAL,
	LIGHTNING,
	TORNADO,
	POISON,	
	BARRIER,
	CHANGE,
};
//壁の位置
enum WALLTYPE
{
	LEFT_SIDE,
	RIGHT_SIDE,
	TOP
};
//衝突頂点
enum ColiderVertex
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_RIGHT,
	BOTTOM_LEFT
};
//ボールの座標の構造体
struct Colider
{
	float x;
	float y;
};
//ゲーム内の場面
enum BattleScene
{
	CountDown,
	Battle,
	Result
};
enum Player
{
	PLAYER1,
	PLAYER2
};
struct DataBattle
{
	int BattleSelectNum;
};

