/**
 * A generic dynamic array implementation loosely follows
 * https://youtu.be/tvw4v7FEF1w 
 * stylistically follows std::vector 
 */
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <cstdint>
#include<climits>
namespace dataStructures
{
    unsigned const default_array_capacity = 16;


    template<typename T>
    class dynamicArray
    {
        public:
            // default constructor initializes array with default capacity
            dynamicArray()
            {
                this(default_array_capacity);
            }
            // initializes array with specified capacity
            dynamicArray(unsigned int s){
                this->size=0;
                this->capacity=s;
                arr = new T(s);
            }
            //removes element at given index. Returns false if failed to remove.
            bool removeAt(unsigned int s)
            {
                if(s>=this->getSize()){
                    return false;
                }
                for(unsigned int i=s+1;i<this->getSize(); i++){
                    this->arr[i-1]=this->arr[i];
                }
                --this->size;
                this->trimCapacity();
                return true;
            }
            ~dynamicArray(){
                delete arr;
            }
            unsigned int getSize()
            {
                return size; 
            }

            // returns false if 
            bool insertBack(T val)
            {
                return this->insertAt(this->getSize(), val);
            }
            bool removeBack(){
                return this->removeAt(this->getSize());
            }
            bool insertAt(unsigned int j, T val){
                // will only up capacity if needed
                if(this->size()==UINT_MAX){
                    return false;
                }
                this->upCapacity();

                for(unsigned int i=j; j<this->getSize();j++ )
                {
                    this->arr[i+1]=this->arr[i];
                }
                this->arr[j]=val;
                ++this->size;
                return true;
            }

            void clear()
            {
                 this->size=0;
                 this->trimCapacity();
            }

        private:
            T arr[];
            unsigned int size;
            unsigned int capacity;

            // Capacity isn't changed at every deletion.
            // it is reduced once size falls under half capacity.
            void trimCapacity()
            {
                unsigned int newCapacity=this->capacity;
                // check if capacity falls below minimum
                if(size <= default_array_capacity/2)
                {
                    newCapacity=default_array_capacity;
                } else if(size >= UINT_MAX/2 ) // don't overflow
                {
                    newCapacity=UINT_MAX;
                } else if(this->capacity> (this->size<<1))
                {
                    newCapacity=this->size;
                }

                if(newCapacity != this->capacity){
                    T newarr[];
                    newarr = new T[newCapacity];
                    for(unsigned int i=0; i<this->getSize();i++){
                        newarr[i]=this->arr[i];
                    }
                    //swap array
                    delete[] this->arr;
                    this->arr=newarr;
                    this->capacity=newCapacity;
                }
                return;
            }

            // if capacity not enough then double it.
            void upCapacity()
            {
                unsigned int newCapacity=this->capacity;
                // check if capacity falls below minimum
                if(size >= (UINT_MAX/2)-1 ) // don't overflow
                {
                    newCapacity=UINT_MAX;
                } else if(size+1>this->capacity)
                {
                    newCapacity=this->capacity<<2;
                }

                if(newCapacity != this->capacity){
                    T newarr[];
                    newarr = new T[newCapacity];
                    for(unsigned int i=0; i<this->size();i++){
                        newarr[i]=this->arr[i];
                    }
                    //swap array
                    delete[] this->arr;
                    this->arr=newarr;
                    this->capacity=newCapacity;
                }
                return;                
            }
    }; 
}

#endif