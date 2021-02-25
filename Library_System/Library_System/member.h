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

void MListInit(MList * plist);//회원리스트 초기화 v
void MemberInit(S_Member * pmb);//회원 초기화 v
void member_insert(MList *plist, S_Member *pmb);//회원 추가 v
S_Member member_delete(MList *plist, S_Member *pmb);//회원 삭제 아이디로 회원을 검색 후 삭제 v
S_Member member_update(MList *plist, S_Member *pmb);//회원 수정 아이디로 회원을 검색 후 수정 v
MList member_select(MList *plist, S_Member *pmb);//회원 검색 v
int M_LCount(MList * plist); //등록된 회원 수 출력

void Qsort_member(MList *plist, int left, int right, char select[]); //회원 정렬 v
void Quest_member(MList *plist, S_Member *pmb, char select[]); //회원 탐색 v

int Load_member(MList *plist); //회원 목록 가져오기
int Save_member(MList *plist); //회원 목록 저장


#endif