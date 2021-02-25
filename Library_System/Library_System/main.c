#include <stdio.h>
#include <time.h>
#include "library.h"
#include "member.h"
#include "rental.h"

void Log_In();                     //�α��� ���
void Member_Join();                //ȸ������ ���
void booklist();                   //���� UI
void memberlist();                 //ȸ�� UI
void rentallist();                  //�뿩 UI
void mainlist();                   //���� UI
void manager_ui();                 //������ UI
void user_ui();                    //ȸ�� UI
void join_ui();                    //ȸ������ UI
void log_ui();                     //�α��� UI
void manager();                    //������ ���
void book_m();                     //�������� ���
void member_m();                   //ȸ������ ���
void rental_m();                   //�뿩�������� ���
void insertBook();                 //�����߰�
void deleteBook();                 //��������
void selectBook();                 //�����˻�
void updateBook();                 //��������
void selectBook_s(S_Book *sb);     //�����󼼰˻�
void selectMember();               //ȸ���˻�
void deleteMember();               //ȸ������
void updateMember();               //ȸ������
void selectMember_s(S_Member *sm); //ȸ���󼼰˻�
void selectRental();               //�뿩��� �˻�
void updateRental();               //��� ����
void deleteRental();               //��� ����
void selectRental_s(B_Rental *br); //�뿩��� �� �˻�
void user(S_Member sm);                       //�������
void bookRental(S_Member sm);                 //�뿩 ���
void bookReturn(S_Member sm);                 //�ݳ� ���
void updateMember_u(S_Member psm);             //ȸ������ ����
int Rental_Time(int *y, int *m, int *d); //�뿩 �ݳ� ��¥���
void Real_Time(int *y, int *m, int *d);  //���� �ð�

int main(void) {

	int input = 0;
	char eorl;

	while (1) {

		mainlist();

		scanf("%d", &input);

		switch (input) {

		case 1:
			Log_In();
			break;
		case 2:
			Member_Join();
			break;
		case 3:
			return 0;
			break;
		}
		_getch();
	}
}

//UI
void mainlist()  //���� ����Ʈ
{
	system("cls");
	printf("����������������������������������������������������������������\n");
	printf("��     ���� ����   ���α׷�     ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. �α���                ��\n");
	printf("��     2. ȸ������              ��\n");
	printf("��     3. ����                  ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");


}

void user_ui() {
	system("cls");
	printf("����������������������������������������������������������������\n");
	printf("��          ȸ    ��            ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. ���� �˻�             ��\n");
	printf("��     2. ���� �뿩             ��\n");
	printf("��     3. ���� �ݳ�             ��\n");
	printf("��     4. ȸ�� ����             ��\n");
	printf("��     5. ����                  ��\n");
	printf("��                              ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");
}

void log_ui() {
	system("cls");
	printf("����������������������������������������������������������������������������������������������\n");
	printf("��               ��     ��     ��              ��\n");
	printf("����������������������������������������������������������������������������������������������\n");
}

void join_ui() {
	system("cls");
	printf("������������������������������������������������������������������������������������������������������\n");
	printf("��             ȸ     ��     ��     ��             ��\n");
	printf("������������������������������������������������������������������������������������������������������\n");
}

void manager_ui() {
	system("cls");
	printf("����������������������������������������������������������������\n");
	printf("��          �� �� ��            ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. ȸ �� �� ��           ��\n");
	printf("��     2. �� �� �� ��           ��\n");
	printf("��     3. �� �� �� ��           ��\n");
	printf("��     4. �� ��                 ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");
}

void booklist()  //���� ����Ʈ
{
	system("cls");

	printf("����������������������������������������������������������������\n");
	printf("��          �� �� �� ��         ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. �� �� �� ��           ��\n");
	printf("��     2. �� �� �� ��           ��\n");
	printf("��     3. �� �� �� ��           ��\n");
	printf("��     4. �� �� �� ��           ��\n");
	printf("��     5. �� ��                 ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");

}

