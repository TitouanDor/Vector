#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <stdexcept>
#include <string.h>

/**
 * @author TitouanDor
 * Vector Class
 */
class Vector{
    public:
        /**
         * Default constructors
         */
        Vector() : dim(2), values(new double[2]()) {}

        /**
         * Constructor that initializes the vector with a given dimension and allocates memory for the values. The values are initialized to zero.
         * @param dim The dimension of the vector
         */
        Vector(short dim) : dim(dim), values(new double[dim]()) {}

        /**
         * Copy constructor that creates a new vector by copying the dimension and values from another vector. It allocates new memory for the values and copies each value from the source vector.
         * @param v The vector to copy from
         */
        Vector(const Vector& v) : dim(v.dim), values(new double[v.dim]) {
            for (short i = 0; i < dim; ++i) {
                values[i] = v.values[i];
            }
        }

        /**
         * Constructor that initializes the vector with an array of double values. The dimension is determined by the size of the input array, and memory is allocated for the values. Each value from the input array is copied to the vector's values.
         * @param values The array of double values to initialize the vector with
         * @param dim Size of the vector
         */
        Vector(double *value, short dim) : dim(dim), values(new double[this->dim]) {
            for (short i = 0; i < this->dim; ++i) {
                this->values[i] = value[i];
            }
        }

        /**
         * Returns the dimension of the vector.
         * @return The dimension of the vector
         */
        short getDim() const {
            return dim;
        }

        /**
         * Overloaded addition operator that adds two vectors of the same dimension. It checks if the dimensions of the vectors are the same, and if so, it creates a new vector to store the result of the addition. Each corresponding value from the two vectors is added together and stored in the result vector. If the dimensions do not match, an exception is thrown.
         * @param other The vector to add to the current vector
         * @return A reference to the resulting vector after addition
         */
        Vector& operator+(const Vector& other) {
            if (this->dim != other.dim) {
                throw std::invalid_argument("Vectors must have the same dimension for addition.");
            }
            Vector* result = new Vector(this->dim);
            for (short i = 0; i < this->dim; ++i) {
                result->values[i] = this->values[i] + other.values[i];
            }
            return *result;
        }

        /**
         * Overloaded subtraction operator that subtracts one vector from another of the same dimension. It checks if the dimensions of the vectors are the same, and if so, it creates a new vector to store the result of the subtraction. Each corresponding value from the two vectors is subtracted and stored in the result vector. If the dimensions do not match, an exception is thrown.
         * @param other The vector to subtract from the current vector
         * @return A reference to the resulting vector after subtraction
         */
        Vector& operator-(const Vector& other) {
            if (this->dim != other.dim) {
                throw std::invalid_argument("Vectors must have the same dimension for subtraction.");
            }
            Vector* result = new Vector(this->dim);
            for (short i = 0; i < this->dim; ++i) {
                result->values[i] = this->values[i] - other.values[i];
            }
            return *result;
        }

        /**
         * Overloaded multiplication operator that multiplies a vector by a scalar. It creates a new vector to store the result of the multiplication. Each value from the vector is multiplied by the scalar and stored in the result vector.
         * @param scalar The scalar to multiply the vector by
         * @return A reference to the resulting vector after multiplication
         */
        Vector& operator*(double scalar) {
            Vector* result = new Vector(this->dim);
            for (short i = 0; i < this->dim; ++i) {
                result->values[i] = this->values[i] * scalar;
            }
            return *result;
        }

        /**
         * Overloaded division operator that divides a vector by a scalar. It checks if the scalar is zero, and if so, it throws an exception. Otherwise, it creates a new vector to store the result of the division. Each value from the vector is divided by the scalar and stored in the result vector.
         * @param scalar The scalar to divide the vector by
         * @return A reference to the resulting vector after division
         */
        Vector& operator/(double scalar) {
            if (scalar == 0) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            Vector* result = new Vector(this->dim);
            for (short i = 0; i < this->dim; ++i) {
                result->values[i] = this->values[i] / scalar;
            }
            return *result;
        }

        /**
         * Overloaded equality operator that checks if two vectors are equal. It compares the dimensions of the vectors and then compares each corresponding value. If all values are equal, it returns true; otherwise, it returns false.
         * @param other The vector to compare with the current vector
         * @return True if the vectors are equal, false otherwise
         */
        bool operator==(const Vector& other) const {
            if (this->dim != other.dim) {
                return false;
            }
            for (short i = 0; i < this->dim; ++i) {
                if (this->values[i] != other.values[i]) {
                    return false;
                }
            }
            return true;
        }

        /**
         * Destructor for the Vector class. It deallocates the memory allocated for the values array.
         */
        ~Vector() {
            delete[] values;
        }

        /**
         * Sets the value of a component of the vector at the specified index.
         * @param index The index of the component to set
         * @param value The value to set
         * @return no return value
         */
        void setValueAt(short index, double value) {
            if (index < 0 || index >= dim) {
                throw std::out_of_range("Index out of range.");
            }
            values[index] = value;
        }

        /**
         * Sets the values of all components of the vector from an array. Checks if the size of the input array matches the dimension of the vector, and if so, it copies each value from the input array to the vector's values. If the sizes do not match, an exception is thrown.
         * @param values The array of values to set
         * @return no return value
         */
        void setValues(double* values) {
            if(sizeof(values[0]) / sizeof(double) != dim) {
                throw std::invalid_argument("Input array size must match the dimension of the vector.");
            }
            for (short i = 0; i < dim; ++i) {
                printf("set");
                this->values[i] = values[i];
            }
        }

        /**
         * Sets the values of all components of the vector from another vector. Checks if the dimensions of the input vector match the dimension of the current vector, and if so, it copies each value from the input vector to the current vector's values. If the dimensions do not match, an exception is thrown.
         * @param v The vector whose values to set
         * @return no return value
         */
        void setValues(Vector& v) {
            if(v.getDim() != this->dim) {
                throw std::invalid_argument("Input vector dimension must match the dimension of the vector.");
            }
            for (short i = 0; i < this->dim; ++i) {
                this->values[i] = v.values[i];
            }
        }

        /**
         * Getter for vector values
         * @param index The index of the component to set
         * @return the values at the given index
         */
        double get(short index){
            if(index<0 || index > this->dim){
                throw std::out_of_range("Index out of range.");
            }
            return this->values[index];
        }

        /**
         * Overloaded assignment operator that copies the values and dimension from another vector.
         * It checks for self-assignment, allocates new memory for the copied values, copies each value
         * from the source vector, releases the current memory, and then updates the dimension and pointer.
         * @param other The vector to assign from
         * @return A reference to the current vector after assignment
         */
        Vector& operator=(const Vector& other) {
            if (this == &other) return *this;

            double* newValues = new double[other.dim];
            for (short i = 0; i < other.dim; ++i) {
                newValues[i] = other.values[i];
            }

            delete[] values;
            values = newValues;
            dim = other.dim;
            return *this;
        }

        /**
         * Formats the vector contents as "Vector(x1, x2, ..., xn)" where xi are the vector components separated by commas.
         * @return std::string of the vector
         */
        std::string toString() {
            std::string result = "Vector(";
            for(int i = 0; i < this->dim; i++) {
                result += std::to_string(this->get(i));
                if(i < this->dim - 1){
                    result += ", ";
                }
            }
            result += ")";
            return result;
        }

    private:
        short dim; // The dimension of the vector
        double* values; // Pointer to an array of double values representing the components of the vector
};

#endif // VECTOR_HPP
