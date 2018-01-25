#ifndef TETRISGAME_H
#define TETRISGAME_H

#define BSHAPE 7
#define BSIZE 4 //블럭 높이 & 넓이
#define BROTATION 4 // 블럭 회전

struct Block {
	int X; // 보드 안에 블럭의 X좌표  
	int Y; // 보드 안에 블럭의 Y좌표
	int R; // 블럭의 회전
	int S; // 블럭의 모양
	int N; //다음 블록의 모양
};
class TetrisGame {
public:
	TetrisGame(); //default 생성자 overloading

	void initGame(); // 테트리스 초기값설정함수
	bool getFlag() { return flag; } // 반복문 설정함수
	void getGameAction();  // 키보드입력에 대한 action 업데이트
	void updateGame();    // 업데이트
	void sleep(int a);   // 슬립함수
	void randBlock(int(*block)[BROTATION][BSIZE][BSIZE]);    // 블록랜덤함수
	void blocktransfer(); //블록위치변경함수
	void nextstate(); // 다음블록받기 함수
	void saveboard(); // board 저장 함수
	void drawboard(); // board 출력함수
	void spacebar(); // spacebar를 입력했을 때 나타나는 함수
	void testflag(); // 테트리스 블록이 위까지 쌓이면 flag종료
	void scoreup(); // 테트리스 한줄이 쌓였을때 줄없애고 점수 카운트하는 함수
	void Reboard(int i); // 점수오를때 테트리스판 다시그리기
	void getblock(int(*blocks)[BROTATION][BSIZE][BSIZE]); // 전역변수로 설정되어있는 배열을 인자로얻기
	void gotoXY(int x, int y);
	bool crush(); // 테트리스 충돌 함수
	void	drawGame(int(*block)[BROTATION][BSIZE][BSIZE]);
	//전역으로 선언되어있는 블록배열을 인자로 전달
	~TetrisGame();//default 소멸자 overloading
private:
	Block bk;
	int **board; //게임 보드를 위한 2차원 동적배열
	int **nextBoard; // 다음 블럭 표시 보드를 위한 2차원 동적배열
	int **scoreBoard;// 점수 출력 보드를 위한 2차원 동적배열 

	int  action;//블럭 운영 방식
	int  score; // 게임점수
	bool flag; //게임 종료 플래그
	int keyValue;
	int rotation; // 블록 회전 변수
	int X; // 이전 bk.x값
	int Y; // 이전 bk.y값
	int R; // 이전 bk.R값
	int block[BSHAPE][BROTATION][BSIZE][BSIZE];
};
#endif