void memberlist()  //ȸ�� ����Ʈ
{
	system("cls");
	printf("����������������������������������������������������������������\n");
	printf("��         ȸ �� �� ��          ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. ȸ �� �� ��           ��\n");
	printf("��     2. ȸ �� �� ��           ��\n");
	printf("��     3. ȸ �� �� ��           ��\n");
	printf("��     4. �� ��                 ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");
}

void rentallist()  //�뿩 ����Ʈ
{
	system("cls");
	printf("����������������������������������������������������������������\n");
	printf("��         �� �� �� ��          ��\n");
	printf("����������������������������������������������������������������\n");
	printf("��                              ��\n");
	printf("��     1. �� �� �� ��           ��\n");
	printf("��     2. �� �� �� ��           ��\n");
	printf("��     3. �� �� �� ��           ��\n");
	printf("��     4. �� ��                 ��\n");
	printf("��                              ��\n");
	printf("����������������������������������������������������������������\n");
}

//���� UI ���
void Log_In() {
	char id[MAX], pw[MAX], eorl;
	MList ml, log;
	S_Member sm;

	MListInit(&ml);
	MListInit(&log);
	MemberInit(&sm);
	Load_member(&ml);

	while (1) {
		system("cls");
		log_ui();
		//ui �ӽ�

		printf(" I D (����:0) >>");
		scanf("%s", id);
		if (strcmp(id, "0") == 0) {
			return;
		}
		printf(" P W >>");
		scanf("%s", pw);

		strcpy(sm.id, id);

		log = member_select(&ml, &sm);

		if (log.list_num == 0) {
			printf("���� ���̵� �Դϴ�.");
			_getch();
		}
		else if (strcmp(log.member_list[0].pw, pw) != 0) {
			printf("��й�ȣ�� �ٽ� �Է��ϼ���");
			_getch();
		}
		else {
			if (strcmp(log.member_list[0].rank, "������") == 0) {
				//������ ��� 
				manager();
				_getch();
			}
			else {
				//ȸ�����
				user(log.member_list[0]);
				_getch();
			}
		}


	}
}

void Member_Join() {
	S_Member sm, save;
	MList ml, select;

	MemberInit(&sm);
	MemberInit(&save);
	MListInit(&ml);
	MListInit(&select);
	Load_member(&ml);

	join_ui();
	printf("ex)123456-1234567\n");
	printf(" �ֹι�ȣ�� �Է��ϼ���>>");
	scanf("%s", sm.s_snum);

	select = member_select(&ml, &sm);

	if (select.list_num == 0) {
		strcpy(save.s_snum, sm.s_snum);
		MemberInit(&sm);

		printf(" ���̵� �Է��ϼ��� >>");
		scanf("%s", sm.id);
		select = member_select(&ml, &sm);
		if (select.list_num == 0) {
			strcpy(save.id, sm.id);

			printf(" ��й�ȣ�� �Է��ϼ��� >>");
			scanf("%s", save.pw);
			printf(" �̸��� �Է��ϼ��� >>");
			scanf("%s", save.name);
			printf(" �ڵ��� ��ȣ�� �Է��ϼ��� >>");
			scanf("%s", save.p_num);
			printf(" �ּҸ� �Է��ϼ��� >>");
			scanf("%s", save.addr);
			strcpy(save.rank, "ȸ��");

			member_insert(&ml, &save);
			Save_member(&ml);
		}
		else {
			printf("�ִ� ���̵��Դϴ�.");
		}
	}
	else {
		printf("���ԵǾ��ֽ��ϴ�.");
	}
}

//������
void manager() {
	int input = 0;
	char eorl;
	while (1) {
		system("cls");
		manager_ui();

		scanf("%d", &input);

		switch (input) {
		case 1:
			member_m();
			break;
		case 2:
			book_m();
			break;
		case 3:
			rental_m();
			break;
		case 4:
			return;
			break;
		}
	}
	_getch();
}

