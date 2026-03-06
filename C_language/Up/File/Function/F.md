# C语言文件操作函数详解

## 一、文件操作基础

### 1. 打开文件 - fopen()

#### 原型
```c
FILE *fopen(const char *filename, const char *mode);
```

#### 参数解释
- `filename`：要打开的文件名（包含路径）
- `mode`：打开模式（如"r", "w", "rb"等）

#### 作用
- 打开指定文件
- 返回文件指针，失败返回NULL

#### 常用打开模式
| 模式 | 含义 |
|------|------|
| "r" | 只读模式，文件必须存在 |
| "w" | 写入模式，创建新文件或覆盖已有文件 |
| "a" | 追加模式，在文件末尾写入 |
| "r+" | 读写模式，文件必须存在 |
| "w+" | 读写模式，创建新文件或覆盖已有文件 |
| "a+" | 读写模式，在文件末尾写入 |
| "rb" | 二进制只读模式，文件必须存在 |
| "wb" | 二进制写入模式，创建新文件或覆盖已有文件 |
| "ab" | 二进制追加模式，在文件末尾写入 |
| "rb+" | 二进制读写模式，文件必须存在 |
| "wb+" | 二进制读写模式，创建新文件或覆盖已有文件 |
| "ab+" | 二进制读写模式，在文件末尾写入 |

#### 示例
```c
FILE *fp = fopen("file.txt", "r");
if (fp == NULL) {
    perror("文件打开失败");
    exit(EXIT_FAILURE);
}
```

### 2. 关闭文件 - fclose()

#### 原型
```c
int fclose(FILE *stream);
```

#### 参数解释
- `stream`：要关闭的文件指针

#### 作用
- 关闭打开的文件
- 成功返回0，失败返回EOF

#### 示例
```c
fclose(fp);
```

## 二、文件读写操作

### 1. 字符读写

#### fgetc() - 读取字符
```c
int fgetc(FILE *stream);
```

#### 参数解释
- `stream`：要读取的文件指针

#### 示例
```c
// 逐个字符读取文件内容
int ch;
while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);  // 输出字符
}
```

#### fputc() - 写入字符
```c
int fputc(int c, FILE *stream);
```

#### 参数解释
- `c`：要写入的字符（ASCII码）
- `stream`：要写入的文件指针

#### 示例
```c
// 写入字符串到文件
const char *str = "Hello, World!\n";
for (int i = 0; str[i] != '\0'; i++) {
    fputc(str[i], fp);  // 逐个字符写入
}
```

### 2. 字符串读写

#### fgets() - 读取字符串
```c
char *fgets(char *str, int num, FILE *stream);
```

#### 参数解释
- `str`：存储读取字符串的缓冲区
- `num`：读取的最大字符数（包括终止符）
- `stream`：要读取的文件指针

#### 示例
```c
// 逐行读取文件内容
char buffer[1024];
while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);  // 输出一行内容
}
```

#### fputs() - 写入字符串
```c
int fputs(const char *str, FILE *stream);
```

#### 参数解释
- `str`：要写入的字符串
- `stream`：要写入的文件指针

#### 示例
```c
// 写入多行文本到文件
fputs("第一行文本\n", fp);
fputs("第二行文本\n", fp);
fputs("第三行文本\n", fp);
```

### 3. 格式化读写

#### fprintf() - 格式化写入
```c
int fprintf(FILE *stream, const char *format, ...);
```

#### 参数解释
- `stream`：要写入的文件指针
- `format`：格式化字符串
- `...`：可变参数列表，对应格式化字符串中的占位符

#### 示例
```c
// 写入格式化数据
int age = 25;
float score = 95.5;
fprintf(fp, "姓名：%s，年龄：%d，成绩：%.1f\n", "张三", age, score);
```

#### fscanf() - 格式化读取
```c
int fscanf(FILE *stream, const char *format, ...);
```

#### 参数解释
- `stream`：要读取的文件指针
- `format`：格式化字符串
- `...`：可变参数列表，用于存储读取结果

#### 示例
```c
// 读取格式化数据
char name[20];
int age;
float score;

// 从文件中读取姓名、年龄和成绩
fscanf(fp, "姓名：%s，年龄：%d，成绩：%f", name, &age, &score);
printf("读取到：姓名=%s，年龄=%d，成绩=%.1f\n", name, age, score);
```

### 4. 二进制读写

#### fread() - 读取二进制数据
```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```

#### 参数解释
- `ptr`：存储读取数据的缓冲区
- `size`：每个数据项的大小（字节）
- `nmemb`：要读取的数据项数量
- `stream`：要读取的文件指针

#### 示例
```c
// 读取二进制数据到结构体数组
struct Student {
    char name[20];
    int age;
    float score;
} students[10];

// 读取10个Student结构体
size_t count = fread(students, sizeof(struct Student), 10, fp);
printf("成功读取%d个学生数据\n", count);
```

#### fwrite() - 写入二进制数据
```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```

