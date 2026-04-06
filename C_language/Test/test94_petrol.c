#include <stdio.h>

/*
 * @brief 计算油费
 * @param choice 服务类型
 * @param price 单价
 * @param num 加油量
 */
void TypeAndTotal(char choice, float price, float num) {
    switch (choice) {
        case 'm':
            printf("油费为: %f\n", price * num * 0.05);
            break;
        case 'e':
            printf("油费为: %f\n", price * num * 0.03);
            break;
        default:
            printf("选择异常，重新选择\n");
    }
}

/*
 * @brief 主函数
 */
int main() {
    do {
        int a;
        int b;
        char c;
        printf("请分别输入加油量、汽油品种、服务类型(以空格分隔[一个]): ");
        scanf("%d %d %c", &a, &b, &c);
        switch (b) {
            case 90:
                TypeAndTotal(c, 6.95, a);
                break;
            case 93:
                TypeAndTotal(c, 7.44, a);
                break;
            case 97:
                TypeAndTotal(c, 7.93, a);
                break;
            default:
                printf("无此汽油品种，重新选择\n");
        }
    } while (1);
    return 0;
}