//�������� ���
void book_m()  //���� �˻� �߰� ���� ����
{
	int input = 0;
	char eorl;

	while (1) {
		system("cls");
		booklist();

		scanf("%d", &input);

		switch (input) {
		case 1:
			selectBook();
			break;
		case 2:
			insertBook();
			break;
		case 3:
			updateBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			return;
			break;
		}
	}
	fflush(stdin);
	_getch();
}

void selectBook() {
	BList bl;
	S_Book sb;
	char eorl;
	int count = 0, num = 0;
	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	while (1) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                        ��    ��        ��    ��                        ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��     S/N        ����        ����     ���ǻ�      ������        �뿩     ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		for (int i = 0;i < 10;i++) {
			if (bl.list_num <= count) break;
			printf("��  %.7s\t %.5s\t     %.5s    %.6s      %.10s\t%-8s ��\n", bl.booklist[count].book_num, bl.booklist[count].book_name,
				bl.booklist[count].book_author, bl.booklist[count].book_publisher, bl.booklist[count].book_Issue_year, bl.booklist[count].book_rental);

			count++;
		}

		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��    ����������: a                                       ���������� :d   ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��      �󼼺���: s               ����: r                �ڷΰ���: w      ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		fflush(stdin);
		eorl = _getch();
		_getch();

		switch (eorl) {
		case 'a':
		case 'A':
			count -= 1;
			if (count < 10) count = 0;
			else {
				count -= count % 10;
				count -= 10;
			}
			break;
		case 'd':
		case 'D':
			if (count >= bl.list_num - 1)
				count -= count % 10;
			break;
		case 's':
		case 'S':
			printf("S/N�� �Է��ϼ��� >>");
			BookInit(&sb);
			scanf("%s", sb.book_num);

			num = BSearch_num(&bl, &sb);
			if (num != -1)
				selectBook_s(&bl.booklist[num]);
			else {
				printf("%s �� ���� ���� �Դϴ�.", sb.book_num);
				_getch();
			}
			count -= count % 10;
			break;
		case 'r':
		case 'R':
			printf("���� ������ ������\n 1.S/N  2.���� 3.���� 4.���ǻ� 5.������ 6.�뿩����");
			eorl = _getch();
			_getch();
			switch (eorl) {
			case '1':
				Qsort_book(&bl, 0, bl.list_num - 1, "num");
				break;
			case '2':
				Qsort_book(&bl, 0, bl.list_num - 1, "name");
				break;
			case '3':
				Qsort_book(&bl, 0, bl.list_num - 1, "author");
				break;
			case '4':
				Qsort_book(&bl, 0, bl.list_num - 1, "publisher");
				break;
			case '5':
				Qsort_book(&bl, 0, bl.list_num - 1, "Issue_year");
				break;
			case '6':
				Qsort_book(&bl, 0, bl.list_num - 1, "rental");
				break;

			default:
				Qsort_book(&bl, 0, bl.list_num - 1, "num");

			}
			count = 0;
			break;
		case 'w':
		case 'W':
			return;

		default:
			count -= count % 10;

		}
		_getch();

	}
}

void selectBook_s(S_Book *sb) {
	char eorl;

	system("cls");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                        ��    ��        ��    ��                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��  S/N    ��   %-55s    ��\n", sb->book_num);
	printf("��  ����   ��   %-55s    ��\n", sb->book_name);
	printf("��  ����   ��   %-55s    ��\n", sb->book_author);
	printf("��  ���ǻ� ��   %-55s    ��\n", sb->book_publisher);
	printf("��  ������ ��   %-55s    ��\n", sb->book_Issue_year);
	printf("��  �뿩   ��   %-55s    ��\n", sb->book_rental);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     �ڷΰ���: w                                                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

	fflush(stdin);
	eorl = _getch();
	_getch();

	switch (eorl) {

	case 'w':
		return;

	}
	_getch();
}

