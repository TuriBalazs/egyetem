namespace progpara4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
            kordinata[] tp = { new kordinata(1, 2), new kordinata(2, 3), new kordinata(3, 4), new kordinata(4, 5), new kordinata(5, 6), new kordinata(6, 7), new kordinata(7, 8) };

            Palya palya = new Palya("asdfghjklmnbv", tp);

            palya.Kiir();
            kordinata teszt = new kordinata(1, 2);
            Console.WriteLine(palya.Eleme(teszt));
            */
            Palya[] palyak = new Palya[10];
            int k = 0;
            try
            {
                StreamReader sr = new StreamReader("C://Munka//palya.txt");

                while (!sr.EndOfStream)
                {
                    string line = sr.ReadLine();
                    string[] d = line.Split();
                    string nev = d[0];
                    kordinata[] kordinatas = new kordinata[(d.Length-1)/4];
                    for (int i = 0; i < kordinatas.Length*4+1; i++)
                    {
                        kordinatas[i] = new kordinata(double.Parse(d[4+i+4]), double.Parse(d[4+i+2]));
                    }
                    Palya p = new Palya(nev, kordinatas);
                    palyak[k] = p;
                }
                for (int i = 0; i < palyak.Length;i++)
                {
                    palyak[i].Kiir();
                }
                
            }
            catch (Exception e)
            {

                Console.WriteLine(e.Message);
            }

        }
    }
}
