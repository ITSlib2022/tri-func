# tri-func

###  1、简介 

> ​      本程序基于设计了一个三角函数计算器，通过显示界面输入计算数值，利用CORDIC算法实现正弦sin、余弦cos、反正弦arcsin、反正切arctan的计算。
>
> ​      语言：C++
>
> ​      编译环境：Visual Studio 2019

### 2、需求分析

>​     2.1 数据域
>
>​           输入 : (sin cos函数)角度值 或者 弧度值 、（asin atan函数）实数值
>
>​           输出 : 计算结果，包括正弦、余弦计算值以及反正弦、反正切计算得出的角度
>
>​     2.2 功能域
>
>​           对输入的数据首先进行判断：1、数据类型   2、是否在定义域内
>
>​           对于输入的数值，根据选择的不同函数进行计算给出结果。 
>
>​     2.3 状态域
>
>​           输入 -->  判断输入  --> 可行    --> 计算 --> 给出结果 --> 返回输入
>
>​                                           |->不可行 --> 提示报错、返回输入

### 3、详细设计       

>​     3.1 计算模块
>
>​			根据输入的数值，以及选择要计算的函数，利用 CORDIC 算法计算结果。
>
>​     3.2 数据模块
>
>​            输入数值，CORDIC 算法所需的数值表(arctan 1/ri)，输出数值
>
>​     3.3 显示界面
>
>​            利用C++ MFC 进行设计，显示计算器界面，包含选择按钮、输入数据框、异常提醒、结果显示。
>
>​     3.4 异常处理
>
>​            判断异常、异常处理、反馈信息