void insertBook() //���� ���� �Է�
{
	BList bl;
	S_Book sb;
	char eorl;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ��    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("  ���� �Ϸù�ȣ�� �Է��Ͻÿ�:");
	scanf("%s", sb.book_num);
	fflush(stdin);
	printf("  �������� �Է��Ͻÿ�:");
	scanf("%s", sb.book_name);
	fflush(stdin);
	printf("  ������ �Է��Ͻÿ�:");
	scanf("%s", sb.book_author);
	fflush(stdin);
	printf("  ���ǻ縦 �Է��Ͻÿ�:");
	scanf("%s", sb.book_publisher);
	fflush(stdin);
	printf("  �������� �⵵�� �Է��Ͻÿ�:");
	scanf("%s", sb.book_Issue_year);
	fflush(stdin);
	strcpy(sb.book_rental, "�뿩����");

	book_insert(&bl, &sb);
	if (Save_book(&bl))
		printf("�����߽��ϴ�.");

	else
		printf("���� ����");

	_getch();
	return;

}

void deleteBook() //���� ���� �Է�
{
	BList bl;
	S_Book sb;
	char eorl;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ��    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("���� ������ �Ϸù�ȣ�� �Է��Ͻÿ�:");
	scanf("%s", sb.book_num);


	book_delete(&bl, &sb);
	if (Save_book(&bl))
		printf("�����߽��ϴ�.");

	else
		printf("���� ����");

	_getch();
	return;

}

void updateBook() {
	BList bl, select;
	S_Book sb;
	char eorl;
	int num = 0;

	BListInit(&bl);
	BListInit(&select);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ��    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("������ ������ �Ϸù�ȣ�� �Է��Ͻÿ�:");
	scanf("%s", sb.book_num);
	fflush(stdin);

	num = BSearch_num(&bl, &sb);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                      ��    ��      ��    ��                     ��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("  �������� �Է��Ͻÿ�:");
		scanf("%s", bl.booklist[num].book_name);
		fflush(stdin);
		printf("  ������ �Է��Ͻÿ�:");
		scanf("%s", bl.booklist[num].book_author);
		fflush(stdin);
		printf("  ���ǻ縦 �Է��Ͻÿ�:");
		scanf("%s", bl.booklist[num].book_publisher);
		fflush(stdin);
		printf("  �������� �⵵�� �Է��Ͻÿ�:");
		scanf("%s", bl.booklist[num].book_Issue_year);

		if (Save_book(&bl))
			printf("�����߽��ϴ�.");
		else
			printf("���� ����");

		_getch();
	}
	else
		printf("���� �����Դϴ�.");

	_getch();
	return;
}

//ȸ�� ���� ���
void member_m()
{
	int input = 0;
	char eorl;

	while (1) {
		system("cls");
		memberlist();

		scanf("%d", &input);

		switch (input) {
		case 1:
			selectMember();
			break;
		case 2:
			updateMember();
			break;
		case 3:
			deleteMember();
			break;
		case 4:
			return;
			break;
		}
	}
	fflush(stdin);
	_getch();
}

