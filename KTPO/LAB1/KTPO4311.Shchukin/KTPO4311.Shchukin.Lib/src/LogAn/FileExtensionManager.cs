using System;
using System.Configuration;

namespace KTPO4311.Shchukin.Lib.src.LogAn
{
    /// <summary> Менеджер расширений фыайлов </summary>
    public class FileExtensionManager : IExtensionManager
    {

        /// <summary> Проверка правильности расширения </summary>    
        public bool IsValid(string fileName)
        {
           foreach (string s in ConfigurationManager.AppSettings.AllKeys)
            {
                if (fileName.Contains(ConfigurationManager.AppSettings.Get(s)))
                {
                    return true;
                }
            }
           return false;
        }

       
    }
}