#include <stdio.h>
#include <malloc.h>
typedef struct Set{
	int *data[2];
	int length;
}Set;
typedef struct SetList{
	Set *set[2];
	int length;
}SetList;

void InitSetList(SetList *SL, int set_count) {
	SL = (SetList *)malloc(sizeof(SetList));
	SL.set = realloc(SL.set, set_count * sizeof(Set));
}

int main() {
	SetList * SL;
	int set_count;
	scanf("%d", &set_count);
	InitSetList(SL, set_count);
	return 0;
}