#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

int BSearch_M_id(MList *plist, S_Member *pmb);
int BSearch_M_snum(MList *plist, S_Member *pmb);
void swap_m(MList *plist, int ch1, int ch2);
int Partition_m(MList *plist, int left, int right, char select[]);

void MListInit(MList * plist) {
	plist->list_num = 0;
}

void MemberInit(S_Member * pmb) {
	pmb->addr[0] = '\0';
	pmb->id[0] = '\0';
	pmb->name[0] = '\0';
	pmb->pw[0] = '\0';
	pmb->p_num[0] = '\0';
	pmb->rank[0] = '\0';
	pmb->s_snum[0] = '\0';
}

void member_insert(MList *plist, S_Member *pmb) {

	Qsort_member(plist, 0, plist->list_num - 1, "s_snum");

	if (BSearch_M_snum(plist, pmb) == -1) {
		Qsort_member(plist, 0, plist->list_num - 1, "id");
		if (BSearch_M_id(plist, pmb) == -1) {

			int num = plist->list_num;

			plist->member_list[num] = *pmb;
			plist->list_num = num + 1;
		}
		else
			printf("중복 아이디");
	}
	else
		printf("중복 회원");
}

S_Member member_delete(MList *plist, S_Member *pmb) {

	S_Member value;
	int num;

	Qsort_member(plist, 0, plist->list_num - 1, "id");
	num = BSearch_M_id(plist, pmb);

	value = plist->member_list[num];

	if (num != -1) {
		for (int i = num;i < plist->list_num;i++) {
			plist->member_list[i] = plist->member_list[i + 1];
		}
		plist->list_num -= 1;
	}

	return value;
}

S_Member member_update(MList *plist, S_Member *pmb) {
	S_Member value;

	int num;

	Qsort_member(plist, 0, plist->list_num - 1, "id");
	num = BSearch_M_id(plist, pmb);

	value = plist->member_list[num];

	plist->member_list[num] = *pmb;

	return value;
}

MList member_select(MList *plist, S_Member *pmb) {

	MList re = *plist;

	if (pmb->id[0] != '\0') {
		Quest_member(&re, pmb, "id");
	}
	if (pmb->name[0] != '\0') {
		Quest_member(&re, pmb, "name");
	}
	if (pmb->s_snum[0] != '\0') {
		Quest_member(&re, pmb, "s_snum");
	}
	if (pmb->p_num[0] != '\0') {
		Quest_member(&re, pmb, "p_num");
	}
	if (pmb->addr[0] != '\0') {
		Quest_member(&re, pmb, "addr");
	}
	if (pmb->rank[0] != '\0') {
		Quest_member(&re, pmb, "rank");
	}

	return re;
}

int M_LCount(MList * plist) {
	return plist->list_num;
}

void Qsort_member(MList *plist, int left, int right, char select[]) {

	if (left <= right)
	{
		int part = Partition_m(plist, left, right, select);
		Qsort_member(plist, left, part - 1, select);
		Qsort_member(plist, part + 1, right, select);
	}
}

void Quest_member(MList *plist, S_Member *pmb, char select[]) {
	MList re;
	S_Member cp;
	char ch1[100], ch2[100];

	MListInit(&re);
	MemberInit(&cp);


	for (int i = 0;i < plist->list_num;i++) {

		if (strcmp(select, "id") == 0) {
			strcpy(ch1, plist->member_list[i].id);
			strcpy(ch2, pmb->id);
		}
		else if (strcmp(select, "name") == 0) {
			strcpy(ch1, plist->member_list[i].name);
			strcpy(ch2, pmb->name);
		}
		else if (strcmp(select, "s_snum") == 0) {

			strcpy(ch1, plist->member_list[i].s_snum);
			strcpy(ch2, pmb->s_snum);
		}
		else if (strcmp(select, "p_num") == 0) {
			strcpy(ch1, plist->member_list[i].p_num);
			strcpy(ch2, pmb->p_num);
		}
		else if (strcmp(select, "addr") == 0) {
			strcpy(ch1, plist->member_list[i].addr);
			strcpy(ch2, pmb->addr);
		}
		else if (strcmp(select, "rank") == 0) {
			strcpy(ch1, plist->member_list[i].rank);
			strcpy(ch2, pmb->rank);
		}
		else {

		}

		if (strcmp(ch1, ch2) == 0) {
			cp = plist->member_list[i];
			member_insert(&re, &cp);
		}

	}

	*plist = re;
}




