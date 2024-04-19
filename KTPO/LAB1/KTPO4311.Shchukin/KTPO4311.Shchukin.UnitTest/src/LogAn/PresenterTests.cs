using NUnit.Framework;
using KTPO4311.Shchukin.Lib.src.LogAn;
using NSubstitute;

namespace KTPO4311.Shchukin.UnitTest.src.LogAn;

[TestFixture]
public class PresenterTests
{
    [Test]
    public void ctor_WhenAnalyzed_CallsViewRender()
    {
        //Подготовка теста
        FakeLogAnalyzer fakeAnalyzer = new FakeLogAnalyzer();
        IView view = Substitute.For<IView>();
        Presenter presenter = new Presenter(fakeAnalyzer, view);

        //Воздействие на тестируемый объект
        fakeAnalyzer.CallRaiseAnalyzedEvent();

        //Проверка ожидаемого результата
        view.Received().Render("Обработка завершена");
    }

    [Test]
    public void ctor_WhenAnalyzed_CallsViewRender_NSubstitute()
    {
        //Подготовка теста
        ILogAnalyze mockAnalyzer = Substitute.For<ILogAnalyze>();
        IView mockView = Substitute.For<IView>();
        Presenter presenter = new Presenter(mockAnalyzer, mockView);

        //Воздействие на тестируемый объект
        mockAnalyzer.Analyzed += Raise.Event<LogAnalyzerAction>();

        //Проверка ожидаемого результата
        mockView.Received().Render("Обработка завершена");
    }
}

public class FakeLogAnalyzer : LogAnalyzer
{
    public void CallRaiseAnalyzedEvent()
    {
        base.RaiseAnalyzedEvent();
    }
}