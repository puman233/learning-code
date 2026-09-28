package Day_08_常用类;

public class _01_String {

    public static void main(String[] args){

        /*
        compareTo() 方法用于两种方式的比较：
        字符串与对象进行比较。
        按字典顺序比较两个字符串。
        语法
        int compareTo(Object o)
        int compareTo(String anotherString)

        如果参数字符串等于此字符串，则返回值 0；
        如果此字符串小于字符串参数，则返回一个小于 0 的值；
        如果此字符串大于字符串参数，则返回一个大于 0 的值。

        如果第一个字符和参数的第一个字符不等，结束比较，
        返回第一个字符的ASCII码差值。

        如果第一个字符和参数的第一个字符相等，
        则以第二个字符和参数的第二个字符做比较，
        以此类推,直至不等为止，返回该字符的ASCII码差值。

        如果两个字符串不一样长，可对应字符又完全一样，
        则返回两个字符串的长度差值。
        */

        String str1 = "Abc";
        String str2 = "abc";
        String str3 = "aBc";
        String str4 = "Abcde";

        int res1 = str1.compareTo(str2);    // A - a
        System.out.println(res1);
        int res2 = str2.compareTo(str3);    // b - B
        System.out.println(res2);
        int res3 = str3.compareTo(str1);    // a - A
        System.out.println(res3);
        int res4 = str1.compareTo(str4);
        System.out.println("length差:" + (str1.length() - str4.length()));
        System.out.println("compare差:" + res4);

        // compareToIgnoreCase() 方法用于按字典顺序比较两个字符串，不考虑大小写。
        int res5 = str1.compareToIgnoreCase(str2);
    
        System.out.println(res5);

        System.out.println();

        /*
        concat() 方法用于连接两个字符串。
        需要注意的是，concat() 方法不会修改原字符串，而是返回一个新的字符串
        语法
            public String concat(String s)
            concat
         */
        String tstr1 = str1.concat(str2);
        System.out.println("str1 + str2 :" + tstr1);

        /*
        contains() 方法用于判断字符串中是否包含指定的字符或字符串。
        语法
            public boolean contains(CharSequence chars)
            contains
        */

        System.out.println(
                "str1 是否包含 a:" + str1.contains("a") +
                "\nstr2 是否包含 b:" + str2.contains("b") +
                "\nstr3 是否包含 C:" + str3.contains("C")
        );

        System.out.println();

        /*
        它将指定字符数组中的所有字符复制到一个新的字符数组中
        并返回一个新的字符串

        public static String copyValueOf(char[] data):
            返回指定数组中表示该字符序列的字符串。

        public static String copyValueOf(char[] data, int offset, int count):
            返回指定数组中表示该字符序列的字符串。
                data -- 字符数组
                offset -- 子数组的初始偏移量
                count -- 子数组的长度

        toCharArray() 方法将字符串转换为字符数组。
            语法
            public char[] toCharArray()
         */
        char[] str11 = str1.toCharArray();
        char[] str12 = str2.toCharArray();

        String copyStr1 = "";
        copyStr1 = String.copyValueOf(str11);
        System.out.println(copyStr1);
        copyStr1 = String.copyValueOf(str12);
        System.out.println(copyStr1);
        String copyStr2 = "";

        copyStr2 = String.copyValueOf(str11,1,2);
        System.out.println(copyStr2);
        copyStr2 = String.copyValueOf(str12, 2,1);
        System.out.println(copyStr2);

        System.out.println();
        /*
        toLowerCase() 方法将字符串转换为小写。
        语法
            public String toLowerCase()
        toUpperCase() 方法将字符串小写字符转换为大写。
        语法
            public String toUpperCase()
         */
        String lowerStr1 = str1.toLowerCase();
        String lowerStr2 = str2.toLowerCase();
        System.out.println("lowerStr1:" + lowerStr1);
        System.out.println("lowerStr2:" + lowerStr2);

        String upperStr1 = str1.toUpperCase();
        String upperStr2 = str2.toUpperCase();
        System.out.println("upperStr1:" + upperStr1);
        System.out.println("upperStr2:" + upperStr2);

        /*
        toString() 方法返回此对象本身（它已经是一个字符串）。
        语法
            public String toString()
         */

        char[] str13 = {'M', 'i', 'k', 'u'};
        String Str13 = new String(str13);
        System.out.println(Str13);
        System.out.println(Str13.toString());

        System.out.println();

        /*
        trim() 方法用于删除字符串的头尾空白符。
        语法
            public String trim()
         */

        String str5 = "  abc  ";
        System.out.println("str5:" + str5);
        System.out.println("str5.trim():" + str5.trim());

        /*
        substring() 方法返回字符串的子字符串。
        语法
            public String substring(int beginIndex)
                or
            public String substring(int beginIndex, int endIndex)
         */

        String Lstr1 = "KFC V 我 50 !";

        String subStr1 = Lstr1.substring(0,3);
        System.out.println(subStr1);    // KFC
        String subStr2 = Lstr1.substring(0,2);
        System.out.println(subStr2);    // KF
        String subStr3 = Lstr1.substring(4);
        System.out.println(subStr3);    // V 我 50 !


        /*
        replace() 方法
        通过用 newChar 字符替换字符串中出现的所有 searchChar 字符，
        并返回替换后的新字符串
        语法
            public String replace(char searchChar, char newChar)
         */

        String reStr1 = Lstr1.replace('V', '?');
        System.out.println(reStr1);

        System.out.println();

        /*
        public int indexOf(int ch):
            返回指定字符在字符串中第一次出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。

        public int indexOf(int ch, int fromIndex):
            返回从 fromIndex 位置开始查找指定字符在字符串中第一次出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。

        int indexOf(String str):
            返回指定字符在字符串中第一次出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。

        int indexOf(String str, int fromIndex):
            返回从 fromIndex 位置开始查找指定字符在字符串中第一次出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。
         */

        String Lstr2 = "I don't wanna wake up from this sweet sweet dream";

        System.out.println("index(b):" + Lstr2.indexOf("b"));
        System.out.println("index(t):" + Lstr2.indexOf("t"));
        System.out.println("index(t, 10):" + Lstr2.indexOf("t", 10));
        System.out.println("index(wake):" + Lstr2.indexOf("wake"));

        /*
        public int lastIndexOf(int ch):
            返回指定字符在此字符串中最后一次出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。

        public int lastIndexOf(int ch, int fromIndex):
            返回指定字符在此字符串中最后一次出现处的索引，
            从指定的索引处开始进行反向搜索，
            如果此字符串中没有这样的字符，则返回 -1。

        public int lastIndexOf(String str):
            返回指定子字符串在此字符串中最右边出现处的索引，
            如果此字符串中没有这样的字符，则返回 -1。

        public int lastIndexOf(String str, int fromIndex):
            返回指定子字符串在此字符串中最后一次出现处的索引，
            从指定的索引开始反向搜索，
            如果此字符串中没有这样的字符，则返回 -1。
         */

        System.out.println("lastIndex(b):" + Lstr2.lastIndexOf("b"));
        System.out.println("lastIndex(t):" + Lstr2.lastIndexOf("t"));
        System.out.println("lastIndex(t, 10):" + Lstr2.lastIndexOf("t", 10));
        System.out.println("lastIndex(wake):" + Lstr2.lastIndexOf("wake"));

        /*
        startsWith() 方法用于检测字符串是否以指定的前缀开始。
        语法
            public boolean startsWith(String prefix, int toffset)
                or
            public boolean startsWith(String prefix)
         */
        System.out.println(Lstr2.startsWith("I"));
        System.out.println(Lstr2.startsWith("wake", 14));
        System.out.println(Lstr2.endsWith("i"));

        System.out.println();
        /*
        valueOf(boolean b): 返回 boolean 参数的字符串表示形式。.
        valueOf(char c): 返回 char 参数的字符串表示形式。
        valueOf(char[] data): 返回 char 数组参数的字符串表示形式。
        valueOf(char[] data, int offset, int count): 返回 char 数组参数的特定子数组的字符串表示形式。
        valueOf(double d): 返回 double 参数的字符串表示形式。
        valueOf(float f): 返回 float 参数的字符串表示形式。
        valueOf(int i): 返回 int 参数的字符串表示形式。
        valueOf(long l): 返回 long 参数的字符串表示形式。
        valueOf(Object obj): 返回 Object 参数的字符串表示形式。
         */

        double tlength = 123.11;
        boolean ttt = true;
        long lnum = 1143241442;

        System.out.println(String.valueOf(lnum));
        System.out.println(String.valueOf(tlength));
        System.out.println(String.valueOf(ttt));
        System.out.println(String.valueOf(str13));

    }



}
