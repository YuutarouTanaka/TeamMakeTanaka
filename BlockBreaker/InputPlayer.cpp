#include "InputPlayer.h"
bool InputPlayer::isUp()
{
	return (inputKey)->CheckKey(UP) == PUSH || (inputKey)->CheckKey(W) == PUSH ||
		(gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH)
		|| (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH);

}
bool InputPlayer::isDown()
{
	return (inputKey)->CheckKey(DOWN) == PUSH || (inputKey)->CheckKey(S) == PUSH ||
		(gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH)
		|| (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH);

}
bool InputPlayer::isLeft()
{
	return (inputKey)->CheckKey(LEFT) == PUSH || (inputKey)->CheckKey(A) == PUSH ||
		(gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH)
		|| (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH);

}
bool InputPlayer::isRight()
{

	return (inputKey)->CheckKey(RIGHT) == PUSH || (inputKey)->CheckKey(D) == PUSH ||
		(gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH)
		|| (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(1, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer1Up()
{
	return (inputKey)->CheckKey(W) || (gamePad)->padCheck[0] == TRUE && (gamePad->ChkGamePadAction(0, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH);
	
}
bool InputPlayer::isPlayer1Down()
{
	return (inputKey)->CheckKey(S) || (gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH);
	
}
bool InputPlayer::isPlayer1Right()
{
	return (inputKey)->CheckKey(D) || (gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer1Left()
{
	return (inputKey)->CheckKey(A) || (gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer1Select()
{
	return (inputKey)->CheckKey(E) || (gamePad->padCheck[0] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B )== GamePad::KEY_ON);
}
bool InputPlayer::isPlayer2Up()
{
	return (inputKey)->CheckKey(UP) || (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_UP) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer2Down()
{
	return (inputKey)->CheckKey(DOWN) || (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_DOWN) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer2Right()
{
	return (inputKey)->CheckKey(RIGHT) || (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_RIGHT) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer2Left()
{
	return (inputKey)->CheckKey(LEFT) || (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadLStick_LEFT) == GamePad::KEY_PUSH);
}
bool InputPlayer::isPlayer2Select()
{
	return (inputKey)->CheckKey(ENTER) || (gamePad->padCheck[1] == TRUE && (gamePad)->ChkGamePadAction(0, GamePad::GamePadBtn_B) == GamePad::KEY_ON);
}
