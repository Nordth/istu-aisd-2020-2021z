package linklist;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Создаем список на основе ячеек
        LinkedList<Integer> mList = new LinkedList<Integer>();
        Scanner scanner = new Scanner(System.in);
            int key;
            do{
                System.out.println("------------------------------------------");
                System.out.println("1. Просмотр списка;");
                System.out.println("2. Поиск элемента;");
                System.out.println("3. Добавить;");
                System.out.println("4. Добавить перед заданным;");
                System.out.println("5. Добавить после заданного;");
                System.out.println("6. Удаление заданного;");
                System.out.println("7. Выйти;");
                System.out.print("Введите номер меню: ");
                key = scanner.nextInt();            
                switch(key)
                {
                    case 1:
                        System.out.println(mList.toString());
                        break;
                    case 2:
                        System.out.print("Введите число для поиска: ");
                        int value = scanner.nextInt();
                        int result = mList.find(value);
                        System.out.printf("Результат поиска числа (-1 не найден): %d\n", result);
                        break;
                    case 3:
                        System.out.print("Введите число для вставки в конец: ");
                        int val = scanner.nextInt();
                        int poz = mList.size();
                        mList.add(poz, val);
                        break;
                    case 4:
                        System.out.print("Введите число перед которым вставка: ");
                        int vl = scanner.nextInt();
                        System.out.print("Введите новое число для вставки: ");
                        int nvl = scanner.nextInt();
                        mList.addBefore(vl, nvl);
                        break;
                    case 5:
                        System.out.print("Введите число после которого вставка: ");
                        int vl1 = scanner.nextInt();
                        System.out.print("Введите новое число для вставки: ");
                        int nvl1 = scanner.nextInt();
                        mList.addAfter(vl1, nvl1);
                        break;                        
                    case 6:
                        System.out.print("Введите число для удаления: ");
                        int dvl = scanner.nextInt();                        
                        mList.delete(dvl);
                        break;
                    case 7:
                        System.out.println("Завершение программы...");
                        break;
                    default:
                        System.out.println("Вы ввели неверное значение меню...\n");
                }
            }while(key!=7);
    }
}
