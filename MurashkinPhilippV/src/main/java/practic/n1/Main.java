package practic.n1;

import java.util.Random;
import java.util.Scanner;

public class Main {
    private static final int ARRAY_LENGTH = 20;
    private static Double[] array =  new Double[ARRAY_LENGTH];

    //1. Разработайте программу по описанию. Дан массив вещественных чисел. Вычислите
    //среднее значение и занулите элементы, которые меньше среднего
    public static void main(String[] args) {
        init();
        Double avg = getAvg(getSumm(array), array.length);
        array = setValueIfLess(array, 0.0, avg);
        calculator();
        sumRecursive(new Integer[]{4,6,7,2,8,8});
        mySort(new Integer[]{1,2,3,4,5,4,3,5,4,3,2,1,6,8,5,4,3,2,1,6,8,7,5,4,3,2,1,6,8,7,0,9,5,4,3,2,1,6,8,7,0,2,5,6,2,6,1,4,6,1,5,4,3,2,1,0,5,4,3,5,2,5,1,4,7,0,3,1,2,4,6,8,3,1,6,8,2,7,9,2,5,4,9,6,4,1,0,8,5,3,6,5,8,7,3,3,4,5,2,3,5,8,9,4,5});

    }

    private static Double[] setValueIfLess(Double[] array, Double value, Double avg) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] < avg){
                array[i] = value;
            }
        }
        return array;
    }

    //3. Разработайте рекурсивный алгоритм рассчета суммы элементов целочисленного массива
    private static Integer sumRecursive(Integer[] array, Integer n){
        if (n == 0) return array[n];
        return sumRecursive(array, n - 1) + array[n];
    }

    private static Integer sumRecursive(Integer[] arr) {
        if (arr.length == 0) return null;
        return sumRecursive(arr, arr.length - 1);
    }

    //2.2 Реализуйте алгоритмы, нарисованные на блок-схемах в виде функций
    private static void reserve(Integer[] arr, Integer n){
        Integer t = 0;
        for (int i = 0; i < n / 2; i++) {
            t = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = t;
        }
    }

    //2.1 Реализуйте алгоритмы, нарисованные на блок-схемах в виде функций
    private static void calculator(){
        Scanner scanner = new Scanner(System.in);
        Double a = scanner.nextDouble();
        Character op = scanner.next().charAt(0);
        Double b = scanner.nextDouble();
        Double result = null;
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
        }
        System.out.println(result);
    }

    private static Double getAvg(Double summ, int length) {
        return summ / length;
    }

    private static Double getSumm(Double[] array) {
        Double summ = 0.0;
        for (int i = 0; i < array.length; i++) {
            summ += array[i];
        }
        return summ;
    }

    private static void init() {
        Random rnd = new Random(1L);
        for (int i = 0; i < ARRAY_LENGTH; i++) {
            array[i] = rnd.nextDouble();
        }
    }

//    4. Разработайте следующий алгоритм сортировки. Дан массив чисел от 0 до 9.
//    Посчитайте кол-во повторений каждой из цифр и выведите отсортированный
//    массив (упорядоченный от меньшего к большему) на основе этой информации
    private static Integer[] mySort(Integer[] array){
        Integer h;
        Integer[] sort = genSort(array);
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (sort[array[j]] > sort[array[j+1]]){
                    h = array[j+1];
                    array[j+1] = array[j];
                    array[j] = h;
                }
            }
        }
        return array;
    }

    private static Integer[] genSort(Integer[] array) {
        Integer[] sort = new Integer[]{0,0,0,0,0,0,0,0,0,0};
        for (int i = 0; i < array.length; i++) {
            sort[array[i]]++;
        }
        return sort;
    }


}

