#pragma once

inline bool eEqual(float n, float m, float epsilon = .00001){
	return (n - epsilon) < m && (n + epsilon > m);
}