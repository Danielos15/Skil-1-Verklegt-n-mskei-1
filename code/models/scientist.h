#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <vector>

/**
 * @brief The data model for scientists
 */

// Forward declaration to let Scientist know that Computer exists
class Computer;

enum sexType {
    female,
    male
};

class Scientist
{
public:
    Scientist();
    ~Scientist();
    Scientist(std::string name, sexType sex, int yearBorn);
    Scientist(std::string name, sexType sex, int yearBorn, int yearDied);
    Scientist(unsigned int id, std::string name, sexType sex, int yearBorn, int yearDied);

    unsigned int getId();
    std::string getName() const;
    enum sexType getSex() const;
    std::string getSexType() const;
    int getYearBorn() const;
    int getYearDied() const;
    std::string getInfo() const;
    std::vector<Computer*> getComputers() const;

    void setComputers(std::vector<Computer> computers);
    void setInfo(std::string info);

    bool contains(std::string searchTerm);

private:
    void destroyComputers();

    unsigned int id;
    std::string name;
    enum sexType sex;
    int yearBorn;
    int yearDied;
    std::string info;

    // Computer now has to be a pointer
    std::vector<Computer*> computers;
};

#endif // SCIENTIST_H
