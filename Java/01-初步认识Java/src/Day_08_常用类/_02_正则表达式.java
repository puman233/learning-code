package Day_08_常用类;
/*
java.util.regex 包是 Java 标准库中用于支持正则表达式操作的包
包含了 Pattern 和 Matcher 类
    Pattern 对象是一个正则表达式的编译表示
    Matcher 对象是对输入字符串进行解释和匹配操作的引擎
 */

import java.util.regex.*;
import java.util.StringTokenizer;

/*
索引方法
索引方法提供了有用的索引值，精确表明输入字符串中在哪能找到匹配：
    1	public int start()
    返回以前匹配的初始索引。
    2	public int start(int group)
    返回在以前的匹配操作期间，由给定组所捕获的子序列的初始索引
    3	public int end()
    返回最后匹配字符之后的偏移量。
    4	public int end(int group)
    返回在以前的匹配操作期间，由给定组所捕获子序列的最后字符之后的偏移量。

查找方法
查找方法用来检查输入字符串并返回一个布尔值，表示是否找到该模式：

    1	public boolean lookingAt()
     尝试将从区域开头开始的输入序列与该模式匹配。
    2	public boolean find()
    尝试查找与该模式匹配的输入序列的下一个子序列。
    3	public boolean find(int start）
    重置此匹配器，然后尝试查找匹配该模式、从指定索引开始的输入序列的下一个子序列。
    4	public boolean matches()
    尝试将整个区域与模式匹配。

替换方法
替换方法是替换输入字符串里文本的方法：

    1	public Matcher appendReplacement(StringBuffer sb, String replacement)
    实现非终端添加和替换步骤。
    2	public StringBuffer appendTail(StringBuffer sb)
    实现终端添加和替换步骤。
    3	public String replaceAll(String replacement)
     替换模式与给定替换字符串相匹配的输入序列的每个子序列。
    4	public String replaceFirst(String replacement)
     替换模式与给定替换字符串匹配的输入序列的第一个子序列。
    5	public static String quoteReplacement(String s)
    返回指定字符串的字面替换字符串。
    这个方法返回一个字符串，就像传递给Matcher类的appendReplacement 方法一个字面字符串一样工作。
*/


public class _02_正则表达式 {

    public static void main(String[] args) {

        String str1 = "I am a human";
        String str2 = "Apple";

        String strStandard = ".*am.*";

        boolean isMatch = Pattern.matches(strStandard, str1);
        boolean isMatch2 = Pattern.matches(strStandard, str2);
        System.out.println("是否包含am：");
        System.out.println(isMatch);
        System.out.println(isMatch2);

        System.out.println("\\\\" + "\n" + "\\");


        /*
        public boolean find()
            尝试查找与该模式匹配的输入序列的下一个子序列。
        public int start(int group)
            返回在以前的匹配操作期间，由给定组所捕获的子序列的初始索引
        public int end()
            返回最后匹配字符之后的偏移量。
         */

        String regex1 = "\\bcat\\b";
        String str3 = "cat cat cat cattle cat";

        // 使用 Pattern.compile() 方法创建模式
        Pattern pattern1 = Pattern.compile(regex1);
        Matcher matcher1 = pattern1.matcher(str3);

        int count = 0;
        while (matcher1.find()) {
            count++;
            System.out.println("match num:" + count + "\tname:" + matcher1.group() + "\tstart:" + matcher1.start() + " \tend:" + matcher1.end());
        }


        /*
        public String replaceAll(String replacement)
         替换模式与给定替换字符串相匹配的输入序列的每个子序列。
        public String replaceFirst(String replacement)
         替换模式与给定替换字符串匹配的输入序列的第一个子序列。
         */

        String regex2 = "apple pie";
        String str4 = "An apple fell from the sky and was turned into apple pie by Xiao Le.\n" +
                "One apple pie, two apple pie, lots of apple pie";
        String rep = "ah-pulu-pie";

        System.out.println(str4);

        Pattern pattern2 = Pattern.compile(regex2);
        Matcher matcher2 = pattern2.matcher(str4);

        str4 = matcher2.replaceAll(rep);
        System.out.println(str4);

        System.out.println();
        /*
        public Matcher appendReplacement(StringBuffer sb, String replacement)
            实现非终端添加和替换步骤。
        public StringBuffer appendTail(StringBuffer sb)
            实现终端添加和替换步骤。
         */

        String regex3 = "(\\d{2})([a-z]{2,3})";
        String str5 = "33aa-32sdy-29ssc";
        String rep2 = "$2";

        Pattern pattern3 = Pattern.compile(regex3);
        Matcher matcher3 = pattern3.matcher(str5);

        StringBuffer sb = new StringBuffer();
        count = 0;
        while (matcher3.find()) {
            count++;
            System.out.println("num:" + count + "\tgroup:" + matcher3.group());
            matcher3.appendReplacement(sb, rep2);
        }
        matcher3.appendTail(sb);
        System.out.println(sb.toString());

        System.out.println();
        /*
        StringTokenizer 类用于构建一个解析器，
        允许程序把字符串按照指定的分隔符集合拆分为标记（Token）。
        常用构造方法：
            public StringTokenizer(String str, String delim)
            delim 中的每个字符都会被当做一个独立的分隔符。

        常用方法：
            hasMoreTokens(): 是否还有未解析的 Token
            nextToken(): 返回下一个 Token
            countTokens(): 返回当前剩余的 Token 总数
         */

        String Str0 = "Apple 12, Banana 5, Orange 20";

        // 空格和逗号
        String delimiters = " ,";

        // StringTokenizer 遇到空格或者逗号就把字符串切断
        // 同时自动过滤掉了这些分隔符
        StringTokenizer tokenizer = new StringTokenizer(Str0, delimiters);
        System.out.println("Token 总数: " + tokenizer.countTokens());

        int index = 1;
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            System.out.print("Token:" + index + "\t \"" + token + "\"\t");
            index++;

            // 判定数字
            if (Pattern.matches("\\d+", token)) {
                System.out.println("数字");
            }
            // 判定字母
            else if (Pattern.matches("[a-zA-Z]+", token)) {
                System.out.println("字母");
            }
            // 其他类型
            else {
                System.out.println("其他");
            }
        }
        System.out.println();

