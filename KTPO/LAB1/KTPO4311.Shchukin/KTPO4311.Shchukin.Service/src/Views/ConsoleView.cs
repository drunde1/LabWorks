using KTPO4311.Shchukin.Lib.src.LogAn;
namespace KTPO4311.Shchukin.Service.src.Views;

class ConsoleView : IView
{
    public void Render(string text)
    {
        Console.WriteLine(text);
    }
}

