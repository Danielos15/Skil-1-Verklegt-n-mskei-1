CREATE TABLE Computers (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name VARCHAR NOT NULL,
    type INTEGER NOT NULL,
    yearBuilt INTEGER,
    wasBuilt BOOL,
	info TEXT
)

CREATE TABLE Scientists (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name VARCHAR NOT NULL,
    sex INTEGER NOT NULL,
    yearBorn INTEGER NOT NULL,
    yearDied INTEGER,
	info TEXT
)

CREATE TABLE ScientistComputerConnections(
    scientistId integer,
    computerId integer,
	reason TEXT,
    foreign key (scientistId) references Scientists(id),
    foreign key (computerId) references Computers(id),
    primary key(scientistId, computerId)
)