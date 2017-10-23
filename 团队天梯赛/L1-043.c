#include <stdio.h>
struct Book{
	int id;    // book[i][0].id 为完整记录的个数
	int flag; //有效性，初始化为0，借或还均加1
	int start_hour;
	int start_min;
	int end_hour;
	int end_min;
}book[10][1002];

int flag[10][1002];    // 每天有效的 id

int main() {
	int day;
	scanf("%d", &day);

	for(int i=0; i<day; i++)
		book[i][0].id = 0;
	for(int i=0; i<day;) {
		int id, hour, min;
		char oper;
		scanf("%d %c %d:%d", &id, &oper, &hour, &min);
		if (id==0) {
			i++;
			continue;
		}

		if (book[i][id].flag!=1 && book[i][id].flag!=2) book[i][id].flag=0;  //初始化
		if (oper=='S'){
			book[i][id].start_hour = hour;
			book[i][id].start_min = min;
		} else {
			book[i][id].end_hour = hour;
			book[i][id].end_min = min;
		}
		if (++book[i][id].flag==2 && id>book[i][0].id) {
			flag[i][book[i][0].id] = id;  
			book[i][0].id++;
		}
	}

	for(int i=0; i<day; i++) {
		int time = 0;
		for(int j=0; j<=book[i][0].id; j++){
			int index = flag[i][j];
			time += (book[i][index].end_hour-book[i][index].start_hour)*60 + book[i][index].end_min - book[i][index].start_min;
		}
		time = book[i][0].id? time/book[i][0].id + (time%book[i][0].id!=0): 0;
		printf("%d %d\n", book[i][0].id, time);
	}
}
// 12分，差8分