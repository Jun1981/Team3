#include "include.h"
#include "p_move.h"
#include "jiki_load.h"
#include "jiki_class.h"
#include "map.h"

#define M_PI 3.14159  //�~����

int nokori[2];//�c�苗���@���A��



void p_move(void){

	dia_chk();//�΂߃`�F�b�N


	if (key.c != -1){
		//��
		if (key.c == 2){
			miku.muki = 2;
			mv_chk(2,nokori);
			miku.rx -= nokori[0];
		/*	miku.x -= nokori[0];*/
			
		}
		else if (key.c == 6){//�E
			miku.muki = 6;
			mv_chk(6, nokori);
			miku.rx += nokori[0];
			//miku.x += nokori[0];
			
			}
		//��
		else if (key.c == 4){
			miku.muki = 4;
			mv_chk(4, nokori);
			miku.ry -= nokori[1];
			//miku.y -= nokori[1];

			
		}
		else if (key.c == 0){//��
			miku.muki = 0;
			mv_chk(0, nokori);
			miku.ry += nokori[1];
			//miku.y += nokori[1];
			
		}

		//�ȂȂ�

		else if (key.c == 3){//����
			miku.muki = 3;
			mv_chk(3, nokori);

			miku.rx -= nokori[0];
			miku.ry -= nokori[1];

		

			//miku.x -= nokori[0];
			//miku.y -= nokori[1];
		}


		else if (key.c == 5){
			miku.muki = 5;
			mv_chk(5, nokori);

			miku.rx += nokori[0];
			miku.ry -= nokori[1];
		}
		//����
		else if (key.c == 1){

			miku.muki = 1;
			mv_chk(1, nokori);

			miku.rx -= nokori[0];
			miku.ry += nokori[1];
			
		}
		//�E��
		else if (key.c == 7){
			miku.muki = 7;
			mv_chk(7, nokori);

			miku.rx += nokori[0];
			miku.ry += nokori[1];
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
			if (miku.ry + miku.r_tate <= bhit[i].y  && miku.ry + miku.r_tate + miku.spd > bhit[i].y   && miku.rx + miku.r_haba > bhit[i].x && miku.rx < bhit[i].x + ChipXY){

				x[1] = bhit[i].y - (miku.ry + miku.r_tate);
				return;

			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;
	case 1:
		for (i = map.bn - 1; i >= 0; i--){
			//DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][1] == 1){//�E��ɂ���
				if (miku.rx - miku.n_spd < bhit[i].x + ChipXY &&  miku.ry +miku.r_tate+ miku.n_spd > bhit[i].y ){//�ړ���Ƀu���b�N�𒴂�����
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
			if (miku.rx >= bhit[i].x + ChipXY && miku.rx - miku.spd < bhit[i].x + ChipXY && miku.ry + miku.r_tate > bhit[i].y && miku.ry < bhit[i].y + ChipXY){

				x[0] = miku.rx - (bhit[i].x + ChipXY);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;

	case 3:
		for (i = map.bn-1; i >=0; i--){
			DrawFormatString(480, 16, 0xffffff, "%d", miku.n_line[i]);

			if (miku.n_line[i][3] == 1){
				if (miku.rx - miku.n_spd < bhit[i].x + ChipXY &&  miku.ry - miku.n_spd < bhit[i].y + ChipXY){
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
			if (miku.ry >= bhit[i].y+ChipXY  && miku.ry - miku.spd < bhit[i].y+ChipXY   && miku.rx + miku.r_haba > bhit[i].x && miku.rx < bhit[i].x + ChipXY){
				x[1] = miku.ry - (bhit[i].y+ChipXY );
				return;
			}
		}
		x[1] = miku.spd; x[0] = 0;
		return;

	case 5:
		for (i = map.bn - 1; i >= 0; i--){
			DrawFormatString(480, 16, (255, 255, 255), "%d", miku.n_line[i]);

			if (miku.n_line[i][2] == 1){//�����ɂ���
				if (miku.rx +miku.r_haba+ miku.n_spd > bhit[i].x  &&  miku.ry - miku.n_spd < bhit[i].y + ChipXY){
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
			if (miku.rx+miku.r_haba <= bhit[i].x  && miku.rx +miku.r_haba+ miku.spd > bhit[i].x  && miku.ry + miku.r_tate > bhit[i].y && miku.ry < bhit[i].y + ChipXY){

				x[0] = bhit[i].x-(miku.rx+miku.r_haba);
				return;

			}
		}
		x[0] = miku.spd; x[1] = 0;
		return;
	case 7:
		for (i = map.bn - 1; i >= 0; i--){			
			if (miku.n_line[i][0] == 1){//����ɂ���
				if (miku.rx + miku.r_haba + miku.n_spd > bhit[i].x  &&  miku.ry +miku.r_tate+ miku.n_spd > bhit[i].y ){
					DrawFormatString(480, 16, (255, 255, 255), "�ǔ���");

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




MHit hb[300];//
double ang[2];
double kakudo = -45 / 180.0 * M_PI;
double deg135 = 135 / 180.0 * M_PI;

int mx0,mx1,x2, x3, x4,           my0,my1,y2, y3, y4,y5;



void dia_chk(void){//�Ԃ�l�̐����͎��@�̌����Ă������

	int i;
	mx0 = miku.rx, my0 = -1 * (miku.ry);//�~�N����
	mx1 = miku.rx + miku.r_haba; my1 = -1 * (miku.ry + miku.r_tate);//�~�N����
	for (i = 0; i < map.bn; i++){
		x2 = bhit[i].x , y2 = (-1) * (bhit[i].y);
		x3 = bhit[i].x + ChipXY, y3 = (-1) * (bhit[i].y + ChipXY );
		x4 = bhit[i].x + ChipXY * 2; y4 = (-1) * (bhit[i].y + ChipXY*2);
		y5 = -1*(bhit[i].y - ChipXY);

		
		DrawFormatString(480, 16, 0xffffff, "kakudo%f", kakudo);


		//�E��
		if (   my0+mx1>x2+y3 &&   mx1+ my0<x4+y5   &&  (miku.ry >= bhit[i].y+ChipXY || miku.rx >= bhit[i].x+ChipXY)){
			miku.n_line[i][3] = 1;//�E���ɂ���
			//if (miku.n_line[i][3] == 1)DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̉E�����C��", i);
		}
		else miku.n_line[i][3] = 0;


		//����
		if (my0 + mx1>x2 + y3 &&   mx1 + my0<x4 + y5 && ( miku.ry+miku.r_tate <= bhit[i].y  || miku.rx+miku.r_haba <= bhit[i].x )  ){
			miku.n_line[i][0] = 1;//����ɂ���
		DrawFormatString(480, 16 * 5 + i * 16, 0xffffff, "%d�̍��ド�C��", i);
		}
		else miku.n_line[i][0] = 0;


		//����
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.rx + miku.r_haba <= bhit[i].x || miku.ry >= bhit[i].y + ChipXY)){
			miku.n_line[i][2] = 1;//����
		}
		else 	miku.n_line[i][2] = 0;//

		//�E��
		if (my1 - mx1<y2 - x2 && my1 - mx1 >y4 - x4 && (miku.rx >= bhit[i].x+ChipXY || miku.ry+miku.r_tate <= bhit[i].y )){
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

