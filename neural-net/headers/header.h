#pragma once

#include <functional>
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <random>
#include <vector>

typedef float float_t;
typedef unsigned int uint_t;
typedef std::function<float(float)> floatfun_t; // should be ( R -> [-1;1] ) most of the time

std::ostream& debug();


#include "matrix.h"
#include "gaussian.h"

#include "activation.h"
#include "network.h"
