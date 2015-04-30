#include <Windows.h>
#include "../DxLib/DxLib.h"

#include "GameMain.h"
#include "key.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	ChangeWindowMode(TRUE);                     // �E�C���h�E���[�h�ɕύX(�������A�Q�T�U�F)

	if (DxLib_Init() == -1) {                    // �c�w���C�u��������������
		return -1;                              // �G���[���N�����璼���ɏI��
	}


	// �Q�[���V�X�e��������
	Init();

	SetDrawScreen(DX_SCREEN_BACK);              // �`���𗠉�ʂ�


	




	//------ �Q�[�����[�v ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Esc�L�[���������܂Ń��[�v
		ClsDrawScreen();                        // ����ʃN���A
		

		// �Q�[���R���g���[�����C��		
		GameMain();//���C���Q�[��
		


		ScreenFlip();                           // ����ʂ�\��ʂ�
		if (ProcessMessage() == -1) {            // ���b�Z�[�W����
			break;                              // �G���[���N�����烋�[�v���甲����
		}
	}
	DxLib_End();// �c�w���C�u�����g�p�̏I������
	return 0;// �A�v���P�[�V�����̏I��

}