using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace progpara9
{
    internal class Versenyzo : IComparable<Versenyzo>
    {
        int ID;
        string Nev;
        List<int> Eredmenyek;

        public Versenyzo(int id, string nev, List<int> eredmenyek)
        {
            this.ID = id;
            this.Nev = nev;
            this.Eredmenyek = eredmenyek;
        }

        public Versenyzo()
        {
            Eredmenyek = new List<int> { };
        }
        public int GetID() { return ID; }
        public string GetNev() { return Nev; }
        public void SetID(int id) { this.ID = id; }
        public void SetNev(string nev) { this.Nev = nev; }

        public int legjobbUgras()
        {
            int temp = 1;
            if (Eredmenyek.Count > 0)
            {
                for (int i = 0; i < Eredmenyek.Count; i++)
                {
                    if (temp < Eredmenyek[i])
                    {
                        temp = Eredmenyek[i];
                    }
                }
            }
            return temp;
        }

        public override string? ToString()
        {
            string szoveg = $"ID: {ID}, Név: {Nev}, Eredmenyek: ";
            for (int i = 0; i < Eredmenyek.Count; i++)
            {
                szoveg += $"{ Eredmenyek[i]}, ";
            }
            
            szoveg += $"Legjobb: {legjobbUgras()}";
            return szoveg;
        }

        public int CompareTo(Versenyzo? other)
        {
            return other.legjobbUgras().CompareTo(this.legjobbUgras());
        }
    }
}
