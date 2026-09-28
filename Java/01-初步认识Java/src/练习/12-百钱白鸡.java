package 练习;

class 百钱白鸡 {
    public static void main(String[] args) {
        /*
            故事：张邱建买鸡，公鸡5文钱一只，母鸡3文钱一只，小鸡1文钱3只。
                用一百文钱买一百只鸡，问：买公鸡、母鸡、小鸡各德几只？
         */
        //第一层循环，用于表示公鸡的范围，初始化表达式的变量定义为 x = 0
        for (int dataOld = 0; dataOld < 20; dataOld++) {
            //第二层循环，表示母鸡的范围
            for (int dataGirl = 0; dataGirl < 33; dataGirl++) {
                //小鸡的数量：dataSmall = 100 - dataOld - dataGirl
                int dataSmall = 100 - dataOld - dataGirl;

                //判断表达式是否成立
                if (dataSmall % 3 == 0 && dataOld * 5 + dataGirl * 3 + dataSmall / 3 == 100) {
                    System.out.println("公鸡" + dataOld + "只");
                    System.out.println("母鸡" + dataGirl + "只");
                    System.out.println("小鸡" + dataSmall + "只");
                }
            }
        }
    }
}
