using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Agency.Forms
{
    public partial class AgencyForAdmins : Form
    {
        private int UserID;
        Database database;
        PersonalAccount personalAccount;
        AdminManagment adminManagment;
        public AgencyForAdmins(int ID, Database DB)
        {
            InitializeComponent();
            UserID = ID;
            database = DB;


        }
        private void AgencyForAdmins_Load(object sender, EventArgs e)
        {
            adminManagment = new AdminManagment(database, this, UserID);
            personalAccount = new PersonalAccount(database, this, UserID);
            openChildForm(personalAccount);
        }

        private void PAbutton_Click(object sender, EventArgs e)
        {
            if (activeform != personalAccount)
                openChildForm(personalAccount);
        }

        private void MenegeButton_Click(object sender, EventArgs e)
        {
            if (activeform != adminManagment)
                openChildForm(adminManagment);
        }
        private Form activeform = null;
        public void openChildForm(Form childForm)
        {
            if (activeform != null)
                activeform.Hide();
            activeform = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            panelChildForm.Controls.Add(childForm);
            panelChildForm.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
        }
    }
}
