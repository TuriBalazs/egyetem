namespace PP1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
            int n = -1;
            bool yes = false;
            Console.WriteLine("Adjon meg egy pozitív egész számot.");

            do {
                n = int.Parse(Console.ReadLine());
                if (n > 0) { yes = true; }
                else { yes = false; Console.WriteLine("A megadot szám nem megfelelő!"); }
            }while (!yes);

            int h = 1;
            for (int i = 0; i <= n; i++) {
                
                Console.WriteLine($"2^{i} = {h}" );
                   h *= 2;
            }
            */

            int n = -1;
            bool yes = false;
            Console.WriteLine("Adjon meg egy 1-nél nagyobb pozitív egész számot.");

            do
            {
                n = int.Parse(Console.ReadLine());
                if (n > 1) { yes = true; }
                else { yes = false; Console.WriteLine("A megadot szám nem megfelelő!"); }
            } while (!yes);

            int szam1 = 0;
            int szam2 = 1;
            int h = -1;
            Console.WriteLine($"A fibonacsi sorozat számai {n} elemmel:");
            Console.Write($"{szam1} ");
            Console.Write($"{szam2} ");
            for (int i = 0; i <= n; i++)
            {
                h = szam1 + szam2;
                szam1 = szam2;
                szam2 = h;
                Console.Write($"{h} ");
            }

        }
    }
}
