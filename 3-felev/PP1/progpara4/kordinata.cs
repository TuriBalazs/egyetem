using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

namespace progpara4
{
    internal class kordinata
    {
        public double x;
        public double y;

        public kordinata(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
        public void Kiir()
        {
            Console.Write($" ({x}, {y})");
        }

    }

}
