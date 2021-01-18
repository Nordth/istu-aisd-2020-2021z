using System;

namespace Zadacha4
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 1, 5, 7, 9, 4, 5, 5, 1, 2, 5, 4, 5, 8, 5 };
            int[] reps = new int[10];
            int k = 0;

            for (int i = 0; i != arr.Length; i++)
            {
                reps[arr[i]]++;
            }

            for (int i = 0; i != 10; i++)
            {
                if (reps[i] > 0)
                {
                    Console.WriteLine(i + " - " + reps[i] + " повторов" + '\n');
                }
            }

            for(var i= 0; i!=reps.Length;i++)
            {
                while (reps[i] != 0)

                {
                    arr[k] = i;
                    k++;
                    reps[i]--;
                }
            }
            Console.Write('\n' + "Source array " + arr[0]);

            for (var i = 0; i != arr.Length; i++)
                Console.Write (", " + arr[i]);
            Console.ReadKey();
        }
    }
}