using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace progpara10
{
    enum Síknegyed 
    {
        Valós, Imaginárius, JobbFelső, JobbAlsó, BalFelső, BalAlsó
    }

    internal abstract class AdatXY
    {
        protected int ID;
        protected string Nev;
        protected double x, y;

        public AdatXY(int id, string nev, double x, double y)
        {
            ID = id;
            Nev = nev;
            this.x = x;
            this.y = y;
        }
        public AdatXY(AdatXY other)
        {
            ID = other.ID;
            Nev = other.Nev;
            this.x = other.x;
            this.y = other.y;
        }

        public abstract double Abs();

       
    }
}
