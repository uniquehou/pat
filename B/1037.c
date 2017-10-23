#include <stdio.h>

struct M {
	int G;    // 17S = 1G
	int S;    // 29K = 1S
	int K;
};

void normal(struct M *m) {
	m->G += m->S / 17;
	m->S = m->S % 17;
	m->S += m->K / 29;
	m->K = m->K % 29;
}

void normal_after(struct M *m) {
	m->G--;
	m->S += 17;
	m->S--;
	m->K += 29;
}

int main() {
	struct M m1, m2, m;
	scanf("%d.%d.%d", &m1.G, &m1.S, &m1.K);
	scanf("%d.%d.%d", &m2.G, &m2.S, &m2.K);
	
	normal_after(&m2);
	printf("%d.%d.%d\n", m2.G, m2.S, m2.K);
	m.K = m2.K - m1.K;
	m.S = m2.S - m1.S;
	m.G = m2.G - m1.G;
	printf("%d.%d.%d\n", m.G, m.S, m.K);
	normal(&m);

	printf("%d.%d.%d\n", m.G, m.S, m.K);
	return 0;
}