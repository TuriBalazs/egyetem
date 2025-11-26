using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace progpara11
{
    internal abstract class Dolgozo
    {
        protected string nev;
        protected int oraber;

        public string Nev
        {
            get { return nev; }
            set { if(nev.Length > 5 && nev.Length < 30) nev = value; }
        }
        public Dolgozo(string nev, int oraber)
        {
            this.nev = nev;
            this.oraber = oraber;
        }

        public abstract bool Szabad_e_ekkor(int kezd, int hossz);
    }
}
