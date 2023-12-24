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
    std::fstream passwords("./passwords.txt");

    // Logging in
    if (automatic_login)
    {
        operating = true;
    }
    else
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
            std::ifstream credentials_new("./credentials.txt");

            std::string stored_username = {};
            std::getline(credentials_new, stored_username);

            std::string stored_password = {};
            std::getline(credentials_new, stored_password);

            while (true)
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
                    // Setting the logged_user to the stored_username
                    logged_user = stored_username;

                    // Operating next
                    operating = true;
                    break;

                } else
                {
                    std::cout << "\nInvalid credentials, try again!\n" << std::endl;
                }


                // End of singing in
                credentials.close();
                operating = true;
            }
        }

    }

    // Operating
    system("cls");
    std::cout << "Welcome " << logged_user << std::endl;

    while (operating)
    {
        // Reloading files


        // Getting user input


    }


    // Exiting program
    system("pause");
    return 0;
}
