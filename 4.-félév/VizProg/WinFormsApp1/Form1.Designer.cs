namespace WinFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            flpPage = new FlowLayoutPanel();
            btApple = new Button();
            btPear = new Button();
            btBanana = new Button();
            btOrange = new Button();
            tbWeight = new TextBox();
            label1 = new Label();
            tbPrice = new TextBox();
            forint = new Label();
            btSettings = new Button();
            flpPage.SuspendLayout();
            SuspendLayout();
            // 
            // flpPage
            // 
            flpPage.Controls.Add(btApple);
            flpPage.Controls.Add(btPear);
            flpPage.Controls.Add(btBanana);
            flpPage.Controls.Add(btOrange);
            flpPage.Dock = DockStyle.Top;
            flpPage.Location = new Point(0, 0);
            flpPage.Name = "flpPage";
            flpPage.Size = new Size(414, 412);
            flpPage.TabIndex = 0;
            // 
            // btApple
            // 
            btApple.Image = Properties.Resources.alma;
            btApple.Location = new Point(3, 3);
            btApple.Name = "btApple";
            btApple.Size = new Size(200, 200);
            btApple.TabIndex = 0;
            btApple.Tag = "Apple";
            btApple.Text = "500";
            btApple.UseVisualStyleBackColor = true;
            btApple.Click += btFruit_Click;
            // 
            // btPear
            // 
            btPear.Image = Properties.Resources.korte;
            btPear.Location = new Point(209, 3);
            btPear.Name = "btPear";
            btPear.Size = new Size(200, 200);
            btPear.TabIndex = 2;
            btPear.Tag = "Pear";
            btPear.Text = "699";
            btPear.UseVisualStyleBackColor = true;
            btPear.Click += btFruit_Click;
            // 
            // btBanana
            // 
            btBanana.Image = Properties.Resources.banan;
            btBanana.Location = new Point(3, 209);
            btBanana.Name = "btBanana";
            btBanana.Size = new Size(200, 200);
            btBanana.TabIndex = 1;
            btBanana.Tag = "Banana";
            btBanana.Text = "300";
            btBanana.UseVisualStyleBackColor = true;
            btBanana.Click += btFruit_Click;
            // 
            // btOrange
            // 
            btOrange.Image = Properties.Resources.narancs;
            btOrange.Location = new Point(209, 209);
            btOrange.Name = "btOrange";
            btOrange.Size = new Size(200, 200);
            btOrange.TabIndex = 3;
            btOrange.Tag = "Orange";
            btOrange.Text = "350";
            btOrange.UseVisualStyleBackColor = true;
            btOrange.Click += btFruit_Click;
            // 
            // tbWeight
            // 
            tbWeight.Location = new Point(47, 441);
            tbWeight.Name = "tbWeight";
            tbWeight.PlaceholderText = "Enter weight";
            tbWeight.Size = new Size(100, 23);
            tbWeight.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(153, 444);
            label1.Name = "label1";
            label1.Size = new Size(20, 15);
            label1.TabIndex = 2;
            label1.Text = "kg";
            // 
            // tbPrice
            // 
            tbPrice.Location = new Point(194, 436);
            tbPrice.Name = "tbPrice";
            tbPrice.ReadOnly = true;
            tbPrice.Size = new Size(100, 23);
            tbPrice.TabIndex = 3;
            // 
            // forint
            // 
            forint.AutoSize = true;
            forint.Location = new Point(314, 441);
            forint.Name = "forint";
            forint.Size = new Size(36, 15);
            forint.TabIndex = 4;
            forint.Text = "forint";
            // 
            // btSettings
            // 
            btSettings.Image = (Image)resources.GetObject("btSettings.Image");
            btSettings.ImageAlign = ContentAlignment.BottomCenter;
            btSettings.Location = new Point(365, 427);
            btSettings.Margin = new Padding(5);
            btSettings.Name = "btSettings";
            btSettings.Size = new Size(40, 40);
            btSettings.TabIndex = 5;
            btSettings.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(414, 476);
            Controls.Add(btSettings);
            Controls.Add(forint);
            Controls.Add(tbPrice);
            Controls.Add(label1);
            Controls.Add(tbWeight);
            Controls.Add(flpPage);
            MaximumSize = new Size(430, 515);
            MinimumSize = new Size(430, 515);
            Name = "Form1";
            Text = "Form1";
            flpPage.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private FlowLayoutPanel flpPage;
        private Button btApple;
        private Button btPear;
        private Button btOrange;
        private Button btBanana;
        private TextBox tbWeight;
        private Label label1;
        private TextBox tbPrice;
        private Label forint;
        private Button btSettings;
    }
}
