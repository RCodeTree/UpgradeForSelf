#include <stdio.h>

/**
 * 函数名：check_speed_violation
 * 功能：根据车速和限速自动判别机动车的处理
 * 参数：speed - 当前车速(km/h)
 *        limit - 限速值(km/h)
 * 返回值：处理结果代码
 *          0: 正常行驶
 *          1: 罚款200元
 *          2: 吊销驾驶证
 */
int check_speed_violation(float speed, float limit) {
    // 计算超速百分比
    float exceed_percentage = ((speed - limit) / limit) * 100;

    if (exceed_percentage >= 50) {
        return 2; // 达到或超出50%，吊销驾驶证
    } else if (exceed_percentage >= 10) {
        return 1; // 达到或超出10%，罚款200元
    } else {
        return 0; // 正常行驶
    }
}

/**
 * 函数名：main
 * 功能：主函数，用于获取用户输入并调用判断函数
 * 参数：无
 * 返回值：0 - 程序正常结束
 */
int main() {
    float speed, limit;

    printf("=== 高速公路机动车超速处理判别程序 ===\n");
    printf("请输入当前车速(km/h): ");
    scanf("%f", &speed);
    printf("请输入本车道限速(km/h): ");
    scanf("%f", &limit);

    // 输入验证
    if (speed < 0 || limit <= 0) {
        printf("错误：车速和限速必须为正数！\n");
        return 1;
    }

    int result = check_speed_violation(speed, limit);
    float exceed_percentage = ((speed - limit) / limit) * 100;

    printf("\n=== 处理结果 ===\n");
    printf("当前车速: %.1f km/h\n", speed);
    printf("限速: %.1f km/h\n", limit);
    printf("超速: %.1f%%\n", exceed_percentage);

    switch (result) {
        case 0:
            printf("处理结果: 正常行驶，无处罚\n");
            break;
        case 1:
            printf("处理结果: 罚款200元（达到或超出限速10%%）\n");
            break;
        case 2:
            printf("处理结果: 吊销驾驶证（达到或超出限速50%%）\n");
            break;
        default:
            printf("处理结果: 未知错误\n");
            break;
    }

    return 0;
}
