

#include "../DxLib/DxLib.h"

#include "MIKU.h"
#include "map.h"//��ʃT�C�Y���擾�̂���

#include "Game_Info.h"
#include "key.h"

#include <math.h>


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
	
	W=28;//�����蔻��̕�
	H=28;//�����蔻��̍����i������j

	mp_rx=640-real_W/2;//�}�b�v���ł̎��ۂ�x���W
	mp_ry=480-real_H/2;//�}�b�v���ł̎��ۂ̂����W


	dsp_rx=DSP_W/2-real_W/2;//��ʓ��̎��ۂ̂����W�i�����琔���āj
	dsp_ry=DSP_H/2-real_H/2;//��ʓ��̎��ۂ�y���W�i�ォ�琔���āj
	
	

	mp_x=mp_rx+(real_W-W)/2;//�}�b�v���ł̃A�^���̂����W
	mp_y=mp_ry+(real_H-H);//�}�b�v���ł̃A�^���̂����W

	dsp_x=dsp_rx+(real_W-W)/2;//��ʓ��̂�����̂����W�i�����琔���āj
	dsp_y=dsp_ry+(real_H-H);//��ʓ��̂�����̂����W�i�ォ�琔���āj

	muki=0;//������

}

//void MIKU::real_adj(){
//
//
//	mp_x=mp_rx+(real_W-W)/2;//�}�b�v���ł̃A�^���̂����W
//	mp_y=mp_ry+(real_H-H);//�}�b�v���ł̃A�^���̂����W
//
//	dsp_x=dsp_rx+(real_W-W)/2;//��ʓ��̂�����̂����W�i�����琔���āj
//	dsp_y=dsp_ry+(real_H-H);//��ʓ��̂�����̂����W�i�ォ�琔���āj
//
//
//
//}

void MIKU::Draw(){

	
		
	//if (key.c==-1){
	///*	DrawGraph(miku.dsp_rx,miku.dsp_ry, miku.GH_Run[0][1], 1);*/
	//		DrawGraph(300,200, miku.GH[0], 1);
	//	}

	if (key.c==-1)DrawGraph(miku.dsp_rx,miku.dsp_ry , miku.GH[miku.muki], 1);
	else DrawGraph(miku.dsp_rx, miku.dsp_ry, miku.GH_Run[miku.muki][miku.anime], 1);

	DrawFormatString(320, 16,(255,255,255) , "�~�N�̃}�b�v���W(%d,%d)", miku.mp_rx, miku.mp_ry);

	


}


#define M_PI 3.14159  //�~����

int nokori[2];//�c�苗���@���A��



void p_move(void){


	//miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
	//miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
	//
	//miku.dsp_x=miku.dsp_rx+(miku.real_W-miku.W)/2;//��ʓ��̂�����̂����W�i�����琔���āj
	//miku.dsp_y=miku.dsp_ry+(miku.real_H-miku.H);//��ʓ��̂�����̂����W�i�ォ�琔���āj

	dia_chk();//�΂߃`�F�b�N


	if (key.c != -1){
		//��
		if (key.c == 2){
			miku.muki = 2;
			mv_chk(2,nokori);


		//	miku.rx -= nokori[0];���@�������ꍇ
			miku.mp_rx -= nokori[0];//�}�b�v�̂ق�������

			miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
		
			
		}
		else if (key.c == 6){//�E
			miku.muki = 6;
			mv_chk(6, nokori);
			//miku.rx += nokori[0];
				miku.mp_rx += nokori[0];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
			
			
			}
		//��
		else if (key.c == 4){
			miku.muki = 4;
			mv_chk(4, nokori);
			//miku.ry -= nokori[1];
			miku.mp_ry -= nokori[1];
			//miku.y -= nokori[1];

			miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W

			
		}
		else if (key.c == 0){//��
			miku.muki = 0;
			mv_chk(0, nokori);
			//miku.ry += nokori[1];
			miku.mp_ry += nokori[1];
			//miku.y += nokori[1];

			miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			
		}

		//�ȂȂ�

		else if (key.c == 3){//����
			miku.muki = 3;
			mv_chk(3, nokori);

			/*miku.rx -= nokori[0];
			miku.ry -= nokori[1];*/

			miku.mp_rx -= nokori[0];
			miku.mp_ry -= nokori[1];

			miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
				miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			//miku.x -= nokori[0];
			//miku.y -= nokori[1];
		}


		else if (key.c == 5){
			miku.muki = 5;
			mv_chk(5, nokori);

			//miku.rx += nokori[0];
			//miku.ry -= nokori[1];
			miku.mp_rx += nokori[0];
			miku.mp_ry -= nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
					miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
		}
		//����
		else if (key.c == 1){

			miku.muki = 1;
			mv_chk(1, nokori);

		/*	miku.rx -= nokori[0];
			miku.ry += nokori[1];*/
			miku.mp_rx -= nokori[0];
			miku.mp_ry += nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
					miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W
			
		}
		//�E��
		else if (key.c == 7){
			miku.muki = 7;
			mv_chk(7, nokori);

		/*	miku.rx += nokori[0];
			miku.ry += nokori[1];*/

			miku.mp_rx += nokori[0];
			miku.mp_ry += nokori[1];

				miku.mp_x=miku.mp_rx+(miku.real_W-miku.W)/2;//�}�b�v���ł̃A�^���̂����W
				miku.mp_y=miku.mp_ry+(miku.real_H-miku.H);//�}�b�v���ł̃A�^���̂����W

		}

	}

	//�ړ����[�h�ؑ�
	if (key.z == 1){
		miku.spd = 10;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;
	}
	else{
		miku.spd = 4;
		miku.n_spd = miku.spd*cos(45 / 180.0*M_PI) + 0.5;//���@�X�s�[�h�ȂȂ߂̏�����
	}



}