        // 判定qq号
        String rawData = "1234567, 012345, 998877665544, abc12345, 10000, 666ddd";
        String regex = "[1-9]\\d{4,10}";
        StringTokenizer tokenizer1 = new StringTokenizer(rawData, delimiters);

        index = 1;
        while (tokenizer1.hasMoreTokens()) {
            String token = tokenizer1.nextToken();
            System.out.print("Token:" + index + "\t \"" + token + "\"\t");
            index++;

            if(Pattern.matches(regex, token)) {
                System.out.println("是");
            }
            else {
                System.out.println("非");
            }
        }

    }
}

/*
    1. 字符类

    [abc]        -> 匹配 a、b 或 c 中的任意单个字符
    [^abc]       -> 匹配除了 a、b、c 之外的任意单个字符（否定）
    [a-zA-Z]     -> 匹配 a 到 z 或 A 到 Z 的任意单个英文字母（范围）
    [a-d[m-p]]   -> 匹配 a 到 d 或 m 到 p 的任意单个字符（并集）
    [a-z&&[def]] -> 匹配 d、e 或 f 中的任意单个字符（交集）

    2. 预定义字符类（注意：Java 字符串中需写成双反斜杠 \\）

    .            -> 匹配任意单个字符（行结束符除外）
    \\d          -> 匹配任意一个数字，等价于 [0-9]
    \\D          -> 匹配任意一个非数字字符，等价于 [^0-9]
    \\s          -> 匹配任意一个空白字符（空格、制表符 \t、换行符 \n 等）
    \\S          -> 匹配任意一个非空白字符
    \\w          -> 匹配任意一个单词字符（字母、数字、下划线），等价于 [a-zA-Z_0-9]
    \\W          -> 匹配任意一个非单词字符

    3. 边界匹配器

    ^            -> 匹配一行的开头
    $            -> 匹配一行的结尾
    \\b          -> 匹配单词边界（例如字母与空格之间，或字母与标点之间）
    \\B          -> 匹配非单词边界

    4. 数量词

    X?           -> X 出现 0 次或 1 次（最多 1 次）
    X*           -> X 出现 0 次或多次（任意次）
    X+           -> X 出现 1 次或多次（至少 1 次）
    X{n}         -> X 恰好出现 n 次
    X{n,}        -> X 至少出现 n 次
    X{n,m}       -> X 出现至少 n 次，但绝对不超过 m 次

 */