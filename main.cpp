#include <iostream>
#include "vectorstore.h"

//int main() {
    //Vectordatabase vdb;
    // vdb.loadFromFile(); 
    // std::cout << "Enter vector ID and values (e.g., 1 1.1 2.2 3.3), enter -1 to stop:\n";
    // while (true) {
    //     int id;
    //     std::vector<float> vec;
    //     std::cin >> id;
    //     if (id == -1) break;

    //     float val;
    //     while (std::cin.peek() != '\n' && std::cin >> val) {
    //         vec.push_back(val);
    //     }
    //     std::cin.ignore();

    //     vdb.Insert(id, vec);
    // }

    // std::cout << "\nEnter two vector IDs to calculate Euclidean Distance: ";
    // int id1, id2;
    // std::cin >> id1 >> id2;

    // std::vector<float> v1 = vdb.search(id1);
    // std::vector<float> v2 = vdb.search(id2);
    
    // if (!v1.empty() && !v2.empty()) {
    //     float dist = Vectordatabase::EuclideanDistance(v1, v2);
    //     std::cout << "Euclidean Distance: " << dist << "\n";
    // } else {
    //     std::cout << "One or both vectors not found.\n";
    // }

    // vdb.saveToFile();
    // std::cout << "Database saved to disk.\n";

    // return 0;

    // Vectordatabase vdb;

    // // Load existing database from file
    // vdb.loadFromFile();

    // // Display loaded vectors
    // std::cout << "Existing vectors in the database:\n";
    // for (const auto& pair : vdb.getAllVectors()) {
    //     std::cout << "ID " << pair.first << ": ";
    //     for (float val : pair.second) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << "\n";
    // }
    // return 0;

#include "sentencetoembedding.h"

int main() {
    SentenceToEmbedding model("cc.en.300.bin");  // Change to your FastText model path
    model.printEmbedding("Hello world!");
    return 0;
}

}
