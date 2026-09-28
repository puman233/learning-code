package Day_12_高级;

import java.util.HashMap;
import java.util.Map;


public class _03_HashMap {

    public static void main(String[] args) {

        HashMap<Integer, String> map = new HashMap<>();

        // 插入数据
        map.put(1, "a");
        map.put(2, "b");
        map.put(3, "c");

        // 更新数据
        map.replace(2, "Miku");
        System.out.println(map.get(1));

        // 获取值
        String value = map.get(2);
        System.out.println(value);

        // 判断值是否存在
        System.out.println(map.containsKey(1));
        System.out.println(map.containsValue("Miku"));

        // 删除
        map.remove(1);
        System.out.println(map.get(1));
        System.out.println(map);

        for (Map.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " : " + entry.getValue());
        }

    }


}
