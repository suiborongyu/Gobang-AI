#pragma once
#include "head.h"

class AI_Class
{
public:
	explicit AI_Class(int Fol, BN *board);
	~AI_Class();

	//�������
	int score(BN *temp_board);

	//����������ӵ��Ӧ�ķ���
	int get_score(BN *original_board, int h, int l, int Player);

	//����
	struct coor
	{
		int x;
		int y;
	};
	typedef struct coor coor;

	//�������������ṩ�������ӵĵ㣩
	vector<coor> generator(BN *temp_board);

	//����Сֵ����
	int maxmin(BN *temp_board, int depth, int player, int alpha, int beta);

	//�ж�
	void decision(BN *board, int &X, int &Y, int depth = 1);

private:
	int first_or_latter;
	BN copy_board[HandL][HandL];
	int valueofposition[HandL][HandL];

	const int zOO = 234322;
	const int fOO = -zOO;

	//Define score
	int ChengWu = 100000;  //����
	int HuoSi = 10000;  //����
	int HuoSan = 1000;  //����
	int HuoEr = 100;  //���
	int HuoYi = 10;  //��һ

	int SiSi = 1000;  //����
	int SiSan = 100;  //����
	int SiEr = 10;  //����

	void update_cb(BN *board);

	//������㲻ͬ��ʽ�ķ���
	void MatchBoard(int *arr, int Player, int &score);

	//Attention�������޶�˼���ķ�Χ
	//For Attention
	struct Attention
	{
		int h_min;
		int l_min;
		int h_max;
		int l_max;
	};
	typedef struct Attention Attention;

	Attention attention(BN *temp_board);
};
