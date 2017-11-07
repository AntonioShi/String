#include <stdio.h>
#include "DString.h"
#include "Brute-Force.h"

int main() {

    DString myString1, myString2, myString3 ;
    int i, max1 = 5, max2 = 9, max3 = 0 ;

    //开始测试初始化函数
    DStringInitiate(&myString1, max1, "Data ") ;
    DStringInitiate(&myString2, max2, "Structure") ;
    DStringInitiate(&myString3, max3, " ") ;
    printf("初始化myString2:    ") ;
    for (int i = 0; i < myString2.length; i++) {
        printf("%c", myString2.str[i]) ;
    }
    printf("   maxLength = %d", myString2.maxLength) ;
    printf("   length = %d\n", myString2.length) ;

    //测试插入函数
    DStringInsert(&myString2, 0, myString1) ;
    printf("插入子串后myString2:  ") ;
    for (int i = 0; i < myString2.length; i++) {
        printf("%c", myString2.str[i]) ;
    }
    printf("   maxLength = %d", myString2.maxLength) ;
    printf("   length = %d\n", myString2.length) ;

    //测试BF算法函数
    int pos = 0 ;
    pos = BFIndex(myString2, pos, myString1) ;
    printf("第一次查找: pos = %d\n", pos) ;

    pos = BFIndex(myString2, pos+1, myString1) ;
    printf("第二次查找: pos = %d\n", pos) ;


    //测试删除函数
    DStringDelete(&myString2, 0, 5) ;
    printf("删除子串后的myString2:  ") ;
    for (int i = 0; i < myString2.length; i++) {
        printf("%c", myString2.str[i]) ;
    }
    printf("   maxLength = %d", myString2.maxLength) ;
    printf("   length = %d\n", myString2.length) ;

    //测试子串的获取函数
    SubString(&myString2, 0, 5, &myString3) ;
    printf("获取子串后myString3   ") ;
    for (int i = 0; i < myString3.length; i++) {
        printf("%c", myString3.str[i]) ;
    }
    printf("   maxLength = %d", myString3.maxLength) ;
    printf("   length = %d\n", myString3.length) ;

    //撤销函数
    Destory(&myString1) ;
    Destory(&myString2) ;
    Destory(&myString3) ;

    printf("Hello, World!\n");
    return 0;
}