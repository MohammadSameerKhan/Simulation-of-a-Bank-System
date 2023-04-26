# Simulation-of-a-Bank-System

Implement the event-driven simulation of a bank that Chapter 13 described. A queue of
arrival events will represent the line of customers in the bank. Maintain the arrival events
and departure events in a priority queue, sorted by the time of event. Use a link-based
implementation for the event list.
The input is a text file of arrival and transaction times. Each line of the file contains the
arrival time and required transaction time for a customer. The arrival times are ordered by
increasing time.
Your program must count customers and keep track of their cumulative waiting time.
These statistics are sufficient to compute the average waiting time after the last event has
been processed.
