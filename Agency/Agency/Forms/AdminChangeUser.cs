using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Agency.Forms
{
    public partial class AdminChangeUser : Form
    {
        public int ID;
        Database database;
        AgencyForAdmins agencyForAdmin;
        AdminManagment parent;
        public AdminChangeUser(Database DB, AgencyForAdmins form, AdminManagment Form, int id)
        {
            InitializeComponent();
            ID = id;
            database = DB;
            agencyForAdmin = form;
            parent = Form;
        }

        private void buttonChange_Click(object sender, EventArgs e)
        {
            if (textBoxNewLogin.Text != "" && textBoxNewPassword.Text != "")
            {
                string querystring = $"BEGIN TRANSACTION; update Users set ULogin = '{textBoxNewLogin.Text}', UPassword = '{textBoxNewPassword.Text}' where UserID = {ID};COMMIT TRANSACTION;";
                SqlCommand command = new SqlCommand(querystring, database.getConnection());
                database.openConnection();
                command.ExecuteNonQuery();
                database.closeConnection();
                agencyForAdmin.openChildForm(parent);
                this.Close();
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            agencyForAdmin.openChildForm(parent);
        }
    }
}
