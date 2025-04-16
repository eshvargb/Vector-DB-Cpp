#ifndef VECTORSTORE_H
#define VECTORSTORE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <fstream>

class Vectordatabase {
private:
    std::unordered_map<int, std::vector<float>> data;

public:
    Vectordatabase(){
        loadFromFile();
    }

    void Insert(int id, const std::vector<float>& vec) {
        data[id] = vec;
    }

    void remove(int id) {
        if (data.erase(id) == 0) {
            std::cout << "Vector ID " << id << " not found.\n";
        }
    }

    void update(int id, const std::vector<float>& vec) {
        if (data.find(id) != data.end()) {
            data[id] = vec;
        } else {
            std::cout << "Vector ID " << id << " not found.\n";
        }
    }

    void saveToFile() {
        std::ofstream file("data.bin", std::ios::binary | std::ios::trunc);
        if (!file) {
            std::cerr << "Error opening file for writing!\n";
            return;
        }

        size_t mapSize = data.size();
        file.write(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));

        for (const auto& pair : data) {
            int id = pair.first;
            size_t vecSize = pair.second.size();

            file.write(reinterpret_cast<char*>(&id), sizeof(id));
            file.write(reinterpret_cast<char*>(&vecSize), sizeof(vecSize));
            file.write(reinterpret_cast<const char*>(pair.second.data()), vecSize * sizeof(float));
        }

        file.close();
    }

    std::vector<float> search(int id) {
        if (data.find(id) != data.end()) {
            return data[id];
        }
        std::cout << "Vector ID " << id << " not found.\n";
        return {};
    }

    void loadFromFile() {
        std::ifstream file("data.bin", std::ios::binary);
        if (!file) {
            std::cout << "No previous data found. Starting fresh.\n";
            return;
        }

        size_t mapSize;
        file.read(reinterpret_cast<char*>(&mapSize), sizeof(mapSize));

        for (size_t i = 0; i < mapSize; ++i) {
            int id;
            size_t vecSize;
            file.read(reinterpret_cast<char*>(&id), sizeof(id));
            file.read(reinterpret_cast<char*>(&vecSize), sizeof(vecSize));

            std::vector<float> vec(vecSize);
            file.read(reinterpret_cast<char*>(vec.data()), vecSize * sizeof(float));
            data[id] = vec;
        }
        file.close();
    }

    static float EuclideanDistance(const std::vector<float>& v1, const std::vector<float>& v2) {
        if (v1.size() != v2.size()) {
            std::cerr << "Error: Vector sizes do not match\n";
            return -1;
        }
        float sum = 0.0;
        for (size_t i = 0; i < v1.size(); i++) {
            sum += pow(v1[i] - v2[i], 2);  
        }
        return sqrt(sum);  
    }

    std::unordered_map<int, std::vector<float>> getAllVectors() {
        return data;
    }
};


#endif

