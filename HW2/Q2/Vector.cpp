//
//  Vector.cpp
//  Question 2
//
//  Created by Avi Soclof on 2/25/22.
//

#include "Vector.h"

//empty constructor
Vector::Vector(){
    data = new int [1];
    capacity = 2;
    size = 0;
}

//regular constructor
Vector::Vector(int requested_size){
    capacity = pow(2, ceil(log(requested_size) / log(2)));
    data = new int[capacity];
    size = 0;
}

//copy constructor
Vector::Vector(const Vector& v1){
    capacity = v1.capacity;
    size = v1.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++){
        data[i] = v1.data[i];
    }
}

//destructor
Vector::~Vector(){
    if (data != nullptr){
    delete [] data;
    }
}

//get capacity
int Vector::getCapacity(){
    return capacity;
}

//get size of data array
int Vector::getSize(){
    return size;
}

//print array 
void Vector::print(){
    
    cout << "capacity: " << capacity << " size: " << size << " values: ";
    
    for (int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
    cout << endl;
    
}

//assign values at each index of the array and increment size accordingly 
void Vector::assign(const Vector& v1){
   
    int* newData = new int[v1.capacity];

    for (int i = 0; i < v1.size; i++){
        newData[i] = v1.data[i];
    }
    
    data = newData;
    capacity = v1.capacity;
    size = v1.size;
    
    
    
}

//test if two vectors are equal 
bool Vector::isEqual(const Vector& v1){
    bool equal = false;
    
    if (size == v1.size){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (data[i] == v1.data[j]){
                    equal = true;
                }
            }
            if (!equal){
                return false;
            }
        }
    }

    return true;
}

//returns the value at the desired index
int& Vector::at(int index){
    if (index < size && index >= 0){
        return data[index];
    }
    else
        cout << "ERROR" << endl;
    return data[0];
}

// returns the dot product of two vectors of the same size
int Vector::scalmul(const Vector& v1){
    int sum = 0;
    if (size == v1.size){
        for (int i = 0; i < size; i++){
            sum += (data[i]*v1.data[i]);
        }
        return sum;
    }
    
    cout << "ERROR" << endl;
    
    return -1;
}

// concatenatew two data arrays and returns a newvector with the concatenated array 
Vector Vector::strnewcat(const Vector& v1){
    
    Vector newVector;
    
    int newSize = v1.size + size;
    
    int newCapacity = capacity + v1.capacity;
    
    newCapacity = pow(2, ceil(log(newCapacity) / log(2)));
    
    int* combinedData = new int[newCapacity];
    
    for (int i = 0; i< size; i++){
        combinedData[i] = data[i];
    }
    
    for (int i = size; i < newSize; i++){
        combinedData[i] = v1.data[i-v1.size];
    }
    

    
    newVector.data = combinedData;
    newVector.capacity = newCapacity;
    newVector.size = newSize;
    
    return newVector;
}

void Vector::clear(){

    for (int i = 0; i < size; i++){
        data[i] = 0;
    }
    size = 0;
}

//deletes the last value in the size of the array and decrements size accordingly 
void Vector::delLast(){
    if (size == 0){
        cout << "ERROR" << endl;
        return;
    }
    else{
        //might have to change size -1
        data[size-1] = 0;
    }
    size --;
}

//inserts value at the end of the array and increments size accordingly  
void Vector::insert(int val){
    
    if (size == capacity){

        capacity = capacity*2;
        int* extend = new int[capacity];
        
        for (int i = 0; i < size; i++){
            extend[i] = data[i];
        }
        
        data = extend;
       
    }
    
    

        size += 1;
        data[size-1] = val;
       
       

    
}
                

