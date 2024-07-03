#include <iostream>
#include "movie.h"
#include "collecter.h"

enum CollecterCommand {ADD, LIST, CONTAINS, CLEAR, REMOVE, QUIT, UNKNOWN};
CollecterCommand ParseCommand(const std::string& command)
{
    if (command == "add")
    {
        return ADD;
    }
    else if (command == "list")
    {
        return LIST;
    }
    else if (command == "clear")
    {
        return CLEAR;
    }
    else if (command == "remove")
    {
        return REMOVE;
    }
    else if (command == "contains")
    {
        return CONTAINS;
    }
    else if (command == "quit" || command == "exit")
    {
        return QUIT;
    }
    else
    {
        return UNKNOWN;
    }
}

void PrintCommands()
{
    std::cout << "Commands:" << std::endl;
    std::cout << "add" << std::endl;
    std::cout << "list" << std::endl;
    std::cout << "clear" << std::endl;
    std::cout << "remove" << std::endl;
    std::cout << "quit" << std::endl;
}

int main()
{
    std::cout << "Hello Collecter" << std::endl;
    PrintCommands();
    Collecter collecter;
    while (true)
    {
        std::cout << "Enter a command:" << std::endl;
        std::string input;
        std::getline(std::cin, input);
        CollecterCommand command = ParseCommand(input);
        switch (command)
        {
            case ADD:
            {
                std::string title;
                std::cout << "Enter a title:" << std::endl;
                std::getline(std::cin, title);
                Movie movie(title);
                collecter.AddMovie(movie);
                std::cout << "Added movie: " << title << std::endl;
                break;
            }
            case LIST:
            {
                collecter.ListMovies();
                break;
            }
            case CLEAR:
            {
                collecter.ClearMovies();
                break;
            }
            case CONTAINS:
            {
                std::string title;
                std::cout << "Enter a title:" << std::endl;
                std::getline(std::cin, title);
                if (collecter.ContainsMovie(title))
                {
                    std::cout << "Contains movie: " << title << std::endl;
                }
                else
                {
                    std::cout << "Does not contain movie: " << title << std::endl;
                }
                break;
            }
            case REMOVE:
            {
                std::string title;
                std::cout << "Enter a title:" << std::endl;
                std::getline(std::cin, title);
                collecter.RemoveMovie(title);
                std::cout << "Removed movie: " << title << std::endl;
                break;
            }
            case QUIT:
            {
                return 0;
            }
            case UNKNOWN:
            {
                std::cout << "Unknown command" << std::endl;
                PrintCommands();
                break;
            }
        }
    }
}