using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace progpara10
{
    internal class Komplex : AdatXY
    {
        Síknegyed sikn;
        double absz;

        public Komplex(int id, string nev, double x, double y) : base(id, nev, x, y)
        {
            sikn = MelyikSíknegyed();
            absz = Abs();
        }
        public Komplex(Komplex other) : base(other)
        {
            sikn = other.sikn;
            absz = other.absz;
        }

        public override string ToString()
        {
            return $"{x}+{y}*i ads: {absz}, típusa: {sikn}";
        }
        public override double Abs()
        {
            return Math.Sqrt(x * x + y * y);
        }
        public Síknegyed MelyikSíknegyed()
        {
            if(y == 0) return Síknegyed.Valós;
            if (x == 0) return Síknegyed.Imaginárius;
            if (x > 0 &&y > 0) return Síknegyed.JobbFelső;
            if (x > 0 && y < 0) return Síknegyed.JobbAlsó;
            if (x < 0 && y > 0) return Síknegyed.BalFelső;
            return Síknegyed.BalAlsó;
        }
        
    }
}
