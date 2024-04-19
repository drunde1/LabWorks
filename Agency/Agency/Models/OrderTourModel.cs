using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class OrderTourModel
    {
        public string Country { get; set; }
        public string City { get; set; }
        public string Hotel { get; set; }
        public DateTime StartdateTime { get; set; }
        public DateTime EnddateTime { get; set; }
        public int Price { get; set; }
        public int Tourists { get; set; }
        public OrderTourModel(string country, string city, string hotel, 
            DateTime startdatetime, DateTime enddatetime, int price, int tourists)
        {
            Country = country;
            City = city;
            Hotel = hotel;
            StartdateTime = startdatetime;
            EnddateTime = enddatetime;
            Price = price;
            Tourists = tourists;
        }
    }
}
