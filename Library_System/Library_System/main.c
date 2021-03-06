#include <stdio.h>
#include <time.h>
#include "library.h"
#include "member.h"
#include "rental.h"

void Log_In();                     //煎斜檣 晦棟
void Member_Join();                //�蛾灠㊣� 晦棟
void booklist();                   //紫憮 UI
void memberlist();                 //�蛾� UI
void rentallist();                  //渠罹 UI
void mainlist();                   //詭檣 UI
void manager_ui();                 //婦葬濠 UI
void user_ui();                    //�蛾� UI
void join_ui();                    //�蛾灠㊣� UI
void log_ui();                     //煎斜檣 UI
void manager();                    //婦葬濠 賅萄
void book_m();                     //紫憮婦葬 晦棟
void member_m();                   //�蛾灠�葬 晦棟
void rental_m();                   //渠罹紫憮婦葬 晦棟
void insertBook();                 //紫憮蹺陛
void deleteBook();                 //紫憮餉薯
void selectBook();                 //紫憮匐儀
void updateBook();                 //紫憮熱薑
void selectBook_s(S_Book *sb);     //紫憮鼻撮匐儀
void selectMember();               //�蛾灠侄�
void deleteMember();               //�蛾艭餑�
void updateMember();               //�蛾虃鶬�
void selectMember_s(S_Member *sm); //�蛾艭騧摯侄�
void selectRental();               //渠罹跡煙 匐儀
void updateRental();               //跡煙 熱薑
void deleteRental();               //跡煙 餉薯
void selectRental_s(B_Rental *br); //渠罹跡煙 鼻撮 匐儀
void user(S_Member sm);                       //嶸盪賅萄
void bookRental(S_Member sm);                 //渠罹 晦棟
void bookReturn(S_Member sm);                 //奩陶 晦棟
void updateMember_u(S_Member psm);             //�蛾讔內� 熱薑
int Rental_Time(int *y, int *m, int *d); //渠罹 奩陶 陳瞼啗骯
void Real_Time(int *y, int *m, int *d);  //⑷營 衛除

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
void mainlist()  //詭檣 葬蝶お
{
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早     紫憮 婦葬   Щ煎斜極     早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. 煎斜檣                早\n");
	printf("早     2. �蛾灠㊣�              早\n");
	printf("早     3. 謙猿                  早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");


}

