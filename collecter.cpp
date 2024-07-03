#include <iostream>
#include <vector>
#include <fstream> 
#include "movie.h"
#include "collecter.h"
Collecter::Collecter() {
    // Load movies from file
    std::ifstream file("movies.txt");
    if (!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return;
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        // File is empty
        file.close();
        return;
    }
    std::string title;
    while (std::getline(file, title))
    {
        movies.push_back(Movie(title));
    }
    file.close();

}
void Collecter::AddMovie(const Movie& movie) {
    movies.push_back(movie);
    Save();
}

void Collecter::ListMovies() {
    if (movies.empty())
    {
        std::cout << "No movies to list" << std::endl;
        return;
    }
    for (const Movie& movie : movies)
    {
        std::cout << movie.m_title << std::endl;
    }
}

void Collecter::ClearMovies() {
    movies.clear();
    Save();
}

void Collecter::RemoveMovie(const std::string& title) {
    for (auto movie = movies.begin(); movie != movies.end();)
    {
        if (movie->m_title == title)
        {
            movie = movies.erase(movie);
            Save();
            continue;
        }
        ++movie;
    }
}

void Collecter::Save() {
    // Save movies to file
    std::ofstream file("movies.txt");
    if (!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        return;
    }
    file.clear();
    for (const Movie& movie : movies)
    {
        file << movie.m_title << std::endl;
    }

    file.close();
}