#include "GameMain.h"
#include <time.h>
#include "../DxLib/DxLib.h"
#include "MIKU.h"
#include "key.h"

int G_MODE=0;


void GameMain(){
	switch(G_MODE){		

		//�I�[�v�j���O
	case 0:
		break;
		////////////////////////////////////




		//�{�Q�[��/////////////////////////////////////////
	case 1:

		key_chk();//�L�[�`�F�b�N
		key_henkan();//�L�[�ϊ�
		// WaitKey();

		Calc();//�v�Z�S��
		Draw();//�`��S��			


		break;
		/////////////////////////////////////////////
		//�Q�[���I�[�o�[
	case 2:
		break;
		//////////////////////////////////////

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}


void Init(){

	G_MODE=1;//�Q�[�����[�h


	miku.Init();//�~�N������

	LoadImg();//�摜�Ȃǂ̓ǂݍ���

}

//���@�摜�f�[�^���̓ǂݍ���
void LoadImg(){


	miku.LoadImg();//�~�N�摜�@MIKU.cpp��


}

//�v�Z���C��
void Calc(){

}


//�`��
void Draw(){
	miku.Draw();


}

//�I������
void Finalize(){

}