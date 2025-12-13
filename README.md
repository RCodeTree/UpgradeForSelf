# 湖北专升本学习资料库 📚

## 项目简介 🎯
本项目面向湖北省普通专升本考试，聚焦英语、C语言、计算机基础三大模块，提供系统化资料与练习，帮助高效备考。

## 项目结构 📁

### 📂 C语言
- Begin（初识）
  - `Array/a1.c` — 一维/二维数组的创建与初始化；索引与地址关系；遍历与边界
  - `Control_Flow_Statements/cfs1.c` — if 条件判断，奇偶判定与基本分支结构
  - `Control_Flow_Statements/cfs2.c` — while 循环输出 1-100 奇数，循环与条件结合
  - `Control_Flow_Statements/cfs3.c` — for 循环基础：计数器、步长与累加求和
  - `Control_Flow_Statements/cfs4.c` — do-while 循环：至少执行一次与用户输入校验
  - `Control_Flow_Statements/cfs5.c` — switch 分支：case、break 与默认分支设计
  - `Control_Flow_Statements/cfs6.c` — 嵌套循环：打印图形（如直角三角形、乘法表）
  - `Control_Flow_Statements/cfs7.c` — 跳转语句：break/continue 的使用场景与差异
  - `Control_Flow_Statements/cfs8.c` — 循环求和与平均值：整型/浮点型精度注意事项
  - `Control_Flow_Statements/cfs9.c` — 序列最大/最小值查找：初始化与边界条件
  - `Control_Flow_Statements/cfs10.c` — 复合条件与逻辑运算：&&、||、! 的组合
  - `Control_Flow_Statements/cfs11.c` — 循环终止条件设计：防止死循环与计数溢出
  - `Control_Flow_Statements/cfs12.c` — 文本菜单驱动：循环 + switch 组织交互式程序
  - `Control_Flow_Statements/cfs13.c` — 控制流综合练习：条件、循环、分支混合案例
  - `Cursor/c1.c` — 指针进阶：指针与数组、指针运算、二级指针的入门示例
  - `Function/f1.c` — 字符串与内存库函数：strcpy、memset 的用法与风险控制
  - `Function/f2.c` — 指针参数交换两个整数：传址与传值差异
  - `Function/f3.c` — 函数定义/声明/调用：返回值与参数类型匹配
  - `Function/f4.c` — 作用域与生命周期：局部变量、全局变量、静态变量
  - `Function/f5.c` — 递归基础：阶乘/斐波那契的递归与终止条件
  - `Function/f6.c` — 数组与函数：数组作为参数的传递与边界校验
  - `Function/f7.c` — 指针操作数组：遍历、修改与越界防护
  - `Function/f8.c` — 函数指针与回调：接口抽象与可扩展设计
  - `Function/f9.c` — 可变参数函数：格式化输出的参数处理思想
  - `Function/f10.c` — 字符串处理组合练习：拼接、查找、比较的封装
  - `Function/f11.c` — 内存操作：memcpy 与 memmove 的行为差异与示例
  - `Function/f12.c` — 排序函数封装：比较函数与可复用接口设计
  - `Function/f13.c` — 递归与迭代对比：复杂度与栈深度讨论
  - `Function/f14.c` — 静态变量与计数器：跨调用记忆与副作用
  - `Function/f15.c` — 多文件工程：头文件声明、实现分离与编译链接
  - `Function/f16.c` — inline 与宏函数：开销、类型检查与可读性
  - `Function/f17.c` — 结构体参数与指针：就地修改与封装
  - `Function/f18.c` — 模块化接口设计：API 约定与单元测试思路
  - `Function/goUpgradeForSelf.sh` — 在 Linux/Unix 环境编译运行的脚本示例
  - `Operators/o1.c` — 算术运算符：加减乘除与取模的细节
  - `Operators/o2.c` — 关系运算符：比较大小、等于与不等
  - `Operators/o3.c` — 逻辑运算符：短路求值与表达式组合
  - `Operators/o4.c` — 赋值与复合赋值：链式赋值与可读性
  - `Operators/o5.c` — 自增自减：前置/后置的求值顺序与差异
  - `Operators/o6.c` — 位运算：与/或/异或/取反与常见技巧
  - `Operators/o7.c` — 位移：左移/右移的数值与符号影响
  - `Operators/o8.c` — 条件运算符（三目）：简化分支与优先级
  - `Operators/o9.c` — 运算符优先级与结合性：括号与歧义消除
  - `Operators/o10.c` — sizeof 与类型相关运算：数组与指针的区别
  - `Operators/o11.c` — 逗号运算符与表达式序列：用法与陷阱
