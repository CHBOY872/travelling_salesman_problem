#ifndef PROBLEMSOLVER_HPP_SENTRY
#define PROBLEMSOLVER_HPP_SENTRY

#include "../Genome/Genome.hpp"

class ProblemSolver {
    enum {
        candidates_len = 3
    };

    Genome **routes;
    const int population_len;

    const int generations;

    Point *arr;
    const int arr_len;

public:
    static ProblemSolver* Init(int _population_len, int _generations, 
        Point* arr, int arr_len); //CHECKED
    void Solve(Genome *res);
    ~ProblemSolver(); //CHECKED

private:
    ProblemSolver(Genome **_routes, int _population_len, int _generations, 
        Point *_arr, int _arr_len)
        : routes(_routes), population_len(_population_len), 
          generations(_generations), arr(_arr), arr_len(_arr_len) {} //CHECKED
    Genome TournamentSelection(); //CHECKED
    void EvolvePopulation(); //CHECKED

    void Sort(); //CHECKED

    Genome& Min(Genome **arr, int len);
    Genome Min();

    bool HasDuplicates(Genome*);

//////////////////////////////

    ProblemSolver();
    ProblemSolver(const ProblemSolver&);
};

#endif