void selectMember() {
	MList ml;
	S_Member sm;
	char eorl;
	int count = 0, num = 0;
	MListInit(&ml);
	MemberInit(&sm);

	Load_member(&ml);

	while (1) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                        ȸ    ��        ��    ��                        ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��     ID             �̸�            �ڵ��� ��ȣ            ���         ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

		for (int i = 0;i < 10;) {
			if (ml.list_num <= count) break;

			if (strcmp(ml.member_list[count].rank, "������") != 0) {
				printf("��  %-15s %-15s  %-20s    %-13s��\n", ml.member_list[count].id, ml.member_list[count].name, ml.member_list[count].p_num, ml.member_list[count].rank);
				i++;
			}

			count++;
		}

		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��    ����������: a                                       ���������� :d   ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��      �󼼺���: s               ����: r                �ڷΰ���: w      ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

		fflush(stdin);
		eorl = _getch();
		_getch();

		switch (eorl) {

		case 'a':
		case 'A':
			count -= 1;
			if (count < 10) count = 0;
			else {
				count -= count % 10;
				count -= 10;
			}
			break;
		case 'd':
		case 'D':
			if (count >= ml.list_num - 1)
				count -= count % 10;
			break;
		case 's':
		case 'S':
			printf("ID�� �Է��ϼ��� >>");
			MemberInit(&sm);
			scanf("%s", sm.id);

			num = BSearch_M_id(&ml, &sm);
			if (num != -1)
				selectMember_s(&ml.member_list[num]);
			else {
				printf("%s �� ���� ���� �Դϴ�.", sm.id);
				_getch();
			}
			count -= count % 10;
			break;
		case 'r':
		case 'R':

			break;
		case 'w':
		case 'W':
			return;

		default:
			count -= count % 10;

		}
		_getch();

	}
}

void selectMember_s(S_Member *sm) {
	char eorl;

	system("cls");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                        ��    ��        ��    ��                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     ID      ��   %-55s��\n", sm->id);
	printf("��     PW      ��   %-55s��\n", sm->pw);
	printf("��    �̸�     ��   %-55s��\n", sm->name);
	printf("��  �ֹ� ��ȣ  ��   %-55s��\n", sm->s_snum);
	printf("�� �ڵ��� ��ȣ ��   %-55s��\n", sm->p_num);
	printf("��    �ּ�     ��   %-55s��\n", sm->addr);
	printf("��    ���     ��   %-55s��\n", sm->rank);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     �ڷΰ���: w                                                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

	fflush(stdin);
	eorl = _getch();
	_getch();

	switch (eorl) {

	case 'w':
		return;

	}
	_getch();
}

void deleteMember() {
	MList ml;
	S_Member sm;
	char eorl;

	MListInit(&ml);
	MemberInit(&sm);

	Load_member(&ml);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ȸ    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("���� ȸ���� ID�� �Է��Ͻÿ�:");
	scanf("%s", sm.id);


	member_delete(&ml, &sm);
	if (Save_member(&ml))
		printf("�����߽��ϴ�.");

	else
		printf("���� ����");

	_getch();
	return;
}

void updateMember() {
	MList ml, select;
	S_Member sm;
	char eorl;
	int num = 0;

	MListInit(&ml);
	MListInit(&select);
	MemberInit(&sm);

	Load_member(&ml);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ȸ    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("������ ȸ���� ID�� �Է��Ͻÿ�:");
	scanf("%s", sm.id);
	fflush(stdin);

	num = BSearch_M_id(&ml, &sm);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                      ȸ    ��      ��    ��                     ��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("  ��й�ȣ�� �Է��Ͻÿ�:");
		scanf("%s", ml.member_list[num].pw);
		fflush(stdin);
		printf("  �̸��� �Է��Ͻÿ�:");
		scanf("%s", ml.member_list[num].name);
		fflush(stdin);
		printf("  �ڵ��� ��ȣ�� �Է��Ͻÿ�:");
		scanf("%s", ml.member_list[num].p_num);
		fflush(stdin);
		printf("  �ּҸ� �Է��Ͻÿ�:");
		scanf("%s", ml.member_list[num].addr);
		fflush(stdin);
		printf("  ����� �Է��Ͻÿ�:");
		scanf("%s", ml.member_list[num].rank);


		if (Save_member(&ml))
			printf("�����߽��ϴ�.");
		else
			printf("���� ����");

		_getch();
	}
	else
		printf("���� ȸ���Դϴ�.");

	_getch();
	return;
}

//�뿩 ���� ���
void rental_m() {
	int input = 0;
	char eorl;

	while (1) {
		system("cls");
		rentallist();

		scanf("%d", &input);

		switch (input) {
		case 1:
			selectRental();
			break;
		case 2:
			updateRental();
			break;
		case 3:
			deleteRental();
			break;
		case 4:
			return;
			break;
		}
	}
	fflush(stdin);
	_getch();
}

