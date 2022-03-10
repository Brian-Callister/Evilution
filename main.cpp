#include <iostream>
#include <mpi.h>
#include "Organism.h"
#include "Board.h"
#define MCW MPI_COMM_WORLD

void OrganismDriverCode(int rank);

using namespace std;

int main(int argc, char** argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);

    //cout << "Size is: " << size;
    //OrganismDriverCode(rank);

    Board* board = new Board(rank);
    board->PrintStats();
    board->PrintFoodArray();
    for (int i = 1; i < 12; i++) {
        board->TimePassing(i);
        cout << "\n\n\n" << endl;
    }
    cout << "finishing here" << endl;
    MPI_Finalize();
    return 0;
}

void OrganismDriverCode(int rank)
{
    int numAttributes = Organism::GetArraySize();
    int* stats = new int[numAttributes];
    if(rank == 0)
    {
        for(int i = 0; i < numAttributes; i++)
        {
            stats[i] = i*2-1;
        }

        auto newOrganism = new Organism(stats);
        newOrganism->SetSpeed(12);
        MPI_Send(newOrganism->GetStatsArray(), numAttributes, MPI_INT, 1, 0, MCW);
    }
    else
    {
        MPI_Recv(stats, numAttributes, MPI_INT, 0, MPI_ANY_TAG, MCW, MPI_STATUS_IGNORE);
        auto newOrganism = new Organism(stats);
        newOrganism->PrintStats();
    }

    delete[] stats;
}

