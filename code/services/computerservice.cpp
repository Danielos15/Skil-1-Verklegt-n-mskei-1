#include "services/computerservice.h"

ComputerService::ComputerService()
{

}

std::vector<Computer> ComputerService::getAllComputers(std::string orderBy, bool orderAscending){
    return computerRepo.getAllComputers(orderBy, orderAscending);
}

std::vector<Computer> ComputerService::searchForComputers(std::string searchTerm){
    return computerRepo.searchForComputers(searchTerm);
}

bool ComputerService::addComputer(Computer computer){
    return computerRepo.addComputer(computer);
}

bool ComputerService::removeComputer(int id){
    return computerRepo.removeComputer(id);
}

Computer ComputerService::fetchById(int id)
{
    return computerRepo.fetchById(id);
}

std::vector<Scientist> ComputerService::queryScientistsByComputer(Computer cpu)
{
    return computerRepo.queryScientistsByComputer(cpu);
}
