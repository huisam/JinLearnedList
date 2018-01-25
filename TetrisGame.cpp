#include <iostream>
#include <windows.h> //GetStdHandle(), Sleep(), SetConsolePosition() 함수 사용
#include <conio.h> //getch()와 kbhit() 함수 사용
#include <ctime> //time()함수 사용
#include <cstdlib> //rand()함수와 srand()함수 사용
#include"TetrisGame.h"

#define ESC 27 //게임 종료
#define LEFT 75 //왼쪽 화살표 키 ASCII값
#define RIGHT 77 // 오른쪽 화살표 키 ASCII값
#define DOWN 80 //아래 화살표 키 ASCII값
#define UP 72 //위쪽 화살표 키 ASCII값
#define SPACE 32 //스페이스 키 ASCII값 

#define BOARD_HEIGHT 22 //게임 보드 높이
#define BOARD_WIDTH  12 //게임 보드 넓이 
#define NEXT_HEIGHT  6 //다음 블럭 보드 높이
#define NEXT_WIDTH   7 //다음 블럭 보드 넓이

#define SCORE_HEIGHT 3 //점수 블럭 보드 높이
#define SCORE_WIDTH  7 //점수 블럭 보드 넓이

#define BSIZE 4 //블럭 높이 & 넓이
#define BROTATION 4 // 블럭 회전

//게임 보드 배열에서 보드 경계선, 보드 내부,  블럭 표시
#define BOARD_BORDER 2 //게임 보드 경계선 표시
#define BOARD_INSIDE 0 //게임 보드 내부 표시
#define BLOCK 1 //블럭 표시

// 테트리스 블록 시작 위치
#define BLOCK_STARTX 28
#define BLOCK_STARTY 3

//게임 보드 그리기 시작 위치
#define BOARD_STARTX 20  
#define BOARD_STARTY 2

//다음 블럭 그리기 시작 위치
#define NEXT_STARTX  45 
#define NEXT_STARTY  3

//점수 그리기 시작 위치
#define SCORE_STARTX 45
#define SCORE_STARTY 21

#define BSHAPE 7


using namespace std;

//MOVE_LEFT: 블럭 왼쪽 1칸 이동, MOVE_RIGHT: 블럭 오른쪽 1칸 이동, MOVE_DOWN: 블록 //아래 1칸 이동, MOVE_DROP: 블럭 아래 1칸 자동 이동, ROTATION: 블록 회전, GAME_QUIT: //게임종료

enum GameAction { MOVE_LEFT = 1, MOVE_RIGHT, MOVE_DOWN, MOVE_DROP, ROTATION, GAME_QUIT };


