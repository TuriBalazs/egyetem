namespace WinFormsApp1
{
    partial class frmPassword
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            tbOk = new Button();
            tbCancel = new Button();
            tbPassword = new TextBox();
            SuspendLayout();
            // 
            // tbOk
            // 
            tbOk.DialogResult = DialogResult.OK;
            tbOk.Location = new Point(50, 100);
            tbOk.Name = "tbOk";
            tbOk.Size = new Size(75, 25);
            tbOk.TabIndex = 0;
            tbOk.Text = "Ok";
            tbOk.UseVisualStyleBackColor = true;
            // 
            // tbCancel
            // 
            tbCancel.DialogResult = DialogResult.Cancel;
            tbCancel.Location = new Point(150, 100);
            tbCancel.Name = "tbCancel";
            tbCancel.Size = new Size(75, 25);
            tbCancel.TabIndex = 1;
            tbCancel.Text = "Mégse";
            tbCancel.UseVisualStyleBackColor = true;
            // 
            // tbPassword
            // 
            tbPassword.Location = new Point(12, 36);
            tbPassword.MaxLength = 10;
            tbPassword.Name = "tbPassword";
            tbPassword.PasswordChar = '*';
            tbPassword.PlaceholderText = "Enter password";
            tbPassword.Size = new Size(260, 23);
            tbPassword.TabIndex = 2;
            // 
            // frmPassword
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(284, 161);
            Controls.Add(tbPassword);
            Controls.Add(tbCancel);
            Controls.Add(tbOk);
            MaximumSize = new Size(300, 200);
            MinimumSize = new Size(300, 200);
            Name = "frmPassword";
            Text = "frmPassword";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button tbOk;
        private Button tbCancel;
        private TextBox tbPassword;
    }
}