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
    public partial class AdminAddChangeTour : Form
    {
        Database database;
        AgencyForAdmins agencyForAdmin;
        AdminManagment parent;
        int Mode;
        public AdminAddChangeTour(Database DB, AgencyForAdmins form, AdminManagment Form, int mode)
        {
            InitializeComponent();
            database = DB;
            agencyForAdmin = form;
            parent = Form;
            Mode = mode;
            if(mode == 0)
                buttonChange.Visible = false;
            else
                buttonAddTour.Visible = false;
        }

        private void buttonAddTour_Click(object sender, EventArgs e)
        {
            if(textBoxHotel.Text != "" && textBoxCity.Text != "" && textBoxCountry.Text != "")
            {
                int countryid;
                string querystring = $"select CountryID from Country where CName = '{textBoxCountry.Text}'";
                SqlDataAdapter adapter = new SqlDataAdapter();
                DataTable table = new DataTable();
                SqlCommand command = new SqlCommand(querystring, database.getConnection());
                adapter.SelectCommand = command;
                adapter.Fill(table);
                if (Convert.ToInt32(table.Rows.Count) == 0)
                {
                    querystring = $"BEGIN TRANSACTION;" +
                   $" DECLARE @id [int];" +
                   $" insert into Country values('{textBoxCountry.Text}');" +
                   $" SELECT @id = SCOPE_IDENTITY();" +
                   $" insert into City values('{textBoxCity.Text}', {numericUpDownTransport.Value}, @id);" +
                   $" SELECT @id = SCOPE_IDENTITY();" +
                   $" insert into Hotel values('{textBoxHotel.Text}', {numericUpDownClass.Value}, {numericUpDownPrice.Value}, @id);" +
                   $" COMMIT TRANSACTION;";
                    command = new SqlCommand(querystring, database.getConnection());
                    database.openConnection();
                    if (command.ExecuteNonQuery() == 3)
                    {
                        MessageBox.Show("Тур добавлен.");
                        database.closeConnection();
                    }
                    else
                    {
                        MessageBox.Show("Тур не добавлен.");
                        database.closeConnection();
                    }
                    
                }
                else
                {
                    int cityid;
                    countryid = Convert.ToInt32(table.Rows[0][0]);
                    querystring = $"select CityID from City where CityName = '{textBoxCity.Text}'";
                    adapter = new SqlDataAdapter();
                    table = new DataTable();
                    command = new SqlCommand(querystring, database.getConnection());
                    adapter.SelectCommand = command;
                    adapter.Fill(table);
                    if (Convert.ToInt32(table.Rows.Count) == 0)
                    {
                        querystring = $"BEGIN TRANSACTION;" +
                                          $"DECLARE @id [int];" +
                                          $" insert into City values('{textBoxCity.Text}', {numericUpDownTransport.Value}, {countryid});" +
                                          $" SELECT @id = SCOPE_IDENTITY();" +
                                          $"insert into Hotel values('{textBoxHotel.Text}', {numericUpDownClass.Value}, {numericUpDownPrice.Value}, @id);" +
                                          $"COMMIT TRANSACTION;"; 
                        command = new SqlCommand(querystring, database.getConnection());
                        database.openConnection();
                        if (command.ExecuteNonQuery() == 2)
                        {
                            MessageBox.Show("Тур добавлен.");
                            database.closeConnection();
                        }
                        else
                        {
                            MessageBox.Show("Тур не добавлен.");
                            database.closeConnection();
                        }
                    }
                    else
                    {
                        cityid = Convert.ToInt32(table.Rows[0][0]);
                        querystring = $"select HotelID from Hotel where HName = '{textBoxHotel.Text}'";
                        adapter = new SqlDataAdapter();
                        table = new DataTable();
                        command = new SqlCommand(querystring, database.getConnection());
                        adapter.SelectCommand = command;
                        adapter.Fill(table);
                        if (Convert.ToInt32(table.Rows.Count) == 0)
                        {
                            querystring = $"insert into Hotel values('{textBoxHotel.Text}', {numericUpDownClass.Value}, {numericUpDownPrice.Value}, {cityid})";
                            command = new SqlCommand(querystring, database.getConnection());
                            database.openConnection();
                            if (command.ExecuteNonQuery() == 1)
                            {
                                MessageBox.Show("Тур добавлен.");
                                database.closeConnection();
                            }
                            else
                            {
                                MessageBox.Show("Тур не добавлен.");
                                database.closeConnection();
                            }
                        }
                        else
                        {
                            MessageBox.Show("Такой тур уже существует.");
                        }
                    }
                }
                this.Close();

            }
           
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            agencyForAdmin.openChildForm(parent);
        }

        private void buttonChange_Click(object sender, EventArgs e)
        {
            if (textBoxHotel.Text != "" && textBoxCity.Text != "" && textBoxCountry.Text != "")
            {

                string querystring = $"	BEGIN TRANSACTION;" +
                    $" declare @id [int];" +
                    $" update Hotel set HName = '{textBoxHotel.Text}', Class = {numericUpDownClass.Value},Price = {numericUpDownPrice.Value} where HotelID = {Mode};" +
                    $" select @id = City.CityID from City, Hotel where Hotel.CityID = City.CityID and Hotel.HotelID = {Mode};" +
                    $" update City set CityName = '{textBoxCity.Text}',Transport = {numericUpDownTransport.Value} where CityID = @id;" +
                    $" select @id = Country.CountryID from Country, City, Hotel where Hotel.CityID = City.CityID and City.CountryID = Country.CountryID and Hotel.HotelID = {Mode}" +
                    $" update Country set CName = '{textBoxCountry.Text}' where CountryID = @id;" +
                    $" COMMIT TRANSACTION;";
                SqlCommand command = new SqlCommand(querystring, database.getConnection());
                database.openConnection();
                command.ExecuteNonQuery();
                database.closeConnection();
                agencyForAdmin.openChildForm(parent);
                this.Close();
            }
        }
    }
}
