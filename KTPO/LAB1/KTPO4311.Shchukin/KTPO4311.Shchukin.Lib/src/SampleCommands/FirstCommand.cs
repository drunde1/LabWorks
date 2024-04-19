using KTPO4311.Shchukin.Lib.src.LogAn;
namespace KTPO4311.Shchukin.Lib.src.SampleCommands;

public class FirstCommand : ISampleCommand
{
    public readonly IView view;
    private int iExecute = 0;

    public FirstCommand(IView view)
    {
        this.view = view;
    }
    public void Execute()
    {
        iExecute++;
        view.Render(this.GetType().ToString() + "\niExecute = " + iExecute);
    }
}