//�}�b�v�ʍs�`�F�b�N
void mv_chk(int k, int *x){ //k�L�����̌��� x�c��̋���

	int i;
	int c=0;
	
	switch (k){
	case 0:
		for (i = 0; i < map.bn; i++){
			if (miku.mp_y + miku.H <= bhit[i].y  && miku.mp_y + miku.H + miku.spd > bhit[i].y   && miku.mp_x+miku.W  > bhit[i].x && miku.mp_x < bhit[i].x + map.Chip){

				x[1] = bhit[i].y - (miku.mp_y + miku.H);
				return;

			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;
	case 1:
		for (i = map.bn - 1; i >= 0; i--){
			//DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][1] == 1){//�E��ɂ���
				if (miku.mp_x - miku.n_spd < bhit[i].x + map.Chip &&  miku.mp_y +miku.H+ miku.n_spd > bhit[i].y ){//�ړ���Ƀu���b�N�𒴂�����
					//DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

					mv_chk(0, x);//��
					mv_chk(2, x); return;//��

				}
			}


			/*	}*/
		}x[0] = miku.n_spd;//��
			x[1] = miku.n_spd;//��
		return;


	case 2:
		for (i = 0; i < map.bn; i++){
			if (miku.mp_x >= bhit[i].x + map.Chip && miku.mp_x - miku.spd < bhit[i].x + map.Chip && miku.mp_y + miku.H > bhit[i].y && miku.mp_y < bhit[i].y + map.Chip){

				x[0] = miku.mp_x - (bhit[i].x + map.Chip);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;

	case 3:
		for (i = map.bn-1; i >=0; i--){
			DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][3] == 1){
				if (miku.mp_x - miku.n_spd < bhit[i].x + map.Chip &&  miku.mp_y - miku.n_spd < bhit[i].y + map.Chip){
					DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

					mv_chk(4, x);
					mv_chk(2, x); return;
					
				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;
	
			break;

	case 4:

		for (i = 0; i<map.bn; i++){
			if (miku.mp_y >= bhit[i].y+map.Chip  && miku.mp_y - miku.spd < bhit[i].y+map.Chip   && miku.mp_x + miku.W > bhit[i].x && miku.mp_x < bhit[i].x + map.Chip){
				x[1] = miku.mp_y - (bhit[i].y+map.Chip );
				return;
			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;

	case 5:
		for (i = map.bn - 1; i >= 0; i--){
			DrawFormatString(480, 16, (255, 255, 255), "%d", miku.n_line[i]);

			if (miku.n_line[i][2] == 1){//�����ɂ���
				if (miku.mp_x +miku.W+ miku.n_spd > bhit[i].x  &&  miku.mp_y - miku.n_spd < bhit[i].y + map.Chip){
					DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

					mv_chk(4, x);
					mv_chk(6, x); return;

				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;

		break;


	case 6:

		for (i = 0; i<map.bn; i++){
			if (miku.mp_x+miku.W <= bhit[i].x  && miku.mp_x +miku.W+ miku.spd > bhit[i].x  && miku.mp_y + miku.H > bhit[i].y && miku.mp_y < bhit[i].y + map.Chip){

				x[0] = bhit[i].x-(miku.mp_x+miku.W);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;
	case 7:
		for (i = map.bn - 1; i >= 0; i--){			
			if (miku.n_line[i][0] == 1){//����ɂ���
				if (miku.mp_x + miku.W + miku.n_spd > bhit[i].x  &&  miku.mp_y +miku.H+ miku.n_spd > bhit[i].y ){
					//DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

					mv_chk(0, x);
					mv_chk(6, x); return;

				}
			}
			

			/*	}*/
		}x[0] = miku.n_spd;
			x[1] = miku.n_spd;
		return;


	}//switch�I���
}

//�΂߃`�F�b�N




MHit hb[1200];//
double ang[2];
double kakudo = -45 / 180.0 * M_PI;
double deg135 = 135 / 180.0 * M_PI;

int mx0,mx1,x2, x3, x4,           my0,my1,y2, y3, y4,y5;



void dia_chk(void){//�Ԃ�l�̐����͎��@�̌����Ă������

	int i;
	mx0 = miku.mp_x, my0 = -1 * (miku.mp_y);//�~�N����
	mx1 = miku.mp_x + miku.W; my1 = -1 * (miku.mp_y + miku.H);//�~�N����
	for (i = 0; i < map.bn; i++){
		x2 = bhit[i].x , y2 = (-1) * (bhit[i].y);
		x3 = bhit[i].x + map.Chip, y3 = (-1) * (bhit[i].y + map.Chip );
		x4 = bhit[i].x + map.Chip * 2; y4 = (-1) * (bhit[i].y + map.Chip*2);
		y5 = -1*(bhit[i].y - map.Chip);

		
		//DrawFormatString(480, 16, 0xffffff, "kakudo%f", kakudo);


		//�E��
		if (   my0+mx1>x2+y3 &&   mx1+ my0<x4+y5   &&  (miku.mp_y >= bhit[i].y+map.Chip || miku.mp_x >= bhit[i].x+map.Chip)){
			miku.n_line[i][3] = 1;//�E���ɂ���
			//if (miku.n_line[i][3] == 1)DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̉E�����C��", i);
		}
		else miku.n_line[i][3] = 0;


		//����
		if (my0 + mx1>x2 + y3 &&   mx1 + my0<x4 + y5 && ( miku.mp_y+miku.H <= bhit[i].y  || miku.mp_x+miku.W <= bhit[i].x )  ){
			miku.n_line[i][0] = 1;//����ɂ���
		DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̍��ド�C��", i);
		}
		else miku.n_line[i][0] = 0;


		//����
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_x + miku.W <= bhit[i].x || miku.mp_y >= bhit[i].y + map.Chip)){
			miku.n_line[i][2] = 1;//����
		}
		else 	miku.n_line[i][2] = 0;//

		//�E��
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.mp_x >= bhit[i].x+map.Chip || miku.mp_y+miku.H <= bhit[i].y )){
			miku.n_line[i][1] = 1;//�E��

			
		}
		else 	miku.n_line[i][1] = 0;//


	}
	DrawFormatString(480, 16 * 6, 0xffffff, "miku.n_line[i]:%d", miku.n_line[i]);

	//DrawFormatString(480, 16 * 7, 0xffffff, "x4+y4:%d", x4 + y4);
	//DrawFormatString(480, 16 * 8, 0xffffff, "x2+y2:%d", x2 + );
	//DrawFormatString(480, 16 * 9, 0xffffff, "x3+y3:%d", x3 + y3);


	//	else miku.n_line[0] = -1;



}


void p_anime(){


	if (key.c != -1){
		miku.anime_c--;//�A�j���[�V�����J�E���^�}�C�i�X
		if (miku.anime_c <= 0){

			if (key.z)miku.anime_c = 2;
			else miku.anime_c = 10;
			if (miku.anime >= 5){
				miku.anime = 0;
			}
			else{ miku.anime++; }
		}
	}
	else{
		miku.anime = 0;//�A�j�����Z�b�g


	}
}
