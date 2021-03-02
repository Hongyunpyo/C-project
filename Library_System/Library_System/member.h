#ifndef __MEMBER_H__
#define __MENBER_H__

#define MAX 100
#define NUM 255

typedef struct member_impormation {
	char id[MAX];
	char pw[MAX];
	char name[MAX];
	char s_snum[MAX];
	char p_num[MAX];
	char addr[MAX];
	char rank[MAX];
}Member;

typedef Member S_Member;


typedef struct member_list {
	S_Member member_list[NUM];
	int list_num;
}Member_List;

typedef Member_List MList;

void MListInit(MList * plist);//ȸ������Ʈ �ʱ�ȭ v
void MemberInit(S_Member * pmb);//ȸ�� �ʱ�ȭ v
void member_insert(MList *plist, S_Member *pmb);//ȸ�� �߰� v
S_Member member_delete(MList *plist, S_Member *pmb);//ȸ�� ���� ���̵�� ȸ���� �˻� �� ���� v
S_Member member_update(MList *plist, S_Member *pmb);//ȸ�� ���� ���̵�� ȸ���� �˻� �� ���� v
MList member_select(MList *plist, S_Member *pmb);//ȸ�� �˻� v
int M_LCount(MList * plist); //��ϵ� ȸ�� �� ���

void Qsort_member(MList *plist, int left, int right, char select[]); //ȸ�� ���� v
void Quest_member(MList *plist, S_Member *pmb, char select[]); //ȸ�� Ž�� v

int Load_member(MList *plist); //ȸ�� ��� ��������
int Save_member(MList *plist); //ȸ�� ��� ����

//�ڷᱸ��
int BSearch_M_id(MList *plist, S_Member *pmb);
int BSearch_M_snum(MList *plist, S_Member *pmb);
void swap_m(MList *plist, int ch1, int ch2);
int Partition_m(MList *plist, int left, int right, char select[]);
#endif