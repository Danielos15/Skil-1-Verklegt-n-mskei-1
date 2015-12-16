#include "services/scientistservice.h"
#include "services/computerservice.h"

#include <algorithm>

using namespace std;

ScientistService::ScientistService(){

}

std::vector<Scientist> ScientistService::getAllScientists(string orderBy, bool orderAscending){
    return scientistRepo.getAllScientists(orderBy, orderAscending);
}

std::vector<Scientist> ScientistService::searchForScientists(string searchTerm){
    return scientistRepo.searchForScientists(searchTerm);
}

std::vector<Computer> ScientistService::queryComputersByScientist(Scientist scientist){
    return scientistRepo.queryComputersByScientist(scientist);
}

bool ScientistService::addScientist(Scientist scientist){
    return scientistRepo.addScientist(scientist);
}

bool ScientistService::removeScientist(int id){
    return scientistRepo.removeScientist(id);
}

Scientist ScientistService::fetchById(int id)
{
    return scientistRepo.fetchById(id);
}
