#include "logger.h"
#include <string>
#include <iostream>

void addReading(const std::string& label, double value,
                std::string labels[], double values[],
                int& size, int capacity) {
    if (size == capacity) {
        throw std::string("Full");
    }
    labels[size] = label;
    values[size] = value;
    ++size;
}

void updateValue(double* valuePtr, double newValue) {
    *valuePtr = newValue;
}

void printReading(const std::string& label, const double& value) {
    std::cout << label << ": " << value << "\n";
}

double average(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double sum = 0.0;
    for (int i = 0; i < size; ++i) sum += values[i];
    return sum / size;
}

double minValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double m = values[0];
    for (int i = 1; i < size; ++i) if (values[i] < m) m = values[i];
    return m;
}

double maxValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double m = values[0];
    for (int i = 1; i < size; ++i) if (values[i] > m) m = values[i];
    return m;
}
