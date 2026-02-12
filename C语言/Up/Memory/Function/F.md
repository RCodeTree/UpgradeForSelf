### 内存函数

- memcpy 拷贝内存(用于非重叠内存区域，即dest和src指向的内存区域不重叠，两块内存区域不重叠)
    - 函数原型：void *memcpy(void *dest, const void *src, size_t n);

    - 功能：将 src 指向的内存区域的前 n 个字节复制到 dest 指向的内存区域
    - 参数：
        - dest：指向目标内存区域的指针
        - src：指向源内存区域的指针
        - n：要复制的字节数
    - 返回值：指向目标内存区域的指针
- memmove 移动内存(用于重叠内存区域)
    - 函数原型：void *memmove(void *dest, const void *src, size_t n);
    - 功能：将 src 指向的内存区域的前 n 个字节移动到 dest 指向的内存区域
    - 参数：
        - dest：指向目标内存区域的指针
        - src：指向源内存区域的指针
        - n：要移动的字节数
    - 返回值：指向目标内存区域的指针

### 以下是对各个函数的自我实现

#### memcpy

```c
#include <stdio.h>
void *my_memcpy(void *dest, const void *src, size_t n) 
{
    void* ret = dest;
    char* pdest = (char*)dest;
    const char* psrc = (const char*)src;
    while (n--)
    {
        *pdest++ = *psrc++;
    }
    return ret;
}
```

#### my_memmove

**内存重叠分析与图解：**

当源区域 (`src`) 和目标区域 (`dest`) 在内存中发生重叠时，直接复制可能会覆盖源数据。根据地址高低，需要采用不同的复制方向：

1. **`dest < src` (目标在低地址)**
    * **策略**：**从前向后**复制。
    * **图解**：
      ```text
      低地址 [ 1 2 3 ... ] (dest)
               [ 1 2 3 ... ] (src)  高地址
      -----------------> (方向：从左往右，安全)
      ```

2. **`dest >= src` (目标在高地址)**
    * **策略**：**从后向前**复制。
    * **原因**：若从前向后，`dest` 的头部会覆盖 `src` 的尾部重叠区，导致后续读取错误。
    * **图解**：
      ```text
      低地址       [ 4 5 6 ... ] (src)
               [ 4 5 6 ... ] (dest) 高地址
      <----------------- (方向：从右往左，避免覆盖)
      ```

``` c
#include <stdio.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    void* ret = dest;
    char* pdest = (char*)dest;
    const char* psrc = (const char*)src;

    if (pdest < psrc)
    {
        // 情况1：dest 在 src 前面，从前向后拷贝（同 memcpy）
        while (n--)
        {
            *pdest++ = *psrc++;
        }
    }
    else
    {
        // 情况2：dest 在 src 后面（含重叠），从后向前拷贝
        while (n--)
        {
            pdest[n] = psrc[n]; // 或者：*(pdest + n) = *(psrc + n);
        }
    }
    return ret;
}
```