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
using System.Reflection;


namespace Agency.Forms
{
    public partial class AdminManagment : Form
    {
        Database database;
        int UserID;
        AgencyForAdmins parent;
        public AdminManagment(Database DB, AgencyForAdmins form, int id)
        {
            InitializeComponent();
            database = DB;
            UserID = id;
            parent = form;
            this.dataGridViewOrders.GetType().GetProperty("DoubleBuffered", BindingFlags.Instance | BindingFlags.NonPublic).SetValue(dataGridViewOrders, true, null);

        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            if (tabControl.SelectedTab == tabPageTours)
            {
                AdminAddChangeTour child = new AdminAddChangeTour(database, parent, this, 0);
                parent.openChildForm(child);
                child.FormClosed += new FormClosedEventHandler(Form_Closed);
                this.Show();
            }

        }
        void Form_Closed(object sender, FormClosedEventArgs e)
        {
            ShowTours();
            ShowOrders();
            ShowUsers();
        }

        private void buttonChange_Click(object sender, EventArgs e)
        {
            if (tabControl.SelectedTab == tabPageTours)
            {
                AdminAddChangeTour child = new AdminAddChangeTour(database, parent, this, Convert.ToInt32(dataGridViewTours.Rows[dataGridViewTours.CurrentCell.RowIndex].Cells[0].Value));
                parent.openChildForm(child);
                child.FormClosed += new FormClosedEventHandler(Form_Closed);
                this.Show();
            }
            if (tabControl.SelectedTab == tabPageUsers)
            {
                AdminChangeUser child = new AdminChangeUser(database, parent, this, Convert.ToInt32(dataGridViewUsers.Rows[dataGridViewUsers.CurrentCell.RowIndex].Cells[0].Value));
                parent.openChildForm(child);
                child.FormClosed += new FormClosedEventHandler(Form_Closed);
                this.Show();
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (tabControl.SelectedTab == tabPageUsers && Convert.ToInt32(dataGridViewTours.Rows[dataGridViewTours.CurrentCell.RowIndex].Cells[0].Value) != UserID)
            {
                DeleteUser();
                ShowUsers();
            }
            if (tabControl.SelectedTab == tabPageOrders)
            {
                DeleteOrder();
                ShowOrders();
            }
            if (tabControl.SelectedTab == tabPageTours)
            {
                DeleteTour();
                ShowTours();
            }
        }

        private void AdminManagment_Load(object sender, EventArgs e)
        {
            ShowTours();
            ShowUsers();
            ShowOrders();
        }

        private void ShowTours()
        {
            string querystring = $"select Hotel.HotelID as ID, CName as Страна, CityName as Город, HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт from Hotel, City, Country where Hotel.CityID = City.CityID and City.CountryID = Country.CountryID";

            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            database.openConnection();
            SqlDataReader reader = command.ExecuteReader();
            BindingList<TourModel> data = new BindingList<TourModel>();

            while (reader.Read())
            {
                var Tour = new TourModel(
                    Convert.ToInt32(reader[0]),
                    reader[1].ToString(),
                    reader[2].ToString(),
                    reader[3].ToString(),
                    Convert.ToInt32(reader[4]),
                    Convert.ToInt32(reader[5]),
                    Convert.ToInt32(reader[6]));
                data.Add(Tour);
            }

            reader.Close();

            database.closeConnection();
            dataGridViewTours.DataSource = data;
        }

        private void ShowUsers()
        {
            string querystring = $"select UserID as ID, UserRole, ULogin, UPassword, Tourist.Surname, FirstName, MidleName, Pasport, PhoneNum, Email from Users, Tourist where Tourist.TouristID = Users.TouristID";

            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            database.openConnection();
            SqlDataReader reader = command.ExecuteReader();
            List<UserModel> data = new List<UserModel>();

            while (reader.Read())
            {
                var User = new UserModel(
                    Convert.ToInt32(reader[0]),
                    reader[1].ToString(),
                    reader[2].ToString(),
                    reader[3].ToString(),
                    reader[4].ToString() + Environment.NewLine + reader[5].ToString() + Environment.NewLine + reader[6].ToString(),
                    reader[7].ToString() + Environment.NewLine + reader[8].ToString() + Environment.NewLine + reader[9].ToString()) ;
                data.Add(User);
            }

            reader.Close();

            database.closeConnection();
            dataGridViewUsers.DataSource = data;
        }

        private void ShowOrders()
        {
            string querystring = $"select Permit.PermitID as ID, Country.CName as Страна, City.CityName as Город, Hotel.HName as Отель, " +
                            $"StartDate as 'Дата начала', EndDate as 'Дата конца', Price as Стоимость, Surname as Фамилия, FirstName as Имя," +
                            $" MidleName as Отчество, PhoneNum as Телефон, Pasport as Паспорт, Email from Orders INNER JOIN Permit ON Orders.PermitID = " +
                            $"Permit.PermitID INNER JOIN Tourist ON Orders.TouristID = Tourist.TouristID INNER JOIN Hotel ON Permit.TourID = Hotel.HotelID INNER JOIN City ON Hotel.CityID = City.CityID INNER JOIN Country ON City.CountryID = Country.CountryID";

            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            database.openConnection();
            SqlDataReader reader = command.ExecuteReader();
            List<OrderViewModel> data = new List<OrderViewModel>();

            while (reader.Read())
            {
                var Order = new OrderViewModel(
                    Convert.ToInt32(reader[0]),
                    reader[1].ToString() + Environment.NewLine + reader[2].ToString() + Environment.NewLine + reader[3].ToString(),
                    reader[4].ToString() + Environment.NewLine + reader[5].ToString(),
                    Convert.ToInt32(reader[6]),
                    reader[7].ToString() + Environment.NewLine + reader[8].ToString() + Environment.NewLine + reader[9].ToString(),
                    reader[10].ToString() + Environment.NewLine + reader[11].ToString() + Environment.NewLine + reader[12].ToString());

                data.Add(Order);
            }
            reader.Close();
            database.closeConnection();
            dataGridViewOrders.DataSource = data;
        }

        private void DeleteOrder()
        {
            string querystring = $"	delete from Orders where PermitID = {dataGridViewOrders.Rows[dataGridViewOrders.CurrentCell.RowIndex].Cells[0].Value} " +
                $"delete from Permit where PermitID = {dataGridViewOrders.Rows[dataGridViewOrders.CurrentCell.RowIndex].Cells[0].Value}";
            SqlCommand command = new SqlCommand(querystring, database.getConnection());
            database.openConnection();
            command.ExecuteNonQuery();
            database.closeConnection();
        }

        private void DeleteTour()
        {
            try
            {
                string querystring = $"BEGIN TRANSACTION;" +
                $"	delete from Hotel where HotelID = {dataGridViewTours.Rows[dataGridViewTours.CurrentCell.RowIndex].Cells[0].Value} " +
               $"COMMIT TRANSACTION;";
                SqlCommand command = new SqlCommand(querystring, database.getConnection());
                database.openConnection();
                command.ExecuteNonQuery();
                database.closeConnection();
            }
            catch (Exception)
            {
                MessageBox.Show("Нельзя удалить этот тур, сначала удалите все заказы с этим туром.");
            }

            
        }

        private void DeleteUser()
        {
            string querystring = $"	delete from Users where UserID = {dataGridViewUsers.Rows[dataGridViewUsers.CurrentCell.RowIndex].Cells[0].Value} ";
            SqlCommand command = new SqlCommand(querystring, database.getConnection());
            database.openConnection();
            command.ExecuteNonQuery();
            database.closeConnection();
        }

      


        private void tabControl1_Selecting(object sender, EventArgs e)
        {
            if(tabControl.SelectedTab == tabPageUsers)
            {
                if (buttonAdd.Visible == true)
                    buttonAdd.Visible = false;
                if (buttonChange.Visible == false)
                    buttonChange.Visible = true;
            }
            if (tabControl.SelectedTab == tabPageOrders)
            {
                if (buttonAdd.Visible == true)
                    buttonAdd.Visible = false;
                if (buttonChange.Visible == true)
                    buttonChange.Visible = false;
            }
            if (tabControl.SelectedTab == tabPageTours)
            {
                if (buttonAdd.Visible == false)
                    buttonAdd.Visible = true;
                if (buttonChange.Visible == false)
                    buttonChange.Visible = true;
            }

        }

       

        private void AdminManagment_VisibleChanged(object sender, EventArgs e)
        {
            ShowUsers();
            ShowTours();
            ShowOrders();
        }
    }
}
