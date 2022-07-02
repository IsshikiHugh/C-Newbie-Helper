# 𝓒 𝓒𝓵𝓪𝓼𝓼 𝓗𝓮𝓵𝓹𝓮𝓻

## 简介 | Brief Intro

[仓库地址 | Github Repo Address](https://github.com/IsshikiHugh/C-Class-Helper)

这是一个为 C 语言学习新手提供的一个日志打印工具，整体功能比较简单，目的是培养刚接触编程的同学学习和养成 Debug 正确方法和好习惯。

为了方便没有接触过多模块编程的同学的使用，该工具将全部通过预编译指令和宏实现，以便使用者也能够直接复制进代码文件使用。

## 注意事项 | FYA

- 如果您将日志输出到文件中，请注意本工具只会不断追加，不会主动清空日志文件。所以请您做好日志的手动清空或备份管理工作。
  - 换句话说，如果你不希望几次运行的日志全都在同一个文件里无法区分，那么请在每次运行完以后删除日志文件或者重命名它。

## 设置 | Config

### 工具开关

**说明**：在保留调试代码的情况下，控制是否显示日志内容。
- 如果您希望日志内容输出，则设置为`1`，否则设置为`0`：

```c
// Set 0 if you don't want to see logs.
// Set 1 if you want to see logs.
#define SHOW_LOGS 1
```

### 输出流

**说明**：
- 如果您希望日志打印在屏幕上但没有颜色高亮，设置为`2`；
- 如果您希望日志打印在屏幕上并且有颜色（CMD无法使用），设置为`1`；
- 如果希望日志打印在文件中，设置为`0`:

```c
// MODE 0 : Logs will be write to 'CCH_log.txt' file.
// MODE 1 : Logs will be print to console (colorful for normal terminal).
// MODE 2 : Logs will be print to console (colorless but fine for CMD).
#define CCH_MODE 2
```

### 简化输出

**说明**：如果您认为正常的输出过于花哨，可以修改该选项切换为简介输出模式。
- 设置为`0`关闭简洁模式；
- 设置为`1`打开简洁模式；

```c
// Set 0 if you want to see normal format.
// Set 1 if you want it to be brief.
#define CCH_BRIEF 0
```
**预览**：

正常输出模式：

![](https://raw.githubusercontent.com/IsshikiHugh/C-Class-Helper/main/img/img1.png)

简化输出模式：

![](https://raw.githubusercontent.com/IsshikiHugh/C-Class-Helper/main/img/img2.png)


## 使用 | Usage

### 导入 | Import

- 对于尚在学习单文件编程的同学，我们建议你直接复制`CClassHelper.h`中的所有内容至你的代码的最前。
- 对于已经知道如何进行多模块编程的同学，我们建议您直接`#include "CClassHelper.h"`

### 一般日志 | Log

使用`LOG(...)`来输出一般日志。
- `LOG()`的使用方法和`printf()`基本一致，只需要把`printf()`语句中的函数名换成`LOG`即可。

举个例子：

如果您想在某一处输出一条日志语句：

```c
    char myCharArr[] = "It's OK!";
    LOG("This is a log message. %s", myCharArr);
```


### 监控变量 | Variable Monitor

使用`SHOW_VAR(CCH_TYPE, CCH_VAR)`来监控变量。
- 其中`CCH_TYPE`指对应变量在`printf()`的 format 中所使用的占位符，例如`int`对应的`CCH_TYPE`为`"%d"`，`double`对应的`CCH_TYPE`为`"%lf"`；
  - 当然，由于该宏函数的底层使用的是`printf()`，所以实际上相关的扩展语法都是支持的。比如`"%.2lf"`
- `CCH_VAR`指对应变量；

举个例子：

如果您想在某一处监控`int`类型变量`x`，则在该位置写上：

```c
    SHOW_VAR("%d", x);
```

### 监控数组 | Array Monitor

#### 一维数组

使用`SHOW_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END)`来监控数组。
- 其中`CCH_TYPE`指对应变量在`printf()`的 format 中所使用的占位符，同上；
- `CCH_ARR_NAME`指数组名，例如`int a[10];`中的`a`；
- `CCH_ARR_BEGIN`和`CCH_ARR_END`分别为需要监控的数组的始末下表，且**左闭右开**；
  - 具体来说，比如为想监控`a[0]` `a[1]` `a[2]` `a[3]` ... `a[9]`，那么对应的`CCH_ARR_BEGIN`为`0`，`CCH_ARR_END`为`10`；
  - 换句话来说，这个宏函数只能用来监控一维数组的连续段；

举个例子：

如果您想在某一处监控`int`类型数组`a[]`，范围是`a[0]`到`a[10]`，则在该位置写上：

```c
    SHOW_ARR("%d", a, 0, 10);
```

#### 二维数组

使用`SHOW_2_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_ROW_NUM, CCH_ARR_COL_NUM)`来监控数组。
- 其中`CCH_TYPE`指对应变量在`printf()`的 format 中所使用的占位符，同上；
- `CCH_ARR_NAME`指数组名，例如`int a[10][10];`中的`a`；
- `CCH_ARR_ROW_NUM`和`CCH_ARR_COL_NUM`分别为需要监控的二维数组的行数和列数；
  - 具体来说，比如为想监控这样一个二维数组：
```c
int a[3][4] = {{1,2,3,11},
               {4,5,6,12},
               {7,8,9,10}};
```
  - 那么对应的`CCH_ARR_ROW_NUM`为`3`，`CCH_ARR_COL_NUM`为`4`；
  - 换句话来说，这个宏函数只能用来监控二维数组从`( 0 , 0 )`到`( CCH_ARR_ROW_NUM-1 , CCH_ARR_COL_NUM-1 )`的矩阵。

举个例子：

如果您想在某一处监控上面那个二维数组`a[][]`，则在该位置写上：

```c
    SHOW_2_ARR("%d", a, 3, 4);
```

#### 任意维数组

使用`SHOW_N_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ELEMENT_SIZE, CCH_SIZE)`来监控任意维数组。
- 其中`CCH_TYPE`指对应变量在`printf()`的 format 中所使用的占位符，同上；
- `CCH_ARR_NAME`指数组名，例如`int a[10][10];`中的`a`；
- `CCH_ELEMENT_SIZE`和`CCH_SIZE`分别为需要监控的数组的每一个元素的大小和整个数组的大小，一般推荐直接写成`sizeof(<EleType>)`和`sizeof(<ArrName>)`；
  - 具体来说，比如有一个三维`double`类数组`a[11][45][14]`，则：
  - `CCH_ELEMENT_SIZE`为`sizeof(double)`；
  - `CCH_SIZE`为`sizeof(a)`；
  举个例子：

如果您想在某一处监控上面那个三维数组`a[][]`，则在该位置写上：

```c
    SHOW_2_ARR("%lf", a, sizeof(double), sizeof(a));
```

## 后续计划

- [x] 输出为日志文件
- [x] 支持正常 terminal 下的彩色字体
- [x] 简化版输出
- [ ] 支持 Windows CMD 下的彩色字体
- [x] 尝试解决多维数组的监控方案 *感谢[@solar-z](https://github.com/solar-z)*
- [ ] 在监控变量时支持自定义注解语句（目前已经能够实现，但是是否有更优雅的解法）
- [ ] 制作一份配套的使用说明视频
- [ ] ...