- Start（初阶）
  - `#define定义常量和宏/#define.c` — 预处理指令：宏常量、宏函数与代码替换
  - `Cursor/cursor.c` — 指针基础：声明、初始化、解引用与指向不同类型
  - `Keywords/keywords.md` — 32 个关键字速查：语义、示例与常见误用
  - `Struct/struct.c` — 结构体：定义、初始化、点与箭头操作符访问成员
  - `Variables_and_Constants/son1.c` — 外部变量与全局变量：链接属性与作用域演示
- Fail（题目收集与错题）
  - `Fail/Fail.md` — 练习题片段：交替偶数序列求和、Fibonacci 前 12 项之和、居中星号三角形
- Test（练习与做过的题目）
  - `test1_string.c` — 字符串逆序：临时数组法与原地逆序对比
  - `test2_arr.c` — 冒泡排序：10 个整数升序、交换与趟次优化
  - `test3_struct.c` — 图书管理小项目：价格计算与结构体排序
  - `test4_recursion.c` — 递推公式计算：递归函数 `Fun` 的调用链与终止
  - `test5_recursion.c` — 递归拆分整数：逐位打印与基准情形
  - `test6_recursion.c` — 递归进阶：复杂递归问题的分治与回溯思路
  - `test7_recursion.c` — 递归字符串原地逆序：双指针与递归边界
  - `test8_recursion.c` — 递归求长度 + 逆序：两次递归的配合
  - `test9_recursion.c` — 递归各位求和（静态变量）：跨调用累加器
  - `test10_recursion.c` — 递归各位求和（纯递归）：无静态变量的写法
  - `test11_recursion.c` — 数组交换：两个相同大小数组的内容互换
  - `test12_operate.c` — 位运算交换整数：异或技巧、不用临时变量
  - `test13_operate.c` — 统计二进制 1 的个数：位移 + 按位与
  - `test14_operate.c` — 爬台阶计数：递推等价 Fibonacci（`ways(n)=ways(n-1)+ways(n-2)`）
  - `test15_operate.c` — 位运算综合：多位段提取与组合
  - `test16_arr.c` — 数组与地址：下标与指针等价、遍历与边界
  - `test17_char.c` — 字符判定：大小写转换、数字与字母分类
  - `test18_char.c` — 字符处理进阶：ASCII 与控制字符
  - `test19.c` — 综合练习：输入处理与流程控制组合
  - `test20_char.c` — 字符串输入：安全读入与缓冲清理
  - `test21_format.c` — printf 基础：占位符、宽度与对齐
  - `test22_format.c` — printf 进阶：精度控制与标志位
  - `test23_char.c` — 字符串遍历与统计：长度、空白与符号计数
  - `test24_char.c` — 子串查找与替换：朴素匹配思想
  - `test25_char.c` — 字符串比较与排序：字典序与稳定性
  - `test26_char.c` — 字符数组与指针：常见陷阱与修复
  - `test27_format.c` — 格式化输出进阶：左/右对齐与填充
  - `test28_format.c` — 自定义格式模板：组合输出案例
  - `test29_scanf.c` — scanf 输入模式：空白处理与缓冲问题
  - `test30_format.c` — 浮点格式化：精度、舍入与显示
  - `test31_format.c` — 表格化输出：列宽控制与对齐策略
  - `test32_scanf.c` — 多项输入：格式串与边界检查
  - `test33_scanf.c` — 安全输入：限定宽度与错误处理
  - `test34_scanf.c` — 输入校验：返回值判断与重试机制
  - `test35_math.c` — 常用数学函数：abs、sqrt、pow 等的用法与误差
  - `test36_math.c` — 数值计算：迭代方法与精度控制
  - `test37_format.c` — 高级格式控制：混合类型与输出美化
  - `test38_char_format.c` — 字符与格式化综合：分类统计 + 展示
  - `test39_e_format.c` — 科学计数法输出：e/E 格式与场景
  - `test40_e_format.c` — 科学计数法进阶：精度与对齐
  - `test41_format.c` — 综合格式化：多列输出与标题行
  - `test42_swap.c` — 不借助临时变量交换：算术与位运算的比较
  - `test43_char_scanf.c` — 字符扫描输入：读取、过滤与转换
  - `test44_circle.c` — 圆相关计算：周长、面积与格式化输出
  - `test45_operator.c` — 基础赋值：变量初始化
  - `test46_num.c` — 位运算统计：二进制中 1 的个数
  - `test47_num.c` — 位运算比较：两个数二进制不同的位数
  - `test48_num.c` — 位运算提取：输出整数的奇偶位
  - `test49_num.c` — 位运算提取：奇偶位操作练习
  - `test50_num.md` — 编译行为：自增运算的未定义行为
  - `test51_num.md` — 变量存储：全局/静态变量默认值
  - `test52_num.c` — 图形打印：X 形图案
  - `test53.c` — 逻辑判断：三角形构成与类型判定
  - `test54_cursor.c` — 指针基础：使用指针遍历数组
  - `test55_string.c` — 字符串操作：自定义逆序函数
  - `test56_sum.c` — 数列求和：Sn = a + aa + ...
  - `test57_sum.c` — 数字特征：水仙花数查找
  - `test58_sum.c` — 逻辑推理：喝汽水问题（空瓶换购）
  - `test59_graph.c` — 图形打印：菱形图案
  - `test60.c` — 逗号表达式：优先级与求值顺序
  - `game/test.c` — 扫雷主程序：菜单与游戏流程控制
  - `game/game.h` — 常量宏、结构体与函数声明
  - `game/game.c` — 游戏核心：初始化、显示、布雷、排雷算法
  - `test61.c` — 居中等腰三角形打印：空格填充 + 星号数量 `2*i-1`
  - `test62.c` — 斐波那契前 n 项之和：for 循环迭代，边界 `n<1`、`n==1`
  - `test63.c` — 斐波那契数列：数组缓存实现
  - `test64.c` — 二维数组：定义、初始化与矩阵遍历
  - `test65_array_map.c` — 内存映射：二维数组的线性存储地址计算
  - `test66_string.c` — 字符串坑点：赋值与 strcpy 的区别
  - `test67_string_word.c` — 字符串统计：单词个数计算
  - `test68_string_char.c` — 数组插入：在有序字符数组中插入新元素
  - `test69_eat.c` — 逻辑推理：猴子吃桃问题（逆推法）
  - `test70.c` — 存储类别：static 静态变量的记忆特性
  - `test71.c` — 算术运算：负数取模规则
  - `test72.c` — 函数入门：简单的数学函数定义
  - `test74_num.c` — 数组重排：奇数前移，偶数后移
  - `test75_mergesort.c` — 排序算法：归并排序
  - `test76_selectionsort.c` — 排序算法：选择排序
  - `test77_insertsort.c` — 排序算法：插入排序
  - `test78_parallelogram.c` — 图形打印：平行四边形
  - `test79_maxnum.c` — 极值查找：输入序列求最大值
  - `test80_readchar.c` — 字符流：getchar/putchar 基础
  - `test81_readchar_str.c` — 字符串交互：简单问答循环
  - `test82_perfectnumber.c` — 数字特征：完数计算（真因子之和）
  - `test83.c` — 图形打印：菱形图案通用逻辑
  - `test84_char.c` — 字符细节：转义字符与 strlen 计算
  - `test85_numformat.c` — 格式化输出：浮点数宽度与精度
  - `test86_money.c` — 实际应用：贷款还款计算
  - `test87.c` — 数值处理：浮点数四舍五入技巧

