#pragma once

typedef float float_t;
typedef unsigned int uint_t;
typedef float_t(*floatfun_t)(float_t); // should be ( R -> [-1;1] ) most of the time

#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <vector>

#include "matrix.h"
#include "gaussian.h"

#include "activation.h"
#include "network.h"
