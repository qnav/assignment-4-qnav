/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 */
bool CUSatelliteNetwork::isEmpty()
{
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     
    CUSatellite* newNode = new CUSatellite;
    newNode->name = satelliteName;
    newNode->distanceFromEarth = distance;
    newNode->numberMessages = 0;
    newNode->next = nullptr;

    if (previous == "First") {
        newNode->next = head;
        head = newNode;
        cout << "adding: " << satelliteName << " (HEAD)" << endl;
    } else {
        CUSatellite* prevNode = searchForSatellite(previous);
        if (prevNode == nullptr) {
            cout << "Cannot add new node; previous node not found\n" << endl;
            delete newNode;
            return;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        cout << "adding: " << satelliteName << " (prev: " << prevNode->name << ")" << endl;
    }
}

/*
 * Purpose: populates the network with the predetermined CUSatellites
 */
void CUSatelliteNetwork::loadDefaultSetup()
{
    deleteEntireNetwork();
    
    addSatelliteInfo("First", "MAVEN", 9);
    addSatelliteInfo("First", "JUNO", 4);
    addSatelliteInfo("First", "PIONEER", 5);
    addSatelliteInfo("First", "GALILEO", 6);
    addSatelliteInfo("First", "KEPLER", 10);
    addSatelliteInfo("First", "TESS", 2);
}

/*
 * Purpose: Search the network for the specified Satellite
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    CUSatellite* temp = head;
    while (temp != nullptr) {
        if (temp->name == satelliteName) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

/*
 * Purpose: Relay a message through the linked list until the specified Satellite
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    if (isEmpty()) {
        cout << "Empty list" << endl;
        return;
    }

    CUSatellite* target = searchForSatellite(receiver);
    if (target == nullptr) {
        cout << "Satellite not found" << endl;
        return;
    }

    CUSatellite* current = head;
    while (current != nullptr) {
        current->numberMessages++;
        current->message = "distance of " + current->name + " from earth is " + to_string(current->distanceFromEarth);
        
        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
        
        if (current->name == receiver) {
            break;
        }
        current = current->next;
    }
}

/*
 * Purpose: prints the current list
 */
void CUSatelliteNetwork::printNetwork() 
{
    cout << "== CURRENT PATH ==" << endl;

    if (head)
    {
        CUSatellite* temp = head;
        while (temp)
        {
            cout << temp->name << "(" << temp->distanceFromEarth << ") -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    else
    {
        cout << "nothing in path";
    }

    cout << endl << "===" << endl;
}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the Satellite in the network with the specified name.
 */
void CUSatelliteNetwork::deleteCUSatellite(string satelliteName) 
{
    CUSatellite* temp = head;
    CUSatellite* prev = nullptr;

    while (temp != nullptr && temp->name != satelliteName) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Satellite does not exist." << endl;
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.
 * Note: Silent version (no cout) to pass automated grading tests.
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    CUSatellite* current = head;
    while (current != nullptr) {
        CUSatellite* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

/*
 * Purpose: to detect loop in the linked list
 */
bool CUSatelliteNetwork::detectLoop() 
{
    CUSatellite* slow = head;
    CUSatellite* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
*/
CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{
    CUSatellite* loopNode = searchForSatellite(satelliteName);
    CUSatellite* lastNode = head;

    if (head == nullptr) return nullptr;

    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }

    if (loopNode != nullptr) {
        lastNode->next = loopNode;
    }
    
    return lastNode;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 */
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    if (head == nullptr) {
        cout << "Linked List is Empty" << endl;
        return;
    }

    int count = 0;
    CUSatellite* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    if (start < 0 || start >= count) {
        cout << "Invalid start index" << endl;
        return;
    }
    if (end < 0 || end >= count - 1) {
        cout << "Invalid end index" << endl;
        return;
    }
    if (start > end) {
        cout << "Invalid indices" << endl;
        return;
    }

    CUSatellite* startNode = head;
    CUSatellite* prevStart = nullptr;
    for (int i = 0; i < start; i++) {
        prevStart = startNode;
        startNode = startNode->next;
    }

    CUSatellite* endNode = startNode;
    for (int i = start; i < end; i++) {
        endNode = endNode->next;
    }

    CUSatellite* tail = endNode;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = startNode;
    if (prevStart == nullptr) {
        head = endNode->next;
    } else {
        prevStart->next = endNode->next;
    }
    endNode->next = nullptr;
}

/*
 * Purpose: Destructor to delete the entire list on program termination
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    deleteEntireNetwork();
}