void selectRental() {
	RList rl;
	B_Rental br;
	char eorl;
	int count = 0, num = 0;
	RListInit(&rl);
	RentalInit(&br);

	Load_rental(&rl);
	while (1) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                        ��    ��        ��    ��                        ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��     S/N          ����           ID        �뿩��        �ݳ� ������    ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		for (int i = 0;i < 10;i++) {
			if (rl.list_num <= count) break;
			printf("��   %-10s  %-14s %-10s %-15s %-15s��\n", rl.rental_list[count].book_num, rl.rental_list[count].book_name, rl.rental_list[count].user_id, rl.rental_list[count].book_rental_day
				, rl.rental_list[count].book_return_day);

			count++;
		}

		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��    ����������: a                                       ���������� :d   ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��      �󼼺���: s               ����: r                �ڷΰ���: w      ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

		fflush(stdin);
		eorl = _getch();
		_getch();

		switch (eorl) {
		case 'a':
		case 'A':
			count -= 1;
			if (count < 10) count = 0;
			else {
				count -= count % 10;
				count -= 10;
			}
			break;
		case 'd':
		case 'D':
			if (count >= rl.list_num - 1)
				count -= count % 10;
			break;
		case 's':
		case 'S':
			printf("S/N�� �Է��ϼ��� >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s �� ��Ͽ� ���� �����Դϴ�.", br.book_num);
				_getch();
			}
			count -= count % 10;
			break;
		case 'r':
		case 'R':

			break;
		case 'w':
		case 'W':
			return;

		default:
			count -= count % 10;

		}
		_getch();

	}
}

void updateRental() {
	RList rl, select;
	B_Rental br;
	char eorl;
	int num = 0;

	RListInit(&rl);
	RListInit(&select);
	RentalInit(&br);
	Load_rental(&rl);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ��    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("������ ����� S/N�� �Է��Ͻÿ�:");
	scanf("%s", br.book_num);
	fflush(stdin);

	num = BSearch_R(&rl, &br);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                      ��    ��      ��    ��                     ��\n");
		printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
		fflush(stdin);
		printf("�ݳ��������� �Է��ϼ���");
		scanf("%s", rl.rental_list[num].book_return_day);


		if (Save_rental(&rl))
			printf("�����߽��ϴ�.");
		else
			printf("���� ����");

		_getch();
	}
	else
		printf("���� ����Դϴ�.");

	_getch();
	return;
}

void deleteRental() {
	RList rl;
	B_Rental br;
	char eorl;

	RListInit(&rl);
	RentalInit(&br);

	Load_rental(&rl);
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                      ��    ��      ��    ��                     ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("���� ����� S/N�� �Է��Ͻÿ�:");
	scanf("%s", br.book_num);


	Rental_delete(&rl, &br);
	if (Save_rental(&rl))
		printf("�����߽��ϴ�.");

	else
		printf("���� ����");

	fflush(stdin);
	_getch();
	return;
}

void selectRental_s(B_Rental *br) {
	char eorl;

	system("cls");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                        ��    ��        ��    ��                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��    S / N    ��   %-55s��\n", br->book_num);
	printf("��    �� ��    ��   %-55s��\n", br->book_name);
	printf("��     I D     ��   %-55s��\n", br->user_id);
	printf("��    �뿩��   ��   %-55s��\n", br->book_rental_day);
	printf("��    �ݳ���   ��   %-55s��\n", br->book_return_day);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     �ڷΰ���: w                                                        ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

	fflush(stdin);
	eorl = _getch();
	_getch();

	switch (eorl) {

	case 'w':
		return;

	}
	_getch();
}

