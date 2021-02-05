using System;

namespace BubleSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int a;
            // Исходный массив 
            int[] nums = { 1,9,2,4,7,5,6,8};
            Console.WriteLine("Массив до сортировки");
            for (int k = 0; k < nums.Length; k++)
            {
                Console.Write(nums[k] + " ");
            }
            Console.WriteLine();
            // Сортировка массива
             for(int i=1; i<nums.Length; i++)
            {
                for(int j=0; j<nums.Length-i; j++)
                {
                    if(nums[j]>nums[j+1])
                    {
                        a = nums[j + 1];
                        nums[j + 1] = nums[j];
                        nums[j] = a;
                    }
                }
            }
            Console.WriteLine("Массив после сортировки");
            for(int k=0; k<nums.Length; k++)
            {
                Console.Write(nums[k] + " ");
            }
        }
    }
}
   
      