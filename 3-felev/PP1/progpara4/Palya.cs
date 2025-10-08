using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace progpara4
{
    internal class Palya
    {
        string Nev;
        kordinata[] P;
        public Palya(string nev, kordinata[] p)
        {
            if (nev.Length >= 10)
            {
                this.Nev = nev.Substring(0, 10);
            }
            else
            {
                this.Nev = nev;
            }
            this.P = p;
        }
        public void Kiir()
        {
            Console.Write($"{Nev}");
            for (int i = 0; i < P.Length; i++)
            {
                P[i].Kiir();
            }
            Console.WriteLine();
        }
        public bool Eleme(kordinata p)
        {

            for (int i = 0; i < this.P.Length; i++)
            {
                if (p.x == P[i].x && p.y == P[i].y) { return true; }
            }
            return false;
        }
        public bool VanKozosPont(Palya a, Palya b)
        {

            for (int i = 0; i < a.P.Length; i++)
            {
                for (int j = 0; j < b.P.Length; j++)
                {
                    if (a.Eleme(b.P[j])) { return true; }
                }
            }
            return false;
        }
    }
}
