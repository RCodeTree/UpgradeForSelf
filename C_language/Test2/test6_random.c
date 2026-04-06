#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {

    srand((unsigned)time(NULL));                // 用当前时间初始化随机种子（只需一次）

    while(1)
    {
	int random_num = rand() % (100) + 1;
    	printf("随机数: %d\n", random_num);
	sleep(1);
    }
    return 0;
}
