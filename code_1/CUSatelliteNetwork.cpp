/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*       This class uses a linked-list of CUSatellite nodes to      */
/*       represent communication paths between Satellites           */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUSatelliteNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 *   between the Satellite previous and the Satellite that follows it in the network.
 * @param previous - name of the Satellite that comes before the new Satellite
 * @param SatelliteName - name of the new Satellite 
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     

    // TODO: Copy-paste your solution from Assignment 3
    
}

/*

 * Purpose: populates the network with the predetermined CUSatellites
 * @param none
 * @return none
 */
void CUSatelliteNetwork::loadDefaultSetup()
{

    deleteEntireNetwork();
    // TODO: Copy-paste your solution from Assignment 3
    
}

/*
 * Purpose: Search the network for the specified Satellite and return a pointer to that node
 * @param SatelliteName - name of the Satellite to look for in the network
 * @return pointer to node of SatelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    // TODO: Copy-paste your solution from Assignment 3
    
    return nullptr;
}

/*
 * Purpose: Relay a message through the linked list until the specified Satellite
 * @param string receiver - name of the Satellite 
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    // TODO: Copy-paste your solution from Assignment 3
    
}

/*

 * Purpose: prints the current list in an organized manner
 * @param none
 * @return none

 */
void CUSatelliteNetwork::printNetwork() 
{
    /* finished. do not touch. */
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
 * @param SatelliteName - name of the Satellite to delete in the network
 * @return none
 */
void CUSatelliteNetwork::deleteCUSatellite(string satelliteName) 

{
    // TODO: Complete this function

}

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.

 * @param: none
 * @return: none
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function

}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUSatelliteNetwork::detectLoop() 
{
    // TODO: Complete this function
    
    return false;
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
* @param SatelliteName - name of the Satellite to loop back to
* returns the last node before loop creation (to break the loop)
*/
CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{
    // TODO: Complete this function
    
    return nullptr;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 * @param: start_index, end_index - indices of start node and the end node
 * @return: none
 */
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    // TODO: Complete this function
    
}

/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    // TODO: Complete this function
    
}