using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Рекурсия
{
    class Program
    {
        static int Sum(int[] Array, int i = 0)
        {
            if (i >= Array.Length) // сравниваем индекс складываемого элемента с длиной массива
                return 0;
            else
                return Array[i] + Sum(Array, i + 1); // если индекс i != Длине то ...



        }

        static void Main(string[] args)
        {
            int[] Array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            Console.WriteLine (Sum(Array));
            Console.ReadKey();
        }
    }
}
