#ifndef COMPILE_OPTIONS_H
#define COMPILE_OPTIONS_H


/**********************  命名习惯  *****************************
1. 指针变量 采用 _下划线命名
2. 当参数传递是值拷贝 而非引用传递时， 参数名使用 param__

**********************  标志选项  *****************************/
/* 似值语义？似指针语义？*/
#define VALUE_SEMANTICS
#define COPY_AND_SWAP
//#define REFERENCE_SEMANTICS

/**********************  测试main  *****************************/


#endif // COMPILE_OPTIONS_H
