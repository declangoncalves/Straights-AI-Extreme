#include "model.h"

Model::Model(int seed) : deck_(new Deck(seed)) : table_(5, std::vector<int>(15, 0)) {}
