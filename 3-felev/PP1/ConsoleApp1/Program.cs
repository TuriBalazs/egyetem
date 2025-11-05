namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Kiraly k = new Kiraly(3,3);

            k.Kirajzol();

            for (int i = 0; i < 10; i++)
            {
                Console.ReadKey();
                k.VeletlenLep();
                k.Kirajzol();
            }
            k.LepesekListaz();

        }
    }
}
