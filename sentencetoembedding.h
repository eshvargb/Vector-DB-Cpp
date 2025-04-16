// sentencetoembedding.h

#ifndef SENTENCE_TO_EMBEDDING_H
#define SENTENCE_TO_EMBEDDING_H

#include <iostream>
#include <vector>
#include <string>
#include "src/fasttext.h"


class SentenceToEmbedding {
public:
    SentenceToEmbedding(const std::string& modelPath) {
        fastText.loadModel(modelPath);
    }

    std::vector<float> getEmbedding(const std::string& sentence) {
        std::vector<float> embedding;
        fastText.getSentenceVector(sentence, embedding);
        return embedding;
    }

    void printEmbedding(const std::string& sentence) {
        std::vector<float> embedding = getEmbedding(sentence);
        std::cout << "Embedding for: " << sentence << "\n[ ";
        for (float val : embedding) {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }

private:
    fasttext::FastText fastText;
};

#endif // SENTENCE_TO_EMBEDDING_H
