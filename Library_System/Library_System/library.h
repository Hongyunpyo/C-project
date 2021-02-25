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

void BListInit(BList * plist);//��������Ʈ �ʱ�ȭ v
void BookInit(S_Book * pbook);//���� �ʱ�ȭ v
void book_insert(BList *plist, S_Book *pbook);//���� �߰� v
S_Book book_delete(BList *plist, S_Book *pbook);//���� ���� �Ϸù�ȣ�� å�� �˻� �� ���� v
S_Book book_update(BList *plist, S_Book *pbook);//���� ���� �Ϸù�ȣ�� å�� �˻� �� ���� v
BList book_select(BList *plist, S_Book *pbook);//���� �˻� v
int B_LCount(BList * plist); //��ϵ� ���� �� ���

void Qsort_book(BList *plist, int left, int right, char select[]); //���� ���� v
void Quest_book(BList *plist, S_Book *pbook, char select[]); //���� Ž�� v

int Load_book(BList *plist); //���� ��� ��������
int Save_book(BList *plist); //���� ��� ����

#endif
