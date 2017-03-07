#include "ManageScene.h"
#include "Battle.h"
#include "Block.h"
#include "Wall.h"
#include "Time.h"
#include "PenaltyTime.h"
#include "Status.h"
#include "Template.h"
#include <winbase.h>
#include"DirectShowSound.h"
extern CSound select1;
extern CSound decision;
CSound ber_bound;
CSound wall_bound;
CSound result_sound;
CSound battle_sound;
void MainScene::InitData()
{
	ber_bound.LoadFile(TEXT("BlockBreakersBGM\\ber_bound.mp3"));
	wall_bound.LoadFile(TEXT("BlockBreakersBGM\\wall_bound.mp3"));
	battle_sound.LoadFile(TEXT("BlockBreakersBGM\\battle.mp3"));
	result_sound.LoadFile(TEXT("BlockBreakersBGM\\result.wav"));

	Player1Block->InitPlayerBlock(Player1Block,PLAYER1);
	Player2Block->InitPlayerBlock(Player2Block, PLAYER2);
	Player1Block->InitBlockPattern(Player1Block, Player2Block);
	Player1Ball.InitPlayerBall(START_X_PLAYER1_BALL, START_Y_PLAYER_BALL, START_DEGREE_BALL, &Player1Ball);
	Player2Ball.InitPlayerBall(START_X_PLAYER2_BALL, START_Y_PLAYER_BALL, START_DEGREE_BALL, &Player2Ball);
	Player1Ber.InitPlayer1Ber(START_X_PLAYER1_BER, START_Y_PLAYER_BER);
	Player2Ber.InitPlayer2Ber(START_X_PLAYER2_BER, START_Y_PLAYER_BER);
	Player1Wall.InitPlayer1Wall(&Player1Wall);
	Player2Wall.InitPlayer2Wall(&Player2Wall);
	Player1flag.InitPenaltyTime();
	Player2flag.InitPenaltyTime();
	BattleTimer.InitTime();
	Player1Status.InitStatus();
	Player2Status.InitStatus();
	EndFlag.InitEndFlag();
	Data.BattleSelectNum = 0;
	battle_sound.PlayRoop();
	fadestep = InMidstream;
}
void MainScene::Input(InputKey** ppInput, ManageScene** ppManageScene, GamePad** ppGamePad)
{
	if (fadestep == OutEnd)
	{
		(*ppManageScene)->ChangeScene(Data.BattleSelectNum);
	}

	if (fadestep != free)return;

	//ここにコントローラー更新関数
	bool padCheck[2];


	for (int i = 0; i < 2; i++){
		if ((*ppGamePad)->ChkPadConect(i)) padCheck[i] = TRUE;
		else{

			padCheck[i] = FALSE;
		}
	}
	(*ppGamePad)->UpdateControllerState();

	if (BattleTimer.GetEndFlag() == false)
	{
		float Player1Xmin = Player1Ber.GetPosX() - (WITDH_BER / 2.0f);
		float Player1Xmax = Player1Ber.GetPosX() + (WITDH_BER / 2.0f);
		float Player2Xmin = Player2Ber.GetPosX() - (WITDH_BER / 2.0f);
		float Player2Xmax = Player2Ber.GetPosX() + (WITDH_BER / 2.0f);
		if (((*ppInput)->CheckKey(D) == ON || (padCheck[0] == TRUE && ((*ppGamePad))->ChkGamePadAction(0, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_ON)) && Player1Xmax < 630.0f)
		{
			Player1Ber.moveBerRight(Player1Status.isPoison());
		}
		if (((*ppInput)->CheckKey(A) == ON || (padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_LEFT) == GamePad::KEY_ON)) && Player1Xmin > 10.0f)
		{
			Player1Ber.moveBerLeft(Player1Status.isPoison());
		}
		if ((*ppInput)->CheckKey(W) == PUSH || (padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B) == GamePad::KEY_ON))
		{
			Player1Status.UseItem(Player1Block, Player2Block, &Player2Status);
		}
		if (((*ppInput)->CheckKey(RIGHT) == ON || (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_ON)) && Player2Xmax<1270.0f)
		{
			Player2Ber.moveBerRight(Player2Status.isPoison());
		}
		if (((*ppInput)->CheckKey(LEFT) == ON || (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_LEFT) == GamePad::KEY_ON)) && Player2Xmin > 650.0f)
		{
			Player2Ber.moveBerLeft(Player2Status.isPoison());
		}
		if ((*ppInput)->CheckKey(UP) == PUSH || (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadBtn_B) == GamePad::KEY_ON))
		{
			Player2Status.UseItem(Player2Block, Player1Block, &Player1Status);
		}
	}
	else if (BattleTimer.GetEndFlag() == true)
	{
		if ((*ppInput)->CheckKey(UP) == PUSH || (*ppInput)->CheckKey(W) == PUSH||
			(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH)
			|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH))
		{
		
			if (Data.BattleSelectNum >SELECT_HOWTO)
			{
				select1.PlayFromStart();
				Data.BattleSelectNum--;
			}
		}
		if ((*ppInput)->CheckKey(DOWN) == PUSH || (*ppInput)->CheckKey(S) == PUSH ||
			(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH)
			|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH))
		{
			
			if (Data.BattleSelectNum <SELECT_END)
			{
				select1.PlayFromStart();
				Data.BattleSelectNum++;
			}
		}

		if ((*ppInput)->CheckKey(ENTER) == PUSH || (*ppInput)->CheckKey(E) == PUSH ||
			(padCheck[0] == TRUE && (*ppGamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B) == GamePad::KEY_ON)
			|| (padCheck[1] == TRUE && (*ppGamePad)->ChkGamePadAction(1, GamePad::GamePadBtn_B) == GamePad::KEY_ON))
		{
			fadestep = OutMidstream;
		}
	}
	(*ppInput)->KeyUpdate();
}
void MainScene::Render(MnageRender** ppRender)
{
	if (BattleTimer.GetEndFlag() == false)  battle_sound.ChkRoop();
	if (BattleTimer.GetEndFlag() == true) 
	{
		battle_sound.Stop();
		result_sound.Play();
	}
	if (fadestep == OutMidstream)
	{
		if ((*ppRender)->FedeOut() == true)fadestep = OutEnd;
	}
	if (fadestep == InMidstream)
	{
		if ((*ppRender)->FedeIn() == true)fadestep = free;
	}

	(*ppRender)->DrawBox(0, "battle.png", 0, 0);
	(*ppRender)->DrawCenterBox(6, "ber_player1.png", Player1Ber.GetPosX(), Player1Ber.GetPosY());
	(*ppRender)->DrawCenterBox(6, "ber_player2.png", Player2Ber.GetPosX(), Player2Ber.GetPosY());
	
	BlockRender(&ppRender,Player1Block,4,0,0,PLAYER1);
	BlockRender(&ppRender, Player2Block, 4,0,0,PLAYER2);
	(*ppRender)->DrawCenterBox(5, "ball_player1.png", Player1Ball.GetPosX(), Player1Ball.GetPosY());
	(*ppRender)->DrawCenterBox(5, "ball_player2.png", Player2Ball.GetPosX(), Player2Ball.GetPosY());
	PenaltyCountRender(&ppRender,&Player1flag,PLAYER1);
	PenaltyCountRender(&ppRender, &Player2flag,PLAYER2);
	CountRender(&ppRender);
	TimeRender(&ppRender,&BattleTimer);
	ItemRender(&ppRender, &Player1Status, PLAYER1);
	ItemRender(&ppRender, &Player2Status, PLAYER2);
	StatusRender(&ppRender, &Player1Status, PLAYER1);
	StatusRender(&ppRender, &Player2Status, PLAYER2);
	EffectRender(&ppRender, &Player1Effect,PLAYER1);
	EffectRender(&ppRender, &Player2Effect,PLAYER2);
	ResultRender(&ppRender,&BattleTimer);

}
void MainScene::Control(ManageScene** ppManageScene)
{
	BattleTimer.UpdateTime();
	if ((BattleTimer.GetTiming() == Battle)&&(Player1flag.CheckFlag()==false))
	{
		Player1Ball.StartBall();
	}
	if ((BattleTimer.GetTiming() == Battle) && (Player2flag.CheckFlag()==false))
	{
		Player2Ball.StartBall();
	}
	Player1flag.UpdatePenaltyTime(&Player1Ball);
	Player2flag.UpdatePenaltyTime(&Player2Ball);
	Player1flag.CheckBall(&Player1Ball, 1);
	Player2flag.CheckBall(&Player2Ball, 2);
	Player1Status.UpdateFlagTime();
	Player2Status.UpdateFlagTime();
	EndFlag.CheakEnd(Player1Block, Player2Block, &BattleTimer, &Player1Ball, &Player2Ball);
	Player1Status.UpdateItemFlagTime();
	Player2Status.UpdateItemFlagTime();
	Player1Status.BreakFlagOff();
	Player2Status.BreakFlagOff();
	Player1Effect.UpDateTime();
	Player2Effect.UpDateTime();
}
void MainScene::Colison()
{
	ManageColisonPlayerWall(&Player1Wall,&Player1Ball);
	ManageColisonPlayerWall(&Player2Wall, &Player2Ball);
	ManageColisonPlayerBer(&Player1Ber,&Player1Ball);
	ManageColisonPlayerBer(&Player2Ber, &Player2Ball);
	ManageColisonPlayerBlock(Player1Block,Player2Block,&Player1Ball,&Player1Status,&Player2Status,&Player1Effect,PLAYER1);
	ManageColisonPlayerBlock(Player2Block,Player1Block,&Player2Ball,&Player2Status,&Player1Status,&Player2Effect,PLAYER2);
	Player1Ball.SetVectorX();
	Player1Ball.SetVectorY();
	Player2Ball.SetVectorX();
	Player2Ball.SetVectorY();
	Player1Ball.Move();
	Player2Ball.Move();
}
Scene* MainScene::ChangeScene(int scenenum)
{
	switch (scenenum)
	{
	case  SELECT_HOWTO:
		return Scene::GO_HowTo();
		break;
	case SELECT_BATTLE:
		return Scene::GO_Battle();
		break;
	case SELECT_END:
		return  Scene::GO_End();
		break;
	default:
		return Scene::GO_HowTo();
		break;
	}
		
}
void MainScene::TimeRender(MnageRender*** pppRender,CTime* ptime)
{
	int temp = ptime->GetBattleTime();
	int  LeftTime = (temp / ONE_SECOND) / 10;
	int  RightTime = (temp / ONE_SECOND) % 10;
	if (temp == 0)
	{
		LeftTime = 0;
		RightTime = 0;
	}
	switch (LeftTime)
	{
	    case 0:
			(*(*pppRender))->DrawCenterBox(4, "number0.png", TIME_LEFT_X, TIME_Y);
			break;
		case 1:
			(*(*pppRender))->DrawCenterBox(4, "number1.png", TIME_LEFT_X, TIME_Y);
		    break;
		case 2:
			(*(*pppRender))->DrawCenterBox(4, "number2.png", TIME_LEFT_X, TIME_Y);
			break;
		case 3:
			(*(*pppRender))->DrawCenterBox(4, "number3.png", TIME_LEFT_X, TIME_Y);
			break;
		case 4:
			(*(*pppRender))->DrawCenterBox(4, "number4.png", TIME_LEFT_X, TIME_Y);
			break;
		case 5:
			(*(*pppRender))->DrawCenterBox(4, "number5.png", TIME_LEFT_X, TIME_Y);
			break;
		case 6:
			(*(*pppRender))->DrawCenterBox(4, "number6.png", TIME_LEFT_X, TIME_Y);
			break;
		case 7:
			(*(*pppRender))->DrawCenterBox(4, "number7.png", TIME_LEFT_X, TIME_Y);
			break;
		case 8:
			(*(*pppRender))->DrawCenterBox(4, "number8.png", TIME_LEFT_X, TIME_Y);
			break;
		case 9:
			(*(*pppRender))->DrawCenterBox(4, "number9.png", TIME_LEFT_X, TIME_Y);
			break;
	}
	switch (RightTime)
	{
	case 0:
		(*(*pppRender))->DrawCenterBox(4, "number0.png", TIME_RIGHT_X, TIME_Y);
		break;

	case 1:
		(*(*pppRender))->DrawCenterBox(4, "number1.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 2:

		(*(*pppRender))->DrawCenterBox(4, "number2.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 3:
		(*(*pppRender))->DrawCenterBox(4, "number3.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 4:
		(*(*pppRender))->DrawCenterBox(4, "number4.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 5:
		(*(*pppRender))->DrawCenterBox(4, "number5.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 6:
		(*(*pppRender))->DrawCenterBox(4, "number6.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 7:
		(*(*pppRender))->DrawCenterBox(4, "number7.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 8:
		(*(*pppRender))->DrawCenterBox(4, "number8.png", TIME_RIGHT_X, TIME_Y);
		break;
	case 9:
		(*(*pppRender))->DrawCenterBox(4, "number9.png", TIME_RIGHT_X, TIME_Y);
		break;
	}
}
void MainScene::CountRender(MnageRender*** pppRender)
{
	if (BattleTimer.GetCountDownTime() > TWO_SECOND)
	{
		(*(*pppRender))->DrawCenterBox(4, "number3.png", COUNTDOWN_X, COUNTDOWN_Y);
	}
	if ((BattleTimer.GetCountDownTime() <= TWO_SECOND) && (BattleTimer.GetCountDownTime() >= ONE_SECOND))
	{
		(*(*pppRender))->DrawCenterBox(4, "number2.png", COUNTDOWN_X, COUNTDOWN_Y);
	}
	if ((BattleTimer.GetCountDownTime() < ONE_SECOND) && (BattleTimer.GetCountDownTime() > 0))
	{
		(*(*pppRender))->DrawCenterBox(4, "number1.png", COUNTDOWN_X, COUNTDOWN_Y);
	}
}
void MainScene::PenaltyCountRender(MnageRender*** pppRender, CPenaltyTime* pPenalty,int Player)
{
		if (pPenalty->GetPenaltyTime() > TWO_SECOND)
		{
			(*(*pppRender))->DrawCenterBox(4, "number3.png", X_PLAYER1_PENALTY_TIME+(Player*PLAYER2_X_GAP), Y_PLAYER_PENALTY_TIME);
		}
		if ((pPenalty->GetPenaltyTime() <= TWO_SECOND) && (pPenalty->GetPenaltyTime() >= ONE_SECOND))
		{
			(*(*pppRender))->DrawCenterBox(4, "number2.png", X_PLAYER1_PENALTY_TIME + (Player*PLAYER2_X_GAP), Y_PLAYER_PENALTY_TIME);
		}
		if ((pPenalty->GetPenaltyTime() < ONE_SECOND) && (pPenalty->GetPenaltyTime() > 0))
		{
			(*(*pppRender))->DrawCenterBox(4, "number1.png", X_PLAYER1_PENALTY_TIME + (Player*PLAYER2_X_GAP), Y_PLAYER_PENALTY_TIME);
		}
	
}
void MainScene::EffectRender(MnageRender*** pppRender, Effect* Effect, int player)
{
	int lighttemp = Effect->GetLightning();
	if (Effect->GetLightningflag() == true)
	{
		(*(*pppRender))->DrawBox(0, lighttemp / 8, "kaminari.png", 80 + (player*PLAYER2_X_GAP) + (float)(Effect->GetLightningline() % 6 * 80), 100);
	}
	int tornadoTemp = Effect->GetTornado();
	if (Effect->GetTornadoflag() == true&&Effect->GetTwinflag()==false)
	{
		(*(*pppRender))->DrawBox(1, tornadoTemp / 7, "tatumaki.png", 20+ (player*PLAYER2_X_GAP), (float)(Effect->GetTornadoline() / 6 * 80)+140);
	}
	if (Effect->GetTornadoflag() == true && Effect->GetTwinflag() == true)
	{
		(*(*pppRender))->DrawBox(1, tornadoTemp / 7, "tatumaki.png", 20 + (player*PLAYER2_X_GAP), (float)(Effect->GetTornadoline() / 6 * 80) + 140);
		if (player == PLAYER1)
		{
			(*(*pppRender))->DrawBox(1, tornadoTemp / 7, "tatumaki.png", 20 + PLAYER2_X_GAP, (float)(Effect->GetTornadoline() / 6 * 80) + 140);
		}
		if (player == PLAYER2)
		{
			(*(*pppRender))->DrawBox(1, tornadoTemp / 7, "tatumaki.png", 20, (float)(Effect->GetTornadoline() / 6 * 80) + 140);
		}
	}
}
void MainScene::ItemRender(MnageRender*** pppRender, Status* pstatus, int player)
{
		int temp = pstatus->GetItemNum();
		if (temp==POISON)
		{
			(*(*pppRender))->DrawCenterBox(4, "poison.png", X_PLAYER_STACK + (player*PLAYER2_X_GAP), Y_PLAYER_STACK);
		}
		if (temp == CHANGE)
		{
			(*(*pppRender))->DrawCenterBox(4, "change.png", X_PLAYER_STACK + (player*PLAYER2_X_GAP), Y_PLAYER_STACK);
		}
		if (temp == BARRIER)
		{
			(*(*pppRender))->DrawCenterBox(4, "barrier.png", X_PLAYER_STACK + (player*PLAYER2_X_GAP), Y_PLAYER_STACK);
		}
}
void MainScene::StatusRender(MnageRender*** pppRender, Status* pstatus, int player)
{
		if (pstatus->isBarrier() == true)
		{
			(*(*pppRender))->DrawCenterBox(4, "barrier_use.png", X_STATUS_BARRIER + (player*PLAYER2_X_GAP), Y_STATUS);
		}
		if (pstatus->isPoison() == true)
		{
			(*(*pppRender))->DrawCenterBox(4, "poison_use.png", X_STATUS_POISON + (player*PLAYER2_X_GAP), Y_STATUS);
		}
}
void MainScene::ResultRender(MnageRender*** pppRender, CTime* pTime)
{
	if (pTime->GetEndFlag()==true)
	{
		(*(*pppRender))->DrawBox(0, "result_screen.png", 0.0f, 0.0f);
		if (EndFlag.Getjudgement()==Player1win)
		{
			(*(*pppRender))->DrawBox(7, "result_win.png", 230.0f, 230.0f);
			(*(*pppRender))->DrawBox(7, "result_lose.png", 110.0f+PLAYER2_X_GAP, 230.0f);
		}
		else if (EndFlag.Getjudgement() == Player2win)
		{
			(*(*pppRender))->DrawBox(7, "result_lose.png", 230.0f, 230.0f);
			(*(*pppRender))->DrawBox(7, "result_win.png", 115.0f + PLAYER2_X_GAP, 230.0f);
		}
		else if (EndFlag.Getjudgement() == Draw)
		{
			(*(*pppRender))->DrawBox(7, "result_draw.png", 490.0f, 230.0f);
		}
		(*(*pppRender))->DrawCenterBox(7, "result_howto.png", RESULT_X, RESULT_Y);
		(*(*pppRender))->DrawCenterBox(7, "result_again.png", RESULT_X, RESULT_Y+MENU_HEIGHT);
		(*(*pppRender))->DrawCenterBox(7, "result_end.png", RESULT_X, RESULT_Y+(MENU_HEIGHT*2));
		switch (Data.BattleSelectNum)
		{
		case SELECT_BATTLE:
			(*(*pppRender))->DrawCenterBox(7, "result_again_select.png", RESULT_X, RESULT_Y + ((float)Data.BattleSelectNum * MENU_HEIGHT));
			break;
		case SELECT_HOWTO:
			(*(*pppRender))->DrawCenterBox(7, "result_howto_select.png", RESULT_X, RESULT_Y + ((float)Data.BattleSelectNum * MENU_HEIGHT));
			break;
		case SELECT_END:
			(*(*pppRender))->DrawCenterBox(7, "result_end_select.png", RESULT_X, RESULT_Y + ((float)Data.BattleSelectNum * MENU_HEIGHT));
			break;
		default:
			break;
		}
	}
	
}
void MainScene::BlockRender(MnageRender*** pppRender, Block block[], int GraphNum, float x, float y,int player)
{
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		if((block[i].GetBlockUse())==true){
			switch (block[i].GetBlockType())
			{
			case NORMAL:
				if (player ==PLAYER1)
				{
					(*(*pppRender))->DrawCenterBox(GraphNum, "block_player1.png", x + block[i].GetBlockPosX(), y + block[i].GetBlockPosY());
				}
				if (player == PLAYER2)
				{
					(*(*pppRender))->DrawCenterBox(GraphNum, "block_player2.png", x + block[i].GetBlockPosX(), y + block[i].GetBlockPosY());
				}
				break;
			case LIGHTNING:
				(*(*pppRender))->DrawCenterBox(GraphNum, "lightning.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			case TORNADO:
				(*(*pppRender))->DrawCenterBox(GraphNum, "tornado.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			case POISON:
				(*(*pppRender))->DrawCenterBox(GraphNum, "poison.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			case BARRIER:
				(*(*pppRender))->DrawCenterBox(GraphNum, "barrier.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			case CHANGE:
				(*(*pppRender))->DrawCenterBox(GraphNum, "change.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			default:
				(*(*pppRender))->DrawCenterBox(GraphNum, "block.png",x +block[i].GetBlockPosX(), x +block[i].GetBlockPosY());
				break;
			}
		}
	}
}
void MainScene::ManageColisonPlayerWall(Wall* pWall,Ball* pBall)
{
	
	float temp = pBall->GetDegree();
	if (pWall->WallColider[TOP_LEFT].y > pBall->GetPosY() - RADIUSU)
	{
		pBall->SetY(pBall->GetPosY() + 5.0f);
		//サウンド
		wall_bound.PlayFromStart();
		if (temp <= 0)
		{
			pBall->SetDegree((temp-360.0f)*-1);
		}
		else
		{
			pBall->SetDegree(temp - 360.0f);
		}
	}
	else if (pWall->WallColider[TOP_LEFT].x > pBall->GetPosX() - RADIUSU)
	{
		//サウンド
		
		wall_bound.PlayFromStart();
		if (temp >= 180.0f)
		{
			pBall->SetDegree(270.0f + (270.0f - temp));
		}
		else if (temp <= 180.0f)
		{
			pBall->SetDegree(90.0f - (temp - 90.0f));
		}
		pBall->SetX(pBall->GetPosX()+10.0f);
	}
	else if (pWall->WallColider[TOP_RIGHT].x < pBall->GetPosX() + RADIUSU)
	{
		
		//サウンド
		wall_bound.PlayFromStart();
		if (90.0f >= temp)
		{
			pBall->SetDegree(180.0f - temp);
		}
		else if (270.0f<=temp)
		{
			pBall->SetDegree(180.f + (360.0f - temp));
		}
		pBall->SetX(pBall->GetPosX() - 10.0f);
	}
}
void MainScene::ManageColisonPlayerBer(Ber* pBer,Ball* pBall)
{
	if ((pBer->BerColider[TOP_LEFT].y<pBall->GetPosY()) && (pBer->BerColider[BOTTOM_LEFT].y>pBall->GetPosY()))
		{
			if (pBall->GetPosX() + RADIUSU>(pBer->GetPosX() - BER_WITDH/2) && pBall->GetPosX() - RADIUSU<(pBer->GetPosX() + BER_WITDH/2))
			{
				//サウンド
				ber_bound.PlayFromStart();
				pBall->SetDegree(270.0f + ((pBall->GetPosX() - pBer->GetPosX()) / 2.0f));
			}
			
		}
}
void MainScene::ManageColisonPlayerBlock(Block* PlayerBlock,Block* EmenyBlock, Ball* pBall, Status* pPlayerStatus,Status* pEmenyStatus,Effect* effect,int playernum)
{
	for (int i = 0; i < BLOCK_MAX; i++)
	{
		
		if ((PlayerBlock[i].BlockColider[TOP_LEFT].x < pBall->GetPosX() + RADIUSU) && (PlayerBlock[i].BlockColider[TOP_RIGHT].x>(pBall->GetPosX() - RADIUSU)))
		{
			if ((PlayerBlock[i].BlockColider[TOP_LEFT].y < (pBall->GetPosY()) + RADIUSU) && (PlayerBlock[i].BlockColider[BOTTOM_LEFT].y>(pBall->GetPosY() - RADIUSU)))
			{
				if (PlayerBlock[i].GetBlockUse() == true)
				{
					
					PlayerBlock[i].HitBlock(PlayerBlock,EmenyBlock, i,pPlayerStatus,pEmenyStatus,effect,playernum);
					if (Player1Status.OnceBreakFlagCheack() == false)
					{
						
							pBall->SetDegree(ManageColisonPlayerBlockBounde(PlayerBlock, pBall, i));
						
					}
					Player1Status.BreakFlagOn();
				}
			}
		}
	}
}
float MainScene::ManageColisonPlayerBlockBounde(Block* pBlock, Ball* pBall, int Blocknum)
{
	float temp = pBall->GetDegree();
	float TempAngle = atan2(pBlock[Blocknum].GetBlockPosY() - pBall->GetPosY(), pBlock[Blocknum].GetBlockPosX() - pBall->GetPosX())*RadtoDeg;
	if (temp > 360.0f)
	{
		temp = temp - 360.0f;
	}
	//上からぶつかった時
	if (TempAngle>=45.000000000f&&TempAngle<=135.000000000f)
	{
		if (temp<90.0f&&temp>=0.0f)
		{
			return(360.0f-temp);
		}
		else if (180.0f>=temp&&temp>90.0f)
		{
			return (360.0f-temp);
		}
	}
	//下からぶつかった時
	else if (TempAngle>=-135.000000000f&&TempAngle<=-45.000000000f)
	{
		if (temp > 270.0f&&temp <= 360.0f)
		{
			return (360.0f - temp);
		}
		else if (temp>=180.0f&&temp<270.0f)
		{
			return (90.0f + (270.0f - temp));
		}
	}
	//右からぶつかった時
	else if(TempAngle>=135.000000000f || TempAngle<=-135.000000000f)
	{
		if (180.0f<temp&&temp<=270.0f)
		{
			return (540.0f-temp);
		}
		else if(180.0f>temp&&temp>=90.0f)
		{
			return (180.0f - temp);
		}
	}
	//左からぶつかった時
	else if ((TempAngle>=-45.0000000000f&&TempAngle<=45.000000000f) || (TempAngle<=0.000000000f&&TempAngle>=-45.000000000f))
	{
		if (360.0f>temp&&temp>=270.0f)
		{
			return (270.0f - (temp-270.f));
		}
		else if (0.0f<temp&&temp<=90.0f)
		{
			return (180.0f-temp);
		}
	}
	//イレギュラーな値は角に当たったようにして誤魔化す
	return TempAngle + 180.0f;
}