using System;


namespace CSharpMergeSort
{
    class Mergesort
    {
        //Метод проверяет длину массива 
        static int[] Division(int[] arr)
        {
            if (arr.Length > 1)
            {

                int[] left = new int[arr.Length/2];
                // Проверка на случай не чётности массива
                int[] right = new int[arr.Length - left.Length];

                for (int i = 0; i < left.Length; i++)
                {
                    left[i] = arr[i];
                }
                for (int i = 0; i < right.Length; i++)
                {
                    right[i] = arr[left.Length + i];
                }
                // Рекурсивные методы деления массива
                if (left.Length > 1)
                    left = Division(left);
                if (right.Length > 1)
                    right = Division(right);
               
                arr = MergeSort(left, right);
            }
            return arr;
        }
        // Сортировка нашим вариантом
        static int[] MergeSort(int[] left, int[] right)
        {
            int[] arr = new int[left.Length + right.Length];
            
            int singlarr = 0; 
            int leftarr = 0;
            int rightarr = 0;

            for (; singlarr < arr.Length; singlarr++)
            {
                if(rightarr >=right.Length)
                {
                    arr[singlarr] = left[leftarr];
                    leftarr++;
                }
                else if (leftarr < left.Length && left[leftarr] < right[rightarr])
                {
                    arr[singlarr] = left[leftarr];
                    leftarr++;
                }
                else
                {
                    arr[singlarr] = right[rightarr];
                    rightarr++;
                }
            }
            return arr;
        }
        static void Main(string[] args)
        {
            Console.Write("Введите размер массива - ");
            int len = int.Parse(Console.ReadLine());
            int[] mass = new int[len];
            Random rand = new Random();
            Console.Write("Массив до сортировки - ");
            for (int i = 0; i < mass.Length; i++)
            {
                mass[i] = rand.Next(15);
                
                Console.Write(mass[i]+ " ");
            }
            Console.WriteLine();
            mass = Division(mass);

            
            Console.Write("Массив после сортировки - ");
         
            foreach (int element in mass)
            {
                Console.Write(element + " ");
            }
        }
    }

    
}