void user(S_Member sm) {
	int input = 0;
	char eorl;
	while (1) {
		system("cls");
		user_ui();

		scanf("%d", &input);
		//�˻� , �뿩, �ݳ�, ��������
		switch (input) {
		case 1:
			selectBook();
			break;
		case 2:
			bookRental(sm);
			break;
		case 3:
			bookReturn(sm);
			break;
		case 4:
			updateMember_u(sm);
			break;
		case 5:
			return;
			break;
		}
	}
	_getch();
}

void bookRental(S_Member sm) {
	B_Rental br;
	RList rl, select;
	S_Book sb;
	BList bl;
	int num = 0, y = 0, m = 0, d = 0;
	char cp[100];
	RentalInit(&br);
	RListInit(&rl);
	RListInit(&select);

	Load_rental(&rl);
	strcpy(br.user_id, sm.id);

	select = Rental_select(&rl, &br);

	if (select.list_num < 3) {
		Load_book(&bl);
		BookInit(&sb);
		system("cls");
		printf("�뿩�� å�� S/N�� �Է��ϼ���>>");
		scanf("%s", sb.book_num);
		num = BSearch_num(&bl, &sb);
		if (num) {
			if (strcmp(bl.booklist[num].book_rental, "�뿩����") == 0) {
				strcpy(br.book_num, bl.booklist[num].book_num);
				strcpy(br.book_name, bl.booklist[num].book_name);
				Real_Time(&y, &m, &d);\

					sprintf(cp, "%d", y);
				strcpy(br.book_rental_day, cp);
				strcat(br.book_rental_day, "-");
				sprintf(cp, "%d", m);
				strcat(br.book_rental_day, cp);
				strcat(br.book_rental_day, "-");
				sprintf(cp, "%d", d);
				strcat(br.book_rental_day, cp);

				Rental_Time(&y, &m, &d);
				sprintf(cp, "%d", y);
				strcpy(br.book_return_day, cp);
				strcat(br.book_return_day, "-");
				sprintf(cp, "%d", m);
				strcat(br.book_return_day, cp);
				strcat(br.book_return_day, "-");
				sprintf(cp, "%d", d);
				strcat(br.book_return_day, cp);

				Rental_insert(&rl, &br);

				if (Save_rental(&rl)) {
					strcpy(bl.booklist[num].book_rental, "�뿩��");
					Save_book(&bl);
					printf("�뿩�߽��ϴ�.");
					_getch();
				}
				else {
					printf("���� ����");
					_getch();
				}
			}
			else {
				printf("�뿩�� �����Դϴ�.");
				_getch();
			}
		}
		else {
			printf("���� �����Դϴ�.");
			_getch();
		}
	}
	else {
		printf("�뿩�� �Ұ����մϴ�(�뿩 3�� �ʰ�)");
		_getch();
	}
}

void bookReturn(S_Member sm) {
	RList rl, select;
	B_Rental br;
	BList bl;
	S_Book sb;
	char eorl;
	int count = 0, num = 0;
	RListInit(&rl);
	RListInit(&select);
	RentalInit(&br);
	BListInit(&bl);
	BookInit(&sb);

	Load_rental(&rl);

	strcpy(br.user_id, sm.id);
	select = Rental_select(&rl, &br);
	while (1) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��                        ��    ��        ��    ��                        ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��     S/N          ����           ID        �뿩��        �ݳ� ������    ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		for (int i = 0;i < 3;i++) {
			if (select.list_num <= count) break;
			printf("��   %-10s  %-14s %-10s %-15s %-15s��\n", select.rental_list[count].book_num, select.rental_list[count].book_name, select.rental_list[count].user_id, select.rental_list[count].book_rental_day
				, select.rental_list[count].book_return_day);

			count++;
		}

		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		printf("��    �󼼺���: s      �ݳ��ϱ�: r      �ڷΰ���: w                       ��\n");
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
		eorl = '\0';

		eorl = _getch();
		_getch();

		switch (eorl) {

		case 'r':
		case 'R':
			printf("�ݳ��� å�� S/N�� �Է��ϼ��� >>");
			scanf("%s", br.book_num);
			if (BSearch_R(&rl, &br) != -1) {

				Rental_delete(&rl, &br);
				Rental_delete(&select, &br);
				if (Save_rental(&rl)) {
					Load_book(&bl);
					strcpy(sb.book_num, br.book_num);
					num = BSearch_num(&bl, &sb);
					strcpy(bl.booklist[num].book_rental, "�뿩����");
					if (Save_book(&bl)) {
						printf("�ݳ��Ϸ�");

						_getch();
					}
					else {
						printf("save_book err!");
						_getch();
					}
				}
				else {
					printf("save_rental err!");
					_getch();
				}
				count -= count % 10;
			}
			else {
				printf("���� ����Դϴ�.");
				_getch();
			}
			break;
		case 's':
		case 'S':
			printf("S/N�� �Է��ϼ��� >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s �� ��Ͽ� ���� �����Դϴ�.", br.book_num);
				_getch();
			}
			count -= count % 10;
			break;
		case 'w':
		case 'W':
			return;

		default:
			count -= count % 10;

		}
		_getch();

	}
}

