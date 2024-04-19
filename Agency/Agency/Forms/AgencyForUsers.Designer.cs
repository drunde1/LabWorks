namespace Agency
{
    partial class Agency
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
            this.panelSideMenu = new System.Windows.Forms.Panel();
            this.buttonTours = new System.Windows.Forms.Button();
            this.panelSubPA = new System.Windows.Forms.Panel();
            this.buttonOrders = new System.Windows.Forms.Button();
            this.buttonUserInf = new System.Windows.Forms.Button();
            this.buttonPA = new System.Windows.Forms.Button();
            this.panelLogo = new System.Windows.Forms.Panel();
            this.panelChildForm = new System.Windows.Forms.Panel();
            this.panelSideMenu.SuspendLayout();
            this.panelSubPA.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelSideMenu
            // 
            this.panelSideMenu.AutoScroll = true;
            this.panelSideMenu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(11)))), ((int)(((byte)(7)))), ((int)(((byte)(27)))));
            this.panelSideMenu.Controls.Add(this.buttonTours);
            this.panelSideMenu.Controls.Add(this.panelSubPA);
            this.panelSideMenu.Controls.Add(this.buttonPA);
            this.panelSideMenu.Controls.Add(this.panelLogo);
            this.panelSideMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelSideMenu.Location = new System.Drawing.Point(0, 0);
            this.panelSideMenu.Name = "panelSideMenu";
            this.panelSideMenu.Size = new System.Drawing.Size(200, 553);
            this.panelSideMenu.TabIndex = 0;
            // 
            // buttonTours
            // 
            this.buttonTours.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonTours.FlatAppearance.BorderSize = 0;
            this.buttonTours.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonTours.ForeColor = System.Drawing.Color.Gainsboro;
            this.buttonTours.Location = new System.Drawing.Point(0, 240);
            this.buttonTours.Name = "buttonTours";
            this.buttonTours.Padding = new System.Windows.Forms.Padding(5, 0, 0, 0);
            this.buttonTours.Size = new System.Drawing.Size(200, 45);
            this.buttonTours.TabIndex = 4;
            this.buttonTours.Text = "Туры";
            this.buttonTours.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonTours.UseVisualStyleBackColor = true;
            this.buttonTours.Click += new System.EventHandler(this.buttonTours_Click);
            // 
            // panelSubPA
            // 
            this.panelSubPA.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(35)))), ((int)(((byte)(32)))), ((int)(((byte)(39)))));
            this.panelSubPA.Controls.Add(this.buttonOrders);
            this.panelSubPA.Controls.Add(this.buttonUserInf);
            this.panelSubPA.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelSubPA.Location = new System.Drawing.Point(0, 145);
            this.panelSubPA.Name = "panelSubPA";
            this.panelSubPA.Size = new System.Drawing.Size(200, 95);
            this.panelSubPA.TabIndex = 3;
            // 
            // buttonOrders
            // 
            this.buttonOrders.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonOrders.FlatAppearance.BorderSize = 0;
            this.buttonOrders.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonOrders.ForeColor = System.Drawing.Color.LightGray;
            this.buttonOrders.Location = new System.Drawing.Point(0, 45);
            this.buttonOrders.Name = "buttonOrders";
            this.buttonOrders.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.buttonOrders.Size = new System.Drawing.Size(200, 45);
            this.buttonOrders.TabIndex = 1;
            this.buttonOrders.Text = "Заказы";
            this.buttonOrders.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonOrders.UseVisualStyleBackColor = true;
            this.buttonOrders.Click += new System.EventHandler(this.buttonOrders_Click);
            // 
            // buttonUserInf
            // 
            this.buttonUserInf.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonUserInf.FlatAppearance.BorderSize = 0;
            this.buttonUserInf.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonUserInf.ForeColor = System.Drawing.Color.LightGray;
            this.buttonUserInf.Location = new System.Drawing.Point(0, 0);
            this.buttonUserInf.Name = "buttonUserInf";
            this.buttonUserInf.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.buttonUserInf.Size = new System.Drawing.Size(200, 45);
            this.buttonUserInf.TabIndex = 0;
            this.buttonUserInf.Text = "Пользователь";
            this.buttonUserInf.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonUserInf.UseVisualStyleBackColor = true;
            this.buttonUserInf.Click += new System.EventHandler(this.buttonUserInf_Click);
            // 
            // buttonPA
            // 
            this.buttonPA.Dock = System.Windows.Forms.DockStyle.Top;
            this.buttonPA.FlatAppearance.BorderSize = 0;
            this.buttonPA.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonPA.ForeColor = System.Drawing.Color.Gainsboro;
            this.buttonPA.Location = new System.Drawing.Point(0, 100);
            this.buttonPA.Name = "buttonPA";
            this.buttonPA.Padding = new System.Windows.Forms.Padding(5, 0, 0, 0);
            this.buttonPA.Size = new System.Drawing.Size(200, 45);
            this.buttonPA.TabIndex = 2;
            this.buttonPA.Text = "Личный кабинет";
            this.buttonPA.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.buttonPA.UseVisualStyleBackColor = true;
            this.buttonPA.Click += new System.EventHandler(this.buttonPA_Click);
            // 
            // panelLogo
            // 
            this.panelLogo.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelLogo.Location = new System.Drawing.Point(0, 0);
            this.panelLogo.Name = "panelLogo";
            this.panelLogo.Size = new System.Drawing.Size(200, 100);
            this.panelLogo.TabIndex = 1;
            // 
            // panelChildForm
            // 
            this.panelChildForm.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(30)))), ((int)(((byte)(45)))));
            this.panelChildForm.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panelChildForm.Location = new System.Drawing.Point(200, 0);
            this.panelChildForm.Name = "panelChildForm";
            this.panelChildForm.Size = new System.Drawing.Size(732, 553);
            this.panelChildForm.TabIndex = 1;
            // 
            // Agency
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(932, 553);
            this.Controls.Add(this.panelChildForm);
            this.Controls.Add(this.panelSideMenu);
            this.MinimumSize = new System.Drawing.Size(950, 600);
            this.Name = "Agency";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Agency";
            this.Load += new System.EventHandler(this.Agency_Load);
            this.panelSideMenu.ResumeLayout(false);
            this.panelSubPA.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelSideMenu;
        private System.Windows.Forms.Button buttonTours;
        private System.Windows.Forms.Panel panelSubPA;
        private System.Windows.Forms.Button buttonOrders;
        private System.Windows.Forms.Button buttonUserInf;
        private System.Windows.Forms.Button buttonPA;
        private System.Windows.Forms.Panel panelLogo;
        private System.Windows.Forms.Panel panelChildForm;
    }
}