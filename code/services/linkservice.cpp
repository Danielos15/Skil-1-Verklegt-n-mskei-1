#include "services/linkservice.h"

#include <string>

using namespace std;

LinkService::LinkService()
{

}

bool LinkService::addLink(int scientistId, int computerId)
{
    return linkRepo.addLink(scientistId, computerId);
}
