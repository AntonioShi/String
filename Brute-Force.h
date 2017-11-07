//
// Created by antonio on 17-10-11.
//

#ifndef STRING_BRUTE_FORCE_H
#define STRING_BRUTE_FORCE_H

#include "DString.h"
int BFIndex(DString S, int start, DString T){
    //查找渚串S从start开始的子串T,成功则返回T在S中的首字符位置
    int i = start, j = 0, v ;

    while (i < S.length && j < T.length) {
        if(S.str[i] == T.str[i]){
            j ++ ;
            i ++ ;
        }
        else{
            i = i - j + 1 ;
            j = 0 ;
        }
    }

    if(j == T.length){
      v = i - T.length ;
    } else
        v = -1 ;

    return v ;

}

#endif //STRING_BRUTE_FORCE_H
