#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <map>

using namespace std;

struct Country {
    private:
    string name;
    double lifeExpectancy;
    double expectedSchooling;
    double averageSchooling;
    double GNIPerCapita;
    double HDI;
    
    public:
    Country(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_) {
        name = name_;
        lifeExpectancy = lifeExpectancy_;
        expectedSchooling = expectedSchooling_;
        averageSchooling = averageSchooling_;
        GNIPerCapita = GNIPerCapita_;
    }
    
    double GetLifeExpectancy();
    double GetExpectedSchooling();
    double GetAverageSchooling();
    double GetGNIPerCapita();
    double GetHDI();
    void ReportBasicInfo();
};

struct World {
    private:
    
    int numCountries;
    
    public:
    int GetNumCountries();
    vector<Country> countries;
    void AddCountriesVec(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_);
};

int World::GetNumCountries() {
    return numCountries;
}

void World::AddCountriesVec(string name_, double lifeExpectancy_, double expectedSchooling_, double averageSchooling_, double GNIPerCapita_) {
    countries.push_back(Country(name_, lifeExpectancy_, expectedSchooling_, averageSchooling_, GNIPerCapita_));
}

double Country::GetLifeExpectancy() {
    return lifeExpectancy;
}

double Country::GetExpectedSchooling() {
    return expectedSchooling;
}

double Country::GetAverageSchooling() {
    return averageSchooling;
}

double Country::GetGNIPerCapita() {
    return GNIPerCapita;
}

double Country::GetHDI() {
    return HDI;
}

void Country::ReportBasicInfo() {
    cout << name << " " << lifeExpectancy << " " << expectedSchooling << " " <<averageSchooling << " " << GNIPerCapita << endl;
}


void ReadFile(string filename, World& world) {
   fstream file(filename);
   string unParsed;
   double lifeExpectancy;
   double expectedSchooling;
   double averageSchooling;
   double GNIPerCapita;
   while (true) {
      if (getline(file, unParsed)) {
         int firstNum = 0;
         int start = 0;
         int tracker = 0;
         while (true) {
             if (isdigit(unParsed[tracker])) {
                 firstNum = tracker;
                 break;
             }
             tracker++;
         }
         string name = unParsed.substr(start, firstNum - 1);
         start = firstNum;
         int spacePos = unParsed.find(' ', start);
         lifeExpectancy = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         spacePos = unParsed.find(' ', start);
         expectedSchooling = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         spacePos = unParsed.find(' ', start);
         averageSchooling = stod(unParsed.substr(start, spacePos-1));
         start = spacePos+1;
         GNIPerCapita = stod(unParsed.substr(start));
         world.AddCountriesVec(name, lifeExpectancy, expectedSchooling, averageSchooling, GNIPerCapita);
      } else {
         break;  
      }
   }
}

int main()
{
    World world;
    string filename;
    cin >> filename;
    ReadFile(filename, world);
    for (int i = 0; i < world.countries.size(); i++) {
        world.countries[i].ReportBasicInfo();
    }
    return 0;
}
