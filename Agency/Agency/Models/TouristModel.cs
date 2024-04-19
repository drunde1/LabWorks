using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class TouristModel
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Passport { get; set; }
        public string MidleName { get; set; }
        public string PhoneNum { get; set; }
        public string Email { get; set; }
        public TouristModel(string surname, string name, string midname, string passport, string phoneNum, string email)
        {
            Surname = surname;
            Name = name;
            Passport = passport;
            MidleName = midname;
            PhoneNum = phoneNum;
            Email = email;
        }
    }
}
