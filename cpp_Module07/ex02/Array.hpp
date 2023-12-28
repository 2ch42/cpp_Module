#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int    size;
    public:
        Array()
        {
            this->size = 0;
            this->arr = new T();
        }
        Array(unsigned int n)
        {
            this->size = n;
            this->arr = new T[n]();
        }
        Array(const Array& array)
        {
            this->size = array.size;
            this->arr = new T[array.size]();
            for(int i = 0; i < array.size; i++)
            {
                this->arr[i] = array.arr[i];
            }
        }
        Array& operator=(const Array& array)
        {
            if (this != &array)
            {
                
            }
            return (*this);
        }
        T& Array[unsigned int n];
        ~Array();
};

#endif