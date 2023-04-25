#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <random>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <cmath>

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
    
    string GetName();
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

string Country::GetName() {
    return name;
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

vector<Country> BucketSortByLifeExpectancy(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetLifeExpectancy() > max) {
            max = world.countries[i].GetLifeExpectancy();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetLifeExpectancy() < min) {
            min = world.countries[i].GetLifeExpectancy();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetLifeExpectancy() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetLifeExpectancy() > buckets[l][j].GetLifeExpectancy()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByExpectedSchooling(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetExpectedSchooling() > max) {
            max = world.countries[i].GetExpectedSchooling();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetExpectedSchooling() < min) {
            min = world.countries[i].GetExpectedSchooling();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetExpectedSchooling() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetExpectedSchooling() > buckets[l][j].GetExpectedSchooling()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByAverageSchooling(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetAverageSchooling() > max) {
            max = world.countries[i].GetAverageSchooling();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetAverageSchooling() < min) {
            min = world.countries[i].GetAverageSchooling();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetAverageSchooling() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetAverageSchooling() > buckets[l][j].GetAverageSchooling()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByGNI(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetGNIPerCapita() > max) {
            max = world.countries[i].GetGNIPerCapita();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetGNIPerCapita() < min) {
            min = world.countries[i].GetGNIPerCapita();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetGNIPerCapita() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetGNIPerCapita() > buckets[l][j].GetGNIPerCapita()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}

vector<Country> BucketSortByHDI(World& world) {
    vector<Country> result;
    double numBuckets = world.countries.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<Country>> buckets(numBuckets);
    double max = 0;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetHDI() > max) {
            max = world.countries[i].GetHDI();
        }
    }
    double min = 99999999;
    for (int i = 0; i < world.countries.size(); i++) {
        if (world.countries[i].GetHDI() < min) {
            min = world.countries[i].GetHDI();
        }
    }
    double range = (max - min) / numBuckets;
    for (int i = 0; i < world.countries.size(); i++) {
        double temp = (world.countries[i].GetHDI() - min) / range;
        int destination = temp;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(world.countries[i]);
    }
    for (auto l = 0; l < buckets.size(); l++) {
        int n = buckets[l].size();
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && buckets[l][j-1].GetHDI() > buckets[l][j].GetHDI()) {
                swap(buckets[l][j], buckets[l][j-1]);
                j = j-1;
            }
        }
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
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
    cout << "1 for Life Expectancy, 2 for Expected Schooling, 3 for Average Schooling, 4 for GNI/capita, 5 for HDI, 6 for custom HDI" << endl;
    int choice;
    cin >> choice;
    vector<Country> report;
    switch(choice) {
        case 1:
        report = BucketSortByLifeExpectancy(world);
        break;
        case 2:
        report = BucketSortByExpectedSchooling(world);
        break;
        case 3:
        report = BucketSortByAverageSchooling(world);
        break;
        case 4:
        report = BucketSortByGNI(world);
        break;
        case 5:
        report = BucketSortByHDI(world);
        break;
    }
    for (int i = 0; i < report.size(); i++) {
        report[i].ReportBasicInfo();
    }
    /*for (int i = 0; i < world.countries.size(); i++) {
        world.countries[i].ReportBasicInfo();
    }*/
    return 0;
}
