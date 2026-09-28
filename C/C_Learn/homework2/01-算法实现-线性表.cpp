///*
//下面的算法是利用两个线性表LA和LB分别表示两个集合A和B，
//求一个新的集合A=A∪B。试用C语言实现该算法。
//void union(List &La，List Lb) {
//       La_len=ListLength(La);
//       Lb_len=ListLength(Lb);
//       for(i=1;i<=Lb_len;i++) {
//           GetElem(Lb,i,e);
//           if(!LocateElem(La,e,equal))
//                 ListInsert(La,++La_len,e)
//       }
//     }
//*/
//
//# define _CRT_SECURE_NO_WARNINGS
//# include <stdio.h>
//
//#define SIZE 999
//
//
//typedef struct {
//    int data[SIZE];
//    int length;
//} List;
//
//// ListLength(La)
//int ListLength(List List) {
//    return List.length;
//}
//
//// GetElem(Lb,i,e)
//int GetList(List List, int i, int* element) {
//
//    if (i > List.length)
//    {
//        return 0;
//    }
//    
//    *element = List.data[i - 1];
//    return 1;
//}
//
//// ListInsert(La,++La_len,e)
//int ListInsert(List *List, int i, int element) {
//
//    int j;
//
//    if (i > List->length + 1)
//    {
//        return 0;
//    }
//    // weicha
//    for (j = List->length; j >= i; j--)
//    {
//        List->data[j] = List->data[j - 1];
//    }
//
//    List->data[i - 1] = element;
//    List->length++;
//
//    return 1;
//
//}
//
//// LocateElem(La,e,equal) ?
////int LocateElement(List list, int element, int equal);
//int LocateElement(List List, int element) {
//
//    int i;
//
//    for ( i = 0; i < List.length; i++)
//    {
//        if (List.data[i] == element)
//        {
//            return 1;
//        }
//    }
//
//    return 0;
//}
//
///*
//void union(List &La，List Lb) {
//    La_len=ListLength(La);
//    Lb_len=ListLength(Lb);
//    for(i=1;i<=Lb_len;i++) {
//        GetElem(Lb,i,e);
//        if(!LocateElem(La,e,equal))
//                ListInsert(La,++La_len,e)
//    }
//}
//*/
//void ListUnion(List* La, List Lb) {
//
//    int lenLa = ListLength(*La), lenLb = ListLength(Lb);
//    int i, element;
//
//    for ( i = 1; i <= lenLb; i++)
//    {
//        GetList(Lb, i, &element);
//
//        if (!LocateElement(*La, element))
//        {
//            ListInsert(La, ++lenLa, element);
//        }
//    }
//}
//
//
//int main(void) {
//    // input ignored.....
//    List La = {
//        {1,3,4}, 3
//    };
//    List Lb = {
//        {1, 2, 4, 5}, 4
//    };
//
//    printf("A U B :\n");
//
//    ListUnion(&La, Lb);
//    int i;
//    for ( i = 0; i < La.length; i++)
//    {
//        printf("%d\t", La.data[i]);
//    }
//
//
//    return 0;
//}
//
//
//
//
//