TetrisGame::TetrisGame() :score(0), action(3), flag(true)
{
	bk.X = BLOCK_STARTX;
	bk.Y = BLOCK_STARTY + 1;
	bk.S = 0;
	bk.R = 0;

	board = new int*[BOARD_HEIGHT + 22];

	for (int i = 0; i < BOARD_HEIGHT + 3; i++)
		board[i] = new int[BOARD_WIDTH + 4];
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int d = 0; d < BOARD_WIDTH + 4; d++)
		{
			if ((i == 0) || (i == 21))
				board[i][d] = BOARD_BORDER;
			else if ((d == 0) || (d == 11))
				board[i][d] = BOARD_BORDER;
			else
				board[i][d] = 0;
		}
	}
	nextBoard = new int*[NEXT_HEIGHT];

	for (int a = 0; a < NEXT_HEIGHT; a++)
		nextBoard[a] = new int[NEXT_WIDTH];
	for (int a = 0; a < NEXT_HEIGHT; a++) {
		for (int b = 0; b < NEXT_WIDTH; b++)
		{
			if ((a == 0) || (a == 5))
				nextBoard[a][b] = BOARD_BORDER;
			else if ((b == 0) || (b == 6))
				nextBoard[a][b] = BOARD_BORDER;
			else
				nextBoard[a][b] = 0;
		}
	}
	scoreBoard = new int*[SCORE_HEIGHT];

	for (int x = 0; x < SCORE_HEIGHT; x++)
		scoreBoard[x] = new int[SCORE_WIDTH];
	for (int x = 0; x < SCORE_HEIGHT; x++) {
		for (int y = 0; y < SCORE_WIDTH; y++)
		{
			if ((x == 0) || (x == 2))
				scoreBoard[x][y] = BOARD_BORDER;
			else if ((y == 0) || (y == 6))
				scoreBoard[x][y] = BOARD_BORDER;
			else
				scoreBoard[x][y] = 0;
		}
	}
}
void TetrisGame::initGame()
{
	gotoXY(BOARD_STARTX, BOARD_STARTY);
	cout << "[GAME BOARD]";
	gotoXY(BOARD_STARTX, BOARD_STARTY + 1);
	for (int i = 0; i < BOARD_HEIGHT + 3; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j] == BOARD_BORDER)
				cout << "□";
			else
				cout << "  ";
		}
		gotoXY(BOARD_STARTX, BOARD_STARTY + i + 2);
	}
	gotoXY(NEXT_STARTX, NEXT_STARTY);
	cout << "[NEXT BLOCK]"<<endl;
	gotoXY(NEXT_STARTX, NEXT_STARTY + 1);
	for (int i = 0; i < NEXT_HEIGHT; i++) {
		for (int j = 0; j < NEXT_WIDTH; j++) {
			if (nextBoard[i][j] == BOARD_INSIDE)
				cout << "  ";
			else
				cout << "□";

		}
		gotoXY(NEXT_STARTX, NEXT_STARTY + i + 2);
	}
	gotoXY(SCORE_STARTX, SCORE_STARTY);
	cout << "[GAME SCORE]" << endl;
	gotoXY(SCORE_STARTX, SCORE_STARTY + 1);
	for (int i = 0; i < SCORE_HEIGHT; i++) {
		for (int j = 0; j < SCORE_WIDTH; j++) {
			if (scoreBoard[i][j] == BOARD_INSIDE)
				cout << "  ";
			else
				cout << "□";

		}
		gotoXY(SCORE_STARTX, SCORE_STARTY + i + 2);
	}
}
void TetrisGame::randBlock(int(*block)[BROTATION][BSIZE][BSIZE])
{
	srand((unsigned)time(NULL));
	if (bk.Y == BLOCK_STARTY +1)
		bk.N = rand() % 7;

	gotoXY(NEXT_STARTX + 4, NEXT_STARTY + 2);

	for (int i = 0; i < BSIZE; i++) {
		for (int j = 0; j <BSIZE; j++) {
			if (block[bk.N][0][i][j] == BLOCK)
				cout << "■";
			else
				cout << "  ";
		}
		gotoXY(NEXT_STARTX + 4, NEXT_STARTY + i + 3);
	}
}
void TetrisGame::drawGame(int(*block)[BROTATION][BSIZE][BSIZE])
{
	for (int i = 0; i < BSIZE; i++) {
		for (int j = 0; j < BSIZE; j++) {
			gotoXY(bk.X + j * 2, bk.Y + i);
			if (block[bk.S][bk.R][i][j] == BLOCK)
				cout << "  ";
		}
	}
	blocktransfer();

	if (crush()) {
		for (int i = 0; i < BSIZE; i++) {
			for (int j = 0; j < BSIZE; j++) {
				gotoXY(bk.X + j * 2, bk.Y + i);
				if (block[bk.S][bk.R][i][j] == BLOCK)
					cout << "■";
			}
		}
	}
	else {
		bk.X = X; bk.Y = Y; bk.R = R;

		for (int i = 0; i < BSIZE; i++) {
			for (int j = 0; j < BSIZE; j++) {
				gotoXY(bk.X + j * 2, bk.Y + i);
				if (block[bk.S][bk.R][i][j] == BLOCK)
					cout << "■";
			}
		}
	}
}
void TetrisGame::getGameAction() {

	if (_kbhit() != 0) //키보드를 눌렀는지 확인함 
	{
		keyValue = _getch();
		if (keyValue == 224) //특수 키를 눌렀을 때 버퍼에 2Byte가 발생함, 첫번째 값은 224값을 발생하고 두번째 값은 특수키에 따라 다름
		{
			keyValue = _getch(); //특수 키를 확인하기 위해 2번의 getch()함수를 호출해야 함
		}
		switch (keyValue)
		{
		case ESC:
			action = GAME_QUIT;
			break;
		case LEFT:
			action = MOVE_LEFT;
			break;
		case RIGHT:
			action = MOVE_RIGHT;
			break;
		case DOWN:
			action = MOVE_DOWN;
			break;
		case UP:
			action = ROTATION;
			break;
		case SPACE:
			action = MOVE_DROP;
			break;
		default:
			break;
		}
	}
}
void TetrisGame::blocktransfer()
{
	X = bk.X;
	Y = bk.Y;
	R = bk.R;
	if (action == MOVE_LEFT)
	{
		bk.X -= 2;
		if (bk.X < 20)
			bk.X = 20;
		bk.Y += 1;
		action = MOVE_DOWN;
	}
	else if (action == MOVE_RIGHT)
	{
		bk.X += 2;
		bk.Y += 1;
		action = MOVE_DOWN;
	}
	else if (action == MOVE_DROP)
	{
		spacebar();
		action = MOVE_DOWN;
	}
	else if (action == ROTATION)
	{
		if (bk.R == 3)
			bk.R = 0;
		else
			bk.R += 1;
		action = MOVE_DOWN;
	}
	else if (action == MOVE_DOWN)
	{
		bk.Y += 1;
	}
	else if (action == GAME_QUIT)
	{
		flag = false;
	}
}
void TetrisGame::updateGame()
{
	gotoXY(SCORE_STARTX + 6, SCORE_STARTY + 2);
	cout << score;

	for (int i = 0; i < BSIZE; i++) {
		for (int j = 0; j < BSIZE; j++) {
			if ((block[bk.S][bk.R][i][j] == BLOCK) &&
				(board[i + bk.Y - BLOCK_STARTY + 1][j + (bk.X - BOARD_STARTX) / 2] == BOARD_BORDER) &&
				((bk.Y == 20) || (bk.Y == 21) || (bk.Y == 22) || (bk.Y == 23)))
			{
				saveboard();
				drawboard();
				nextstate();
			}
			else if ((block[bk.S][bk.R][i][j] == BLOCK) &&
				(board[i + bk.Y - BLOCK_STARTY + 1][j + (bk.X - BOARD_STARTX) / 2] == BLOCK))
			{
				saveboard();
				drawboard();
				nextstate();
			}
		}
	}
	// 테트리스 블록이 밑에 도달했을때 초기화시켜주는 조건문
	
	scoreup();
	testflag();
}
void TetrisGame::saveboard()
{
	for (int i = 0; i < BSIZE; i++) {
		for (int j = 0; j < BSIZE; j++) {
			if (block[bk.S][bk.R][i][j] == BLOCK)
				board[bk.Y - 3 + i][(bk.X - 20) / 2 + j] = block[bk.S][bk.R][i][j];
		}
	}
}
void TetrisGame::drawboard()
{
	gotoXY(BOARD_STARTX, BOARD_STARTY + 1);
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (board[i][j] == BOARD_BORDER)
				cout << "□";
			else if (board[i][j] == BOARD_INSIDE)
				cout << "  ";
			else
				cout << "■";
		}
		gotoXY(BOARD_STARTX, BOARD_STARTY + i + 2);
	}
}
bool TetrisGame::crush()
{
	for (int i = 0; i < BSIZE; i++) {
		for (int j = 0; j < BSIZE; j++) {
			if ((block[bk.S][bk.R][i][j] == BLOCK) && (board[i + bk.Y - 3][j + (bk.X - 20) / 2] != BOARD_INSIDE))
				return false;
		}
	}
	return true;
}
void TetrisGame::nextstate()
{
	bk.X = BLOCK_STARTX;
	bk.Y = BLOCK_STARTY + 1;
	bk.R = 0;
	bk.S = bk.N;
}
void TetrisGame::spacebar()
{
	for (int i = 1; i < BOARD_HEIGHT+3 - bk.Y; i++) {
		bk.Y += 1;
		if (crush())
			NULL;
		else
			bk.Y = Y;
	}
}
void TetrisGame::scoreup()
{
	for (int i = BOARD_HEIGHT - 2; i >0; i--) {
		if ((board[i][1] == BLOCK) && (board[i][2] == BLOCK) && (board[i][3] == BLOCK) && (board[i][4] == BLOCK) && (board[i][5] == BLOCK) && (board[i][6] == BLOCK)
			&& (board[i][7] == BLOCK) && (board[i][8] == BLOCK) && (board[i][9] == BLOCK) && (board[i][10] == BLOCK))
		{
			for (int d = 1; d < BOARD_WIDTH - 1; d++)
			{
				board[i][d] = 0;
			}
			score += 10; Reboard(i); drawboard();
		}
	}
}
void TetrisGame::Reboard(int i)
{
	for (int a = i; a > 1; a--) {
		for (int b = BOARD_WIDTH - 1; b > 0; b--) {
			board[a][b] = board[a - 1][b];
		}
	}
}
void TetrisGame::testflag()
{
	for (int d = 0; d < BOARD_WIDTH; d++)
	{
		if (board[1][d] == BLOCK)
			flag = false;
	}
}
void TetrisGame::sleep(int a)
{
	Sleep(a);
}
TetrisGame :: ~TetrisGame()
{
	
	delete[] board;
	delete[] nextBoard;
	delete[] scoreBoard;
}
void TetrisGame::getblock(int(*blocks)[BROTATION][BSIZE][BSIZE])
{
	for (int a = 0; a < BSHAPE; a++) {
		for (int b = 0; b < BROTATION; b++) {
			for (int c = 0; c < BSIZE; c++) {
				for (int d = 0; d<BSIZE; d++)
					block[a][b][c][d] = blocks[a][b][c][d];
			}
		}
	}
	
}
void TetrisGame::gotoXY(int x, int y)
{
	COORD Pos = { (short)x, (short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
