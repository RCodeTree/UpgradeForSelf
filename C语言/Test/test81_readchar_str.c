#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int correct_answers = 0;
    
    while (1) {
        gets(input);
        if (input[0] == '#') {
            break;
        }
        
        int a, b, c;
        char op;
        
        // 从字符数组中解析字符
        sscanf(input, "%d%c%d=%c", &a, &op, &b, &c);
        
        if (op == '+') {
            if (c != '?' && c == (a + b)) {
                correct_answers++;
            }
        } else if (op == '-') {
            if (c != '?' && c == (a - b)) {
                correct_answers++;
            }
        }
    }
    
    printf("%d", correct_answers);
    return 0;
}
