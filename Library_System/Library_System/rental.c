#include <stdio.h>
#include <stdlib.h>
#include "rental.h"


void RListInit(RList * plist) {
	plist->list_num = 0;
}

void RentalInit(B_Rental * pr) {
	pr->user_id[0] = '\0';
	pr->book_num[0] = '\0';
	pr->book_name[0] = '\0';
	pr->book_rental_day[0] = '\0';
	pr->book_return_day[0] = '\0';
}

void Rental_insert(RList *plist, B_Rental *pr) {

	Qsort_rental(plist, 0, plist->list_num - 1, "book_num");
	if (BSearch_R(plist, pr) == -1) {

		int num = plist->list_num;

		plist->rental_list[num] = *pr;
		plist->list_num = num + 1;
	}
	else
		printf("이미 대여된 도서입니다.");

}

B_Rental Rental_delete(RList *plist, B_Rental *pr) {
	B_Rental value;
	int num;

	Qsort_rental(plist, 0, plist->list_num - 1, "book_num");
	num = BSearch_R(plist, pr);

	value = plist->rental_list[num];

	for (int i = num;i < plist->list_num;i++) {
		plist->rental_list[i] = plist->rental_list[i + 1];
	}
	plist->list_num -= 1;

	return value;
}

B_Rental Rental_update(RList *plist, B_Rental *pr) {
	B_Rental value;

	int num;

	Qsort_rental(plist, 0, plist->list_num - 1, "book_num");
	num = BSearch_R(plist, pr);
	value = plist->rental_list[num];

	plist->rental_list[num] = *pr;

	return value;
}

RList Rental_select(RList *plist, B_Rental *pmb) {
	RList re = *plist;

	if (pmb->user_id[0] != '\0') {
		Quest_rental(&re, pmb, "user_id");
	}
	if (pmb->book_num[0] != '\0') {
		Quest_rental(&re, pmb, "book_num");
	}
	if (pmb->book_name[0] != '\0') {
		Quest_rental(&re, pmb, "book_name");
	}
	if (pmb->book_rental_day[0] != '\0') {
		Quest_rental(&re, pmb, "rental_day");
	}
	if (pmb->book_return_day[0] != '\0') {
		Quest_rental(&re, pmb, "return_day");
	}

	return re;
}

int R_LCount(RList * plist) {
	return plist->list_num;
}

void Qsort_rental(RList *plist, int left, int right, char select[]) {

	if (left <= right)
	{
		int part = Partition_R(plist, left, right, select);
		Qsort_rental(plist, left, part - 1, select);
		Qsort_rental(plist, part + 1, right, select);

	}
}

void Quest_rental(RList *plist, B_Rental *pr, char select[]) {
	RList re;
	B_Rental cp;
	char ch1[100], ch2[100];

	RListInit(&re);

	for (int i = 0;i < plist->list_num;i++) {

		if (strcmp(select, "user_id") == 0) {

			strcpy(ch1, plist->rental_list[i].user_id);
			strcpy(ch2, pr->user_id);
		}
		else if (strcmp(select, "book_num") == 0) {

			strcpy(ch1, plist->rental_list[i].book_num);
			strcpy(ch2, pr->book_num);
		}
		else if (strcmp(select, "book_name") == 0) {
			strcpy(ch1, plist->rental_list[i].book_name);
			strcpy(ch2, pr->book_name);
		}
		else if (strcmp(select, "rental_day") == 0) {
			strcpy(ch1, plist->rental_list[i].book_rental_day);
			strcpy(ch2, pr->book_rental_day);
		}
		else if (strcmp(select, "return_day") == 0) {
			strcpy(ch1, plist->rental_list[i].book_return_day);
			strcpy(ch2, pr->book_return_day);
		}
		else {

		}

		if (strcmp(ch1, ch2) == 0) {
			cp = plist->rental_list[i];
			Rental_insert(&re, &cp);
		}
	}

	*plist = re;
}


int BSearch_R(RList *plist, B_Rental *pr) {
	int first = 0;
	int last = plist->list_num - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (strcmp(plist->rental_list[mid].book_num, pr->book_num) == 0)
		{
			return mid;
		}
		else
		{
			if (strcmp(pr->book_num, plist->rental_list[mid].book_num) != 1)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int Partition_R(RList *plist, int left, int right, char select[]) {
	int part = left;
	int low = left + 1;
	int high = right;

	while (low <= high) {

		if (strcmp(select, "user_id") == 0) {
			while (strcmp(plist->rental_list[part].user_id, plist->rental_list[low].user_id) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->rental_list[part].user_id, plist->rental_list[high].user_id) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "book_num") == 0) {

			while (strcmp(plist->rental_list[part].book_num, plist->rental_list[low].book_num) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->rental_list[part].book_num, plist->rental_list[high].book_num) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "book_name") == 0) {
			while (strcmp(plist->rental_list[part].book_name, plist->rental_list[low].book_name) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->rental_list[part].book_name, plist->rental_list[high].book_name) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "rental_day") == 0) {
			while (strcmp(plist->rental_list[part].book_rental_day, plist->rental_list[low].book_rental_day) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->rental_list[part].book_return_day, plist->rental_list[high].book_return_day) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "return_day") == 0) {
			while (strcmp(plist->rental_list[part].book_return_day, plist->rental_list[low].book_return_day) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->rental_list[part].book_return_day, plist->rental_list[high].book_return_day) != 1
				&& high >= (left + 1))
				high--;
		}
		else printf("partition err!");

		if (low <= high)
			swap_R(plist, low, high);
	}

	swap_R(plist, part, high);
	return high;
}

void swap_R(RList *plist, int ch1, int ch2) {

	B_Rental temp;

	temp = plist->rental_list[ch1];
	plist->rental_list[ch1] = plist->rental_list[ch2];
	plist->rental_list[ch2] = temp;
}

int Load_rental(RList *plist) {
	FILE *fp = NULL;
	B_Rental re;
	fp = fopen("rentallist.txt", "r");
	if (plist->list_num != 0) RListInit(plist);
	RentalInit(&re);
	while (EOF != fscanf(fp, "%s\t%s\t%s\t%s\t%s\n", re.user_id, re.book_num, re.book_name,
		re.book_rental_day, re.book_return_day)) {
		Rental_insert(plist, &re);
		RentalInit(&re);
	}

	fclose(fp);
	Qsort_rental(plist, 0, plist->list_num - 1, "book_num");
	return 1;
}

int Save_rental(RList *plist) {


	FILE *fp = NULL;

	fp = fopen("rentallist.txt", "w");
	Qsort_rental(plist, 0, plist->list_num - 1, "book_num");
	for (int i = 0;i < plist->list_num;i++) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\n",
			plist->rental_list[i].user_id, plist->rental_list[i].book_num, plist->rental_list[i].book_name,
			plist->rental_list[i].book_rental_day, plist->rental_list[i].book_return_day);
	}

	fclose(fp);

	return 1;
}