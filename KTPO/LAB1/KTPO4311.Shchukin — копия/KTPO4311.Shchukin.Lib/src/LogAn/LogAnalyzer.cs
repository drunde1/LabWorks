namespace KTPO4311.Shchukin.Lib.src.LogAn
{
    /// <summary> Анализатор лог. файлов </summary>
    public class LogAnalyzer
    {
        private IExtensionManager Mrg { get; set; }

        public LogAnalyzer(IExtensionManager mrg)
        {
            Mrg = mrg;
        }
        /// <summary> Проверка правильности имен файлов </summary>
        public bool IsValidLogFileName(string fileName)
        {
            IExtensionManager mrg = new FileExtensionManager();
            return Mrg.IsValid(fileName);
        }
    }
}
