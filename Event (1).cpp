/*
 * filename: Event.cpp
 * 
 * Mohammad Sameer Khan  
 *                   04/7/2023
 */
#include "Event.h"


Event::Event()
{
}

Event::Event(bool arrival, int arrivalTime, int transactionTime)
{
   this->arrival = arrival;
   this->time = arrivalTime;
   this->transactionTime = transactionTime;
}
   
bool Event::isArrival() const
{
   return arrival;
}

int Event::getTime() const
{
   return time;
}

int Event::getTransactionTime() const
{
   return transactionTime;
}