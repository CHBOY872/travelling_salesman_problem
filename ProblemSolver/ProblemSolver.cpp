#include <stdlib.h>
#include <stdio.h>

#include "ProblemSolver.hpp"
#include "../Point/PointHandler/PointHandler.hpp"

ProblemSolver::~ProblemSolver()
{
    int i;
    for (i = 0; i < population_len; i++)
        delete routes[i];
    delete[] routes;
}

ProblemSolver *ProblemSolver::Init(int _population_len, int _generations, 
        Point* arr, int arr_len)
{
    Genome **_routes = new Genome *[_population_len];
    int i;
    for (i = 0; i < _population_len; i++)
    {
        _routes[i] = Genome::InitGenome(arr, arr_len);
        _routes[i]->Shuffle();
    }
    return new ProblemSolver(_routes, _population_len, 
        _generations, arr, arr_len);
}

Genome &ProblemSolver::Min(Genome **arr, int len)
{
    Genome *res = *arr;
    int i;
    for (i = 1; i < len; i++)
    {
        if (*arr[i] < *res)
            res = arr[i];
    }

    return *res;
}

Genome ProblemSolver::TournamentSelection()
{
    int i, idx;
    Genome **candidates = new Genome*[candidates_len];

    for (i = 0; i < candidates_len; i++)
    {
        idx = rand() % population_len;
        candidates[i] = new Genome(*routes[idx]);
        int j;
    }

    Genome best_candidate(Min(candidates, candidates_len));

    for (i = 0; i < candidates_len; i++)
        delete candidates[i];
    delete[] candidates;

    return best_candidate;
}

void ProblemSolver::Sort()
{
    Genome *temp = 0;
    int i, j;
    for (i = 0; i < population_len - 1; i++)
    {
        for (j = 0; j < population_len - i - 1; j++)
        {
            if (!(*routes[j] < *routes[j + 1]))
            {
                temp = routes[j];
                routes[j] = routes[j + 1];
                routes[j + 1] = temp;
            }
        }
    }
}

void ProblemSolver::EvolvePopulation()
{
    Sort();
    Genome parent1(arr_len), parent2(arr_len), child(arr_len);
    int i, j;
    Genome **new_routes = new Genome *[population_len];
    for (i = 0; i < population_len; i++)
        new_routes[i] = new Genome(arr_len);

    *new_routes[0] = *routes[0];
    *new_routes[1] = *routes[1];

    for (i = 2; i < population_len; ++i)
    {
        parent1 = TournamentSelection();
        parent2 = TournamentSelection();
        child = parent1.Crossover(parent2);


        if (HasDuplicates(&child))
            child = *routes[i];
        else
            child.Mutate();

        *new_routes[i] = child;
    }

    for (i = 0; i < population_len; i++)
        delete routes[i];
    delete[] routes;

    routes = new_routes;
}

Genome ProblemSolver::Min()
{
    Genome *res = routes[0];
    int i;
    for (i = 1; i < population_len; i++)
    {
        if (*routes[i] < *res)
            res = routes[i];
    }

    return Genome(*res);
}

void ProblemSolver::Solve(Genome *res)
{
    int i;
    for (i = 0; i < generations; i++)
        EvolvePopulation();
    
    *res = Min();
}

bool ProblemSolver::HasDuplicates(Genome* a)
{
    int i, j;
    for (i = 0; i < arr_len - 1; i++)
    {
        for (j = i + 1; j < arr_len; j++)
        {
            if ((*a)[i] == (*a)[j])
                return true;
        }
    }
    return false;
}