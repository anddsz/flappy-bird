#pragma once

#define Vector2(T) struct { T x; T y; }
#define clamp(x, a, b) (((x) < (a)) ? (a) : (((x) > (b)) ? (b) : (x)))
