#include "person.h"

person::person()
{  }

person::person(QString n, int a, QString fc)
    : name{n}, age{a}, favcolour(fc)
{  }

void person::setName(const QString &newName)
{
    name = newName;
}

const QString &person::getName() const
{
    return name;
}

int person::getAge() const
{
    return age;
}

void person::setAge(int newAge)
{
    age = newAge;
}

const QString &person::getFavcolour() const
{
    return favcolour;
}

void person::setFavcolour(const QString &newFavcolour)
{
    favcolour = newFavcolour;
}


