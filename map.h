
class MAP{
private:
	int* ChipH ;//�O���t�B�b�N�`�b�v�n���h��
	
public:

	int W;//��
	int H;//����

	int BW;//���̃u���b�N��
	int BH;//�c�̃u���b�N��

	int Chip;//�}�b�v�`�b�v�̃T�C�Y

	int** bg_array;

	char *ChipName;//�}�b�v�`�b�v�̖��O

	int bn;//������u���b�N�̐�

	


	int GH;

	void CreateMap();


};

class MHit{
public:

	 //int mchip[15][20];//�}�b�v�`�b�v
	 //int mhit[15][20];//�ʍs�ݒ�

	int x,y;
	int haba;

	double x_sa[2];//x���W�̍�
	double y_sa[2];


	
};
extern MAP map;

extern void LoadMap1();//�x�[�X�}�b�v
extern void DrawMap();

extern MHit bhit[1200];


extern int mhit2[30][40];