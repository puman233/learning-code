////
//// Created by Administrator on 2023/9/2.
////
//#include<iostream>
//using namespace std;
//
//int main(){
//    // 指向 指 地址
//    // 修饰指针
//    int a =10;
//    int b = 20;
//
//    //  指针指向的值不可改
//    const int * p = &a;
//    cout<< "* p = " << p <<endl;
//
////     *p = 20; # 报错
//    p = &b;
//    cout<< "* p = " << p <<endl;
//
//    // 修饰常量
//    int * const p2 = &a;
//    cout<< "*p2 = " << *p2 <<endl;
//
//
//    //  指针的指向不可改
//    *p2 = 20;
//    cout<<"*p2 = "<< *p2 <<endl;
////    p2 = &b;  # 报错
//
//    // 修饰指针和常量
//    const int * const p3 = &a;
//
//    //指针指向和值不可改
//    /*
//     * *p3 = 30;
//     * p3 = &b;
//     * 均报错
//     */
//
//    return 0;
//}