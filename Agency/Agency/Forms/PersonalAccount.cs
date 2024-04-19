using Agency.Models;
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
    public partial class PersonalAccount : Form
    {
        Database database;
        Form parent;
        int UserID;
        public PersonalAccount(Database DB, Form form, int id)
        {
            InitializeComponent();
            database = DB;
            parent = form;
            UserID = id;
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            string querystring = $"select TouristID from Users where UserId = {UserID}";

            SqlDataAdapter adapter = new SqlDataAdapter();
            DataTable table = new DataTable();
            SqlCommand command = new SqlCommand(querystring, database.getConnection());
            adapter.SelectCommand = command;
            adapter.Fill(table);
            if (Convert.ToInt32(table.Rows[0][0]) == 0)
            {
                querystring = $"select TouristID, Surname, FirstName, MidleName, Pasport, PhoneNum, Email from Tourist where(Surname = '{textBoxSurName.Text}' and FirstName = '{textBoxName.Text}' and MidleName = '{textBoxMidName.Text}' and Pasport = '{textBoxPassport.Text}')";

                adapter = new SqlDataAdapter();
                table = new DataTable();
                command = new SqlCommand(querystring, database.getConnection());

                adapter.SelectCommand = command;
                adapter.Fill(table);
                database.openConnection();
                if (table.Rows.Count > 0)
                {
                    querystring = $"update Users set TouristID = {Convert.ToInt32(table.Rows[0][0])}";
                    command = new SqlCommand(querystring, database.getConnection());
                    if (command.ExecuteNonQuery() == 1)
                    {
                        MessageBox.Show("Данные сохранены.");
                        database.closeConnection();
                    }
                    else
                    {
                        MessageBox.Show("Данные не сохранены.");
                        database.closeConnection();
                    }
                }
                else
                {
                    querystring = $"BEGIN TRANSACTION; DECLARE @id[int]; " +
                        $"insert into Tourist values('{textBoxSurName.Text}', '{textBoxName.Text}', '{textBoxMidName.Text}', '{textBoxPassport.Text}', '{textBoxPhone.Text}', '{textBoxEmail.Text}');" +
                        $" SELECT @id = SCOPE_IDENTITY(); " +
                        $"update Users set TouristID = @id where UserID = {UserID};" +
                        $" COMMIT TRANSACTION;";
                    command = new SqlCommand(querystring, database.getConnection());
                    if (command.ExecuteNonQuery() == 1)
                    {
                        MessageBox.Show("Данные сохранены.");
                        database.closeConnection();
                    }
                    else
                    {
                        MessageBox.Show("Данные не сохранены.");
                        database.closeConnection();
                    }
                }
            }
            else
            {
                querystring = $"update Tourist set Surname = '{textBoxSurName.Text}', FirstName = '{textBoxName.Text}', MidleName = '{textBoxMidName.Text}', Pasport = '{textBoxPassport.Text}', PhoneNum = '{textBoxPhone.Text}', Email = '{textBoxEmail.Text}' where Tourist.TouristID = {Convert.ToInt32(table.Rows[0][0])}";
                command = new SqlCommand(querystring, database.getConnection());
                database.openConnection();
                if (command.ExecuteNonQuery() == 1)
                {
                    MessageBox.Show("Данные сохранены.");
                    database.closeConnection();
                }
                else
                {
                    MessageBox.Show("Данные не сохранены.");
                    database.closeConnection();
                }
            }
        }

        private void buttonChange_Click(object sender, EventArgs e)
        {
            string querystring = $"update Users set ULogin = '{textBoxLogin.Text}', UPassword = '{textBoxPassword.Text}' where UserID = {UserID}";
            SqlCommand command = new SqlCommand(querystring, database.getConnection());
            database.openConnection();
            if (command.ExecuteNonQuery() == 1)
            {
                MessageBox.Show("Данные сохранены.");
                database.closeConnection();
            }
            else
            {
                MessageBox.Show("Данные не сохранены.");
                database.closeConnection();
            }
        }

        private void PersonalAccount_Load(object sender, EventArgs e)
        {
            string querystring = $"select ULogin, UPassword, Surname, FirstName, MidleName, Pasport, PhoneNum, Email from Users, Tourist where Tourist.TouristID = Users.TouristID and Users.UserID = {UserID}";
            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            DataTable table = new DataTable();
            SqlDataAdapter adapter = new SqlDataAdapter();
            adapter.SelectCommand = command;
            adapter.Fill(table);
            PersonalAccountModelcs model = new PersonalAccountModelcs(
                table.Rows[0][3].ToString(),
                table.Rows[0][2].ToString(),
                table.Rows[0][4].ToString(),
                table.Rows[0][5].ToString(),
                table.Rows[0][6].ToString(),
                table.Rows[0][7].ToString(),
                table.Rows[0][0].ToString(),
                table.Rows[0][1].ToString());
            textBoxSurName.Text = model.Surname;
            textBoxName.Text = model.Name;
            textBoxMidName.Text = model.MidleName;
            textBoxPassport.Text = model.Passport;
            textBoxPhone.Text = model.PhoneNumber;
            textBoxEmail.Text = model.Email;
            textBoxLogin.Text = model.Login;
            textBoxPassword.Text = model.Password;
        }
    }
}
