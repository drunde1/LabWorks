using NUnit.Framework;
using KTPO4311.Shchukin.Lib.src.LogAn;

namespace KTPO4311.Shchukin.UnitTest.src.LogAn
{
    [TestFixture]
    public class LogAnalyzerTests
    {
        [Test]
        public void IsValidFileName_NameSupportedExtension_ReturnsTrue()
        {
            //Подготовка теста
            FakeExtensionManager fakeManager = new FakeExtensionManager(); 
            fakeManager.WillBeValid = true;

            LogAnalyzer log = new LogAnalyzer(fakeManager);

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

            LogAnalyzer log = new LogAnalyzer(fakeManager);

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

            LogAnalyzer log = new LogAnalyzer(fakeManager);

            //Воздействие на тестируемый объект
            bool rezult = log.IsValidLogFileName("short.ext");

            //Проверка жидаемого результата
            Assert.False(rezult);
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
}
