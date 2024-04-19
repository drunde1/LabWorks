using Agency.Models;
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

namespace Agency.Forms
{
    public partial class MakingOrder : Form
    {
        int UserID;
        Database database;
        ToursForm toursForm;
        Agency agencyForm;
        OrderTourModel orderTourModel;
        public MakingOrder(ToursForm form, Agency Form, OrderTourModel model, Database DB, int id)
        {
            InitializeComponent();
            toursForm = form;
            agencyForm = Form;
            orderTourModel = model;
            database = DB;
            UserID = id;
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            agencyForm.openChildForm(toursForm);
        }

        private void MakingOrder_Load(object sender, EventArgs e)
        {
            textBoxCountry.Text = orderTourModel.Country;
            textBoxCity.Text = orderTourModel.City;
            textBoxHotel.Text = orderTourModel.Hotel;
            dateTimePickerStart.Value = orderTourModel.StartdateTime;
            dateTimePickerEnd.Value = orderTourModel.EnddateTime;
            textBoxOrderPrice.Text = (orderTourModel.Price*orderTourModel.Tourists*
                (orderTourModel.EnddateTime.Date - orderTourModel.StartdateTime.Date).Days).ToString();
            numericUpDownTourists.Value = orderTourModel.Tourists;
            if (orderTourModel.Tourists == 2)
                groupBoxTourist2.Visible = true;
            if (orderTourModel.Tourists == 3)
            {
                groupBoxTourist2.Visible = true;
                groupBoxTourist3.Visible = true;
            }
            if (orderTourModel.Tourists == 4)
            {
                groupBoxTourist4.Visible = true;
                groupBoxTourist3.Visible = true;
                groupBoxTourist2.Visible = true;
            }
            textBoxEmail1.Text = "dfgdfgdf";
            textBoxMidName1.Text = "sdfsdfsdf";
            textBoxName1.Text = "sdfsdfsdf";
            textBoxSurName1.Text = "sdfsdf";
            textBoxPassport1.Text = "1234567890";
            textBoxPhone1.Text = "12345678900";
            dateTimePickerStart.CustomFormat = "yyyy.dd.MM";
            dateTimePickerStart.Format = DateTimePickerFormat.Custom;
            dateTimePickerEnd.CustomFormat = "yyyy.dd.MM";
            dateTimePickerEnd.Format = DateTimePickerFormat.Custom;
            string querystring = $"select ULogin, UPassword, Surname, FirstName, MidleName, Pasport, PhoneNum, Email from Tourist, Users where Users.TouristID = Tourist.TouristID and Users.UserID = {UserID}";
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
            textBoxSurName1.Text = model.Surname;
            textBoxName1.Text = model.Name;
            textBoxMidName1.Text = model.MidleName;
            textBoxPassport1.Text = model.Passport;
            textBoxPhone1.Text = model.PhoneNumber;
            textBoxEmail1.Text = model.Email;
        }

        private void numericUpDownTourists_ValueChanged(object sender, EventArgs e)
        {
            textBoxOrderPrice.Text = (Convert.ToInt32(textBoxOrderPrice.Text) / orderTourModel.Tourists * numericUpDownTourists.Value).ToString();
            orderTourModel.Tourists = Convert.ToInt32(numericUpDownTourists.Value);
            if (orderTourModel.Tourists == 1)
            {               
                groupBoxTourist4.Visible = false;
                groupBoxTourist3.Visible = false;
                groupBoxTourist2.Visible = false;
            }

            if (orderTourModel.Tourists == 2)
            {
                groupBoxTourist4.Visible = false;
                groupBoxTourist3.Visible = false;
                groupBoxTourist2.Visible = true;
            }
            if (orderTourModel.Tourists == 3)
            {
                groupBoxTourist4.Visible = false;
                groupBoxTourist2.Visible = true;
                groupBoxTourist3.Visible = true;

            }
            if (orderTourModel.Tourists == 4)
            {
                groupBoxTourist4.Visible = true;
                groupBoxTourist2.Visible = true;
                groupBoxTourist3.Visible = true;
            }
        }

