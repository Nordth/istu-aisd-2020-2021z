using System;

namespace Laboratornaya_1
{
    class Program
    {
        static void sortingAlgorithm(int[] input)
        {
            for (int i = 0; i < input.Length - 1; i++) // Iskluchaem perviy element
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (input[j - 1] > input[j]) // esli proshliy element bolshe tekushego
                    {
                        int x = input[j - 1];
                        input[j - 1] = input[j]; // to menyaem ih mestami
                        input[j] = x;
                    }
                }
                print(input);
            }
        }
        public static void print(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
        }

        static void Main(string[] input)
        {
            int[] array = { 4, 5, 7, 1, 12, 6, 8, 91, 16, 0 };
            Console.WriteLine("Before sorting:");
            print(array);
            Console.WriteLine("Sorting starts:");
            sortingAlgorithm(array);
            Console.WriteLine("Sorting ends.");
            Console.WriteLine("After sorting:");
            print(array);
            Console.ReadKey();
        }
    }
}