#### 参数解释
- `ptr`：要写入数据的缓冲区
- `size`：每个数据项的大小（字节）
- `nmemb`：要写入的数据项数量
- `stream`：要写入的文件指针

#### 示例
```c
// 写入结构体数组到二进制文件
struct Student {
    char name[20];
    int age;
    float score;
} students[2] = {
    {"张三", 20, 95.5},
    {"李四", 21, 88.0}
};

// 写入2个Student结构体
size_t count = fwrite(students, sizeof(struct Student), 2, fp);
printf("成功写入%d个学生数据\n", count);
```

## 三、文件定位操作

### 1. fseek() - 设置文件位置
```c
int fseek(FILE *stream, long offset, int whence);
```

#### 参数解释
- `stream`：要操作的文件指针
- `offset`：偏移量（字节）
- `whence`：起始位置

#### 常用whence参数
- SEEK_SET：从文件开头开始
- SEEK_CUR：从当前位置开始
- SEEK_END：从文件末尾开始

#### 示例
```c
// 移动到文件开头
fseek(fp, 0, SEEK_SET);

// 移动到文件末尾
fseek(fp, 0, SEEK_END);

// 从当前位置向后移动100字节
fseek(fp, 100, SEEK_CUR);

// 从文件开头向前移动50字节（实际是向后移动50字节）
fseek(fp, 50, SEEK_SET);
```

### 2. ftell() - 获取文件位置
```c
long ftell(FILE *stream);
```

#### 参数解释
- `stream`：要操作的文件指针

#### 示例
```c
// 获取当前文件位置
long position = ftell(fp);
printf("当前文件位置：%ld字节\n", position);

// 获取文件大小
fseek(fp, 0, SEEK_END);
long file_size = ftell(fp);
printf("文件大小：%ld字节\n", file_size);
```

### 3. rewind() - 重置文件位置
```c
void rewind(FILE *stream);
```

#### 参数解释
- `stream`：要操作的文件指针

#### 示例
```c
// 重置文件指针到开头
rewind(fp);

// 重新读取文件内容
char buffer[1024];
while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
}
```

## 四、文件状态检查

### 1. feof() - 检查文件结束
```c
int feof(FILE *stream);
```

#### 参数解释
- `stream`：要检查的文件指针

#### 示例
```c
// 读取文件直到结束
char buffer[1024];
while (1) {
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        if (feof(fp)) {
            printf("文件读取结束\n");
        } else {
            perror("文件读取错误");
        }
        break;
    }
    printf("%s", buffer);
}
```

### 2. ferror() - 检查文件错误
```c
int ferror(FILE *stream);
```

#### 参数解释
- `stream`：要检查的文件指针

#### 示例
```c
// 写入数据并检查错误
const char *str = "测试数据\n";
if (fputs(str, fp) == EOF) {
    if (ferror(fp)) {
        perror("写入文件错误");
        clearerr(fp);  // 清除错误标志
    }
}
```

### 3. clearerr() - 清除文件错误
```c
void clearerr(FILE *stream);
```

#### 参数解释
- `stream`：要操作的文件指针

#### 示例
```c
// 清除文件错误标志
if (ferror(fp)) {
    printf("检测到文件错误\n");
    clearerr(fp);  // 清除错误标志
    printf("错误标志已清除\n");
}

// 尝试重新操作
if (fputs("恢复写入\n", fp) != EOF) {
    printf("文件操作恢复成功\n");
}
```

## 五、常用文件操作常量

### 1. EOF
- 宏定义，值为-1
- 表示文件结束或错误

### 2. NULL
- 空指针常量
- 表示指针不指向任何对象

### 3. BUFSIZ
- 标准I/O缓冲区大小
- 通常为512或4096字节

## 六、文件操作示例

### 示例1：读取文件内容
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }
    
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    
    fclose(fp);
    return 0;
}
```

### 示例2：写入文件内容
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("file.txt", "w");
    if (fp == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }
    
    fprintf(fp, "Hello, World!\n");
    fprintf(fp, "C语言文件操作\n");
    
    fclose(fp);
    return 0;
}
```

## 七、文件操作注意事项

### 1. 错误处理
- 始终检查fopen()的返回值
- 使用perror()或strerror()获取错误信息

### 2. 资源管理
- 确保所有打开的文件都被关闭
- 避免文件描述符泄漏

### 3. 缓冲区问题
- 注意缓冲区刷新（fflush()）
- 理解行缓冲和全缓冲的区别

### 4. 二进制与文本模式
- Windows系统中，文本模式会转换换行符
- 二进制模式保持数据原样

## 八、总结

C语言提供了丰富的文件操作函数，主要包括：
1. **打开/关闭**：fopen(), fclose()
2. **读写**：fgetc(), fputc(), fgets(), fputs(), fprintf(), fscanf(), fread(), fwrite()
3. **定位**：fseek(), ftell(), rewind()
4. **状态检查**：feof(), ferror(), clearerr()

掌握这些函数的使用对于编写文件处理程序至关重要。在实际编程中，应注意错误处理和资源管理，确保程序的健壮性。