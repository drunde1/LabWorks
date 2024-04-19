using KTPO4311.Shchukin.Lib.src.LogAn;
using NSubstitute;
using NUnit.Framework;

namespace KTPO4311.Shchukin.UnitTest.src.LogAn
{
    public class LogAnalyzerNSubstituteTests
    {
        [Test]
        public void IsValidFileName_NameSupportedExtension_ReturnsTrue()
        {
            // Подготовка теста
            IExtensionManager fakeExtensionManager = Substitute.For<IExtensionManager>();

            // Конфигурируем фабрику для создания поддельных объектов
            fakeExtensionManager.IsValid("filename.slf").Returns(true);
            ExtensionManagerFactory.SetManager(fakeExtensionManager);

            LogAnalyzer log = new LogAnalyzer();
            bool result = log.IsValidLogFileName("filename.slf");

            Assert.IsTrue(result);
        }

        [Test]
        public void IsValidFileName_NameUnsupportedExtension_ReturnsFalse()
        {
            // Подготовка теста
            IExtensionManager fakeExtensionManager = Substitute.For <IExtensionManager>();

            // Конфигурируем фабрику для создания поддельных объектов
            fakeExtensionManager.IsValid("filename.slf").Returns(true);
            ExtensionManagerFactory.SetManager(fakeExtensionManager);

            LogAnalyzer log = new LogAnalyzer();
            bool result = log.IsValidLogFileName("filename.gfd");

            Assert.IsFalse(result);
        }

        [Test]
        public void IsValidFileName_ExtManagerThrowsException_ReturnsFalse()
        {
            // Создать поддельный объект
            IExtensionManager fakeExtensionManager = Substitute.For<IExtensionManager>();

            //Настроить объект, чтобы метод вызвал исключение назависимо от входного дараметра
            fakeExtensionManager.When(x => x.IsValid("notrightstr")) // WhenCalled<IExtensionManager>
            .Do(context => { throw new Exception("fake exception"); });

            // Конфигурируем фабрику для создания поддельных объектов
            ExtensionManagerFactory.SetManager(fakeExtensionManager);
            LogAnalyzer log = new LogAnalyzer();

            // Проверка ожидаемого результата
            Assert.False(log.IsValidLogFileName("filename.gfd"));
        }

        [Test]
        public void Analyze_TooShortFileName_CallsWebService()
        {
            IWebService mockWebService = Substitute.For<IWebService>();
            WebServiceFactory.SetWebService(mockWebService);
            LogAnalyzer log = new LogAnalyzer();
            string tooShortFileName = "abc.ext";

            // Воздействие на тестирцемый объект
            log.Analyze(tooShortFileName);

            // Проверка ожидаемого результата
            mockWebService.Received().LogError("Слишком короткое имя файла: abc.ext");
        }

        [Test]
        public void Analyze_WebServiceThrows_SendsEmail()
        {
            IWebService mockWebService = Substitute.For<IWebService>();
            mockWebService.When(x => x.LogError(Arg.Any<string>())) // WhenCalled IWebService>
                .Do(context => { throw new Exception(message: "это подделка");});
            WebServiceFactory.SetWebService(mockWebService);

            IEmailService mockEmailService = Substitute.For<IEmailService>();
            EmailServiceFactory.SetEmailService(mockEmailService);

            LogAnalyzer log = new LogAnalyzer();
            string tooShortFileName = "abc.ext";

            // Воздействие на тестируемый объект
            log.Analyze(tooShortFileName);

            mockEmailService.Received().SendEmail(to: "someone@somewhere.com", subject: "Невозможно вызвать веб-сервис", body: "это подделка");
        }


    }
}
