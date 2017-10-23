// 差4分
#include <stdio.h>
#include <malloc.h>

#define null 0
#define INIT_SIZE 100
#define AUTO_SIZE 10
struct SqList {
	int *inventory;
	float *price;
	float *price_cell;
	int size;
	int maxsize;
};
typedef struct SqList *SqList;
struct LinkList {
	int index;
	struct LinkList *next;
};
typedef struct LinkList *LinkList;

LinkList PriceSort;
SqList cargo;

SqList CreateSqList() {
	SqList L = (SqList)malloc(sizeof(struct SqList));
	L->inventory = (int*)calloc(INIT_SIZE, sizeof(int));
	L->price = (float*)calloc(INIT_SIZE, sizeof(float));
	L->price_cell = (float*)calloc(INIT_SIZE, sizeof(float));
	L->size = 0;
	L->maxsize = INIT_SIZE;
	return L;
}

void InsertInventory(SqList L, int inventory) {
	if (L->size == L->maxsize) {
		L->maxsize += AUTO_SIZE;
		L->inventory = (int*)realloc(L->inventory, L->maxsize*sizeof(int));
		L->price = (float*)realloc(L->price, L->maxsize*sizeof(float));
		L->price_cell = (float*)realloc(L->price_cell, L->maxsize*sizeof(float));
	}
	L->inventory[L->size] = inventory;
	L->size++;
}

void InsertPrice(SqList L, float price) {
	void InsertLinkList(LinkList L, SqList cargo, float price_cell, int index);
	L->price[L->size] = price;
	L->price_cell[L->size] = price/L->inventory[L->size];
	InsertLinkList(PriceSort, cargo, L->price_cell[L->size], L->size);
	L->size++;
}

LinkList CreateLinkList() {
	LinkList L = (LinkList)malloc(sizeof(struct LinkList));
	L->next = null;
	return L;
}

void InsertLinkList(LinkList L, SqList cargo, float price_cell, int index) {
	LinkList temp = CreateLinkList();
	temp->index = index;
	LinkList UpL = L;
	for(L=L->next; L && cargo->price_cell[L->index]>price_cell; L=L->next)  UpL = L;
	temp->next = UpL->next;
	UpL->next = temp;
}


int main() {
	PriceSort = CreateLinkList();
	cargo = CreateSqList();

	int m, n, inventory;
	float price, profits=0;
	scanf("%d %d", &m, &n);
	// 读取数据并存储
	for(int i=0; i<m; i++) {
		scanf("%d", &inventory);
		InsertInventory(cargo, inventory);
	}
	cargo->size=0;
	for(int i=0; i<m; i++) {
		scanf("%f", &price);
		InsertPrice(cargo, price);
	}

	for(LinkList temp=PriceSort->next; n; temp=temp->next) {
		int TmpInventory = n>cargo->inventory[temp->index]? cargo->inventory[temp->index]: n;
		profits += TmpInventory * (cargo->price_cell[(temp->index)]);
		n -= TmpInventory;
	}
	printf("%.2f\n", profits);
	return 0;
}