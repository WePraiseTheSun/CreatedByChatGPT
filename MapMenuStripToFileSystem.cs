/*
c# winform, if it is drag and drop component just assume the commponent is dragged and dropped on the form, there is no need to provide the common settings such as location size tabindex ..etc, function need to be re-usable in design
I need to create a menu that maps to filesystem with folders subfolders files and files under subfolders
*/

// Create a reusable and dynamically updating menu that maps to the filesystem including all folders and files

using System;
using System.IO;
using System.Windows.Forms;

public class FileSystemMenuForm : Form
{
    private MenuStrip menuStrip;

    public FileSystemMenuForm()
    {
        menuStrip = new MenuStrip();
        Controls.Add(menuStrip);
        InitializeFileSystemMenu(@"C:\"); // Initial path for the file system menu
    }

    private void InitializeFileSystemMenu(string rootPath)
    {
        DirectoryInfo rootDirectory = new DirectoryInfo(rootPath);
        ToolStripMenuItem rootMenuItem = new ToolStripMenuItem(rootDirectory.Name);
        menuStrip.Items.Add(rootMenuItem);
        PopulateMenuWithFileSystemEntries(rootMenuItem, rootDirectory);
    }

    private void PopulateMenuWithFileSystemEntries(ToolStripMenuItem menuItem, DirectoryInfo directoryInfo)
    {
        // Add directories to the menu item
        foreach (DirectoryInfo subDir in directoryInfo.GetDirectories())
        {
            ToolStripMenuItem subDirItem = new ToolStripMenuItem(subDir.Name);
            menuItem.DropDownItems.Add(subDirItem);
            PopulateMenuWithFileSystemEntries(subDirItem, subDir);
        }

        // Add files to the menu item
        foreach (FileInfo file in directoryInfo.GetFiles())
        {
            ToolStripMenuItem fileItem = new ToolStripMenuItem(file.Name);
            menuItem.DropDownItems.Add(fileItem);
        }
    }
}
