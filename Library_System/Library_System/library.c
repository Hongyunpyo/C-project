#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int BSearch_num(BList *plist, S_Book *pbook);//이중탐색
int Partition(BList *plist, int left, int right, char select[]);//퀵정렬
void swap(BList *plist, int ch1, int ch2);//퀵정렬

void BListInit(BList * plist) {
	plist->list_num = 0;
}

void BookInit(S_Book * pbook) {
	pbook->book_author[0] = '\0';
	pbook->book_Issue_year[0] = '\0';
	pbook->book_name[0] = '\0';
	pbook->book_num[0] = '\0';
	pbook->book_publisher[0] = '\0';
	pbook->book_rental[0] = '\0';
}

void book_insert(BList *plist, S_Book *pbook) {

	Qsort_book(plist, 0, plist->list_num - 1, "num");

	if (BSearch_num(plist, pbook) == -1) {
		int num = plist->list_num;

		plist->booklist[num] = *pbook;
		plist->list_num = num + 1;

		Qsort_book(plist, 0, plist->list_num - 1, "num");
	}
	else
		printf("중복 도서입니다.");
}

S_Book book_delete(BList *plist, S_Book *pbook) {
	S_Book value;
	int num;

	Qsort_book(plist, 0, plist->list_num - 1, "num");
	num = BSearch_num(plist, pbook);
	value = plist->booklist[num];

	for (int i = num;i < plist->list_num;i++) {
		plist->booklist[i] = plist->booklist[i + 1];
	}
	plist->list_num -= 1;

	return value;
}

S_Book book_update(BList *plist, S_Book *pbook) {
	S_Book value;
	int num;

	Qsort_book(plist, 0, plist->list_num - 1, "num");
	num = BSearch_num(plist, pbook);
	value = plist->booklist[num];

	plist->booklist[num] = *pbook;

	return value;
}


BList book_select(BList *plist, S_Book *pbook) {
	BList re = *plist;

	if (pbook->book_name[0] != '\0') {
		Quest_book(&re, pbook, "name");
	}
	if (pbook->book_author[0] != '\0') {
		Quest_book(&re, pbook, "author");
	}
	if (pbook->book_publisher[0] != '\0') {
		Quest_book(&re, pbook, "publisher");
	}
	if (pbook->book_Issue_year[0] != '\0') {
		Quest_book(&re, pbook, "Issue_year");
	}
	if (pbook->book_num[0] != '\0') {
		Quest_book(&re, pbook, "num");
	}
	if (pbook->book_rental[0] != '\0') {
		Quest_book(&re, pbook, "rental");
	}

	return re;
}

int B_LCount(BList * plist) {
	return plist->list_num;
}

void Qsort_book(BList *plist, int left, int right, char select[])
{
	;	if (left <= right)
	{
		int part = Partition(plist, left, right, select);
		Qsort_book(plist, left, part - 1, select);
		Qsort_book(plist, part + 1, right, select);
	}
}


void Quest_book(BList *plist, S_Book *pbook, char select[]) {

	BList re;
	S_Book cp;
	char ch1[100], ch2[100];

	BListInit(&re);

	for (int i = 0;i < plist->list_num;i++) {

		if (strcmp(select, "num") == 0) {
			strcpy(ch1, plist->booklist[i].book_num);
			strcpy(ch2, pbook->book_num);
		}
		else if (strcmp(select, "name") == 0) {
			strcpy(ch1, plist->booklist[i].book_name);
			strcpy(ch2, pbook->book_name);
		}
		else if (strcmp(select, "author") == 0) {
			strcpy(ch1, plist->booklist[i].book_author);
			strcpy(ch2, pbook->book_author);
		}
		else if (strcmp(select, "publisher") == 0) {
			strcpy(ch1, plist->booklist[i].book_publisher);
			strcpy(ch2, pbook->book_publisher);
		}
		else if (strcmp(select, "Issue_year") == 0) {
			strcpy(ch1, plist->booklist[i].book_Issue_year);
			strcpy(ch2, pbook->book_Issue_year);
		}
		else if (strcmp(select, "rental") == 0) {
			strcpy(ch1, plist->booklist[i].book_rental);
			strcpy(ch2, pbook->book_rental);
		}
		else
			printf("quest_book err!");

		if (strcmp(ch1, ch2) == 0) {
			cp = plist->booklist[i];
			book_insert(&re, &cp);
		}
	}

	*plist = re;

}



void swap(BList *plist, int ch1, int ch2) {

	S_Book temp;

	temp = plist->booklist[ch1];
	plist->booklist[ch1] = plist->booklist[ch2];
	plist->booklist[ch2] = temp;

}

int Partition(BList *plist, int left, int right, char select[]) {
	int part = left;
	int low = left + 1;
	int high = right;
	while (low <= high) {
		if (strcmp(select, "num") == 0) {
			while (strcmp(plist->booklist[part].book_num, plist->booklist[low].book_num) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_num, plist->booklist[high].book_num) != 1
				&& high >= (left + 1))
				high--;

		}
		else if (strcmp(select, "name") == 0) {
			while (strcmp(plist->booklist[part].book_name, plist->booklist[low].book_name) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_name, plist->booklist[high].book_name) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "author") == 0) {
			while (strcmp(plist->booklist[part].book_author, plist->booklist[low].book_author) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_author, plist->booklist[high].book_author) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "publisher") == 0) {
			while (strcmp(plist->booklist[part].book_publisher, plist->booklist[low].book_publisher) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_publisher, plist->booklist[high].book_publisher) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "Issue_year") == 0) {
			while (strcmp(plist->booklist[part].book_Issue_year, plist->booklist[low].book_Issue_year) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_Issue_year, plist->booklist[high].book_Issue_year) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "rental") == 0) {
			while (strcmp(plist->booklist[part].book_rental, plist->booklist[low].book_rental) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->booklist[part].book_rental, plist->booklist[high].book_rental) != 1
				&& high >= (left + 1))
				high--;
		}
		else printf("partition err!");

		if (low <= high)
			swap(plist, low, high);

	}

	swap(plist, part, high);
	return high;
}

int BSearch_num(BList *plist, S_Book *pbook) {

	int first = 0;
	int last = plist->list_num - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (strcmp(plist->booklist[mid].book_num, pbook->book_num) == 0)
		{
			return mid;
		}
		else
		{
			if (strcmp(pbook->book_num, plist->booklist[mid].book_num) != 1)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int Load_book(BList *plist) {
	FILE *fp = NULL;
	S_Book re;
	fp = fopen("booklist.txt", "r");
	if (plist->list_num != 0) BListInit(plist);
	BookInit(&re);
	while (EOF != fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\n", re.book_num, re.book_name, re.book_author, re.book_publisher, re.book_Issue_year, re.book_rental)) {

		book_insert(plist, &re);
		BookInit(&re);
	}

	fclose(fp);
	Qsort_book(plist, 0, plist->list_num - 1, "num");
	return 1;

}

int Save_book(BList *plist) {


	FILE *fp = NULL;

	fp = fopen("booklist.txt", "w");
	Qsort_book(plist, 0, plist->list_num - 1, "num");
	for (int i = 0;i < plist->list_num;i++) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\n",
			plist->booklist[i].book_num, plist->booklist[i].book_name, plist->booklist[i].book_author,
			plist->booklist[i].book_publisher, plist->booklist[i].book_Issue_year, plist->booklist[i].book_rental);
	}

	fclose(fp);

	return 1;
}

