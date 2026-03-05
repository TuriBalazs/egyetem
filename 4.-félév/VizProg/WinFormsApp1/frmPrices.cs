using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class frmPrices : Form
    {
        public DataGridView DGV { get { return dgv; } }
        public frmPrices()
        {
            InitializeComponent();
        }
    }
}
