using System;
using System.Security.Cryptography.X509Certificates;

namespace InsertionSort
{
    class Program
    {
        public int[] InsertionSort(int[] arr)
        {
            int[] result = new int[arr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                int j = i;
                while (j > 0 && result[j - 1] > arr[i])
                {
                    result[j] = result[j - 1];
                    j--;
                }
                result[j] = arr[i];
            }
            return result;
        }
        static void Main()
        {
            Console.WriteLine("Введите елементы массива через пробел: ");
            string stringElements = Console.ReadLine();
            string[] stringArr = stringElements.Split(" ");
            int[] arr = new int[stringArr.Length];
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = Convert.ToInt32(stringArr[i]);
            }
            Program a = new Program();
            int[] sortedArr = a.InsertionSort(arr);
            for (int i = 0; i < sortedArr.Length; i++)
            {
                Console.Write($"{sortedArr[i]} ");
            }

        }
    }
}