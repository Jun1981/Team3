#pragma once




//�N���X�錾
class MIKU{

private:
	
	//�O���t�B�b�N�n���h��
	int GH[8];//�W����
	int GH_Run[8][6];//�W�����̌������[�v�摜 �Q�ڂ̔z��̓A�j���[�V�����ԍ�


public:

	//MIKU();//�f�t�H���g�R���X�g���N�^
	//~MIKU();//�f�X�g���N�^

	/*���W�͍��ォ��

	*/

	//���ۂ�
	int real_W;//���ۂ̕�
	int real_H;//���ۂ̍���

	int mp_rx;//�}�b�v���ł̎��ۂ�x���W
	int mp_ry;//�}�b�v���ł̎��ۂ̂����W

	int dsp_rx;//��ʓ��̎��ۂ̂����W�i�����琔���āj
	int dsp_ry;//��ʓ��̎��ۂ�y���W�i�ォ�琔���āj


	//������
	int mp_x;//�}�b�v���ł̌����ڂ̂����W
	int mp_y;//�}�b�v���ł̌����ڂ̂����W	
	
	int dsp_x;//��ʓ��̌����ڂ̂����W�i�����琔���āj
	int dsp_y;//��ʓ��̌����ڂ̂����W�i�ォ�琔���āj
	
	int W;//�����ڂ̕�	
	int H;//�����ڂ̍���

	//�֐�
	void Init();//�~�N�ϐ�������
	void LoadImg();//���@�摜�ǂݍ���
	void Draw();//�~�N�`��֐�
	

};

///�~�N
void miku_init();//
extern MIKU miku;//�N���X�錾

//
////�֐��錾
//void P_LoadImg();//���@�摜�ǂݍ���