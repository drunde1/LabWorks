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


namespace Agency
{
    public partial class SignUp : Form
    {
        Database database;
        private LogIn parentform;
        public SignUp(LogIn form, Database DB)
        {
            InitializeComponent();
            parentform = form;
            database = DB;
        }

        private void SignUpBut_Click(object sender, EventArgs e)
        {
            if (LoginSignTextBox.Text != "" && PasswordSignTextBox.Text != "")
            {
                var login = LoginSignTextBox.Text;
                var password = PasswordSignTextBox.Text;

                string querystring = $"select UserID, ULogin, UPassword from Users where ULogin = '{login}' or UPassword = '{password}'";

                SqlDataAdapter adapter = new SqlDataAdapter();
                DataTable table = new DataTable();
                SqlCommand command = new SqlCommand(querystring, database.getConnection());

                adapter.SelectCommand = command;
                adapter.Fill(table);
                if (table.Rows.Count > 0)
                {
                    MessageBox.Show("Логин/Пароль уже существует.");
                }
                else
                {
                    querystring = $"insert into Users values('{login}', '{password}', 'User', 0)";
                    command = new SqlCommand(querystring, database.getConnection());

                    database.openConnection();

                    if (command.ExecuteNonQuery() == 1)
                    {
                        database.closeConnection();
                        MessageBox.Show("Вы успешно зарегестрировались.");
                        this.Close();

                    }
                    else
                    {
                        MessageBox.Show("Аккаунт не создан.");
                        database.closeConnection();
                    }

                }
            }
            else
                MessageBox.Show("Заполните форму.");

        }

        private void SignUp_Load(object sender, EventArgs e)
        {
            PasswordSignTextBox.PasswordChar = '*';
            KeyPreview = true;
        }

        private void SignUp_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (LoginSignTextBox.Text != "" && PasswordSignTextBox.Text != "")
                    SignUpBut_Click(sender, e);
                else if (LoginSignTextBox.Text == "")
                    LoginSignTextBox.Focus();
                else
                    PasswordSignTextBox.Focus();
            }
        }
    }
}
