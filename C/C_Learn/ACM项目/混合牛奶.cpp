//#include<stdio.h>
//#include<stdlib.h>
//
//int compare(const void* num1, const void* num2) {
//    int x1 = (*(int**)num1)[0];
//    int x2 = (*(int**)num2)[0];
//    return (x1 - x2);    // 升序
//}
//
//int main()
//{
//    /*
//        Marry 乳业从一些奶农手中采购牛奶，
//        并且每一位奶农为乳制品加工企业提供的价格可能相同。
//        此外，就像每头奶牛每天只能挤出固定数量的奶，
//        每位奶农每天能提供的牛奶数量是一定的。
//        每天 Marry 乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。
//
//        给出 Marry 乳业每天对牛奶的需求量，
//        还有每位奶农提供的牛奶单价和产量。
//        计算采购足够数量的牛奶所需的最小花费。
//
//        注：每天所有奶农的总产量不少于 Marry 乳业的需求量。
//
//        输入格式
//        第一行二个整数 n,m，
//        n 表示需要牛奶的总量，
//        m 和提供牛奶的农民个数。
//
//        接下来 m 行，每行两个整数 p a
//        p 表示第 i 个农民牛奶的单价
//        a 和农民 i 一天最多能卖出的牛奶量。
//
//        输出格式
//        单独的一行包含单独的一个整数，
//        表示 Marry 的牛奶制造公司拿到所需的牛奶所要的最小费用。
//
//        in
//        n   m
//        100 5
//        单价 个
//        5   20
//        9   40
//        3   10
//        8   80
//        6   30
//
//        out
//        630
//
//    */
//
//    // 需要的牛奶 提供牛奶的农民
//    int n, m;
//    // 牛奶的单价 最多卖出牛奶量
//    int p = 0, a = 0;
//    int minprice = 0;
//    int i;
//
//    scanf_s("%d %d", &n, &m);
//
//    // 创建牛奶单价喝卖出量的容器
//    int** priceMilk = (int**)malloc(m * sizeof(int*));
//    for (i = 0; i < m; i++)
//    {
//        priceMilk[i] = (int*)malloc(2 * sizeof(int));
//    }
//    // int* milk = (int*)malloc(10000 * sizeof(int));
//
//    // 录入数据
//    
//    for (i = 0; i < m; i++)
//    {
//        scanf_s("%d %d", &p, &a);
//        priceMilk[i][0] = p;
//        priceMilk[i][1] = a;
//        // milk[i] = a;
//    }
//
//    // 排序
//    qsort(priceMilk, m, sizeof(priceMilk[0]), compare);
//    
//    int count = n;
//    for (i = 0; i<m && count > 0;i++){
//        if (count > priceMilk[i][1])
//        {
//            minprice += priceMilk[i][0] * priceMilk[i][1];
//            count -= priceMilk[i][1];
//        }
//        else
//        {
//            minprice += priceMilk[i][0] * count;
//            count = 0;
//        }
//
//
//       /* if (count == 0)
//        {
//            break;
//        }
//        else if (count > 0)
//        {
//            if (count - priceMilk[i][1] > 0)
//            {
//                minprice += (priceMilk[i][0] * priceMilk[i][1]);
//                count -= priceMilk[i][1];
//            }
//            else if(count - priceMilk[i][1] == 0)
//            {
//                minprice += (priceMilk[i][0] * count);
//                count = 0;
//            }
//        }
//        else if (count - priceMilk[i][1] < 0)
//        {
//            minprice += (priceMilk[i][0] * count);
//            count = 0;
//        }*/
//    }
//
//    printf("%d\n", minprice);
//
//    for (i = 0; i < m; i++)
//    {
//        free(priceMilk[i]);
//    }
//
//    //free(milk);
//
//    return 0;
//}