# C Class Helper

## 注意事项 | FYA

- 如果您将日志输出到文件中，请注意本工具只会不断追加，不会主动清空日志文件。所以请您做好日志的手动清空或备份管理工作。
  - 换句话说，如果你不希望几次运行的日志全都在同一个文件里无法区分，那么请在每次运行完以后删除日志文件或者重命名它。
- 该工具中的宏函数都需要在函数内使用，也就是说你不能把它写在函数外，当然我相信几乎没有人会这么做。

## 使用之前的设置 | Config

**说明**：

- 该项内容需要您手动修改源代码中的对应部分，请放心，它被放在来代码的头部，很好找。

- 如果您希望日志打印在屏幕上但没有颜色高亮，设置为`2`；
- 如果您希望日志打印在屏幕上并且有颜色（CMD无法使用），设置为`1`；
- 如果希望日志打印在文件中，设置为`0`:

设置为`1`时效果最佳，但对于不熟悉命令行的一般同学我们推荐使用`2`，在有特殊需求时可以使用`0`

```c
// MODE 0 : Logs will be write to 'CCH_log.txt' file.
// MODE 1 : Logs will be print to console (colorful for normal terminal).
// MODE 2 : Logs will be print to console (colorless but fine for CMD).
#define CCH_MODE 2
```

## 使用 | Usage

### 导入 | Import

- 对于尚在学习单文件编程的同学，我们建议您直接复制`CClassHelper.h`中的所有内容至你的代码的最前。
- 如果您觉得这太过累赘，那么请在本地将`CClassHelper.h`文件与您正在编写的`.c`文件放在同一目录，并在代码的开头写上`#include "CClassHelper.h"`，但请注意，此时您无法直接将代码内容提交至在线评测工具（比如PTA）。解决方法请参考上一条。
- 对于已经知道如何进行多模块编程的同学，我们建议您直接`#include "CClassHelper.h"`

### 显示 | Show

**说明**：在保留调试代码的情况下，控制是否显示日志内容。

- 默认情况下，该工具都会默认输出所有日志内容；
- 您也可以通过调用`SET_CCH_SHOW(0);`来关闭显示；
- 在关闭之后您也可以通过`SET_CCH_SHOW(1);`来启用显示；

```c
// Run 'demo1.c' to see more!
int main(){
    SET_CCH_SHOW(1);
    LOG("(QWQ) I can be seen!");
	SET_CCH_SHOW(0);
    LOG("(QAQ) I can't be seen!");
}
```

### 简化 | Simplify

**说明**：如果您认为正常的输出过于花哨，`CCH`提供了两套方案来调整输出的格式。

使用如下方法可以**全局性**地更改输出格式：

- 使用`SET_CCH_BRIEF_MODE(1);`来启用简化模式；
- 使用`SET_CCH_BRIEF_MODE(0);`来关闭简化模式；

使用`BRIEF();`和`NORMAL();`可以**局部性**地修改输出格式：

```c
// Run 'demo2.c' to see more!
int main(){
    SET_CCH_BRIEF_MODE(0);
    LOG("Normal mode here!");
	BRIEF(
		LOG("Brief mode here!");
        LOG("Multiline is ok!");
	);
    LOG("Normal mode here!");

    SET_CCH_BRIEF_MODE(1);
	LOG("Brief mode here!");
    NORMAL(
		LOG("Normal mode here!");
        LOG("Multiline is ok!");
    );
	LOG("Brief mode here!");
}
```

**预览**：

正常输出模式：

![](https://raw.githubusercontent.com/IsshikiHugh/C-Class-Helper/main/img/img1.png)

简化输出模式：

![](https://raw.githubusercontent.com/IsshikiHugh/C-Class-Helper/main/img/img2.png)

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
- [ ] 制作一份配套的基础使用说明视频
- [ ] 准备一份扩展玩法说明
- [ ] ...
