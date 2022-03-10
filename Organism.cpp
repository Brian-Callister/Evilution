#include "Organism.h"

using namespace std;

int Organism::m_array_size = 4;

Organism::Organism(int *stats)
{
    m_x_location = stats[m_X_INDEX];
    m_y_location = stats[m_Y_INDEX];
    m_speed = stats[m_SPEED_INDEX];
    m_sight = stats[m_SIGHT_INDEX];
    m_stats_array = new int[m_array_size];
    m_currentFood = 0;
    UpdateArray();
}

Organism::Organism(int x, int y, int speed, int sight)
{
    m_x_location = x;
    m_y_location = y;
    m_speed = speed;
    m_sight = sight;
    m_stats_array = new int[m_array_size];
    m_currentFood = 0;
    UpdateArray();
}

void Organism::UpdateArray()
{
    m_stats_array[m_X_INDEX] = m_x_location;
    m_stats_array[m_Y_INDEX] = m_y_location;
    m_stats_array[m_SPEED_INDEX] = m_speed;
    m_stats_array[m_SIGHT_INDEX] = m_sight;
}

int Organism::GetArraySize()
{
    return m_array_size;
}

int Organism::GetX()
{
    return m_x_location;
}

int Organism::GetY()
{
    return m_y_location;
}

int Organism::GetSpeed()
{
    return m_speed;
}

int Organism::GetSight()
{
    return m_sight;
}

std::pair<int, int> Organism::GetCoordinatePair() 
{
    return std::pair<int, int>(m_x_location, m_y_location);
}

void Organism::SetX(int x)
{
    m_x_location = x;
    m_stats_array[m_X_INDEX] = m_x_location;
}

void Organism::SetY(int y)
{
    m_y_location = y;
    m_stats_array[m_Y_INDEX] = m_y_location;
}

void Organism::SetSpeed(int speed)
{
    m_speed = speed;
    m_stats_array[m_SPEED_INDEX] = m_speed;
}

void Organism::SetSight(int sight)
{
    m_sight = sight;
    m_stats_array[m_SIGHT_INDEX] = m_sight;
}

void Organism::PrintStats() const
{
    cout << "X Location: " << m_x_location << endl;
    cout << "Y Location: " << m_y_location << endl;
    cout << "Speed: " << m_speed << endl;
    cout << "Sight: " << m_sight << endl;
}

int *Organism::GetStatsArray()
{
    return m_stats_array;
}

void Organism::MoveToLocation(std::pair<int, int>* location) {
    m_x_location = location->first;
    m_y_location = location->second;
    UpdateArray();
    cout << "new location is " << m_x_location << "," << m_y_location << endl;
}

void Organism::ConsumeFood(int food) {
    m_currentFood += food;
    cout << "Current food is " << m_currentFood << endl;
}


bool Organism::WantsMoreFood() { return m_moreFood; }

int* Organism::RandomOrganismStats() {
    int numAttributes = Organism::GetArraySize();
    int* stats = new int[numAttributes];
    for (int i = 0; i < numAttributes; i++)
    {
        stats[i] = i * 2 + 1;
    }
    return stats;
}
