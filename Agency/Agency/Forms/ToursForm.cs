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
using Agency.Models;
using Agency.Forms;

namespace Agency
{
    public partial class ToursForm : Form
    {
        Database database;
        int UserId;
        Agency parent { get; }
        public ToursForm(Database DB, Agency form, int id)
        {
            InitializeComponent();
            database = DB;
            parent = form;
            UserId = id;
        }
        private void ShowTours(string querysrting, int Duration, int Tourists)
        {
            SqlCommand command = new SqlCommand(querysrting, database.getConnection());

            database.openConnection();
            SqlDataReader reader = command.ExecuteReader();
            List<TourModel> data = new List<TourModel>();

            while (reader.Read())
            {
                var Tour = new TourModel(
                    1,
                    reader[0].ToString(),
                    reader[1].ToString(),
                    reader[2].ToString(),
                    Convert.ToInt32(reader[3]),
                    Convert.ToInt32(reader[4]) * Duration * Tourists + Convert.ToInt32(reader[5]) * Tourists);
                data.Add(Tour);
            }

            reader.Close();

            database.closeConnection();
            dataGridViewTours.DataSource = data;
        }
        private void ToursForm_Load(object sender, EventArgs e)
        {
            dateTimePickerStart.CustomFormat = "yyyy.dd.MM";
            dateTimePickerStart.Format = DateTimePickerFormat.Custom;
            dateTimePickerEnd.CustomFormat = "yyyy.dd.MM";
            dateTimePickerEnd.Format = DateTimePickerFormat.Custom;
            dateTimePickerStart.Value = new DateTime(dateTimePickerStart.Value.Date.Year,
               dateTimePickerStart.Value.Date.Month, dateTimePickerStart.Value.Date.Day + 2,
               dateTimePickerStart.Value.Date.Hour, dateTimePickerStart.Value.Date.Minute, dateTimePickerStart.Value.Date.Second);
            dateTimePickerEnd.Value = new DateTime(dateTimePickerStart.Value.Date.Year,
                dateTimePickerStart.Value.Date.Month, dateTimePickerStart.Value.Date.Day + 7,
                dateTimePickerStart.Value.Date.Hour, dateTimePickerStart.Value.Date.Minute, dateTimePickerStart.Value.Date.Second);
            string querystring = $"select CName as Страна, City.CityName as Город, Hotel.HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт from Country, City, Hotel where Hotel.CityID = City.CityID and City.CountryID = Country.CountryID";
            ShowTours(querystring , 7, 1);
        }

        private void buttonMakeOrder_Click(object sender, EventArgs e)
        {
            int rowindex = dataGridViewTours.CurrentCell.RowIndex;
            int days = (dateTimePickerEnd.Value.Date - dateTimePickerStart.Value.Date).Days;
            int persons = Convert.ToInt32(numericUpDownTourists.Value);
            int price = Convert.ToInt32(dataGridViewTours.Rows[rowindex].Cells[4].Value);
            price = price/(days*persons);
            OrderTourModel model = new OrderTourModel(
                dataGridViewTours.Rows[rowindex].Cells[0].Value.ToString(),
                dataGridViewTours.Rows[rowindex].Cells[1].Value.ToString(),
                dataGridViewTours.Rows[rowindex].Cells[2].Value.ToString(),
                dateTimePickerStart.Value,
                dateTimePickerEnd.Value,
                price,
                Convert.ToInt32(numericUpDownTourists.Value));
            parent.openChildForm(new MakingOrder(this, parent, model, database, UserId));
        }

        private void buttonFilter_Click(object sender, EventArgs e)
        {
            if (textBoxCountry.Text == "" && textBoxCity.Text != "")
            {
                string querystring = $"select CName as Страна, CityName as Город, HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт " +
                    $"from Country, City, Hotel where (Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and CityName = '{textBoxCity.Text}')";
                ShowTours(querystring, (dateTimePickerEnd.Value.Date - dateTimePickerStart.Value.Date).Days, Convert.ToInt32(numericUpDownTourists.Value));
            }
            else if (textBoxCountry.Text != "" && textBoxCity.Text == "")
            {
                string querystring = $"select CName as Страна, CityName as Город, HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт " +
                    $"from Country, City, Hotel where (Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and CName = '{textBoxCountry.Text}')";
                ShowTours(querystring, (dateTimePickerEnd.Value.Date - dateTimePickerStart.Value.Date).Days, Convert.ToInt32(numericUpDownTourists.Value));
            }
            else if (textBoxCountry.Text != "" && textBoxCity.Text != "")
            {
                string querystring = $"select CName as Страна, CityName as Город, HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт " +
                    $"from Country, City, Hotel where (Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and CityName = '{textBoxCity.Text}' and CName = '{textBoxCountry.Text}')";
                ShowTours(querystring, (dateTimePickerEnd.Value.Date - dateTimePickerStart.Value.Date).Days, Convert.ToInt32(numericUpDownTourists.Value));
            }
            else if (textBoxCountry.Text == "" && textBoxCity.Text == "")
            {
                string querystring = $"select CName as Страна, CityName as Город, HName as Отель, Class as Класс, Price as Цена, Transport as Транспорт " +
                    $"from Country, City, Hotel where Hotel.CityID = City.CityID and City.CountryID = Country.CountryID";
                ShowTours(querystring, (dateTimePickerEnd.Value.Date - dateTimePickerStart.Value.Date).Days, Convert.ToInt32(numericUpDownTourists.Value));
            }
        }

        private void numericUpDownTourists_ValueChanged(object sender, EventArgs e)
        {
            buttonFilter_Click(sender, e);
        }

        private void dateTimePickerEnd_ValueChanged(object sender, EventArgs e)
        {
            buttonFilter_Click(sender, e);

        }

        private void dateTimePickerStart_ValueChanged(object sender, EventArgs e)
        {
            buttonFilter_Click(sender, e);

        }
    }
}