        private void buttonMakeOrder_Click(object sender, EventArgs e)
        {
            if((numericUpDownTourists.Value == 1 && textBoxSurName1.Text != "" && textBoxName1.Text != "" && textBoxMidName1.Text != "" && textBoxPassport1.Text != "" && textBoxPhone1.Text != "" && textBoxEmail1.Text != "") ||
                (numericUpDownTourists.Value == 2 && textBoxSurName2.Text != "" && textBoxName2.Text != "" && textBoxMidName2.Text != "" && textBoxPassport2.Text != "" && textBoxPhone2.Text != "" && textBoxEmail2.Text != "") ||
                (numericUpDownTourists.Value == 3 && textBoxSurName3.Text != "" && textBoxName3.Text != "" && textBoxMidName3.Text != "" && textBoxPassport3.Text != "" && textBoxPhone3.Text != "" && textBoxEmail3.Text != "") ||
                (numericUpDownTourists.Value == 4 && textBoxSurName4.Text != "" && textBoxName4.Text != "" && textBoxMidName4.Text != "" && textBoxPassport4.Text != "" && textBoxPhone4.Text != "" && textBoxEmail4.Text != ""))
            {
                int tourid;
                int permitid;
                string querystring = $"select HotelID from Hotel, City, Country where(Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and Country.CName = '{textBoxCountry.Text}' and City.CityName = '{textBoxCity.Text}' and Hotel.HName = '{textBoxHotel.Text}')";
                SqlCommand command = new SqlCommand(querystring, database.getConnection());
                SqlDataAdapter adapter = new SqlDataAdapter();
                DataTable table = new DataTable();

                adapter.SelectCommand = command;
                adapter.Fill(table);
                //querystring = $"select UserID, UserRole from Users where ULogin = '' and UPassword = ''";

                //command = new SqlCommand(querystring, database.getConnection());

                //adapter.SelectCommand = command;
                //adapter.Fill(table);

                //if (table.Rows.Count == 1)
                //{
                //    int n = Convert.ToInt32(table.Rows[0][0]);
                //    this.Hide();
                //    if (table.Rows[0][1].ToString() == "User")
                //    {
                //        Agency agency = new Agency(n, database);
                //        agency.ShowDialog();
                //    }
                //    if (table.Rows[0][1].ToString() == "Admin")
                //    {
                //        AgencyForAdmins agency = new AgencyForAdmins(n, database);
                //        agency.ShowDialog();
                //    }
                //    this.Show();
                //}
                //else
                //{

                //}


                tourid = Convert.ToInt32(table.Rows[0][0]);
                string datestart = dateTimePickerStart.Value.Date.ToString("yyyy") + '/' + dateTimePickerStart.Value.Date.ToString("MM") + '/' + dateTimePickerStart.Value.Date.ToString("dd");
                string dateend = dateTimePickerEnd.Value.Date.ToString("yyyy") + '/' + dateTimePickerEnd.Value.Date.ToString("MM") + '/' + dateTimePickerEnd.Value.Date.ToString("dd");
                querystring = $"BEGIN TRANSACTION; " +
                    $"insert into Permit values({tourid}, '{datestart}', '{dateend}')" +
                    $"SELECT PermitID from Permit where(TourID = {tourid} and StartDate = '{datestart}' and EndDate = '{dateend}');" +
                    $"COMMIT TRANSACTION;";
                command = new SqlCommand(querystring, database.getConnection());
                adapter = new SqlDataAdapter();
                table = new DataTable();

                adapter.SelectCommand = command;
                adapter.Fill(table);
                permitid = Convert.ToInt32(table.Rows[0][0]);

                List<TouristModel> list = new List<TouristModel>();
                for(int i = 0; i < numericUpDownTourists.Value; i++)
                {
                    if (i == 0)
                    {
                        list.Add(new TouristModel(
                        textBoxSurName1.Text,
                        textBoxName1.Text,
                        textBoxMidName1.Text,
                        textBoxPassport1.Text,
                        textBoxPhone1.Text,
                        textBoxEmail1.Text));
                    }
                    else if (i == 1)
                    {
                        list.Add(new TouristModel(
                       textBoxSurName2.Text,
                       textBoxName2.Text,
                       textBoxMidName2.Text,
                       textBoxPassport2.Text,
                       textBoxPhone2.Text,
                       textBoxEmail2.Text));
                    }
                    else if (i == 2)
                    {
                        list.Add(new TouristModel(
                       textBoxSurName3.Text,
                       textBoxName3.Text,
                       textBoxMidName3.Text,
                       textBoxPassport3.Text,
                       textBoxPhone3.Text,
                       textBoxEmail3.Text));
                    }
                    else if (i == 3)
                    {
                        list.Add(new TouristModel(
                       textBoxSurName4.Text,
                       textBoxName4.Text,
                       textBoxMidName4.Text,
                       textBoxPassport4.Text,
                       textBoxPhone4.Text,
                       textBoxEmail4.Text));
                    }


                }
                int[] tourists = CheckTourists(list);


                for (int i = 0; i < numericUpDownTourists.Value; i++)
                {
                    if (i == 0)
                        querystring = $"insert into Orders values({permitid}, {tourists[i]}, {UserID})";
                    else if (i == 1)
                        querystring = $"insert into Orders values({permitid}, {tourists[i]}, {UserID})";
                    else if (i == 2)
                        querystring = $"insert into Orders values({permitid}, {tourists[i]}, {UserID})";
                    else if (i == 3)
                        querystring = $"insert into Orders values({permitid}, {tourists[i]}, {UserID})";
                    command = new SqlCommand(querystring, database.getConnection());
                    database.openConnection();
                    if (command.ExecuteNonQuery() == 1)
                    {
                        database.closeConnection();
                    }
                    else
                    {
                        MessageBox.Show("Заказ не сделан.");
                        database.closeConnection();
                    }

                }
                MessageBox.Show("Заказ успешно сделан.");
                agencyForm.openChildForm(toursForm);
                this.Close();
            }
            
        }

