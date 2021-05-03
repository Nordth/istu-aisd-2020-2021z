package lab.n2;

public class Main {
    public static void main(String[] args) {
        List list = new List();
        list.print();
        list.add(1);
        list.print();
        list.add(3);
        list.print();
        list.add(5);
        list.print();
        list.insertBefore(2, 2);
        list.print();
        list.insertBefore(4, 4);
        list.print();
        list.add(13);
        list.print();
        Integer val = list.get(3);
        System.out.println(val);
        list.deleteByValue(3);
        list.print();
        list.deleteByValue(1);
        list.print();
    }
}
