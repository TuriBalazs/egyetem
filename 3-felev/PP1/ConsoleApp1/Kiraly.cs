using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Kiraly : Figura
    {
        public Kiraly(int x, int y) : base(x, y,'K')
        {
           
        }

        public override List<Pozicio> LehetsegesLepesek()
        {
            List<Pozicio> Osszes = new List<Pozicio>()
            {
                new Pozicio(Poz.x-1,Poz.y-1),
                new Pozicio(Poz.x,Poz.y-1),
                new Pozicio(Poz.x+1,Poz.y-1),
                new Pozicio(Poz.x-1,Poz.y),
                new Pozicio(Poz.x+1,Poz.y),
                new Pozicio(Poz.x-1,Poz.y+1),
                new Pozicio(Poz.x,Poz.y+1),
                new Pozicio(Poz.x+1,Poz.y+1)
            };

            List<Pozicio> szurt = new List<Pozicio>();

            foreach (var item in Osszes)
            {
                if(item.x >=0 && item.y >= 0 && item.x <= 7 &&  item.y <= 7) { szurt.Add(item); }
            }
            return szurt;
        }
    }
}
