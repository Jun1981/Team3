

#include "../DxLib/DxLib.h"

#include "MIKU.h"
#include "map.h"//��ʃT�C�Y���擾�̂���

#include "Game_Info.h"
#include "key.h"


MIKU miku;//���@�N���X�錾



//�~�N�摜�ǂݍ���
void MIKU::LoadImg(){

	LoadDivGraph("Img/miku/mikusan.png", 8, 8, 1, 48, 64, GH, 1);//���@�摜

	LoadDivGraph("Img/miku/loop1000/loop0.png", 6, 6, 1, 48, 64, GH_Run[0], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1001/loop1.png", 6, 6, 1, 48, 64, GH_Run[1], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1002/loop2.png", 6, 6, 1, 48, 64, GH_Run[2], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1003/loop3.png", 6, 6, 1, 48, 64, GH_Run[3], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1004/loop4.png", 6, 6, 1, 48, 64, GH_Run[4], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1005/loop5.png", 6, 6, 1, 48, 64, GH_Run[5], 1);//���@�摜

	LoadDivGraph("Img/miku/loop1006/loop6.png", 6, 6, 1, 48, 64, GH_Run[6], 1);//���@�摜
	LoadDivGraph("Img/miku/loop1007/loop7.png", 6, 6, 1, 48, 64, GH_Run[7], 1);//���@�摜
	

}

void MIKU::Init(){

	real_W=48;//���ۂ̕�


	real_H=64;//���ۂ̍���


	mp_rx=0;//�}�b�v���ł̎��ۂ�x���W
	mp_ry=0;//�}�b�v���ł̎��ۂ̂����W


	dsp_rx=DSP_W/2-real_W/2;//��ʓ��̎��ۂ̂����W�i�����琔���āj
	dsp_ry=DSP_H/2-real_H/2;//��ʓ��̎��ۂ�y���W�i�ォ�琔���āj
	
	W=24;//�����ڂ̕�
	H=24;//�����ڂ̍���

	mp_x=mp_rx-(real_W-W)/2;//�}�b�v���ł̌����ڂ̂����W
	mp_y=mp_ry-(real_H-H)/2;//�}�b�v���ł̌����ڂ̂����W

	dsp_x=DSP_W/2-W/2;//��ʓ��̌����ڂ̂����W�i�����琔���āj
	dsp_y=DSP_H/2-H/2;//��ʓ��̌����ڂ̂����W�i�ォ�琔���āj

}

void MIKU::Draw(){


		
	if (key.c==-1){
	/*	DrawGraph(miku.dsp_rx,miku.dsp_ry, miku.GH_Run[0][1], 1);*/
			DrawGraph(300,200, miku.GH[0], 1);
		}

	DrawFormatString(320, 16,(255,255,255) , "���W(%d,%d)", miku.dsp_rx, miku.dsp_ry);

	


}