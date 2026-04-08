#include <stdio.h>
#include <string.h>

void cpy(char* s, char* t, int index)
{
	char* p1 = s; p1 = p1 + index;
	while (*t)
	{
		*p1 = *t;
		p1++;
		t++;
	}
	*p1 = '\0';
}
int main()
{
	char s[100], t[100];
	int index;
	scanf("%s", s);
	scanf("%s", t);
	scanf("%d", &index);
	printf("复制前：%s\n", s);
	cpy(s, t, index);
	printf("复制后：%s\n", s);
	return 0;
}
