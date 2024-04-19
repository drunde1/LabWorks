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
using Agency.Models;

namespace Agency.Forms
{
    public partial class OrdersView : Form
    {
        int UserID;
        Database database;
        Agency parent;
        public OrdersView(Database DB, Agency form, int id)
        {
            InitializeComponent();
            database = DB;
            parent = form;
            UserID = id;
        }

        private void OrdersView_Load(object sender, EventArgs e)
        {
            string querystring = $"select Permit.PermitID as ID, CName as Страна, CityName as Город, HName as Отель, StartDate as 'Дата начала', EndDate as 'Дата конца', Price as Стоимость, Transport as Трвнспорт, Surname as Фамилия, FirstName as Имя, MidleName as Отчество, PhoneNum as Телефон, Pasport as Паспорт, Email from Permit, Orders, Country, City, Hotel, Tourist where(Orders.PermitID = Permit.PermitID and Orders.TouristID = Tourist.TouristID and Permit.TourID = Hotel.HotelID and Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and Orders.UserID = {UserID})";
            SqlCommand command = new SqlCommand(querystring, database.getConnection());

            database.openConnection();
            SqlDataReader reader = command.ExecuteReader();
            List<OrderViewModel> data = new List<OrderViewModel>();

            while (reader.Read())
            {
                //int days = Convert.ToInt32(Convert.ToDateTime(reader[5]).Date - Convert.ToDateTime(reader[4]).Date);
                
                var Order = new OrderViewModel(
                    Convert.ToInt32(reader[0]),
                    reader[1].ToString() + Environment.NewLine + reader[2].ToString() + Environment.NewLine + reader[3].ToString(),
                    reader[4].ToString() + Environment.NewLine + reader[5].ToString(),
                    Convert.ToInt32(reader[6]) * (Convert.ToDateTime(reader[5]).Date - Convert.ToDateTime(reader[4]).Date).Days + Convert.ToInt32(reader[7]),
                    reader[8].ToString() + Environment.NewLine + reader[9].ToString() + Environment.NewLine + reader[10].ToString(),
                    reader[11].ToString() + Environment.NewLine + reader[12].ToString() + Environment.NewLine + reader[13].ToString());
                    data.Add(Order);
            }

            reader.Close();
          
            database.closeConnection();
            dataGridViewOrders.DataSource = data;
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            OrdersView_Load(sender, e);
        }
    }
}
