package stackarray;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Создаем пустой стек на 5 ячеек
        Stack mStack = new Stack(5);
        Scanner scanner = new Scanner(System.in);
            int key;
            do{
                System.out.println("------------------------------------------");
                System.out.println("1. Проверка пустоты стека;");
                System.out.println("2. Проверка заполнения стекового массива;");
                System.out.println("3. Добавить в вершину стека;");
                System.out.println("4. Удалить из вершины стека;");
                System.out.println("5. Просмотр вершины стека;");
                System.out.println("6. Просмотр стека;");
                System.out.println("7. Выйти;");
                System.out.print("Введите номер меню: ");
                key = scanner.nextInt();            
                switch(key)
                {
                    case 1:
                        if(mStack.isEmpty()){
                            System.out.println("Стек пуст");
                        }else{
                            System.out.println("Стек не пуст");
                        }
                        break;
                    case 2:
                        if(mStack.isFull()){
                            System.out.println("Стек полон");
                        }else{
                            System.out.println("Стек не полон");
                        }
                        break;
                    case 3:
                        int value;
                        System.out.print("Введите число: ");
                        value = scanner.nextInt();
                        mStack.addElement(value);
                        break;
                    case 4:
                        int val = mStack.deleteElement();
						System.out.printf("Удаленный элемент: %d\n", val);
                        break;
                    case 5:
                        int top = mStack.readTop();
                        System.out.printf("TOP: %d\n", top);
                        break;
                    case 6:
                        mStack.print();
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
