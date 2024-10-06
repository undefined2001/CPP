#include <iostream>

class Person {
    std::string m_Name;


public:
    class Address {
        std::string m_Country;
        std::string m_Division;
        std::string m_District;

    public:
        Address(const std::string& country, const std::string& division, const std::string& district)
            : m_Country(country), m_Division(division), m_District(district) {}

        void setCountry(const std::string& country) {
            m_Country = country;
        }

        void setDivision(const std::string& division) {
            m_Division = division;
        }

        void setDistrict(const std::string& district) {
            m_District = district;
        }
    };

    Address address;

public:
    Person(const std::string& name) : m_Name(name), address("", "", "") {}
};

int main() {
    Person p("Asraful");
    p.address = Person::Address("Bangladesh", "Dhaka", "Madaripur");

    return 0;
}
