#ifndef __RENTAL_H__
#define __RENTAL_H__

#define MAX 100
#define NUM 255

typedef struct book_rental_impormation {
	char user_id[MAX];
	char book_num[MAX];
	char book_name[MAX];
	char book_rental_day[MAX];
	char book_return_day[MAX];

}Book_Lental;

typedef Book_Lental B_Rental;

typedef struct rentar_list {
	B_Rental rental_list[NUM];
	int list_num;
}Rental_List;

typedef Rental_List RList;

void RListInit(RList * plist);//��Ż����Ʈ �ʱ�ȭ v
void RentarInit(B_Rental * pr);//�뿩�������� �ʱ�ȭ v
void Rental_insert(RList *plist, B_Rental *pmb);//�뿩���� �߰� v
B_Rental Rental_delete(RList *plist, B_Rental *pr);//�뿩���� ���� v
B_Rental Rental_update(RList *plist, B_Rental *pr);//�뿩���� ���� v
RList Rental_select(RList *plist, B_Rental *pmb);//�뿩���� �˻� v
int R_LCount(RList * plist); //�뿩���� ���

void Qsort_rental(RList *plist, int left, int right, char select[]); //�뿩���� ���� v
void Quest_rental(RList *plist, B_Rental *pr, char select[]); //�뿩���� Ž�� v

int Load_rental(RList *plist); //�뿩 ��� ��������
int Save_rental(RList *plist); //�뿩 ��� ����

//�ڷᱸ��
int BSearch_R(RList *plist, B_Rental *pr);//����Ž��
int Partition_R(RList *plist, int left, int right, char select[]);//������
void swap_R(RList *plist, int ch1, int ch2);//������

#endif

