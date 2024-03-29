#ifndef PROBLEMSOLVER_HPP_SENTRY
#define PROBLEMSOLVER_HPP_SENTRY

#include "../Genome/Genome.hpp"

class ProblemSolver {
    Genome **routes;
    const int population_len;

    const int generations;

    NamedPoint *arr;
    const int arr_len;

    int candidates_len;

public:
    static ProblemSolver* Init(int _population_len, int _generations, 
        NamedPoint* arr, int arr_len, int _candidates_len);
    void Solve(Genome *res);
    ~ProblemSolver();

private:
    ProblemSolver(Genome **_routes, int _population_len, int _generations, 
        NamedPoint *_arr, int _arr_len, int _candidates_len)
        : routes(_routes), population_len(_population_len), 
          generations(_generations), arr(_arr), arr_len(_arr_len),
          candidates_len(_population_len > _candidates_len 
          ? _candidates_len : _population_len - 1) {}
    Genome TournamentSelection();
    void EvolvePopulation();

    void Sort();

    Genome& Min(Genome **arr, int len);
    Genome Min();

    bool HasDuplicates(Genome*);

//////////////////////////////

    ProblemSolver();
    ProblemSolver(const ProblemSolver&);
};

#endif