### 📂 C语言 - Up（进阶）
- `Cursor/c.md` — 指针阅读：右左法则与复杂声明解析
- `Cursor/c_arrcursor.c` — 数组指针：指向数组的指针 `int(*)[n]`
- `Cursor/c_char.c` — 字符指针：字符串常量与内存分布
- `Cursor/c_cursorarr.c` — 指针数组：存储字符串列表 `char*[]`
- `Storage/Storage_int.md` — 内存视角：大端与小端存储模式

### 📂 英语
- 单词与短语：
  - `单词和短语/day1.md`-`day5.md` — 基础词汇
  - `单词和短语/improve1.md` — 进阶词汇表
- 工具：
  - `convert/` — Markdown 转 HTML 试题格式化工具
- 语法（之了体系）：
  - `语法/之了/名词.md`、`动词1-实义动词.md`、`动词2-系动词.md`、`形容词.md`、`副词.md`、`代词.md`、`数词.md`、`冠词.md`、`介词.md`、`介词-拓展.md`、`连词.md`、`情态动词的主谓一致.md`、`情态动词的语态.md`

### 📂 计算机基础
- `计算机基础/test.md` — 待补充理论知识

### 📂 简历
- `简历/韦克荣-武汉职业技术大学-计算机应用技术-简历.html`
- `简历/my.jpg`

## 学习进度 📊
- ✅ C语言：Start 与 Begin 阶段完成
- ✅ C语言测试：新增 45-87 题，涵盖排序、位运算、字符串、图形打印等
- ✅ C语言进阶：新增指针与内存存储（Up 模块）
- ✅ 英语：基础词汇 Day1-Day5 + 进阶词汇 improve1 + 试题转换工具
- 📝 计算机基础：待补充
- ✅ 简历制作：已完成
- 🎮 项目实践：扫雷多文件工程

## 使用说明 📖
- C语言学习路径：Start → Begin → Test
- 建议亲自编译运行，理解递归与位运算核心思想
- 多文件工程编译示例：`gcc test.c game.c -o game.exe`
- 循环复习词汇与语法，坚持每日练习

## 备注 📝
- 资料供学习参考，建议结合教材与在线资源
- 欢迎交流建议与问题
