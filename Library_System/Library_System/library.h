#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#define TRUE	1
#define FALSE	0
#define MAX 100
#define NUM 255

typedef struct book_impormation {
	char book_num[MAX];
	char book_name[MAX];
	char book_author[MAX];
	char book_publisher[MAX];
	char book_Issue_year[MAX];
	char book_rental[MAX];

}Book;

typedef Book S_Book;

typedef struct book_list {
	S_Book booklist[NUM];
	int list_num;

}Book_List;

typedef Book_List BList;

void BListInit(BList * plist);//도서리스트 초기화 v
void BookInit(S_Book * pbook);//도서 초기화 v
void book_insert(BList *plist, S_Book *pbook);//도서 추가 v
S_Book book_delete(BList *plist, S_Book *pbook);//도서 삭제 일련번호로 책을 검색 후 삭제 v
S_Book book_update(BList *plist, S_Book *pbook);//도서 수정 일련번호로 책을 검색 후 수정 v
BList book_select(BList *plist, S_Book *pbook);//도서 검색 v
int B_LCount(BList * plist); //등록된 도서 수 출력

void Qsort_book(BList *plist, int left, int right, char select[]); //도서 정렬 v
void Quest_book(BList *plist, S_Book *pbook, char select[]); //도서 탐색 v

int Load_book(BList *plist); //도서 목록 가져오기
int Save_book(BList *plist); //도서 목록 저장

//자료구조
int BSearch_num(BList *plist, S_Book *pbook);//이중탐색
int Partition(BList *plist, int left, int right, char select[]);//퀵정렬
void swap(BList *plist, int ch1, int ch2);//퀵정렬
#endif
