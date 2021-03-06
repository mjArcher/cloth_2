#ifndef VECTOR3
#define VECTOR3

#include <cmath>
#include <iostream>
using namespace std;
const int SIZE = 3;

template <typename T> class Vector3;

template <class T> 
ostream& operator<< (ostream& os, const Vector3<T>&);

template <class T> class Vector3
{
  public:

    T X;
    T Y;
    T Z;

    Vector3();
    Vector3(T x, T y, T z);

    Vector3         operator+(const Vector3&) const;
    Vector3         operator-(const Vector3&) const;
    Vector3         operator-() const;
    Vector3         operator*(T) const;
    Vector3         operator/(T) const;

    T               operator[](int x) const { 
      switch(x) {case 0: return X; case 1: return Y; case 2: return Z; }}
    Vector3&        operator+=(const Vector3&);
    Vector3&        operator-=(const Vector3&);
    Vector3&        operator*=(T);
    Vector3&        operator/=(T);

    friend ostream& operator<< <>(ostream& os, const Vector3<T>&);
    /* friend T dot(const Vector3&, const Vector3&); */

    bool            operator==(const Vector3&) const;
    bool            operator!=(const Vector3&) const;

		/* static const unsigned int e_size = 13; */


    static const Vector3    Zero;
    static const T      Epsilon;
};

template <class T>
T dot(const Vector3<T>&, const Vector3<T>&);


template <class T>
inline bool Vector3<T>::operator==(const Vector3& vec) const
{
  return X == vec.X && Y == vec.Y && Z == vec.Z;
}

template <class T>
inline bool Vector3<T>::operator!=(const Vector3& vec) const
{
  return X != vec.X || Y != vec.Y || Z != vec.Z;
}

template <class T>
inline Vector3<T> Vector3<T>::operator+(const Vector3& vec) const
{
  return Vector3(X + vec.X, Y + vec.Y, Z + vec.Z);
}

template <class T>
inline Vector3<T> Vector3<T>::operator-(const Vector3& vec) const
{
  return Vector3(X - vec.X, Y - vec.Y, Z - vec.Z);
}

template <class T>
T dot(const Vector3<T>& left, const Vector3<T>& right) 
{
  T temp = 0;
  for(int i = 0; i < 3; i++){
    std::cout << left[i] << " " << right[i] << " " << i << std::endl;
    temp += left[i] * right[i];
  }
  return temp;
}


template <class T>
inline Vector3<T> Vector3<T>::operator-() const
{
  return Vector3(-X,-Y,-Z);
}

template <class T>
inline Vector3<T> Vector3<T>::operator*(T num) const
{
  return Vector3(X * num, Y * num, Z * num);
}

template <class T>
inline Vector3<T> Vector3<T>::operator/(T num) const
{
  return Vector3(X / num, Y / num, Z / num);
}

template <class T>
ostream& operator<< (ostream& os, const Vector3<T>& vec)
{
  os.precision(3);
  os << vec.X << ", " << vec.Y << ", " << vec.Z;
  return os;
}


#endif
