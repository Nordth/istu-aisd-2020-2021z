using System;

namespace Algorythm2
{
    class Quick_Sorting
    {
        public static void QuickSort(int[] input, int left, int right)
        {
            if (left < right)
            {
                int q = Partition(input, left, right);
                QuickSort(input, left, q - 1);
                QuickSort(input, q + 1, right);
            }
        }

        private static int Partition(int[] input, int left, int right)
        {
            print(input);
            // reference - opornoe chislo. prinimaem za nego krayniy praviy element ishodnogo massiva
            int reference = input[right];
            int x;

            int i = left;
            // sravnivaem vse elementi c 1-go s opornim
            for (int j = left; j < right; j++) // polzem sleva napravo po massivu
            {
                // sdvigaem oporniy element na ego mesto
                if (input[j] <= reference)
                {
                    x = input[j];
                    input[j] = input[i];
                    input[i] = x;
                    i++;
                }
            }

            input[right] = input[i];
            input[i] = reference;

            return i;
        }

        public static void print(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
        }
        static void Main(string[] args)
        {
            
            int[] arr = { 5, 7, 3, 4, 1 };

            Console.WriteLine("Before Sorting");
            print(arr);
            Console.WriteLine('\n'+ "Sorting starts:");
            QuickSort(arr, 0, arr.Length - 1);
            Console.WriteLine("Sorting ends." + '\n');
            Console.WriteLine("After Sorting");
            print(arr);
            Console.ReadKey();

        }
    }
}