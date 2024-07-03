#include <iostream>
#include <vector>
#include "movie.h"
#include "collecter.h"

void Collecter::AddMovie(const Movie& movie) {
    movies.push_back(movie);
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
}

void Collecter::RemoveMovie(const std::string& title) {
    for (auto it = movies.begin(); it != movies.end();)
    {
        if (it->m_title == title)
        {
            it = movies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}