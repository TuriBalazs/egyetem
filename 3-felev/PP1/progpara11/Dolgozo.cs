using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace progpara11
{
    internal abstract class Dolgozo // az absztrakt classból lehet adatokat származtatni más classokhoz
    {
        protected string nev;
        protected int oraber;

        public string Nev // getter, setter: alternativa az értékadáshoz.
        {
            get { return nev; }
            set { if(nev.Length > 5 && nev.Length < 30) nev = value; }
        }
        public Dolgozo(string nev, int oraber) // a konstruktor: csak ez fér hozzá privát és protected változókhoz. ez ad értéket nekik
        {
            this.nev = nev;
            this.oraber = oraber;
        }

        public abstract bool Szabad_e_ekkor(int kezd, int hossz);
    }
}