        private bool ifInDB(string surname, string name, string midname, string pasport, string phone, string mail)
        {
            return true;
        }

        private int[] CheckTourists(List<TouristModel> list)
        {
            string querystring;
            SqlCommand command;
            SqlDataAdapter adapter = new SqlDataAdapter();
            DataTable table = new DataTable();

            int[] rez = new int[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                querystring = $"select TouristID from Tourist where( Surname = '{list[i].Surname}' and FirstName = '{list[i].Name}' and MidleName = '{list[i].MidleName}' and Pasport = '{list[i].Passport}' )";
                command = new SqlCommand(querystring, database.getConnection());
                adapter.SelectCommand = command;
                table = new DataTable();
                adapter.Fill(table);
                if(table.Rows.Count > 0)
                    rez[i] = Convert.ToInt32(table.Rows[0][0]);
                else
                {
                    querystring = $"BEGIN TRANSACTION; " +
                        $"insert into Tourist values('{list[i].Surname}', '{list[i].Name}', '{list[i].MidleName}', '{list[i].Passport}', '{list[i].PhoneNum}', '{list[i].Email}');" +
                        $"SELECT TouristID from Tourist where(Surname = '{list[i].Surname}' and FirstName = '{list[i].Name}' " +
                        $"and MidleName =  '{list[i].MidleName}' and Pasport = '{list[i].Passport}' and PhoneNum =  '{list[i].PhoneNum}' and Email = '{list[i].Email}'); " +
                        $" COMMIT TRANSACTION;";
                    command = new SqlCommand(querystring, database.getConnection());
                    adapter.SelectCommand = command;
                    adapter.Fill(table);
                    rez[i] = Convert.ToInt32(table.Rows[0][0]);
                }
            }
            return rez;
        }
    }
}
