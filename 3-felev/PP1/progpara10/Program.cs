namespace progpara10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Komplex> list = new List<Komplex>();
			try
			{
                StreamReader sr = new StreamReader("C:\\Users\\4-110-4\\source\\repos\\progpara10\\progpara10\\adat.txt");
                while (!sr.EndOfStream)
                {
                    string line = sr.ReadLine();
                    string[] d = line.Split();
                    int id = int.Parse(d[0]);
                    string nev = d[1];
                    double x = double.Parse(d[2]), y = double.Parse(d[3]);
                    Komplex k = new Komplex(id, nev, x, y);
                    list.Add(k);
                }
                sr.Close();

                foreach (Komplex k in list)
                {
                    Console.WriteLine(k);
                }
            }
			catch (Exception e)
			{
                Console.WriteLine(e.Message);
			}
        }
    }
}
