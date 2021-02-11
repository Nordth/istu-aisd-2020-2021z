using System;
using System.Security.Cryptography.X509Certificates;

namespace MergeSort
{
    class Program
    {
        //Преобразование массива string в массив int
        public static int[] TransformationArrays(string [] arr)
        {
            int[] intigerArr = new int[arr.Length];
            for(int i = 0; i < arr.Length; i++)
            {
                intigerArr[i] = Convert.ToInt32(arr[i]);
            }
            return intigerArr;
        }

        public static int[] Sort(int[] arr)
        {
            if (arr.Length > 1)
            {
                int[] left = new int[arr.Length / 2];
                int[] right = new int[arr.Length - left.Length];
                for (int i = 0; i < left.Length; i++)
                {
                    left[i] = arr[i];
                }
                for (int i = 0; i < right.Length; i++)
                {
                    right[i] = arr[left.Length + i];
                }
                if (left.Length > 1)
                    left = Sort(left);
                if (right.Length > 1)
                    right = Sort(right);
                arr = MergeSort(left, right);
            }
            return arr;
        }

        public static int[] MergeSort(int[] left, int[] right)
        {
            int[] arr = new int[left.Length + right.Length];
            int i = 0;
            int l = 0;
            int r = 0;
            for (; i < arr.Length; i++)
            {
                if (r >= right.Length)
                {
                    arr[i] = left[l];
                    l++;
                }
                else if (l < left.Length && left[l] < right[r])
                {
                    arr[i] = left[l];
                    l++;
                }
                else
                {
                    arr[i] = right[r];
                    r++;
                }
            }
            return arr;
        }
        public static void PrintArray(int[] arr) {

            Console.WriteLine("Ответ:");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write($"{arr[i]}, ");
            }
        }
        static void Main()
        {
            Console.WriteLine("Введите элементы массива через пробел: ");
            string elementsArr = Console.ReadLine();
            string[] strArr = elementsArr.Split(' ');
            int[] array = TransformationArrays(strArr);
            PrintArray(Sort(array));
        }   
    }
}
