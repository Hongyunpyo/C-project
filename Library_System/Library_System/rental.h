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

void RListInit(RList * plist);//랜탈리스트 초기화 v
void RentarInit(B_Rental * pr);//대여도서정보 초기화 v
void Rental_insert(RList *plist, B_Rental *pmb);//대여도서 추가 v
B_Rental Rental_delete(RList *plist, B_Rental *pr);//대여도서 삭제 v
B_Rental Rental_update(RList *plist, B_Rental *pr);//대여도서 수정 v
RList Rental_select(RList *plist, B_Rental *pmb);//대여도서 검색 v
int R_LCount(RList * plist); //대여도서 출력

void Qsort_rental(RList *plist, int left, int right, char select[]); //대여도서 정렬 v
void Quest_rental(RList *plist, B_Rental *pr, char select[]); //대여도서 탐색 v

int Load_rental(RList *plist); //대여 목록 가져오기
int Save_rental(RList *plist); //대여 목록 저장


#endif

