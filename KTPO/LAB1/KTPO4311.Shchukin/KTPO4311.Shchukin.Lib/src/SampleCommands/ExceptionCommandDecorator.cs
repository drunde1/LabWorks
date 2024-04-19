using KTPO4311.Shchukin.Lib.src.LogAn;

namespace KTPO4311.Shchukin.Lib.src.SampleCommands;

public class ExceptionCommandDecorator : ISampleCommand
{
    private readonly ISampleCommand sampleCommand;
    private IView view;

    public ExceptionCommandDecorator(ISampleCommand sampleCommand, IView view)
    {
        this.sampleCommand = sampleCommand;
        this.view = view;
    }


    public void Execute()
    {
        try
        {
            sampleCommand.Execute();
        }
        catch (Exception e)
        {
            view.Render("Перехват исключения: " + this.GetType().ToString() + "-" + e.Message);
        }
    }
}

