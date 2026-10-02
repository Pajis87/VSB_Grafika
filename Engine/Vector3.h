#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
public:
	float x, y, z;
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3 operator+(const Vector3& other) {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	Vector3 operator-(const Vector3& other) {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	Vector3 operator*(float scalar) {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}
	Vector3 operator/(float scalar) {
		return Vector3(x / scalar, y / scalar, z / scalar);
	}
};

#endif