package lab.n3;

public class Main {
    public static void main(String[] args) {
        HashTable table = new HashTable();
        String value;
        table.put(1, "One");
        System.out.println(table);
        table.put(3, "Three");
        System.out.println(table);
        table.put(5, "Five");
        System.out.println(table);
        table.put(2, "Two");
        System.out.println(table);
        table.put(4, "Four");
        System.out.println(table);
        table.put(7, "Seven");
        System.out.println(table);
        table.put(9, "Nine");
        System.out.println(table);
        table.put(11, "Eleven");
        System.out.println(table);
        table.put(8, "Eight");
        System.out.println(table);

        value = table.get(4);
        System.out.println(value);
        value = table.get(22);
        System.out.println(value);

        table.remove(4);
        System.out.println(table);

        table.put(4, "Four 2");
        System.out.println(table);
        table.put(7, "Seven 2");
        System.out.println(table);

        table.clear();
    }
}
