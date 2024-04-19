using NUnit.Framework;
using KTPO4311.Shchukin.Lib.src.LogAn;


namespace KTPO4311.Shchukin.UnitTest.src.LogAn
{
    [TestFixture]
    public class LogAnalyzerTests
    {
        [TearDown]
        public void AfterEachTest()
        {
            ExtensionManagerFactory.SetManager(mgr:null);
            WebServiceFactory.SetWebService(service:null);
            EmailServiceFactory.SetEmailService(service:null);
        }

        [Test]
        public void IsValidFileName_NameSupportedExtension_ReturnsTrue()
        {
            //Подготовка теста
            FakeExtensionManager fakeManager = new FakeExtensionManager(); 
            fakeManager.WillBeValid = true;
            //..конфигурируем фабрику для создания поддельнх объектов
            ExtensionManagerFactory.SetManager(fakeManager);

            LogAnalyzer log = new LogAnalyzer();

            //Воздействие на тестируемый объект
            bool rezult = log.IsValidLogFileName("short.ext");

            //Проверка жидаемого результата
            Assert.True(rezult);
        }

        [Test]
        public void IsValidFileName_NameUnupportedExtension_ReturnsFalse()
        {
            //Подготовка теста
            FakeExtensionManager fakeManager = new FakeExtensionManager();
            fakeManager.WillBeValid = false;
            //..конфигурируем фабрику для создания поддельнх объектов
            ExtensionManagerFactory.SetManager(fakeManager);

            LogAnalyzer log = new LogAnalyzer();

            //Воздействие на тестируемый объект
            bool rezult = log.IsValidLogFileName("short.ext");

            //Проверка жидаемого результата
            Assert.False(rezult);
        }

        [Test]
        public void IsValidFileName_ExtManagerThrowsException_ReturnsFalse()
        {
            //Подготовка теста
            FakeExtensionManager fakeManager = new FakeExtensionManager();
            fakeManager.WillBeValid = false;
            fakeManager.WillThrow = new Exception();
            //..конфигурируем фабрику для создания поддельнх объектов
            ExtensionManagerFactory.SetManager(fakeManager);

            LogAnalyzer log = new LogAnalyzer();

            //Воздействие на тестируемый объект
            bool rezult = log.IsValidLogFileName("short.ext");

            //Проверка жидаемого результата
            Assert.False(rezult);
        }

        [Test]
        public void Analyze_TooShortFileName_CallsWebService()
        {
            //Подготовка теста
            FakeWebService mockWebService = new FakeWebService();
            WebServiceFactory.SetWebService(mockWebService);
            LogAnalyzer log = new LogAnalyzer();
            string tooShortFileName = "abc.ext";

            //Воздействие на тестируемый объект
            log.Analyze(tooShortFileName);

            //Проверка жидаемого результата
           StringAssert.Contains("Слишком короткое имя файла: abc.ext",
               mockWebService.LastError);
        }

        [Test]
        public void Analyze_WebServiceThrows_SendsEmail()
        {
            //Подготовка теста
            FakeWebService stubWebService = new FakeWebService();
            WebServiceFactory.SetWebService(stubWebService);
            stubWebService.WillThrowWeb = new Exception(message: "подделка");

            FakeEmailService mockEmail = new FakeEmailService();
            EmailServiceFactory.SetEmailService(mockEmail);

            LogAnalyzer log = new LogAnalyzer();
            string tooShortFileName = "abc.ext";

            //Воздействие на тестируемый объект
            log.Analyze(tooShortFileName);

            //Проверка жидаемого результата
            //Здесь тест будет ложным, если неверно хотя бы одно утверждение
            //поэтому здесь допустимо несмколько утверждений
            StringAssert.Contains(expected: "someone@somewhere.com", actual: mockEmail.To);
            StringAssert.Contains(expected: "подделка", actual: mockEmail.Body);
            StringAssert.Contains(expected: "Невозможно вызвать веб-сервис", actual: mockEmail.Subject);
        }

        [Test]
        public void Analyze_WhenAnalyzed_FiredEvent()
        {
            //Подготовка теста
            bool analyzedFired = false;
            LogAnalyzer logAnalyzer = new LogAnalyzer();

            logAnalyzer.Analyzed += delegate()
            {
                analyzedFired = true;
            };

            //Воздействие на тестируемый объект
            logAnalyzer.Analyze("validfilename.vld");

            //Проверка жидаемого результата
            Assert.IsTrue(analyzedFired);
        }
    }


    ///<summary> Поддельный менеджер расширений </summary>
    internal class FakeExtensionManager : IExtensionManager
    {
        ///<summary> это поле позволяет настроить
        /// поддельный результат для метода IsValid</summary>
        public bool WillBeValid = false;

        ///<summary> это поле позволяет настроить
        /// поддельное исключение для метода IsValid</summary>
        public Exception? WillThrow = null;

        public bool IsValid(string fileName)
        {
            if (WillThrow != null)
            {
                return false;
            }
            return WillBeValid;
        }
    }

    ///<summary> Поддельная веб-служба </summary>
    internal class FakeWebService : IWebService
    {
        ///<summary> это поле запоминает состояние полсле вызова метода LogError
        ///При тестировании взаимодействия утверждения высказываются относительно</summary>
        public string LastError;
        public Exception? WillThrowWeb = null;
        public void LogError(string message)
        {
            if (WillThrowWeb != null)
            {
                throw WillThrowWeb;
            }
            LastError = message;
        }
    }

    ///<summary> Поддельная email-служба </summary>
    internal class FakeEmailService : IEmailService
    {
        ///<summary> это поле запоминает состояние полсле вызова метода SendEmail
        ///При тестировании взаимодействия утверждения высказываются относительно</summary>
        public string To, Subject, Body;
        public Exception? WillThrowWeb = null;
        public void SendEmail(string to, string subject, string body)
        {
            To = to;
            Subject = subject; 
            Body = body;
        }
    }
}
