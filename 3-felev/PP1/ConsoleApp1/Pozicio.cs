using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Pozicio
    {
        public int x;
        public int y;

        public Pozicio(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {

            return $"({x}, {y}); ";
        }
    }
}
