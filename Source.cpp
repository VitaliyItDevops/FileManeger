#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

//File manager

class fileDirectory {
public:
    string path = "";

    void print_InfoDirectoryDrive() {
        cout << "Enter Path. Example: D:/ " << endl;
        cout << "Enter: ";
        cin >> path;

        try {
            //Loop outputting disk contents
            for (const auto& entry : fs::directory_iterator(path)) {
                std::cout << entry.path() << std::endl;
            }
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when accessing the file system: " << e.what() << std::endl;
            path = "";
        }
    }


    void CreateFolder() {


        cout << "Enter Path. Example: C:/Users/myPC/Desktop/new " << endl;
        cout << "where /new is the name of the new folder" << endl;
        cout << "Enter: ";
        cin >> path;

        try {
            //Path to new folder
            fs::path new_directory_path(path);

            //Creating a folder 
            fs::create_directory(new_directory_path);
            cout << "The folder has been created successfully." << std::endl;

            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when accessing the file system: " << e.what() << std::endl;

            path = "";
        }
    }

    void createFile() {
        cout << "Enter Path. Example: path/to/new_file.txt " << endl;
        cout << "where /new_file.txt is the name of the new file" << endl;
        cout << "Enter: ";
        cin >> path;

        ofstream file(path);

        //Opening the file via fstream, this is how we create it. Afterwards we close
        if (file.is_open()) {
            file.close();
            cout << "The file was created successfully." << std::endl;
            path = "";
        }
        else {
            cerr << "Failed to create file." << std::endl;
            path = "";
        }
    }

    void deleteFolder() {
        cout << "Enter Path. Example: C:/Users/myPC/Desktop/new " << endl;
        cout << "where /new is the name of the folder you want to delete" << endl;
        cout << "Enter: ";
        cin >> path;


        try {
            //Path to the folder to be deleted
            fs::path directory_to_remove(path);

            //Deleting a folder 
            fs::remove_all(directory_to_remove);
            std::cout << "The folder was successfully deleted." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when accessing the file system:" << e.what() << std::endl;
            path = "";
        }
    }

    void deleteFile() {

        cout << "Enter Path. Example: C:/Users/myPC/Desktop/file.txt " << endl;
        cout << "where /file.txt is the name of the file you want to delete" << endl;
        cout << "Enter: ";
        cin >> path;

        try {
            //Path to the file to be deleted
            fs::path file_to_remove(path);

            //Deleting a file
            fs::remove(file_to_remove);
            std::cout << "The file was successfully deleted." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when accessing the file system: " << e.what() << std::endl;
            path = "";
        }
    }

    void renameFolder() {
        cout << "Enter Path. Example: old file - path/to/old_directory. New file path/to/new_directory" << endl;
        cout << "where /new_directory is the new folder name" << endl;
        cout << "Enter: ";
        cin >> path;


        cout << "Enter: ";
        string path2;
        cin >> path2;

        try {
            //Path to existing folder
            fs::path old_directory_path(path);

            //Path to new folder
            fs::path new_directory_path(path2);

            //Renaming a folder
            fs::rename(old_directory_path, new_directory_path);
            std::cout << "The folder has been successfully renamed." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when renaming a folder:" << e.what() << std::endl;
            path = "";
        }
    }

    void renameFile() {
        cout << "Enter Path. Example: old file - path/to/old_file.txt. New file path/to/new_file.txt" << endl;
        cout << "where /new_file.txt is the new file name" << endl;
        cout << "Enter: ";
        cin >> path;

        
        cout << "Enter: ";
        string path2;
        cin >> path2;


        try {
            //Path to existing file
            fs::path old_file_path(path);

            // Путь к новому файлу
            fs::path new_file_path(path2);

            //Renaming a file
            fs::rename(old_file_path, new_file_path);
            std::cout << "The file has been successfully renamed." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when renaming a file:" << e.what() << std::endl;
            path = "";
        }
    }

    void copyFolder() {
        cout << "Enter Path. Example: old directory - path/to/source_directory. New directory path/to/target_directory" << endl;
        cout << "where path/to/target_directory the directory where you want to copy the folder" << endl;
        cout << "Enter: ";
        cin >> path;


        cout << "Enter: ";
        string path2;
        cin >> path2;


        try {
            //Path to existing folder
            fs::path source_directory(path);

            //Path to target folder (new location)
            fs::path target_directory(path2);

            //Copying a folder
            fs::copy(source_directory, target_directory / source_directory.filename(), fs::copy_options::recursive);
            std::cout << "The folder was copied successfully." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when copying folder:" << e.what() << std::endl;
            path = "";
        }
    }

    void transferFolder() {
        cout << "Enter Path. Example: old directory - path/to/source_directory. New directory path/to/target_directory" << endl;
        cout << "where path/to/target_directory the directory where you want to transfer the folder" << endl;
        cout << "Enter: ";
        cin >> path;


        cout << "Enter: ";
        string path2;
        cin >> path2;

        try {
            //Path to existing folder
            fs::path source_directory(path);

            //Path to target folder (new location)
            fs::path target_directory(path2);

            //Moving (transferring) a folder
            fs::rename(source_directory, target_directory / source_directory.filename());
            std::cout << "The folder has been successfully moved." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when moving folder:" << e.what() << std::endl;
            path = "";
        }
    }

