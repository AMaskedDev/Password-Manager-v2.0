//
// Created by Theodoridhs on 12/23/2023.
//

#include <iostream>
#include <fstream>

int main()
{
    static bool automatic_login = false;
    static bool operating = false;

    static std::string logged_user = {};

    std::fstream credentials("./credentials.txt");

    // Logging in
    if (automatic_login)
    {
        operating = true;
    }
    else
    {
        // Singing up
        if(credentials)
        {
            std::cout << "No saved credentials found." << std::endl;

            // Credentials variables
            std::string username = {};
            std::string password = {};

            // Asking for new credentials
            std::cout << "Enter username: ";
            std::cin >> username;

            std::cout << "Enter password";
            std::cin >> password;

            // Saving credentials
            credentials << username << std::endl << password;

            // Saving the credentials & closing the file
            credentials.close();
        }

        // Logging in
        else
        {
            std::cout << "Saved credentials found." << std::endl;

            // Credentials variables
            std::string username = {};

            credentials << username;
            logged_user = username;

            std::string password = {};

            // Asking for credentials
            std::cout << "Enter username: ";
            std::cin >> username;

            std::cout << "Enter password";
            std::cin >> password;

            // Saving the credentials & closing the file
            credentials.close();
        }
    }

    // Operating
    std::cout << "Welcome " << logged_user << std::endl;

    while(operating)
    {
        // Reloading files

        // Getting user input
    }


    // Exiting program
    std::cin.get();

    return 0;
}

