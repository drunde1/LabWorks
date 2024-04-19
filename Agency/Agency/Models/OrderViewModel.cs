using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class OrderViewModel
    {
        public int OrderID { get; set; }
        public string Tour { get; set; }
        public string Date { get; set; }
        public int Price { get; set; }
        public string Name { get; set; }
        public string Data { get; set; }
        public OrderViewModel(int ID, string tour, string date, int price, string name, string data)
        {
            OrderID = ID;
            Tour = tour;
            Date = date;
            Price = price;
            Name = name;
            Data = data;
        }
    }
}
