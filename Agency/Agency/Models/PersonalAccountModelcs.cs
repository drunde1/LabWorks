using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class PersonalAccountModelcs
    {
        public string Name { get; set; }
        public string Email { get; set; }
        public string PhoneNumber { get; set; }
        public string Surname { get; set; }
        public string Passport { get; set; }
        public string MidleName { get; set; }
        public string Login { get; set; }
        public string Password { get; set; }
        public PersonalAccountModelcs(string name, string surname, string midlename, string passport, string phone, string email, string login, string password)
        {
            Name = name;
            Email = email;
            PhoneNumber = phone;
            Surname = surname;
            Passport = passport;
            MidleName = midlename;
            Login = login;
            Password = password;
        }

    }
}
