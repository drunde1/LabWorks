using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class TourModel
    {
        public int ID { get; set; }
        public string Country { get; set; }
        public string City { get; set; }
        public string Hotel { get; set; }
        public int HotClass { get; set; }
        public int Price { get; set; }
        public int Transport { get; set; }


        public TourModel(int id, string country, string city, string hotel, int hotelclass, int price, int transport = 0)
        {
            ID = id;
            Country = country;
            City = city;
            Hotel = hotel;
            HotClass = hotelclass;
            Price = price;
            Transport = transport;
        }
    }
}
