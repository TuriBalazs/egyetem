using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal abstract class Figura
    {
        protected char Nev;
        protected Pozicio Poz;
        protected List<Pozicio> EddigiLepesek;
        protected Random rnd;

        public Figura(int x, int y, char nev)
        {
            if (x < 0 || x > 7)
            {
                x = 0;
            }
            if (y < 0 || y > 7)
            {
                y = 0;
            }
            this.Poz = new Pozicio(x, y);
            this.Nev = nev;
            this.EddigiLepesek = new List<Pozicio>();
            EddigiLepesek.Add(this.Poz);
            this.rnd = new Random();
        }

        public void Kirajzol()
        {
            Console.Clear();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if(this.Poz.x == i && this.Poz.y == j)
                    {
                        Console.Write(Nev + " ");
                    }
                    else
                    {
                        Console.Write("0 ");
                    }
                }
                Console.WriteLine();
            }
        }

        public abstract List<Pozicio> LehetsegesLepesek();

        public void VeletlenLep()
        {
            List<Pozicio> lepesek = LehetsegesLepesek();
            int V = rnd.Next(0, lepesek.Count);
            this.Poz.x = lepesek[V].x;
            this.Poz.y = lepesek[V].y;
            EddigiLepesek.Add(lepesek[V]);
        }
        public void LepesekListaz()
        {
            foreach (Pozicio i in EddigiLepesek)
            {
                Console.Write(i.ToString());
            }
        }
    }
}
