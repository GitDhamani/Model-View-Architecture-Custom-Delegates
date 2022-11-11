#ifndef PERSON_H
#define PERSON_H
#include <QString>

class person
{
private:
    QString name;
    int age;
    QString favcolour;

public:
    person();
    person(QString name, int age, QString favcolour);

    //These were all generated when I refactored all the private variables into getters and setters.
    void setName(const QString &newName);
    const QString &getName() const;
    int getAge() const;
    void setAge(int newAge);
    const QString &getFavcolour() const;
    void setFavcolour(const QString &newFavcolour);
};

#endif // PERSON_H