    void copyFile() {
        cout << "Enter Path. Example: old directory - path/to/source_file.txt. New directory path/to/target_file.txt" << endl;
        cout << "where path/to/target_file.txt the directory where you want to copy the file" << endl;
        cout << "Enter: ";
        cin >> path;


        cout << "Enter: ";
        string path2;
        cin >> path2;


        try {
            //Path to existing folder
            fs::path source_file(path);

            //Path to target folder (new location)
            fs::path target_file(path2);

            //Copying a folder
            fs::copy(source_file, target_file);
            std::cout << "The folder was copied successfully." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when copying folder:" << e.what() << std::endl;
            path = "";
        }
    }

    void transferFile() {
        cout << "Enter Path. Example: old directory - path/to/source_file.txt. New directory path/to/target_file.txt" << endl;
        cout << "where path/to/target_file.txt the directory where you want to transfer the file" << endl;
        cout << "Enter: ";
        cin >> path;


        cout << "Enter: ";
        string path2;
        cin >> path2;


        try {
            //Source file path
            fs::path source_file(path);

            //Path to target file (new location)
            fs::path target_file(path2);

            //Move a file
            fs::rename(source_file, target_file);
            std::cout << "The file has been successfully moved." << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when moving file:" << e.what() << std::endl;
            path = "";
        }
    }

    void folderSize() {
        cout << "Enter Path. Example: path/to/directory " << endl;
        cout << "where /directory is the name of the folder whose size you want to know" << endl;
        cout << "Enter: ";
        cin >> path;

        try {
            //Path to the folder whose size needs to be calculated
            fs::path directory_path(path);

            //Disk space information, including folder size
            fs::space_info space = fs::space(directory_path);

            //Display folder size in bytes
            std::cout << "Folder size: " << space.capacity << " byte" << std::endl;

            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error when calculating folder size: " << e.what() << std::endl;
            path = "";
        }
    }

    void fileSize() {

        cout << "Enter Path. Example: path/to/file.txt " << endl;
        cout << "where /file.txt is the name of the file whose size you want to know" << endl;
        cout << "Enter: ";
        cin >> path;


        try {
            //Path to the file whose size you want to find out
            fs::path file_path(path);

            //Getting the file size in bytes
            std::uintmax_t file_size = fs::file_size(file_path);

            //File size output
            std::cout << "File size: " << file_size << " byte" << std::endl;
            path = "";
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error getting file size: " << e.what() << std::endl;
            path = "";
        }
    }

    void searchFiles() {
        cout << "Enter Path. Example: directory - path/to/search_directory. type file - .txt" << endl;
        cout << "where path/to/search_directory the path in which you want to find files by mask" << endl;
        cout << "Enter: ";
        cin >> path;

        cout << "Enter: ";
        string mask;
        cin >> mask;

        fs::path search_directory(path);

        //The extension of the files you are looking for (for example, ".txt")
        std::string file_extension(mask);

        try {
            for (const auto& entry : fs::recursive_directory_iterator(path)) {
                if (entry.is_regular_file() && entry.path().extension() == mask) {
                    std::cout << "File found: " << entry.path() << std::endl;
                }
            }
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error while searching for files: " << e.what() << std::endl;
        }
    }

};


int main() {

    setlocale(LC_ALL, "RU");
    fileDirectory os;

    //Program menu 

    bool b = true;
    while (b == true) {
        int number;
        cout << "Menu: " << endl;
        cout << "1. Find out the disk size" << endl;
        cout << "2. Create a folder" << endl;
        cout << "3. Create an empty file" << endl;
        cout << "4. Delete folder" << endl;
        cout << "5. Delete file" << endl;
        cout << "6. Rename the folder" << endl;
        cout << "7. Rename the file" << endl;
        cout << "8. Copy folder" << endl;
        cout << "9. Move folder" << endl;
        cout << "10. Copy file" << endl;
        cout << "11. Move file" << endl;
        cout << "12. Calculate folder size" << endl;
        cout << "13. Calculate file size" << endl;
        cout << "14. search by mask (with search by subfolders)" << endl;
        cout << "15. End" << endl;

        cin >> number;
        switch (number) {
        case 1:
            cout << "1. Find out the disk size" << endl;
            os.print_InfoDirectoryDrive();
            break;
        case 2:
            cout << "2. Create a folder" << endl;
            os.CreateFolder();
            break;
        case 3:
            cout << "3. Create an empty file" << endl;
            os.createFile();
            break;
        case 4:
            cout << "4. Delete folder" << endl;
            os.deleteFolder();
            break;
        case 5:
            cout << "5. Delete file" << endl;
            os.deleteFile();
            break;
        case 6:
            cout << "6. Rename the folder" << endl;
            os.renameFolder();
            break;
        case 7:
            cout << "7. Rename the file" << endl;
            os.renameFile();
            break;
        case 8:
            cout << "8. Copy folder" << endl;
            os.copyFolder();
            break;
        case 9:
            cout << "9. Move folder" << endl;
            os.transferFolder();
            break;
        case 10:
            cout << "10. Copy file" << endl;
            os.copyFile();
            break;
        case 11:
            cout << "11. Move file" << endl;
            os.transferFile();
            break;
        case 12:
            cout << "12. Calculate folder size" << endl;
            os.folderSize();
            break;
        case 13:
            cout << "13. Calculate file size" << endl;
            os.fileSize();
            break;
        case 14:
            cout << "14. search by mask (with search by subfolders)" << endl;
            os.searchFiles();
            break;
        case 15:
            cout << "15. End" << endl;
            b = false;
            break;
        }

    }


    return 0;
}