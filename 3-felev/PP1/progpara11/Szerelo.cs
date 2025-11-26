using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace progpara11
{
    internal class Szerelo : Dolgozo, IComparable<Szerelo>
    {
        char munkakor;
        public bool[] foglaltsag = new bool[10];

        public char Munkakor
        {
            get { return munkakor; }
            set { munkakor = value; }
        }
        public Szerelo(string nev, int oraber, char munkakor) : base(nev, oraber)
        {
            this.munkakor = munkakor;
            for (int i = 0; i < 10; i++)
            {
                foglaltsag[i] = true;
            }
        }
        

        public int FoglaltsagiSzint()
        {
            int f = 0;
            for (int i = 0; i < foglaltsag.Length; i++)
            {
                if (foglaltsag[i] == false) f++;
            }
            return f;
        }

        public int CompareTo(Szerelo? other)
        {
           return this.FoglaltsagiSzint().CompareTo(other.FoglaltsagiSzint());
        }

        public override bool Szabad_e_ekkor(int kezd, int hossz)
        {
            for (int i = kezd; i < kezd + hossz; i++)
            {
                if (!foglaltsag[i])
                {
                    return false;
                }
            }
            
            return true;
        }

        public override string? ToString()
        {
            string foglalt = "";
            for (int i = 0; i < foglaltsag.Length; i++)
            {
                if (foglaltsag[i] == false)
                {
                    foglalt += "X";
                } else
                {
                    foglalt+= "-";
                }
            }
            
            return $"{nev}, órabér: {oraber}, munkakör: {munkakor}, foglaltság: {foglalt}";
        }

        public static bool Foglal(List<Szerelo> szer, char mk, int kezd, int hossz)
        {
            for (int i = 0; i < szer.Count; i++)
            {
                if (szer[i].munkakor == mk && szer[i].Szabad_e_ekkor(kezd,hossz))
                {
                    for (int j = kezd; j < kezd + hossz; j++) 
                    {
                        szer[i].foglaltsag[j] = false;
                    }
                    szer.Sort();
                    return true;
                }
            }
            return false;
        }
    }
}
