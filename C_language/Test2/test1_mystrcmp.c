#include <stdio.h>
#include <string.h>

/*
 * 功能：模仿标准库strcmp函数，比较两个字符串
 * 参数：str1 - 第一个字符串，str2 - 第二个字符串
 * 返回值：
 *   < 0: str1 < str2
 *   = 0: str1 == str2
 *   > 0: str1 > str2
 */
int my_strcmp(const char *str1, const char *str2)
{
    // 逐个字符比较，直到遇到不同字符或字符串结束
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    
    // 返回字符差值
    return *str1 - *str2;
}

int main()
{
    char str1[100], str2[100];
    int choice;
    
    printf("=== my_strcmp 函数测试程序 ===\n");
    
    do {
        printf("\n请选择操作：\n");
        printf("1. 比较两个字符串\n");
        printf("2. 查看函数说明\n");
        printf("3. 退出程序\n");
        printf("请选择 (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("输入错误，请输入数字！\n");
            while (getchar() != '\n'); // 清空输入缓冲区
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("\n请输入第一个字符串: ");
                scanf("%s", str1);
                printf("请输入第二个字符串: ");
                scanf("%s", str2);
                
                int my_result = my_strcmp(str1, str2);
                int std_result = strcmp(str1, str2);
                
                printf("\n=== 比较结果 ===\n");
                printf("字符串1: '%s'\n", str1);
                printf("字符串2: '%s'\n", str2);
                printf("my_strcmp 结果: %d\n", my_result);
                printf("strcmp    结果: %d\n", std_result);
                
                // 解释结果含义
                if (my_result < 0) {
                    printf("结果解释: 字符串1 < 字符串2\n");
                } else if (my_result > 0) {
                    printf("结果解释: 字符串1 > 字符串2\n");
                } else {
                    printf("结果解释: 字符串1 == 字符串2\n");
                }
                
                // 验证结果是否一致
                if ((my_result < 0 && std_result < 0) || 
                    (my_result == 0 && std_result == 0) || 
                    (my_result > 0 && std_result > 0)) {
                    printf("✓ 与标准库结果一致\n");
                } else {
                    printf("✗ 与标准库结果不一致\n");
                }
                
                // 显示字符比较过程
                printf("\n=== 字符比较过程 ===\n");
                int i = 0;
                while (str1[i] && str2[i] && str1[i] == str2[i]) {
                    printf("位置 %d: '%c'(%d) == '%c'(%d) → 继续\n", 
                           i, str1[i], str1[i], str2[i], str2[i]);
                    i++;
                }
                
                if (str1[i] || str2[i]) {
                    printf("位置 %d: '%c'(%d) != '%c'(%d) → 返回 %d - %d = %d\n", 
                           i, str1[i], str1[i], str2[i], str2[i], 
                           str1[i], str2[i], my_result);
                } else {
                    printf("所有字符都相等，字符串完全相同\n");
                }
                break;
                
            case 2:
                printf("\n=== 函数说明 ===\n");
                printf("my_strcmp 函数模仿标准库的 strcmp 函数\n");
                printf("功能: 比较两个字符串\n");
                printf("返回值含义:\n");
                printf("  < 0: 字符串1 < 字符串2\n");
                printf("  = 0: 字符串1 == 字符串2\n");
                printf("  > 0: 字符串1 > 字符串2\n");
                printf("\n比较规则: 逐个字符比较ASCII码值\n");
                printf("示例: 'bus' 与 'book' 比较过程:\n");
                printf("  'b' == 'b' → 继续\n");
                printf("  'u' != 'o' → 返回 'u'(117) - 'o'(111) = 6\n");
                break;
                
            case 3:
                printf("程序退出，谢谢使用！\n");
                break;
                
            default:
                printf("无效选择，请输入 1-3 之间的数字！\n");
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}