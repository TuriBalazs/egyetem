using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class frmPassword : Form
    {
        public frmPassword()
        {
            InitializeComponent();

        }
        public string Password { get { return tbPassword.Text; } }
    }
}
