namespace KTPO4311.Shchukin.Lib.src.LogAn
{
    public static class WebServiceFactory
    {
        private static IWebService? customService = null;

        ///<summary>Создание объектов</summary>
        public static IWebService Create()
        {
            if (customService != null)
            {
                return customService;
            }
            return new WebService();
        }

        ///<summary>Методт позволит тестам контролировать,
        ///что возвращает фабрика</summary>
        ///<param name="mgr"></param>
        public static void SetWebService(IWebService? service)
        {
            customService = service;
        }
    }
}
