#ifndef     _FILE_MERGE_H
#define     _FILE_MERGE_H

#include <stdlib.h>



//所有的模式均是new相对于old的改变
//new相对于old的改变一共分为四种情况：
//插入：在old的当前文件指针的后边插入一段
//删除：删除old的两个文件指针之间的一段
//替换：先记录为删除，再记录为插入
//DEL_INS：替换的一种特殊情况
#define     INSERT      1
#define     DELETE      2
#define     REPLACE     3
#define     DEL_INS     4

typedef     int         mode

//判断文件的修改类型
mode which_mode(FILE *new, FILE *old);
//根据判断出来的修改类型调用相应的函数
void add_message(FILE *diff, mode which_mode); 
void insert_message(FILE *diff, FILE *new, FILE *old);
void delete_message(FILE *diff, FILE *new,  FILE *old);
void replace_message(FILE *diff, FILE *new, FILE *old);
//
#endif      //_FILE_MERGE_H
