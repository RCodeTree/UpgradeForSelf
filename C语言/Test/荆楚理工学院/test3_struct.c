struct Book
{
	char name[100];
	float price;
} books[5];


// 计算平均价格
float GetAvgForBook(float total)
{
	float avg = total / 5;
	return avg;
}

// 获取最大值
struct Book GetMaxForBook()
{
	 /*
           *  获取价格最高的书籍
          */
          // 1. 先做升序排序
          for (int i = 0; i < 4; i++)
          {
                  for (int j = 0; j < 4 - i; j++)
                  {
                          if (books[j].price > books[j + 1].price)
                          {
                                  struct Book temp = books[j];
                                  books[j] = books[j + 1];
                                  books[j + 1] = temp;
                          }
                  }
          }
          // 2. 返回最大值
	  return books[4];
 
}

#include <stdio.h>
int main()
{
	float total; // 书本总价格
	float maxPrice; // 书籍价格最大值


	printf("=====欢迎来到图书管理系统=====\n");

	// 获取书籍
	for (int i = 0; i < 5; i++) {
		// 获取书名和价格
		printf("请输入第%d本书的书名和价格(使用空格做间隔输入):\n", i + 1);
		scanf("%s %f",  books[i].name, &books[i].price);
		
		// 计算总价格
		total += books[i].price;
	}

	// 计算并输出平均价格
	float avg = GetAvgForBook(total);
	printf("书籍的平均价格为: %f\n", avg);

	// 输出最大值
	struct Book maxBook = GetMaxForBook();
	printf("价格最高的书籍的名称和价格分别为: %s %f\n", maxBook.name, maxBook.price);


	return 0;
}
