#include <stdio.h>
#include <time.h>
#include <string.h>
#include "library.h"
#include "member.h"
#include "rental.h"

void Log_In();                     //로그인 기능
void Member_Join();                //회원가입 기능
void booklist();                   //도서 UI
void memberlist();                 //회원 UI
void rentallist();                  //대여 UI
void mainlist();                   //메인 UI
void manager_ui();                 //관리자 UI
void user_ui();                    //회원 UI
void join_ui();                    //회원가입 UI
void log_ui();                     //로그인 UI
void manager();                    //관리자 모드
void book_m();                     //도서관리 기능
void member_m();                   //회원관리 기능
void rental_m();                   //대여도서관리 기능
void insertBook();                 //도서추가
void deleteBook();                 //도서삭제
void selectBook();                 //도서검색
void updateBook();                 //도서수정
void selectBook_s(S_Book *sb);     //도서상세검색
void selectMember();               //회원검색
void deleteMember();               //회원삭제
void updateMember();               //회원수정
void selectMember_s(S_Member *sm); //회원상세검색
void selectRental();               //대여목록 검색
void updateRental();               //목록 수정
void deleteRental();               //목록 삭제
void selectRental_s(B_Rental *br); //대여목록 상세 검색
void user(S_Member sm);            //유저모드
void bookRental(S_Member sm);      //대여 기능
void bookReturn(S_Member sm);      //반납 기능
void updateMember_u(S_Member psm); //회원정보 수정
int Rental_Time(int *y, int *m, int *d); //대여 반납 날짜계산
void Real_Time(int *y, int *m, int *d);  //현재 시간

