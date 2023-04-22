#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

vector<double> BucketSort(vector<double> vec) {
    vector<double> result;
    double numBuckets = vec.size();
    numBuckets = sqrt(numBuckets);
    vector<vector<double>> buckets(numBuckets);
    double max = 0;
    for (int i : vec) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    double min = 99999999;
    for (int i : vec) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }
    double range = (max - min) / numBuckets;
    double diffOrderOfMagnitude = log10(numBuckets) - log10(range);
    int temp = diffOrderOfMagnitude;
    //range = pow(range, temp);
    for (int i = 0; i < vec.size(); i++) {
        int destination = (vec[i] - min) / range;
        if (destination > numBuckets-1) {
            destination = numBuckets-1;
        }
        buckets[destination].push_back(vec[i]);
    }
    for (auto i = 0; i < buckets.size(); i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    for (auto i = 0; i < buckets.size(); i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
        }
    }
    return result;
}


int main()
{
    vector<double> arr = { 4.852, 7.674, 0.644, 8.239, 9.293, 5.235, 1.023, 6.117, 2.138, 1.348,
9.185, 4.063, 7.342, 8.236, 1.698, 7.992, 6.139, 9.491, 1.347, 8.775,
7.132, 3.555, 3.857, 8.448, 2.108, 5.467, 8.717, 5.845, 7.612, 5.149,
9.649, 5.679, 2.256, 5.044, 6.506, 5.258, 8.787, 6.135, 7.656, 8.057,
3.338, 3.131, 5.965, 2.027, 4.305, 3.755, 2.688, 1.255, 4.152, 8.408,
9.846, 6.815, 8.576, 0.743, 2.807, 6.699, 9.768, 5.955, 2.945, 5.525,
7.674, 0.528, 9.947, 8.447, 1.888, 7.011, 8.310, 3.464, 2.540, 3.256,
4.926, 4.318, 4.609, 4.078, 4.140, 3.613, 7.245, 2.634, 8.129, 6.115,
2.116, 7.413, 4.682, 7.784, 6.974, 5.798, 7.510, 9.347, 6.065, 1.277,
0.868, 8.219, 5.511, 6.365, 7.839, 1.605, 5.218, 6.180, 0.788, 7.991 };
vector<double> result = BucketSort(arr);
  cout << "Sorted array: ";
  for (double i : result) {
    cout << i << " ";
  }

    return 0;
}




