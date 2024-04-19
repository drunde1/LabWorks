namespace Agency.Forms
{
    partial class AgencyForAdmins
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.MenegeButton = new System.Windows.Forms.Button();
            this.PAbutton = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panelChildForm = new System.Windows.Forms.Panel();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(11)))), ((int)(((byte)(7)))), ((int)(((byte)(27)))));
            this.panel1.Controls.Add(this.MenegeButton);
            this.panel1.Controls.Add(this.PAbutton);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(200, 553);
            this.panel1.TabIndex = 0;
            // 
            // MenegeButton
            // 
            this.MenegeButton.Dock = System.Windows.Forms.DockStyle.Top;
            this.MenegeButton.FlatAppearance.BorderSize = 0;
            this.MenegeButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.MenegeButton.ForeColor = System.Drawing.Color.Gainsboro;
            this.MenegeButton.Location = new System.Drawing.Point(0, 145);
            this.MenegeButton.Name = "MenegeButton";
            this.MenegeButton.Size = new System.Drawing.Size(200, 45);
            this.MenegeButton.TabIndex = 3;
            this.MenegeButton.Text = "Управление Агенством";
            this.MenegeButton.UseVisualStyleBackColor = true;
            this.MenegeButton.Click += new System.EventHandler(this.MenegeButton_Click);
            // 
            // PAbutton
            // 
            this.PAbutton.Dock = System.Windows.Forms.DockStyle.Top;
            this.PAbutton.FlatAppearance.BorderSize = 0;
            this.PAbutton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.PAbutton.ForeColor = System.Drawing.Color.Gainsboro;
            this.PAbutton.Location = new System.Drawing.Point(0, 100);
            this.PAbutton.Name = "PAbutton";
            this.PAbutton.Size = new System.Drawing.Size(200, 45);
            this.PAbutton.TabIndex = 2;
            this.PAbutton.Text = "Личный Кабинет";
            this.PAbutton.UseVisualStyleBackColor = true;
            this.PAbutton.Click += new System.EventHandler(this.PAbutton_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(200, 100);
            this.panel2.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.Color.Gainsboro;
            this.label1.Location = new System.Drawing.Point(60, 38);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(76, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "ADMIN";
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
            // AgencyForAdmins
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(932, 553);
            this.Controls.Add(this.panelChildForm);
            this.Controls.Add(this.panel1);
            this.MaximumSize = new System.Drawing.Size(950, 600);
            this.Name = "AgencyForAdmins";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "AgencyForAdmins";
            this.Load += new System.EventHandler(this.AgencyForAdmins_Load);
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button MenegeButton;
        private System.Windows.Forms.Button PAbutton;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panelChildForm;
    }
}