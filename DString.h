//
// Created by antonio on 17-10-11.
//

#ifndef STRING_DSTRING_H
#define STRING_DSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str ;
    int maxLength ;
    int length ;
}DString;

//初始化
void DStringInitiate(DString *S, int max, char *string){
    int i ;
    S->str = (char *)malloc(sizeof(char)*max) ;//申请动态数组空间
    S->maxLength = max ;//设置动态数组元素的最大个数
    S->length = strlen(string) ;//得到要赋值的串的长度
    for (i = 0; i < S->length; i++) {
        S->str[i] = string[i] ;//赋值
    }
}

//插入子串!!!着实很复杂呢
int DStringInsert(DString *S, int pos, DString T){
    //在渚串S的pos位置上插入子串T
    int i ;
    if(pos < 0){
      printf("pos is wrong\n") ;
        return 0 ;
    }
    else{
        if(S->length + T.length > S->maxLength){
          //重新申请S->str所指的数组的空间,原数组元素存放在新数组里面
            S->str = (char *)realloc(S->str, (S->length + T.length)* sizeof(char)) ;//申请新数组内存
            //realloc函数申请空间如果大于原来的空间,那么元数据保存,如果小于原来的空间,那么很有可能会发生数据丢失的情况
            S->maxLength = S->length + T.length ;//确定新数组的最大长度 = 两个子串的长度和
        }
        for (i = S->length - 1; i >= pos; i--) {
            S->str[i + T.length] = S->str[i] ;//依次后移T.length个位置
        }
        for (i = 0; i < T.length; ++i) {
            S->str[pos + i] = T.str[i] ;//插入
        }

        S->length += T.length ;//新的数据元素个数
        return 1 ;
    }
}

//删除子串
int DStringDelete(DString *S, int pos, int len){
    //删除从pos位置开始长度为len的子串
    if(S->length <= 0){
      printf("数组中没有存放可删除的字符\n") ;
        return 0 ;
    }
    else if(pos < 0 || len < 0 || pos + len > S->length){
      printf("pos AND len are illege\n") ;
        return 0 ;
    }
    else{
        for (int i = len + pos; i <= S->length - 1; ++i) {
            S->str[i - len] = S->str[i] ;//前置覆盖:删除
        }
        S->length = S->length - len ;//及时修改长度
        return 1 ;
    }
}
//获得子串
int SubString(DString *S, int pos, int len, DString *T){
    //获取渚串从pos开始长度为len的字串,赋予T带回
    if(pos < 0 || len < 0 || pos+len > S->length){
        printf("pos AND len are illege\n") ;
        return 0 ;
    }
    if(len > T->maxLength){
      //要获取的子串长度较长,要扩大T的空间
        T->str = (char *)malloc(sizeof(char)*len) ;
        T->maxLength = len ;
    }
    for (int i = 0; i < len; ++i) {
        T->str[i] = S->str[pos + i] ;//赋值
    }
    T->length = len ;//修改长度
    return 1 ;
}
//撤销串
void Destory(DString *S){
    free(S->str) ;
    S->length = 0 ;
    S->maxLength = 0 ;
}




#endif //STRING_DSTRING_H
