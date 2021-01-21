// Distance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iterator>
#include <vector>
#include <iomanip>
#include <memory>
#include <utility>
#include <cmath>
#include <string>
#include <chrono>

#define CANTIDAD_VECTORES 250
#define DIMENSION_VECTOR 5
#define INICIO_NUMERO 1.7*pow(10,-308)
#define FIN_NUMEROS 18446744073709551610


double RandomNumber() { return (std::rand() % FIN_NUMEROS + INICIO_NUMERO); }

int main()
{

    std::vector<std::vector<double> > main_vector;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();

    for (double i = 0; i < CANTIDAD_VECTORES; i++) {
        std::vector<double> v1(DIMENSION_VECTOR);
        generate(v1.begin(), v1.end(), RandomNumber);
        main_vector.push_back(v1);
    }

    double suma_temporal = 0;
    for (double i = 0; i < CANTIDAD_VECTORES - 1 ; i++) {
        for (double j = 0; j < DIMENSION_VECTOR; j++) {
            //std::cout << main_vector[i][j] << " "; // to verify
            suma_temporal += sqrt(pow(abs(main_vector[i][j] - main_vector[i + 1][j]), 2));
        }
        //std::cout << suma_temporal << std::endl; // to verify
        suma_temporal = 0;
    }

    end = std::chrono::high_resolution_clock::now();
    int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::cout << "Duration: " + std::to_string(duration) + " ns\n";

    return 0;
}
