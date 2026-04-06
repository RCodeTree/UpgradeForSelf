# C语言动态内存管理函数详解

## 1. malloc() - 分配内存块

### 原型
```c
void *malloc(size_t size);
```

### 作用
- 在堆上分配指定大小的内存块
- 分配的内存未初始化，内容是随机的垃圾值
- 成功返回指向内存块的指针，失败返回NULL

### 示例
```c
int *p = (int *)malloc(10 * sizeof(int));
if (p == NULL) {
    // 内存分配失败处理
}
```

## 2. calloc() - 分配并初始化内存块

### 原型
```c
void *calloc(size_t num, size_t size);
```

### 作用
- 在堆上分配`num`个`size`大小的内存块
- 分配的内存初始化为0
- 成功返回指向内存块的指针，失败返回NULL

### 示例
```c
int *p = (int *)calloc(10, sizeof(int));
// p指向的内存块初始化为0
```

## 3. realloc() - 重新分配内存块

### 原型
```c
void *realloc(void *ptr, size_t size);
```

### 作用
- 调整已分配内存块的大小
- 可以扩大或缩小内存块
- 成功返回新的内存块指针，失败返回NULL，原内存块保持不变
- 如果ptr为NULL，相当于malloc(size)

### 示例
```c
int *p = (int *)malloc(10 * sizeof(int));
// 扩大内存到20个int
p = (int *)realloc(p, 20 * sizeof(int));
```

## 4. free() - 释放内存块

### 原型
```c
void free(void *ptr);
```

### 作用
- 释放之前通过malloc、calloc或realloc分配的内存块
- 释放后ptr变为野指针，建议设置为NULL
- 不能重复释放同一内存块，不能释放栈内存

### 示例
```c
int *p = (int *)malloc(10 * sizeof(int));
// 使用内存
free(p);
p = NULL; // 避免野指针
```

## 5. 注意事项

### 常见错误
1. **内存泄漏**：忘记释放动态分配的内存
2. **重复释放**：多次释放同一内存块
3. **使用已释放内存**：访问已被free的内存
4. **野指针**：指针指向已释放内存或未初始化

### 最佳实践
1. 始终检查内存分配是否成功
2. 分配和释放匹配使用
3. 释放后将指针置为NULL
4. 避免内存泄漏，特别是在循环和递归中

## 6. 完整示例

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // 初始化数组
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    // 扩大数组
    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("内存重分配失败\n");
        return 1;
    }
    
    // 使用新分配的内存
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    // 输出数组
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    // 释放内存
    free(arr);
    arr = NULL;
    
    return 0;
}
```

**总结**：动态内存管理是C语言的重要特性，掌握这四个函数的使用对于编写高效、健壮的程序至关重要。