// 模拟用户登录场景，并且只能登录三次(三次密码校验)
#include <stdio.h>
#include <string.h>
int main()
{
	char password[] = "123456";
	char input[20];

	for (int i = 0; i < 3; i++)
	{
		printf("请输入密码(%d/3)> ", i + 1);
		scanf("%s", input);

		if (strcmp(password, input) == 0)
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误(%d/3)\n", i + 1);
		}
	}

	return 0;
}