int main(void) {

	int input = 0;

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
void mainlist()  //메인 리스트
{
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃     도서 관리   프로그램     ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 로그인                ┃\n");
	printf("┃     2. 회원가입              ┃\n");
	printf("┃     3. 종료                  ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");


}

void user_ui() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃          회    원            ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 도서 검색             ┃\n");
	printf("┃     2. 도서 대여             ┃\n");
	printf("┃     3. 도서 반납             ┃\n");
	printf("┃     4. 회원 정보             ┃\n");
	printf("┃     5. 종료                  ┃\n");
	printf("┃                              ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void log_ui() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃               로     그     인              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void join_ui() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃             회     원     가     입             ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void manager_ui() {
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃          관 리 자            ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 회 원 관 리           ┃\n");
	printf("┃     2. 도 서 관 리           ┃\n");
	printf("┃     3. 대 여 관 리           ┃\n");
	printf("┃     4. 종 료                 ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void booklist()  //도서 리스트
{
	system("cls");

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃          도 서 관 리         ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 도 서 검 색           ┃\n");
	printf("┃     2. 도 서 추 가           ┃\n");
	printf("┃     3. 도 서 수 정           ┃\n");
	printf("┃     4. 도 서 삭 제           ┃\n");
	printf("┃     5. 종 료                 ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}

void memberlist()  //회원 리스트
{
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃         회 원 관 리          ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 회 원 검 색           ┃\n");
	printf("┃     2. 회 원 수 정           ┃\n");
	printf("┃     3. 회 원 삭 제           ┃\n");
	printf("┃     4. 종 료                 ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void rentallist()  //대여 리스트
{
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃         대 여 관 리          ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃                              ┃\n");
	printf("┃     1. 대 여 목 록           ┃\n");
	printf("┃     2. 목 록 수 정           ┃\n");
	printf("┃     3. 목 록 삭 제           ┃\n");
	printf("┃     4. 종 료                 ┃\n");
	printf("┃                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

//메인 UI 기능
void Log_In() {
	char id[MAX], pw[MAX];
	MList ml, log;
	S_Member sm;

	MListInit(&ml);
	MListInit(&log);
	MemberInit(&sm);
	Load_member(&ml);

	while (1) {
		system("cls");
		log_ui();
		//ui 임시

		printf(" I D (종료:0) >>");
		scanf("%s", id);
		if (strcmp(id, "0") == 0) {
			return;
		}
		printf(" P W >>");
		scanf("%s", pw);

		strcpy(sm.id, id);

		log = member_select(&ml, &sm);

		if (log.list_num == 0) {
			printf("없는 아이디 입니다.");
			_getch();
		}
		else if (strcmp(log.member_list[0].pw, pw) != 0) {
			printf("비밀번호를 다시 입력하세요");
			_getch();
		}
		else {
			if (strcmp(log.member_list[0].rank, "관리자") == 0) {
				//관리자 모드 
				manager();
				_getch();
			}
			else {
				//회원모드
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
	printf(" 주민번호를 입력하세요>>");
	scanf("%s", sm.s_snum);

	select = member_select(&ml, &sm);

	if (select.list_num == 0) {
		strcpy(save.s_snum, sm.s_snum);
		MemberInit(&sm);

		printf(" 아이디를 입력하세요 >>");
		scanf("%s", sm.id);
		select = member_select(&ml, &sm);
		if (select.list_num == 0) {
			strcpy(save.id, sm.id);

			printf(" 비밀번호를 입력하세요 >>");
			scanf("%s", save.pw);
			printf(" 이름을 입력하세요 >>");
			scanf("%s", save.name);
			printf(" 핸드폰 번호를 입력하세요 >>");
			scanf("%s", save.p_num);
			printf(" 주소를 입력하세요 >>");
			scanf("%s", save.addr);
			strcpy(save.rank, "회원");

			member_insert(&ml, &save);
			Save_member(&ml);
		}
		else {
			printf("있는 아이디입니다.");
		}
	}
	else {
		printf("가입되어있습니다.");
	}
}

//관리자
void manager() {
	int input = 0;

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

//도서관리 기능
void book_m()  //도서 검색 추가 수정 삭제
{
	int input = 0;

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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                        도    서        목    록                        ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃     S/N        제목        저자     출판사      출판일        대여     ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		for (int i = 0;i < 10;i++) {
			if (bl.list_num <= count) break;
			printf("┃  %.7s\t %.5s\t     %.5s    %.6s      %.10s\t%-8s ┃\n", bl.booklist[count].book_num, bl.booklist[count].book_name,
				bl.booklist[count].book_author, bl.booklist[count].book_publisher, bl.booklist[count].book_Issue_year, bl.booklist[count].book_rental);

			count++;
		}

		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃    이전페이지: a                                       다음페이지 :d   ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃      상세보기: s               정렬: r                뒤로가기: w      ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
			printf("S/N를 입력하세요 >>");
			BookInit(&sb);
			scanf("%s", sb.book_num);

			num = BSearch_num(&bl, &sb);
			if (num != -1)
				selectBook_s(&bl.booklist[num]);
			else {
				printf("%s 는 없는 도서 입니다.", sb.book_num);
				_getch();
			}
			count -= count % 10;
			break;
		case 'r':
		case 'R':
			printf("정렬 기준을 고르세요\n 1.S/N  2.제목 3.저자 4.출판사 5.출판일 6.대여여부");
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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                        상    세        정    보                        ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃  S/N    ┃   %-55s    ┃\n", sb->book_num);
	printf("┃  제목   ┃   %-55s    ┃\n", sb->book_name);
	printf("┃  저자   ┃   %-55s    ┃\n", sb->book_author);
	printf("┃  출판사 ┃   %-55s    ┃\n", sb->book_publisher);
	printf("┃  출판일 ┃   %-55s    ┃\n", sb->book_Issue_year);
	printf("┃  대여   ┃   %-55s    ┃\n", sb->book_rental);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     뒤로가기: w                                                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	fflush(stdin);
	eorl = _getch();
	_getch();

	switch (eorl) {

	case 'w':
		return;

	}
	_getch();
}

void insertBook() //도서 정보 입력
{
	BList bl;
	S_Book sb;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      도    서      추    가                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("  도서 일련번호을 입력하시오:");
	scanf("%s", sb.book_num);
	fflush(stdin);
	printf("  도서명을 입력하시오:");
	scanf("%s", sb.book_name);
	fflush(stdin);
	printf("  저자을 입력하시오:");
	scanf("%s", sb.book_author);
	fflush(stdin);
	printf("  출판사를 입력하시오:");
	scanf("%s", sb.book_publisher);
	fflush(stdin);
	printf("  도서출판 년도를 입력하시요:");
	scanf("%s", sb.book_Issue_year);
	fflush(stdin);
	strcpy(sb.book_rental, "대여가능");

	book_insert(&bl, &sb);
	if (Save_book(&bl))
		printf("저장했습니다.");

	else
		printf("저장 오류");

	_getch();
	return;

}

void deleteBook() //도서 정보 입력
{
	BList bl;
	S_Book sb;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      도    서      삭    제                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("삭제 도서의 일련번호을 입력하시오:");
	scanf("%s", sb.book_num);


	book_delete(&bl, &sb);
	if (Save_book(&bl))
		printf("삭제했습니다.");

	else
		printf("삭제 오류");

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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      도    서      수    정                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("수정할 도서의 일련번호을 입력하시오:");
	scanf("%s", sb.book_num);
	fflush(stdin);

	num = BSearch_num(&bl, &sb);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                      도    서      수    정                     ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("  도서명을 입력하시오:");
		scanf("%s", bl.booklist[num].book_name);
		fflush(stdin);
		printf("  저자을 입력하시오:");
		scanf("%s", bl.booklist[num].book_author);
		fflush(stdin);
		printf("  출판사를 입력하시오:");
		scanf("%s", bl.booklist[num].book_publisher);
		fflush(stdin);
		printf("  도서출판 년도를 입력하시요:");
		scanf("%s", bl.booklist[num].book_Issue_year);

		if (Save_book(&bl))
			printf("수정했습니다.");
		else
			printf("수정 오류");

		_getch();
	}
	else
		printf("없는 도서입니다.");

	_getch();
	return;
}

//회원 관리 기능
void member_m()
{
	int input = 0;

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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                        회    원        목    록                        ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃     ID             이름            핸드폰 번호            등급         ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");

		for (int i = 0;i < 10;) {
			if (ml.list_num <= count) break;

			if (strcmp(ml.member_list[count].rank, "관리자") != 0) {
				printf("┃  %-15s %-15s  %-20s    %-13s┃\n", ml.member_list[count].id, ml.member_list[count].name, ml.member_list[count].p_num, ml.member_list[count].rank);
				i++;
			}

			count++;
		}

		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃    이전페이지: a                                       다음페이지 :d   ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃      상세보기: s               정렬: r                뒤로가기: w      ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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
			printf("ID를 입력하세요 >>");
			MemberInit(&sm);
			scanf("%s", sm.id);

			num = BSearch_M_id(&ml, &sm);
			if (num != -1)
				selectMember_s(&ml.member_list[num]);
			else {
				printf("%s 는 없는 도서 입니다.", sm.id);
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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                        상    세        정    보                        ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     ID      ┃   %-55s┃\n", sm->id);
	printf("┃     PW      ┃   %-55s┃\n", sm->pw);
	printf("┃    이름     ┃   %-55s┃\n", sm->name);
	printf("┃  주민 번호  ┃   %-55s┃\n", sm->s_snum);
	printf("┃ 핸드폰 번호 ┃   %-55s┃\n", sm->p_num);
	printf("┃    주소     ┃   %-55s┃\n", sm->addr);
	printf("┃    등급     ┃   %-55s┃\n", sm->rank);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     뒤로가기: w                                                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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

	MListInit(&ml);
	MemberInit(&sm);

	Load_member(&ml);
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      회    원      삭    제                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("삭제 회원의 ID을 입력하시오:");
	scanf("%s", sm.id);


	member_delete(&ml, &sm);
	if (Save_member(&ml))
		printf("삭제했습니다.");

	else
		printf("삭제 오류");

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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      회    원      수    정                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("수정할 회원의 ID을 입력하시오:");
	scanf("%s", sm.id);
	fflush(stdin);

	num = BSearch_M_id(&ml, &sm);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                      회    원      수    정                     ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("  비밀번호을 입력하시오:");
		scanf("%s", ml.member_list[num].pw);
		fflush(stdin);
		printf("  이름을 입력하시오:");
		scanf("%s", ml.member_list[num].name);
		fflush(stdin);
		printf("  핸드폰 번호를 입력하시오:");
		scanf("%s", ml.member_list[num].p_num);
		fflush(stdin);
		printf("  주소를 입력하시요:");
		scanf("%s", ml.member_list[num].addr);
		fflush(stdin);
		printf("  등급을 입력하시요:");
		scanf("%s", ml.member_list[num].rank);


		if (Save_member(&ml))
			printf("수정했습니다.");
		else
			printf("수정 오류");

		_getch();
	}
	else
		printf("없는 회원입니다.");

	_getch();
	return;
}

//대여 관리 기능
void rental_m() {
	int input = 0;

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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                        대    여        목    록                        ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃     S/N          제목           ID        대여일        반납 예정일    ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		for (int i = 0;i < 10;i++) {
			if (rl.list_num <= count) break;
			printf("┃   %-10s  %-14s %-10s %-15s %-15s┃\n", rl.rental_list[count].book_num, rl.rental_list[count].book_name, rl.rental_list[count].user_id, rl.rental_list[count].book_rental_day
				, rl.rental_list[count].book_return_day);

			count++;
		}

		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃    이전페이지: a                                       다음페이지 :d   ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃      상세보기: s               정렬: r                뒤로가기: w      ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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
			printf("S/N를 입력하세요 >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s 는 목록에 없는 도서입니다.", br.book_num);
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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      목    록      수    정                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("수정할 목록의 S/N을 입력하시오:");
	scanf("%s", br.book_num);
	fflush(stdin);

	num = BSearch_R(&rl, &br);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                      목    록      수    정                     ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		fflush(stdin);
		printf("반납예정일을 입력하세요");
		scanf("%s", rl.rental_list[num].book_return_day);


		if (Save_rental(&rl))
			printf("수정했습니다.");
		else
			printf("수정 오류");

		_getch();
	}
	else
		printf("없는 목록입니다.");

	_getch();
	return;
}

void deleteRental() {
	RList rl;
	B_Rental br;

	RListInit(&rl);
	RentalInit(&br);

	Load_rental(&rl);
	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                      목    록      삭    제                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("삭제 목록의 S/N을 입력하시오:");
	scanf("%s", br.book_num);


	Rental_delete(&rl, &br);
	if (Save_rental(&rl))
		printf("삭제했습니다.");

	else
		printf("삭제 오류");

	fflush(stdin);
	_getch();
	return;
}

void selectRental_s(B_Rental *br) {
	char eorl;

	system("cls");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                        상    세        정    보                        ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃    S / N    ┃   %-55s┃\n", br->book_num);
	printf("┃    제 목    ┃   %-55s┃\n", br->book_name);
	printf("┃     I D     ┃   %-55s┃\n", br->user_id);
	printf("┃    대여일   ┃   %-55s┃\n", br->book_rental_day);
	printf("┃    반납일   ┃   %-55s┃\n", br->book_return_day);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     뒤로가기: w                                                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

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

	while (1) {
		system("cls");
		user_ui();

		scanf("%d", &input);
		//검색 , 대여, 반납, 정보수정
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
		printf("대여할 책의 S/N를 입력하세요>>");
		scanf("%s", sb.book_num);
		num = BSearch_num(&bl, &sb);
		if (num) {
			if (strcmp(bl.booklist[num].book_rental, "대여가능") == 0) {
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
					strcpy(bl.booklist[num].book_rental, "대여중");
					Save_book(&bl);
					printf("대여했습니다.");
					_getch();
				}
				else {
					printf("저장 실패");
					_getch();
				}
			}
			else {
				printf("대여된 도서입니다.");
				_getch();
			}
		}
		else {
			printf("없는 도서입니다.");
			_getch();
		}
	}
	else {
		printf("대여가 불가능합니다(대여 3권 초과)");
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
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                        대    여        목    록                        ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃     S/N          제목           ID        대여일        반납 예정일    ┃\n");
		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		for (int i = 0;i < 3;i++) {
			if (select.list_num <= count) break;
			printf("┃   %-10s  %-14s %-10s %-15s %-15s┃\n", select.rental_list[count].book_num, select.rental_list[count].book_name, select.rental_list[count].user_id, select.rental_list[count].book_rental_day
				, select.rental_list[count].book_return_day);

			count++;
		}

		printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("┃    상세보기: s      반납하기: r      뒤로가기: w                       ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		eorl = '\0';

		eorl = _getch();
		_getch();

		switch (eorl) {

		case 'r':
		case 'R':
			printf("반납할 책의 S/N를 입력하세요 >>");
			scanf("%s", br.book_num);
			if (BSearch_R(&rl, &br) != -1) {

				Rental_delete(&rl, &br);
				Rental_delete(&select, &br);
				if (Save_rental(&rl)) {
					Load_book(&bl);
					strcpy(sb.book_num, br.book_num);
					num = BSearch_num(&bl, &sb);
					strcpy(bl.booklist[num].book_rental, "대여가능");
					if (Save_book(&bl)) {
						printf("반납완료");

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
				printf("없는 목록입니다.");
				_getch();
			}
			break;
		case 's':
		case 'S':
			printf("S/N를 입력하세요 >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s 는 목록에 없는 도서입니다.", br.book_num);
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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                        내     정    보                                 ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     ID      ┃   %-55s┃\n", psm.id);
	printf("┃     PW      ┃   %-55s┃\n", psm.pw);
	printf("┃    이름     ┃   %-55s┃\n", psm.name);
	printf("┃  주민 번호  ┃   %-55s┃\n", psm.s_snum);
	printf("┃ 핸드폰 번호 ┃   %-55s┃\n", psm.p_num);
	printf("┃    주소     ┃   %-55s┃\n", psm.addr);
	printf("┃    등급     ┃   %-55s┃\n", psm.rank);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃     뒤로가기: w   수정하기: u                                           ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	fflush(stdin);
	eorl = _getch();
	_getch();
	strcpy(sm.id, psm.id);
	tg = BSearch_M_id(&ml, &sm);
	switch (eorl) {
	case 'U':
	case 'u':
		printf("수정할 정보를 고르세요(1.핸드폰번호 2.주소)>>");
		scanf("%d", &num);
		if (num == 1) {
			printf("핸드폰 번호를 입력하세요>>");
			scanf("%s", ml.member_list[tg].p_num);
		}
		else if (num == 2) {
			printf("주소를 입력하세요>>");
			scanf("%s", ml.member_list[tg].addr);
		}
		else
			return;
		if (Save_member(&ml)) {
			printf("수정되었습니다.");
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
	else if ((py & 400) == 0) {
		day[2] = 29;
	}

	if (pd > day[pm] || pm < 1 || pm>12 || py < 0) {
		return -1;
	}
	//대여 2주
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