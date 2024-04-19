using Agency.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Agency
{
    public partial class Agency : Form
    {
        private int UserID;
        Database database;
        ToursForm tours;
        PersonalAccount personalAccount;
        OrdersView OrdersView;
        public Agency(int id, Database DB)
        {
            InitializeComponent();
            UserID = id;
            database = DB;
        }

        private void Agency_Load(object sender, EventArgs e)
        {
            panelSubPA.Visible = false;
            tours = new ToursForm(database, this, UserID);
            personalAccount = new PersonalAccount(database, this, UserID);
            OrdersView = new OrdersView(database, this, UserID);
            openChildForm(tours);
        }
        private void hideSubMenu()
        {
            if(panelSubPA.Visible)
            {
                panelSubPA.Visible=false;
            }
        }
        private void showSubMenu()
        {
            if(!panelSubPA.Visible)
            {
                panelSubPA.Visible = true;
            }
        }

        private void buttonPA_Click(object sender, EventArgs e)
        {
            showSubMenu();
        }

        private void buttonUserInf_Click(object sender, EventArgs e)
        {
            hideSubMenu();
            if (activeform != personalAccount)
                openChildForm(personalAccount);
        }

        private void buttonOrders_Click(object sender, EventArgs e)
        {
            hideSubMenu();
            if (activeform != OrdersView)
                openChildForm(OrdersView);
        }

        private void buttonTours_Click(object sender, EventArgs e)
        {
            hideSubMenu();
            if (activeform != tours)
                openChildForm(tours);
        }
        private Form activeform = null;
        public void openChildForm(Form childForm)
        {
            if(activeform != null)
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
