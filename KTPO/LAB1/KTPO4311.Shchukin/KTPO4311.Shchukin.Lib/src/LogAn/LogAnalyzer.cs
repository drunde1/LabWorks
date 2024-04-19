namespace KTPO4311.Shchukin.Lib.src.LogAn
{
    /// <summary> Анализатор лог. файлов </summary>
    public class LogAnalyzer : ILogAnalyze
    {
        ///<summary> Объявление события</summary>
        public event LogAnalyzerAction? Analyzed = null;

       
        /// <summary> Проверка правильности имен файлов </summary>
        public bool IsValidLogFileName(string fileName)
        {
            IExtensionManager Mrg = ExtensionManagerFactory.Create();
            return Mrg.IsValid(fileName);
        }

        ///<summary> Анализировать лог файл</summary>
        ///<param name="fileName"></param>
        public void Analyze(string fileName)
        {
            if (fileName.Length < 8)
            {
                try
                {
                    //Передать внешней службе сообщение об ошибке
                    IWebService srv = WebServiceFactory.Create();
                    srv.LogError("Слишком короткое имя файла: " + fileName);
                }
                catch (Exception e)
                {
                    IEmailService emailService = EmailServiceFactory.Create();
                    emailService.SendEmail(to: "someone@somewhere.com", subject: "Невозможно вызвать веб-сервис", body: e.Message);
                }
            }

            //Обработка лога
            //...
            RaiseAnalyzedEvent();
        }
        public void RaiseAnalyzedEvent()
        {
            //Вызов события
            if (Analyzed != null)
            {
                Analyzed();
            }
        }
    }
}