void swap_m(MList *plist, int ch1, int ch2) {

	S_Member temp;

	temp = plist->member_list[ch1];
	plist->member_list[ch1] = plist->member_list[ch2];
	plist->member_list[ch2] = temp;

}

int Partition_m(MList *plist, int left, int right, char select[]) {
	int part = left;
	int low = left + 1;
	int high = right;
	while (low <= high) {
		if (strcmp(select, "id") == 0) {
			while (strcmp(plist->member_list[part].id, plist->member_list[low].id) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].id, plist->member_list[high].id) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "name") == 0) {
			while (strcmp(plist->member_list[part].name, plist->member_list[low].name) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].name, plist->member_list[high].name) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "s_snum") == 0) {
			while (strcmp(plist->member_list[part].s_snum, plist->member_list[low].s_snum) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].s_snum, plist->member_list[high].s_snum) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "p_num") == 0) {
			while (strcmp(plist->member_list[part].p_num, plist->member_list[low].p_num) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].p_num, plist->member_list[high].p_num) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "addr") == 0) {
			while (strcmp(plist->member_list[part].addr, plist->member_list[low].addr) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].addr, plist->member_list[high].addr) != 1
				&& high >= (left + 1))
				high--;
		}
		else if (strcmp(select, "rank") == 0) {
			while (strcmp(plist->member_list[part].rank, plist->member_list[low].rank) != -1
				&& low <= right)
				low++;

			while (strcmp(plist->member_list[part].rank, plist->member_list[high].rank) != 1
				&& high >= (left + 1))
				high--;
		}
		else printf("partition err!");

		if (low <= high)
			swap_m(plist, low, high);

	}

	swap_m(plist, part, high);
	return high;
}

int BSearch_M_id(MList *plist, S_Member *pmb) {

	int first = 0;
	int last = plist->list_num - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (strcmp(plist->member_list[mid].id, pmb->id) == 0)
		{
			return mid;
		}
		else
		{
			if (strcmp(pmb->id, plist->member_list[mid].id) != 1)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	return -1;
}

int BSearch_M_snum(MList *plist, S_Member *pmb) {

	int first = 0;
	int last = plist->list_num - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (strcmp(plist->member_list[mid].s_snum, pmb->s_snum) == 0)
		{
			return mid;
		}
		else
		{
			if (strcmp(pmb->s_snum, plist->member_list[mid].s_snum) != 1)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return -1;
}

int Load_member(MList *plist) {
	FILE *fp = NULL;
	S_Member re;
	fp = fopen("memberlist.txt", "r");
	if (plist->list_num != 0) MListInit(plist);
	MemberInit(&re);
	while (EOF != fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", re.id, re.pw,
		re.name, re.s_snum, re.p_num, re.addr, re.rank)) {

		member_insert(plist, &re);
		MemberInit(&re);
	}

	fclose(fp);
	Qsort_member(plist, 0, plist->list_num - 1, "id");
	return 1;
}

int Save_member(MList *plist) {


	FILE *fp = NULL;

	fp = fopen("memberlist.txt", "w");
	//Qsort_member(plist, 0, plist->list_num - 1, "id");
	for (int i = 0;i < plist->list_num;i++) {
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			plist->member_list[i].id, plist->member_list[i].pw, plist->member_list[i].name,
			plist->member_list[i].s_snum, plist->member_list[i].p_num, plist->member_list[i].addr,
			plist->member_list[i].rank);
	}

	fclose(fp);

	return 1;
}