using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Huszar : Figura
    {
        public Huszar(int x, int y) : base(x, y, 'H')
        {
        }

        public override List<Pozicio> LehetsegesLepesek()
        {
            throw new NotImplementedException();
        }
    }
}
