#pragma once
#include <vector>
#include <string>
#include "movie.h"
class Collecter {
private:
    std::vector<Movie> movies;
public:
    void AddMovie(const Movie& movie);
    void ListMovies();
    void ClearMovies();
    void RemoveMovie(const std::string& title);
};