void user_ui() {
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早          ��    錳            早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. 紫憮 匐儀             早\n");
	printf("早     2. 紫憮 渠罹             早\n");
	printf("早     3. 紫憮 奩陶             早\n");
	printf("早     4. �蛾� 薑爾             早\n");
	printf("早     5. 謙猿                  早\n");
	printf("早                              早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

void log_ui() {
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早               煎     斜     檣              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

void join_ui() {
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早             ��     錳     陛     殮             早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

void manager_ui() {
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早          婦 葬 濠            早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. �� 錳 婦 葬           早\n");
	printf("早     2. 紫 憮 婦 葬           早\n");
	printf("早     3. 渠 罹 婦 葬           早\n");
	printf("早     4. 謙 猿                 早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

void booklist()  //紫憮 葬蝶お
{
	system("cls");

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早          紫 憮 婦 葬         早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. 紫 憮 匐 儀           早\n");
	printf("早     2. 紫 憮 蹺 陛           早\n");
	printf("早     3. 紫 憮 熱 薑           早\n");
	printf("早     4. 紫 憮 餉 薯           早\n");
	printf("早     5. 謙 猿                 早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

}

void memberlist()  //�蛾� 葬蝶お
{
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早         �� 錳 婦 葬          早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. �� 錳 匐 儀           早\n");
	printf("早     2. �� 錳 熱 薑           早\n");
	printf("早     3. �� 錳 餉 薯           早\n");
	printf("早     4. 謙 猿                 早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

void rentallist()  //渠罹 葬蝶お
{
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早         渠 罹 婦 葬          早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早                              早\n");
	printf("早     1. 渠 罹 跡 煙           早\n");
	printf("早     2. 跡 煙 熱 薑           早\n");
	printf("早     3. 跡 煙 餉 薯           早\n");
	printf("早     4. 謙 猿                 早\n");
	printf("早                              早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
}

//詭檣 UI 晦棟
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
		//ui 歜衛

		printf(" I D (謙猿:0) >>");
		scanf("%s", id);
		if (strcmp(id, "0") == 0) {
			return;
		}
		printf(" P W >>");
		scanf("%s", pw);

		strcpy(sm.id, id);

		log = member_select(&ml, &sm);

		if (log.list_num == 0) {
			printf("橈朝 嬴檜蛤 殮棲棻.");
			_getch();
		}
		else if (strcmp(log.member_list[0].pw, pw) != 0) {
			printf("綠塵廓�ㄧ� 棻衛 殮溘ж撮蹂");
			_getch();
		}
		else {
			if (strcmp(log.member_list[0].rank, "婦葬濠") == 0) {
				//婦葬濠 賅萄 
				manager();
				_getch();
			}
			else {
				//�蛾籪藒�
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
	printf(" 輿團廓�ㄧ� 殮溘ж撮蹂>>");
	scanf("%s", sm.s_snum);

	select = member_select(&ml, &sm);

	if (select.list_num == 0) {
		strcpy(save.s_snum, sm.s_snum);
		MemberInit(&sm);

		printf(" 嬴檜蛤蒂 殮溘ж撮蹂 >>");
		scanf("%s", sm.id);
		select = member_select(&ml, &sm);
		if (select.list_num == 0) {
			strcpy(save.id, sm.id);

			printf(" 綠塵廓�ㄧ� 殮溘ж撮蹂 >>");
			scanf("%s", save.pw);
			printf(" 檜葷擊 殮溘ж撮蹂 >>");
			scanf("%s", save.name);
			printf(" с萄ア 廓�ㄧ� 殮溘ж撮蹂 >>");
			scanf("%s", save.p_num);
			printf(" 輿模蒂 殮溘ж撮蹂 >>");
			scanf("%s", save.addr);
			strcpy(save.rank, "�蛾�");

			member_insert(&ml, &save);
			Save_member(&ml);
		}
		else {
			printf("氈朝 嬴檜蛤殮棲棻.");
		}
	}
	else {
		printf("陛殮腎橫氈蝗棲棻.");
	}
}

//婦葬濠
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

//紫憮婦葬 晦棟
void book_m()  //紫憮 匐儀 蹺陛 熱薑 餉薯
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                        紫    憮        跡    煙                        早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早     S/N        薯跡        盪濠     轎っ餌      轎っ橾        渠罹     早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		for (int i = 0;i < 10;i++) {
			if (bl.list_num <= count) break;
			printf("早  %.7s\t %.5s\t     %.5s    %.6s      %.10s\t%-8s 早\n", bl.booklist[count].book_num, bl.booklist[count].book_name,
				bl.booklist[count].book_author, bl.booklist[count].book_publisher, bl.booklist[count].book_Issue_year, bl.booklist[count].book_rental);

			count++;
		}

		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早    檜瞪む檜雖: a                                       棻擠む檜雖 :d   早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早      鼻撮爾晦: s               薑溺: r                菴煎陛晦: w      早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
			printf("S/N蒂 殮溘ж撮蹂 >>");
			BookInit(&sb);
			scanf("%s", sb.book_num);

			num = BSearch_num(&bl, &sb);
			if (num != -1)
				selectBook_s(&bl.booklist[num]);
			else {
				printf("%s 朝 橈朝 紫憮 殮棲棻.", sb.book_num);
				_getch();
			}
			count -= count % 10;
			break;
		case 'r':
		case 'R':
			printf("薑溺 晦遽擊 堅腦撮蹂\n 1.S/N  2.薯跡 3.盪濠 4.轎っ餌 5.轎っ橾 6.渠罹罹睡");
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                        鼻    撮        薑    爾                        早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早  S/N    早   %-55s    早\n", sb->book_num);
	printf("早  薯跡   早   %-55s    早\n", sb->book_name);
	printf("早  盪濠   早   %-55s    早\n", sb->book_author);
	printf("早  轎っ餌 早   %-55s    早\n", sb->book_publisher);
	printf("早  轎っ橾 早   %-55s    早\n", sb->book_Issue_year);
	printf("早  渠罹   早   %-55s    早\n", sb->book_rental);
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     菴煎陛晦: w                                                        早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	fflush(stdin);
	eorl = _getch();
	_getch();

	switch (eorl) {

	case 'w':
		return;

	}
	_getch();
}

void insertBook() //紫憮 薑爾 殮溘
{
	BList bl;
	S_Book sb;
	char eorl;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      紫    憮      蹺    陛                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("  紫憮 橾溼廓��擊 殮溘ж衛螃:");
	scanf("%s", sb.book_num);
	fflush(stdin);
	printf("  紫憮貲擊 殮溘ж衛螃:");
	scanf("%s", sb.book_name);
	fflush(stdin);
	printf("  盪濠擊 殮溘ж衛螃:");
	scanf("%s", sb.book_author);
	fflush(stdin);
	printf("  轎っ餌蒂 殮溘ж衛螃:");
	scanf("%s", sb.book_publisher);
	fflush(stdin);
	printf("  紫憮轎っ 喇紫蒂 殮溘ж衛蹂:");
	scanf("%s", sb.book_Issue_year);
	fflush(stdin);
	strcpy(sb.book_rental, "渠罹陛棟");

	book_insert(&bl, &sb);
	if (Save_book(&bl))
		printf("盪濰ц蝗棲棻.");

	else
		printf("盪濰 螃盟");

	_getch();
	return;

}

void deleteBook() //紫憮 薑爾 殮溘
{
	BList bl;
	S_Book sb;
	char eorl;

	BListInit(&bl);
	BookInit(&sb);

	Load_book(&bl);
	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      紫    憮      餉    薯                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("餉薯 紫憮曖 橾溼廓��擊 殮溘ж衛螃:");
	scanf("%s", sb.book_num);


	book_delete(&bl, &sb);
	if (Save_book(&bl))
		printf("餉薯ц蝗棲棻.");

	else
		printf("餉薯 螃盟");

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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      紫    憮      熱    薑                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("熱薑й 紫憮曖 橾溼廓��擊 殮溘ж衛螃:");
	scanf("%s", sb.book_num);
	fflush(stdin);

	num = BSearch_num(&bl, &sb);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                      紫    憮      熱    薑                     早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("  紫憮貲擊 殮溘ж衛螃:");
		scanf("%s", bl.booklist[num].book_name);
		fflush(stdin);
		printf("  盪濠擊 殮溘ж衛螃:");
		scanf("%s", bl.booklist[num].book_author);
		fflush(stdin);
		printf("  轎っ餌蒂 殮溘ж衛螃:");
		scanf("%s", bl.booklist[num].book_publisher);
		fflush(stdin);
		printf("  紫憮轎っ 喇紫蒂 殮溘ж衛蹂:");
		scanf("%s", bl.booklist[num].book_Issue_year);

		if (Save_book(&bl))
			printf("熱薑ц蝗棲棻.");
		else
			printf("熱薑 螃盟");

		_getch();
	}
	else
		printf("橈朝 紫憮殮棲棻.");

	_getch();
	return;
}

//�蛾� 婦葬 晦棟
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                        ��    錳        跡    煙                        早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早     ID             檜葷            с萄ア 廓��            蛔晝         早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");

		for (int i = 0;i < 10;) {
			if (ml.list_num <= count) break;

			if (strcmp(ml.member_list[count].rank, "婦葬濠") != 0) {
				printf("早  %-15s %-15s  %-20s    %-13s早\n", ml.member_list[count].id, ml.member_list[count].name, ml.member_list[count].p_num, ml.member_list[count].rank);
				i++;
			}

			count++;
		}

		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早    檜瞪む檜雖: a                                       棻擠む檜雖 :d   早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早      鼻撮爾晦: s               薑溺: r                菴煎陛晦: w      早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
			printf("ID蒂 殮溘ж撮蹂 >>");
			MemberInit(&sm);
			scanf("%s", sm.id);

			num = BSearch_M_id(&ml, &sm);
			if (num != -1)
				selectMember_s(&ml.member_list[num]);
			else {
				printf("%s 朝 橈朝 紫憮 殮棲棻.", sm.id);
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                        鼻    撮        薑    爾                        早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     ID      早   %-55s早\n", sm->id);
	printf("早     PW      早   %-55s早\n", sm->pw);
	printf("早    檜葷     早   %-55s早\n", sm->name);
	printf("早  輿團 廓��  早   %-55s早\n", sm->s_snum);
	printf("早 с萄ア 廓�� 早   %-55s早\n", sm->p_num);
	printf("早    輿模     早   %-55s早\n", sm->addr);
	printf("早    蛔晝     早   %-55s早\n", sm->rank);
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     菴煎陛晦: w                                                        早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      ��    錳      餉    薯                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("餉薯 �蛾衋� ID擊 殮溘ж衛螃:");
	scanf("%s", sm.id);


	member_delete(&ml, &sm);
	if (Save_member(&ml))
		printf("餉薯ц蝗棲棻.");

	else
		printf("餉薯 螃盟");

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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      ��    錳      熱    薑                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("熱薑й �蛾衋� ID擊 殮溘ж衛螃:");
	scanf("%s", sm.id);
	fflush(stdin);

	num = BSearch_M_id(&ml, &sm);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                      ��    錳      熱    薑                     早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("  綠塵廓��擊 殮溘ж衛螃:");
		scanf("%s", ml.member_list[num].pw);
		fflush(stdin);
		printf("  檜葷擊 殮溘ж衛螃:");
		scanf("%s", ml.member_list[num].name);
		fflush(stdin);
		printf("  с萄ア 廓�ㄧ� 殮溘ж衛螃:");
		scanf("%s", ml.member_list[num].p_num);
		fflush(stdin);
		printf("  輿模蒂 殮溘ж衛蹂:");
		scanf("%s", ml.member_list[num].addr);
		fflush(stdin);
		printf("  蛔晝擊 殮溘ж衛蹂:");
		scanf("%s", ml.member_list[num].rank);


		if (Save_member(&ml))
			printf("熱薑ц蝗棲棻.");
		else
			printf("熱薑 螃盟");

		_getch();
	}
	else
		printf("橈朝 �蛾衋埭炴�.");

	_getch();
	return;
}

//渠罹 婦葬 晦棟
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                        渠    罹        跡    煙                        早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早     S/N          薯跡           ID        渠罹橾        奩陶 蕨薑橾    早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		for (int i = 0;i < 10;i++) {
			if (rl.list_num <= count) break;
			printf("早   %-10s  %-14s %-10s %-15s %-15s早\n", rl.rental_list[count].book_num, rl.rental_list[count].book_name, rl.rental_list[count].user_id, rl.rental_list[count].book_rental_day
				, rl.rental_list[count].book_return_day);

			count++;
		}

		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早    檜瞪む檜雖: a                                       棻擠む檜雖 :d   早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早      鼻撮爾晦: s               薑溺: r                菴煎陛晦: w      早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
			printf("S/N蒂 殮溘ж撮蹂 >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s 朝 跡煙縑 橈朝 紫憮殮棲棻.", br.book_num);
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      跡    煙      熱    薑                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("熱薑й 跡煙曖 S/N擊 殮溘ж衛螃:");
	scanf("%s", br.book_num);
	fflush(stdin);

	num = BSearch_R(&rl, &br);

	eorl = _getch();
	_getch();

	if (num != -1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                      跡    煙      熱    薑                     早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		fflush(stdin);
		printf("奩陶蕨薑橾擊 殮溘ж撮蹂");
		scanf("%s", rl.rental_list[num].book_return_day);


		if (Save_rental(&rl))
			printf("熱薑ц蝗棲棻.");
		else
			printf("熱薑 螃盟");

		_getch();
	}
	else
		printf("橈朝 跡煙殮棲棻.");

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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                      跡    煙      餉    薯                     早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("餉薯 跡煙曖 S/N擊 殮溘ж衛螃:");
	scanf("%s", br.book_num);


	Rental_delete(&rl, &br);
	if (Save_rental(&rl))
		printf("餉薯ц蝗棲棻.");

	else
		printf("餉薯 螃盟");

	fflush(stdin);
	_getch();
	return;
}

void selectRental_s(B_Rental *br) {
	char eorl;

	system("cls");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                        鼻    撮        薑    爾                        早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早    S / N    早   %-55s早\n", br->book_num);
	printf("早    薯 跡    早   %-55s早\n", br->book_name);
	printf("早     I D     早   %-55s早\n", br->user_id);
	printf("早    渠罹橾   早   %-55s早\n", br->book_rental_day);
	printf("早    奩陶橾   早   %-55s早\n", br->book_return_day);
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     菴煎陛晦: w                                                        早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

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
		//匐儀 , 渠罹, 奩陶, 薑爾熱薑
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
		printf("渠罹й 疇曖 S/N蒂 殮溘ж撮蹂>>");
		scanf("%s", sb.book_num);
		num = BSearch_num(&bl, &sb);
		if (num) {
			if (strcmp(bl.booklist[num].book_rental, "渠罹陛棟") == 0) {
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
					strcpy(bl.booklist[num].book_rental, "渠罹醞");
					Save_book(&bl);
					printf("渠罹ц蝗棲棻.");
					_getch();
				}
				else {
					printf("盪濰 褒ぬ");
					_getch();
				}
			}
			else {
				printf("渠罹脹 紫憮殮棲棻.");
				_getch();
			}
		}
		else {
			printf("橈朝 紫憮殮棲棻.");
			_getch();
		}
	}
	else {
		printf("渠罹陛 碳陛棟м棲棻(渠罹 3掏 蟾婁)");
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
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                        渠    罹        跡    煙                        早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早     S/N          薯跡           ID        渠罹橾        奩陶 蕨薑橾    早\n");
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		for (int i = 0;i < 3;i++) {
			if (select.list_num <= count) break;
			printf("早   %-10s  %-14s %-10s %-15s %-15s早\n", select.rental_list[count].book_num, select.rental_list[count].book_name, select.rental_list[count].user_id, select.rental_list[count].book_rental_day
				, select.rental_list[count].book_return_day);

			count++;
		}

		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
		printf("早    鼻撮爾晦: s      奩陶ж晦: r      菴煎陛晦: w                       早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		eorl = '\0';

		eorl = _getch();
		_getch();

		switch (eorl) {

		case 'r':
		case 'R':
			printf("奩陶й 疇曖 S/N蒂 殮溘ж撮蹂 >>");
			scanf("%s", br.book_num);
			if (BSearch_R(&rl, &br) != -1) {

				Rental_delete(&rl, &br);
				Rental_delete(&select, &br);
				if (Save_rental(&rl)) {
					Load_book(&bl);
					strcpy(sb.book_num, br.book_num);
					num = BSearch_num(&bl, &sb);
					strcpy(bl.booklist[num].book_rental, "渠罹陛棟");
					if (Save_book(&bl)) {
						printf("奩陶諫猿");

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
				printf("橈朝 跡煙殮棲棻.");
				_getch();
			}
			break;
		case 's':
		case 'S':
			printf("S/N蒂 殮溘ж撮蹂 >>");
			RentalInit(&br);
			scanf("%s", br.book_num);

			num = BSearch_R(&rl, &br);
			if (num != -1)
				selectRental_s(&rl.rental_list[num]);
			else {
				printf("%s 朝 跡煙縑 橈朝 紫憮殮棲棻.", br.book_num);
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                        頂     薑    爾                                 早\n");
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     ID      早   %-55s早\n", psm.id);
	printf("早     PW      早   %-55s早\n", psm.pw);
	printf("早    檜葷     早   %-55s早\n", psm.name);
	printf("早  輿團 廓��  早   %-55s早\n", psm.s_snum);
	printf("早 с萄ア 廓�� 早   %-55s早\n", psm.p_num);
	printf("早    輿模     早   %-55s早\n", psm.addr);
	printf("早    蛔晝     早   %-55s早\n", psm.rank);
	printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽\n");
	printf("早     菴煎陛晦: w   熱薑ж晦: u                                           早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	fflush(stdin);
	eorl = _getch();
	_getch();
	strcpy(sm.id, psm.id);
	tg = BSearch_M_id(&ml, &sm);
	switch (eorl) {
	case 'U':
	case 'u':
		printf("熱薑й 薑爾蒂 堅腦撮蹂(1.с萄ア廓�� 2.輿模)>>");
		scanf("%d", &num);
		if (num == 1) {
			printf("с萄ア 廓�ㄧ� 殮溘ж撮蹂>>");
			scanf("%s", ml.member_list[tg].p_num);
		}
		else if (num == 2) {
			printf("輿模蒂 殮溘ж撮蹂>>");
			scanf("%s", ml.member_list[tg].addr);
		}
		else
			return;
		if (Save_member(&ml)) {
			printf("熱薑腎歷蝗棲棻.");
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
	//渠罹 2輿
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