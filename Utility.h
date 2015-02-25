#include "stdafx.h"

bool epsilon_equal(float n, float m, float epsilon = .00001){
	return (n - epsilon) < m && (n + epsilon > m);
}