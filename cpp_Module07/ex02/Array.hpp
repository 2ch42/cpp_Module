#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int    length;
    public:
        Array()
        {
            this->length = 0;
            this->arr = new T();
        }
        Array(unsigned int n)
        {
            this->length = n;
            this->arr = new T[n]();
        }
        Array(const Array& array)
        {
            this->length = array.length;
            this->arr = new T[array.length]();
            for(int i = 0; i < array.length; i++)
            {
                this->arr[i] = array.arr[i];
            }
        }
        Array& operator=(const Array& array)
        {
            if (this != &array)
            {
                this->length = array.length;
                this->arr = new T[array.length]();
                for(int i = 0; i < array.length; i++)
                {
                    this->arr[i] = array[i];
                }
            }
            return (*this);
        }
        T& operator[] (unsigned int n)
        {
            if (n < length)
                return (this->arr[n]);
            else
                throw (std::runtime_error("Out of Bounds!"));
        }
        unsigned int  size() const
        {
            return (this->length);
        }
        ~Array()
        {
            if (this->arr)
                delete[] arr;
        }
};

#endif