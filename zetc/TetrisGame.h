#ifndef TETRISGAME_H
#define TETRISGAME_H

#define BSHAPE 7
#define BSIZE 4 //�� ���� & ����
#define BROTATION 4 // �� ȸ��

struct Block {
	int X; // ���� �ȿ� ���� X��ǥ  
	int Y; // ���� �ȿ� ���� Y��ǥ
	int R; // ���� ȸ��
	int S; // ���� ���
	int N; //���� ����� ���
};
class TetrisGame {
public:
	TetrisGame(); //default ������ overloading

	void initGame(); // ��Ʈ���� �ʱⰪ�����Լ�
	bool getFlag() { return flag; } // �ݺ��� �����Լ�
	void getGameAction();  // Ű�����Է¿� ���� action ������Ʈ
	void updateGame();    // ������Ʈ
	void sleep(int a);   // �����Լ�
	void randBlock(int(*block)[BROTATION][BSIZE][BSIZE]);    // ��Ϸ����Լ�
	void blocktransfer(); //�����ġ�����Լ�
	void nextstate(); // ������Ϲޱ� �Լ�
	void saveboard(); // board ���� �Լ�
	void drawboard(); // board ����Լ�
	void spacebar(); // spacebar�� �Է����� �� ��Ÿ���� �Լ�
	void testflag(); // ��Ʈ���� ����� ������ ���̸� flag����
	void scoreup(); // ��Ʈ���� ������ �׿����� �پ��ְ� ���� ī��Ʈ�ϴ� �Լ�
	void Reboard(int i); // ���������� ��Ʈ������ �ٽñ׸���
	void getblock(int(*blocks)[BROTATION][BSIZE][BSIZE]); // ���������� �����Ǿ��ִ� �迭�� ���ڷξ��
	void gotoXY(int x, int y);
	bool crush(); // ��Ʈ���� �浹 �Լ�
	void	drawGame(int(*block)[BROTATION][BSIZE][BSIZE]);
	//�������� ����Ǿ��ִ� ��Ϲ迭�� ���ڷ� ����
	~TetrisGame();//default �Ҹ��� overloading
private:
	Block bk;
	int **board; //���� ���带 ���� 2���� �����迭
	int **nextBoard; // ���� �� ǥ�� ���带 ���� 2���� �����迭
	int **scoreBoard;// ���� ��� ���带 ���� 2���� �����迭 

	int  action;//�� � ���
	int  score; // ��������
	bool flag; //���� ���� �÷���
	int keyValue;
	int rotation; // ��� ȸ�� ����
	int X; // ���� bk.x��
	int Y; // ���� bk.y��
	int R; // ���� bk.R��
	int block[BSHAPE][BROTATION][BSIZE][BSIZE];
};
#endif