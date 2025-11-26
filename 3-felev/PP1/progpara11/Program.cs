namespace progpara11
{
    internal class Program
    {
        static void Main(string[] args)
        {
			List<Szerelo> list = new List<Szerelo>();
			try
			{
				StreamReader sr = new StreamReader("C:\\Users\\4-110-4\\source\\repos\\progpara11\\progpara11\\szerelok.txt");
				while (!sr.EndOfStream)
				{
					string line = sr.ReadLine();
					string[] d = line.Split();
					string nev = $"{d[0]} {d[1]}";
					int oraber = int.Parse(d[2]);
					char munkakor = char.Parse(d[3]);
					Szerelo sz = new Szerelo(nev, oraber, munkakor);
					list.Add(sz);
				}
				sr.Close();

                Console.WriteLine("foglalás előtt");
				foreach (Szerelo sz in list)
				{
					Console.WriteLine(sz);
				}

				Szerelo.Foglal(list, 'm', 2, 4);

                Console.WriteLine("foglalás után");
                foreach (Szerelo sz in list)
                {
                    Console.WriteLine(sz);
                }

            }
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
			}
        }
    }
}
