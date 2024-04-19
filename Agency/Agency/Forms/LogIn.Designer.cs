namespace Agency
{
    partial class LogIn
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
            this.AutorizLabel = new System.Windows.Forms.Label();
            this.LoginTextBox = new System.Windows.Forms.TextBox();
            this.PasswordTextBox = new System.Windows.Forms.TextBox();
            this.LogLabel = new System.Windows.Forms.Label();
            this.PassLabel = new System.Windows.Forms.Label();
            this.EnterBut = new System.Windows.Forms.Button();
            this.registrationLink = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // AutorizLabel
            // 
            this.AutorizLabel.AutoSize = true;
            this.AutorizLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.AutorizLabel.ForeColor = System.Drawing.Color.LightGray;
            this.AutorizLabel.Location = new System.Drawing.Point(135, 76);
            this.AutorizLabel.Name = "AutorizLabel";
            this.AutorizLabel.Size = new System.Drawing.Size(186, 32);
            this.AutorizLabel.TabIndex = 0;
            this.AutorizLabel.Text = "Авторизация";
            // 
            // LoginTextBox
            // 
            this.LoginTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LoginTextBox.Location = new System.Drawing.Point(152, 169);
            this.LoginTextBox.Name = "LoginTextBox";
            this.LoginTextBox.Size = new System.Drawing.Size(150, 30);
            this.LoginTextBox.TabIndex = 1;
            // 
            // PasswordTextBox
            // 
            this.PasswordTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PasswordTextBox.Location = new System.Drawing.Point(152, 231);
            this.PasswordTextBox.Name = "PasswordTextBox";
            this.PasswordTextBox.Size = new System.Drawing.Size(150, 30);
            this.PasswordTextBox.TabIndex = 2;
            // 
            // LogLabel
            // 
            this.LogLabel.AutoSize = true;
            this.LogLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LogLabel.ForeColor = System.Drawing.Color.LightGray;
            this.LogLabel.Location = new System.Drawing.Point(65, 172);
            this.LogLabel.Name = "LogLabel";
            this.LogLabel.Size = new System.Drawing.Size(61, 20);
            this.LogLabel.TabIndex = 3;
            this.LogLabel.Text = "Login:";
            // 
            // PassLabel
            // 
            this.PassLabel.AutoSize = true;
            this.PassLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PassLabel.ForeColor = System.Drawing.Color.LightGray;
            this.PassLabel.Location = new System.Drawing.Point(24, 234);
            this.PassLabel.Name = "PassLabel";
            this.PassLabel.Size = new System.Drawing.Size(97, 20);
            this.PassLabel.TabIndex = 4;
            this.PassLabel.Text = "Password:";
            // 
            // EnterBut
            // 
            this.EnterBut.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.EnterBut.ForeColor = System.Drawing.Color.LightGray;
            this.EnterBut.Location = new System.Drawing.Point(181, 311);
            this.EnterBut.Name = "EnterBut";
            this.EnterBut.Size = new System.Drawing.Size(92, 35);
            this.EnterBut.TabIndex = 5;
            this.EnterBut.Text = "Войти";
            this.EnterBut.UseVisualStyleBackColor = true;
            this.EnterBut.Click += new System.EventHandler(this.EnterBut_Click);
            // 
            // registrationLink
            // 
            this.registrationLink.AutoSize = true;
            this.registrationLink.LinkColor = System.Drawing.Color.Silver;
            this.registrationLink.Location = new System.Drawing.Point(161, 378);
            this.registrationLink.Name = "registrationLink";
            this.registrationLink.Size = new System.Drawing.Size(132, 16);
            this.registrationLink.TabIndex = 6;
            this.registrationLink.TabStop = true;
            this.registrationLink.Text = "Еще нет аккаунта?";
            this.registrationLink.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.registrationLink_LinkClicked);
            // 
            // LogIn
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(30)))), ((int)(((byte)(45)))));
            this.ClientSize = new System.Drawing.Size(454, 450);
            this.Controls.Add(this.registrationLink);
            this.Controls.Add(this.EnterBut);
            this.Controls.Add(this.PassLabel);
            this.Controls.Add(this.LogLabel);
            this.Controls.Add(this.PasswordTextBox);
            this.Controls.Add(this.LoginTextBox);
            this.Controls.Add(this.AutorizLabel);
            this.Name = "LogIn";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "LogIn";
            this.Load += new System.EventHandler(this.LogIn_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.LogIn_KeyDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label AutorizLabel;
        private System.Windows.Forms.TextBox LoginTextBox;
        private System.Windows.Forms.TextBox PasswordTextBox;
        private System.Windows.Forms.Label LogLabel;
        private System.Windows.Forms.Label PassLabel;
        private System.Windows.Forms.Button EnterBut;
        private System.Windows.Forms.LinkLabel registrationLink;
    }
}