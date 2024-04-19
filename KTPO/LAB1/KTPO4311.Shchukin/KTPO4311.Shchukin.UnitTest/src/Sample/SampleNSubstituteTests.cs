using KTPO4311.Shchukin.Lib.src.LogAn;
using NSubstitute;
using NUnit.Framework;

namespace KTPO4311.Shchukin.UnitTest.src.Sample
{
    internal class SampleNSubstituteTests
    {
        [Test]
        public void Returns_ParticularArg_Works()
        {
            //Создать поддельный объект
            IExtensionManager fakeExtensionManager = Substitute.For<IExtensionManager>();

            //Настроить объект, чтобы метод возвращал срое для заданого значения входного параметра
            fakeExtensionManager.IsValid("validfile.ext").Returns(true);

            //Воздействие на тестируемый объект
            bool result = fakeExtensionManager.IsValid("validfile.ext");

            //Проверка охидаемого результата
            Assert.IsTrue(result);
        }

        [Test]
        public void Returns_ArgAny_Works()
        {
            // Создать поддельный объект
            IExtensionManager fakeExtensionManager = Substitute.For<IExtensionManager>();

            //Настроить объект, чтобы метод возвращал срое для дюбого значения входного параметра
            fakeExtensionManager.IsValid(Arg.Any<string>()).Returns(true);

            // Воздействие на тестуршеный объект
            bool result = fakeExtensionManager.IsValid("anyfile.ext");

            //Дроверка ожидаемого результата
            Assert.IsTrue(result);
        }

        [Test]
        public void Returns_ArgAny_Throws()
        {
            // Создать поддельный объект
            IExtensionManager fakeExtensionManager = Substitute.For<IExtensionManager>();

            //Настроить объект, чтобы метод вызвал исключение назависико от входного дараметра
            fakeExtensionManager.When(x => x.IsValid(Arg.Any<string>())).Do(context => { throw new Exception("fake exception"); });

            // Дроверка, что было вызвано мокличение
            Assert.Throws<Exception>(() => fakeExtensionManager.IsValid("anystring"));
        }

        [Test]
        public void Received_ParticularArg_Saves()
        {
            // Создать поддельный объект
            IWebService mockWebService = Substitute.For<IWebService>();

            //Воздействие на доддельный объект
            mockWebService.LogError("Поддельное сообщение");

            // Дроверка, что поддельный объект сохранил дараметвы вызова
            mockWebService.Received().LogError("Поддельное сообщение");
        }
    }
}
