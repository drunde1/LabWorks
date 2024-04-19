using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using Agency.Forms;

namespace Agency
{
    public partial class LogIn : Form
    {
       Database database = new Database();

        public LogIn()
        {
            InitializeComponent();
        }

        private void EnterBut_Click(object sender, EventArgs e)
        {
            var loginUser = PasswordTextBox.Text;
            var passUser = LoginTextBox.Text;

            SqlDataAdapter adapter = new SqlDataAdapter();
            DataTable table = new DataTable();

            string querystring = $"select UserID, UserRole from Users where ULogin = '{loginUser}' and UPassword = '{passUser}'";

            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            adapter.SelectCommand = command;
            adapter.Fill(table);

            if (table.Rows.Count == 1)
            {
                int n = Convert.ToInt32(table.Rows[0][0]);
                this.Hide();
                if (table.Rows[0][1].ToString() == "User")
                {
                    Agency agency = new Agency(n, database);
                    agency.ShowDialog();
                }
                if (table.Rows[0][1].ToString() == "Admin")
                {
                    AgencyForAdmins agency = new AgencyForAdmins(n, database);
                    agency.ShowDialog();
                }
                this.Show();
            }
            else
                MessageBox.Show("Такого аккаунта не существует.", "Аккаунта не существует.", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }

        private void LogIn_Load(object sender, EventArgs e)
        {
            PasswordTextBox.PasswordChar = '*';
            PasswordTextBox.MaxLength = 20;
            LoginTextBox.MaxLength = 20;
            LoginTextBox.Text = "admin";
            PasswordTextBox.Text = "admin";
            KeyPreview = true;
        }

        private void LogIn_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (LoginTextBox.Text != "" && PasswordTextBox.Text != "")
                    EnterBut_Click(sender, e);
                else if (LoginTextBox.Text == "")
                    LoginTextBox.Focus();
                else
                    PasswordTextBox.Focus();
            }
        }

        private void registrationLink_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            SignUp signup = new SignUp(this, database);
            this.Hide();
            signup.ShowDialog();
            this.Show();

        }
    }
}
