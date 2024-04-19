using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Agency.Models
{
    public class UserModel
    {
        public int ID { get; set; }
        public string UserRole { get; set; }
        public string UserLogin { get; set; }
        public string UserPassword { get; set; }
        public string UserName { get; set; }
        public string UserData { get; set; }
        public UserModel(int id, string role, string login, string password, string name, string data)
        {
            ID = id;
            UserRole = role;
            UserLogin = login;
            UserPassword = password;
            UserName = name;
            UserData = data;
        }

    }
}
