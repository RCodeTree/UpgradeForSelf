/*
喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。
money ---- 钱

cola ---- 汽水

empty ---- 空瓶

20 money ----> 20 cola, 20 empty

----> 10 cola, 10 empty

----> 5 cola, 5 empty(兑换后余：1 empty)

----> 2 cola, 2 empty + 1 empty（兑换后余：1 empty）

----> 1 cola, 1 empty + 1 empty

----> 1 cola, 1 empty

cola = 20 + 10 + 5 + 2 + 1 + 1 = 39
*/
#include <stdio.h>
int main()
{
	int money = 20;
	int cola = money;
	int empty = money;

	while (empty >= 2)
	{
		cola += (empty / 2);

		empty = (empty / 2) + (empty % 2);
	}

	printf("%d 元能换 %d 个可乐\n", money, cola);

	return 0;
}
