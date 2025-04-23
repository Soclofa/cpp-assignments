//
//  Clock.cpp
//  Clock
//
//  Created by Avi Soclof on 3/23/22.
//

#include "Clock.hpp"

//constructors
Clock::Clock(){
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int hr, int min, int sec){

    try
    {
        setSec(hr);
        setMin(min);
        setHr(sec);
    }
    
    catch (const char* e){
        hour = 0;
        minute = 0;
        second = 0;
        throw;
    }
    
    hour = hr;
    minute = min;
    second = sec;
}

////copy
//Clock::Clock(Clock& time){
//    hour = time.hour;
//    minute = time.minute;
//    second = time.second;
//}
//
//Clock& Clock::operator= (Clock& time){
//    hour = time.hour;
//    minute = time.minute;
//    second = time.second;
//    return *this;
//}
//
////move
//Clock::Clock(Clock&& time){
//    hour = time.hour;
//    minute = time.minute;
//    second = time.second;
//
//    time.hour = 0;
//    time.second = 0;
//    time.minute = 0;
//}
//Clock& Clock::operator= (Clock&& time){
//    hour = time.hour;
//    minute = time.minute;
//    second = time.second;
//
//    time.hour = 0;
//    time.second = 0;
//    time.minute = 0;
//    return *this;
//}


//setters
void Clock::setHr(int hr){
    if (hr < 0){
        throw "Invalid time - negative number of hours.\n";
    }
    
    if (hr >= 24){
        throw "Invalid time - more than 24 hours.\n";
    }
    
    hour = hr;
}

void Clock::setMin(int min){
    
    if (min < 0){
        throw "Invalid time - negative number of minutes.\n";
    }
    
    if (min >= 60){
        throw "Invalid time - more than 60 minutes.\n";
    }
    
    minute = min;
}

void Clock::setSec(int sec){
    if (sec < 0)
    {
        throw "Invalid time - negative number of seconds.\n";
    }
    
    if (sec >= 60)
    {
        throw "Invalid time - more than 60 seconds.\n";
    }
    
    second = sec;
}

//getters
int Clock::getHr() const{
    return hour;
}

int Clock::getMin() const{
    return minute;
}

int Clock::getSec() const{
    return second;
}


//increments clock based on parameter
Clock& Clock::operator += (int sec){
    
    second += sec;
    
    while (second >= 60){
        second -= 60;
        ++minute;
    }
    
    while (minute >= 60){
        minute -=60;
        ++hour;
    }
    
    if (hour >= 24){
        hour -=24;
    }
    
    return *this;
}

// input and ouput stream operators
ostream& operator<< (ostream& os, const Clock& time){
   
        if (time.hour < 10)
        {
            os << 0;
        }
        os << time.hour << ':';

        if (time.minute < 10)
        {
            os << 0;
        }
        os << time.minute << ':';

        if (time.second < 10)
        {
            os << 0;
        }
        os << time.second << endl;

        return os;
    }



istream& operator>> (istream& is,  Clock& time)
{
    
    int hr, min, sec;
    char colon;
    is >> hr >> colon >> min >>  colon >> sec;
    
    try
    {
        time.setHr(hr);
        time.setMin(min);
        time.setSec(sec);
    }
    
    catch (const char* e){
        time.hour = 0;
        time.minute = 0;
        time.second = 0;
        throw;
    }
    
    return is;
}
