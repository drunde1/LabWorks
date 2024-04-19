namespace KTPO4311.Shchukin.Lib.src.LogAn
{
    public class EmailServiceFactory
    {
        public static IEmailService? customService = null;

        ///<summary>Создание объектов</summary>
        public static IEmailService Create()
        {
            if (customService != null)
            {
                return customService;
            }
            return new EmailService();
        }

        ///<summary>Методт позволит тестам контролировать,
        ///что возвращает фабрика</summary>
        ///<param name="mgr"></param>
        public static void SetEmailService(IEmailService? service)
        {
            customService = service;
        }
    }
}