void updateMember_u(S_Member psm) {
	char eorl;
	int num = 0, tg = 0;
	MList ml;
	S_Member sm;

	MListInit(&ml);
	MemberInit(&sm);

	Load_member(&ml);
	system("cls");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                        ��     ��    ��                                 ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     ID      ��   %-55s��\n", psm.id);
	printf("��     PW      ��   %-55s��\n", psm.pw);
	printf("��    �̸�     ��   %-55s��\n", psm.name);
	printf("��  �ֹ� ��ȣ  ��   %-55s��\n", psm.s_snum);
	printf("�� �ڵ��� ��ȣ ��   %-55s��\n", psm.p_num);
	printf("��    �ּ�     ��   %-55s��\n", psm.addr);
	printf("��    ���     ��   %-55s��\n", psm.rank);
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��     �ڷΰ���: w   �����ϱ�: u                                           ��\n");
	printf("����������������������������������������������������������������������������������������������������������������������������������������������������\n");

	fflush(stdin);
	eorl = _getch();
	_getch();
	strcpy(sm.id, psm.id);
	tg = BSearch_M_id(&ml, &sm);
	switch (eorl) {
	case 'U':
	case 'u':
		printf("������ ������ ������(1.�ڵ�����ȣ 2.�ּ�)>>");
		scanf("%d", &num);
		if (num == 1) {
			printf("�ڵ��� ��ȣ�� �Է��ϼ���>>");
			scanf("%s", ml.member_list[tg].p_num);
		}
		else if (num == 2) {
			printf("�ּҸ� �Է��ϼ���>>");
			scanf("%s", ml.member_list[tg].addr);
		}
		else
			return;
		if (Save_member(&ml)) {
			printf("�����Ǿ����ϴ�.");
			_getch();
		}
		else
			printf("save_member err!");
		break;
	case 'w':
	case 'W':
		return;

	}
	_getch();
}

void Real_Time(int *y, int *m, int *d) {
	time_t rt;
	struct tm* t;
	time(&rt);
	t = (struct tm*)localtime(&rt);
	*y = t->tm_year + 1900;
	*m = t->tm_mon + 1;
	*d = t->tm_mday;

}

int Rental_Time(int *y, int *m, int *d) {
	int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int py = *y, pm = *m, pd = *d;
	if (py % 4 == 0 && py % 100 != 0) {
		day[2] = 29;
	}
	else if (py & 400 == 0) {
		day[2] = 29;
	}

	if (pd > day[pm] || pm < 1 || pm>12 || py < 0) {
		return -1;
	}
	//�뿩 2��
	pd += 13;

	if (pd > day[pm]) {
		pd = pd - day[pm];
		pm++;
		if (pm == 13) {
			pm = 1;
			py++;
		}
	}
	*y = py, *m = pm, *d = pd;
}