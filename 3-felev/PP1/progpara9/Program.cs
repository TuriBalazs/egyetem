namespace progpara9
{
    internal class Program
    {
       
        static void Main(string[] args)
        {
            List<int> eredmenyek = new List<int>() {444, 666, 555 };
            Versenyzo versenyzok = new Versenyzo(0, "Ádám", eredmenyek);
            Console.WriteLine(versenyzok);

            versenyzok.SetID(1);
            Console.WriteLine(versenyzok);
            versenyzok.SetNev("Tamás");
            Console.WriteLine(versenyzok);
            Versenyzo v;
            List<Versenyzo> verseny = new List<Versenyzo>();
            Console.WriteLine();
            try
            {
                StreamReader sr = new StreamReader("C:\\Users\\4-110-4\\source\\repos\\progpara9\\progpara9\\adatok.txt");
                while (!sr.EndOfStream)
                {
                    string line = sr.ReadLine();
                    string[] d = line.Split();
                    int id = int.Parse(d[0].Substring(1));
                    string nev = $"{d[1]} {d[2]}";
                    List<int> list = new List<int>();
                    for (int i = 3; i < d.Length; i++)
                    {
                        int x= int.Parse(d[i]);
                        list.Add(x);
                    }
                    v = new Versenyzo(id, nev, list);
                    verseny.Add(v);
                }
                sr.Close();
                foreach (var x in verseny)
                {
                    Console.WriteLine(x);
                }

                verseny.Sort();
                Console.WriteLine("Rendezett:");
                foreach (var x in verseny)
                {
                    Console.WriteLine(x);
                }

                Console.WriteLine("Azonos nevü: ");
                for (int i = 0; i < verseny.Count; i++)
                {
                    for (int j = i + 1; j < verseny.Count; j++)
                    {
                        if (verseny[i].GetNev() == verseny[j].GetNev())
                        {
                            Console.WriteLine(verseny[i]);
                            Console.WriteLine(verseny[j]);
                        }
                    }
                }

            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }
    }
}
