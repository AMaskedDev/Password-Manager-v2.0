#include <iostream>
#include <fstream>

static void display_help()
{
    std::cout << "\nCommand List\n" <<
              "\n1) 'help' - shows this menu.\n" <<
              "2) 'exit' - exit the program, closing with the x button at the top works as well.\n" <<
              "3) ...\n" << std::endl;
}

static void display_passwords(int lines, std::string array[])
{
     std::cout << "\n";
     for (int i = 0; i < lines; ++i)
     {
         std::cout << array[i] << std::endl << std::endl;
     }
}

static void display_create(std::fstream& file)
{
    // Saving variables
    std::string service = {};
    std::string username = {};
    std::string password = {};

    // Getting the information
    std::cout << "Enter service: ";
    std::cin >> service;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    // Saving
    if(file.is_open())
    {
        std::string account = service + " | " + username + " : " + password;
        file << account;
    }
    else
    {
        std::cerr << "Error writing to file!" << std::endl;
    }
}

int main()
{
    std::fstream credentials("./credentials.txt");
    std::fstream passwords("./passwords.txt");

    std::string stored_username = {};
    std::getline(credentials, stored_username);

    std::string stored_password = {};
    std::getline(credentials, stored_password);

    /*std::cout << stored_username << std::endl;
    std::cout << stored_password << std::endl;*/


    static bool automatic_login = false;
    static bool operating = false;
    static int login_tries = 3;

    if (!passwords) std::ofstream lcl_passwords("./passwords.txt");

    // Logging in
    if (!automatic_login)
    {
        // Singing up
        if (!credentials)
        {
            std::ofstream credentials_new("./credentials.txt");
            std::cout << "No saved credentials found." << std::endl;

            // Credentials variables
            std::string username = {};
            std::string password = {};

            // Asking for new credentials
            std::cout << "Enter username: ";
            std::cin >> username;

            std::cout << "Enter password: ";
            std::cin >> password;

            // Saving credentials
            credentials_new << username << std::endl << password;

            // Saving the credentials & closing the file
            credentials_new.close();
        }

            // Logging in
        else
        {
            std::cout << "Saved credentials found." << std::endl << std::endl;
            while (login_tries > 0)
            {
                // Credentials variables
                std::string input_username = {};
                std::string input_password = {};

                // Asking for credentials
                std::cout << "Enter username: ";
                std::cin >> input_username;

                std::cout << "Enter password: ";
                std::cin >> input_password;

                // Checking the credentials
                if (input_username == stored_username && input_password == stored_password)
                {
                    operating = true;
                    break;
                }
                else
                {
                    std::cout << "\nInvalid credentials, try again!\n" << std::endl;
                    login_tries--;
                }

                // End of singing in
                credentials.close();
            }
        }
    }

    // Operating
    system("cls");
    std::cout << "Welcome " << stored_username << std::endl;

    while (operating)
    {
        // Reloading files
        passwords.close();
        passwords.open("./passwords.txt");

        // Getting how many lines are in the file
        int file_lines = 0;
        std::string output;

        // Counting the number of lines
        while (std::getline(passwords, output)) file_lines++;

        // Rewind the file to the beginning
        passwords.clear();
        passwords.seekg(0, std::ios::beg);

        // Saving for each line the text into an array
        std::string saved_passwords[file_lines];
        for (int i = 0; i < file_lines && std::getline(passwords, output); ++i) saved_passwords[i] = output;

        // Getting user input
        std::string command = {};

        std::cout << "Enter command: ";
        std::cin >> command;

        // Checking what command the user made
        if (command == "help")
        {
            display_help();
        }

        else if (command == "exit")
        {
            break;
        }

        else if (command == "display")
        {
           display_passwords(file_lines, saved_passwords);
        }
        else if(command == "create")
        {
            display_create(passwords);
        }
        else
        {
            std::cout << "Invalid command! Use help." << std::endl;
        }
    }

    // Exiting program
    return 0;
}
