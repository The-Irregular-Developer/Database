#include <iostream>
#include <fstream>
#include <map>

void mainMenu()
{
    std::cout << "1. Add person to database\n";
    std::cout << "2. Search database\n";
    std::cout << "3. View entire database\n";
    std::cout << "4. Exit\n";
}
int main()
{
    std::ofstream writeDatabase;
    writeDatabase.open("Database.txt", std::ios::app);
    std::string name;
    int id;
    int choice;
    std::map <int, std::string> idDatabase;
    while (true)
    {
        mainMenu();
        std::cout << "\nWhat would you like to do? ";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                system("cls");
                std::cout << "What is the ID of the person? ";
                std::cin >> id;
                std::cout << std::endl;
                std::cout << "What is the name of the person? ";
                std::cin >> name;
                idDatabase[id] = name;
                writeDatabase << "ID: " << id << std::endl << "Name: "<< name << std::endl << std::endl;
                std::cout << "Added successfully\n\n";
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                std::cout << "\nWhat is the ID of the person that you would like to search? ";
                std::cin >> id;
                std::cout << std::endl;
                if (idDatabase.find(id) != idDatabase.end())
                {
                    std::cout << "Found! The name of the person is " << idDatabase[id] << std::endl << std::endl;
                }
                else
                {
                    std::cout << "Did not find ID " << id << " in the database. Add the ID to the database.\n";
                }
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                for (std::map <int, std::string>::iterator idIT = idDatabase.begin(); idIT != idDatabase.end(); idIT++)
                {
                    std::cout << "ID: " << idIT->first << std::endl << "Name: " << idIT->second << std::endl << std::endl;
                }
                system("pause");
                system("cls");
                break;
            case 4:
                writeDatabase.close();
                return 0;
        }
    }

}
