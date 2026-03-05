using System.ComponentModel;
using System.Runtime;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        

        private void btFruit_Click(object sender, EventArgs e)
        {
            if (int.TryParse((sender as Button)?.Text, out int UnitPrice) &&
            float.TryParse(tbWeight.Text, out float Weight))
                tbPrice.Text = (UnitPrice * Weight).ToString();
            else
                tbPrice.Text = " ";
        }

        /*
         private void btSettings_Click(object sender, EventArgs e)
        {
            var frmPassword = new frmPassword();
            if (frmPassword.ShowDialog() == DialogResult.OK)
            {
                if (frmPassword.Password == "123456")
                {
                    BindingList<Fruit> blFruitList = new BindingList<Fruit>();
                    var btList = flpPage.Controls.OfType<Button>().ToList();
                    foreach (var bt in btList)
                    {
                        int UnitPrice;
                        int.TryParse((sender as Button)?.Text, out int UnitPrice);
                        blFruitList.Add(
                        new Fruit
                        {
                            FruitName = bt.Tag.ToString(),
                            UnitPrice = UnitPrice
                        });
                        var frmPrices = new frmPrices();
                        frmPrices.DGV.DataSource = blFruitList;
                        frmPrices.DGV.Columns[0].ReadOnly = true;
                        frmPrices.ShowDialog();
                        for (var i = 0; i < btList.Count; i++)
                            btList[i].Text = blFruitList[i].UnitPrice.ToString();
                    }
                }
            }
        }
         
         */

    }
}
