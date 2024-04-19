namespace Agency
{
    partial class SignUp
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
            this.SignUpBut = new System.Windows.Forms.Button();
            this.PassSignLabel = new System.Windows.Forms.Label();
            this.LogSignLabel = new System.Windows.Forms.Label();
            this.PasswordSignTextBox = new System.Windows.Forms.TextBox();
            this.LoginSignTextBox = new System.Windows.Forms.TextBox();
            this.SignUpLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // SignUpBut
            // 
            this.SignUpBut.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.SignUpBut.ForeColor = System.Drawing.Color.LightGray;
            this.SignUpBut.Location = new System.Drawing.Point(131, 307);
            this.SignUpBut.Name = "SignUpBut";
            this.SignUpBut.Size = new System.Drawing.Size(190, 35);
            this.SignUpBut.TabIndex = 11;
            this.SignUpBut.Text = "Зарегестрироваться";
            this.SignUpBut.UseVisualStyleBackColor = true;
            this.SignUpBut.Click += new System.EventHandler(this.SignUpBut_Click);
            // 
            // PassSignLabel
            // 
            this.PassSignLabel.AutoSize = true;
            this.PassSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PassSignLabel.ForeColor = System.Drawing.Color.LightGray;
            this.PassSignLabel.Location = new System.Drawing.Point(28, 231);
            this.PassSignLabel.Name = "PassSignLabel";
            this.PassSignLabel.Size = new System.Drawing.Size(97, 20);
            this.PassSignLabel.TabIndex = 10;
            this.PassSignLabel.Text = "Password:";
            // 
            // LogSignLabel
            // 
            this.LogSignLabel.AutoSize = true;
            this.LogSignLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LogSignLabel.ForeColor = System.Drawing.Color.LightGray;
            this.LogSignLabel.Location = new System.Drawing.Point(69, 169);
            this.LogSignLabel.Name = "LogSignLabel";
            this.LogSignLabel.Size = new System.Drawing.Size(61, 20);
            this.LogSignLabel.TabIndex = 9;
            this.LogSignLabel.Text = "Login:";
            // 
            // PasswordSignTextBox
            // 
            this.PasswordSignTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PasswordSignTextBox.Location = new System.Drawing.Point(156, 228);
            this.PasswordSignTextBox.Name = "PasswordSignTextBox";
            this.PasswordSignTextBox.Size = new System.Drawing.Size(150, 30);
            this.PasswordSignTextBox.TabIndex = 8;
            // 
            // LoginSignTextBox
            // 
            this.LoginSignTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LoginSignTextBox.Location = new System.Drawing.Point(156, 166);
            this.LoginSignTextBox.Name = "LoginSignTextBox";
            this.LoginSignTextBox.Size = new System.Drawing.Size(150, 30);
            this.LoginSignTextBox.TabIndex = 7;
            // 
            // SignUpLabel
            // 
            this.SignUpLabel.AutoSize = true;
            this.SignUpLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.SignUpLabel.ForeColor = System.Drawing.Color.LightGray;
            this.SignUpLabel.Location = new System.Drawing.Point(139, 73);
            this.SignUpLabel.Name = "SignUpLabel";
            this.SignUpLabel.Size = new System.Drawing.Size(182, 32);
            this.SignUpLabel.TabIndex = 6;
            this.SignUpLabel.Text = "Регистрация";
            // 
            // SignUp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(30)))), ((int)(((byte)(45)))));
            this.ClientSize = new System.Drawing.Size(454, 450);
            this.Controls.Add(this.SignUpBut);
            this.Controls.Add(this.PassSignLabel);
            this.Controls.Add(this.LogSignLabel);
            this.Controls.Add(this.PasswordSignTextBox);
            this.Controls.Add(this.LoginSignTextBox);
            this.Controls.Add(this.SignUpLabel);
            this.Name = "SignUp";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "SignUp";
            this.Load += new System.EventHandler(this.SignUp_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.SignUp_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button SignUpBut;
        private System.Windows.Forms.Label PassSignLabel;
        private System.Windows.Forms.Label LogSignLabel;
        private System.Windows.Forms.TextBox PasswordSignTextBox;
        private System.Windows.Forms.TextBox LoginSignTextBox;
        private System.Windows.Forms.Label SignUpLabel;
    }
}