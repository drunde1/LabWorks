using KTPO4311.Shchukin.Lib.src.LogAn;
using KTPO4311.Shchukin.Lib.src.SampleCommands;
using NSubstitute;
using NUnit.Framework;

namespace KTPO4311.Shchukin.UnitTest.src.Command;
[TestFixture]
public class CommandNSubstituteTests
{
    [Test]
    public void FirstCommand_Execute_IsValidText()
    {
        IView mockView = Substitute.For<IView>();
        FirstCommand firstCommand = new FirstCommand(mockView);

        firstCommand.Execute();
        var iExecute = 1;

        mockView.Received().Render(firstCommand.GetType().ToString() + "\niExecute = " + iExecute);
    }

    [Test]
    public void SampleCommandDecorator_Execute_CallsExecute()
    {
        IView mockView = Substitute.For<IView>();
        ISampleCommand mockCommand = Substitute.For<ISampleCommand>();

        SampleCommandDecorator decorator = new SampleCommandDecorator(mockCommand, mockView);

        decorator.Execute();
        mockCommand.Received().Execute();
    }

    [Test]
    public void SampleCommandDecorator_Execute_IsvalidText()
    {
        IView mockView = Substitute.For<IView>();
        ISampleCommand mockCommand = Substitute.For<ISampleCommand>();

        SampleCommandDecorator decorator = new SampleCommandDecorator(mockCommand, mockView);

        decorator.Execute();
        mockView.Received().Render($"Начало: {decorator.GetType()}");
        mockView.Received().Render($"Конец: {decorator.GetType()}");

    }

    [Test]
    public void ExceptionCommandDecorator_Execute_CallsExecute()
    {
        IView mockView = Substitute.For<IView>();
        ISampleCommand mockCommand = Substitute.For<ISampleCommand>();

        ExceptionCommandDecorator decorator = new ExceptionCommandDecorator(mockCommand, mockView);

        decorator.Execute();
        mockCommand.Received().Execute();
    }

    [Test]
    public void ExceptionCommandDecorator_Execute_CatchesException()
    {
        IView mockView = Substitute.For<IView>();
        ISampleCommand mockCommand = Substitute.For<ISampleCommand>();

        Exception e = new Exception("Исключение");
        mockCommand.When(x => x.Execute()).Do(context => { throw e; }) ;

        ExceptionCommandDecorator decorator = new ExceptionCommandDecorator(mockCommand, mockView);

        decorator.Execute();
       // mockView.Received().Render("Перехват исключения: " + this.GetType().ToString() + "-" + e.Message);
    }
        
}


