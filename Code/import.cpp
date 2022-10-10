#include <iostream>
#include <fstream>
#include <string>
#include "Address.h"

void Import_File(Address **A, uint32_t *numRecords, std::string filename) {
    std::ifstream myfile; 
    myfile.open(filename);

    if ( myfile.is_open() ) {
        std::string split[6];
        std::string buffer;

        uint32_t addr_counter = 0;
        
        uint8_t loopNum = 0;
        while ( myfile.good() ) {
            // First Name
            myfile >> buffer;
            split[0] = buffer;

            // Last Name
            myfile >>  buffer;
            split[1] = buffer;

            // |
            myfile >>  buffer;

            // Begin Street Address
            myfile >>  buffer;
            split[2] = buffer;

            myfile >>  buffer;
            while(buffer != "|") {
                split[2] += " " + buffer;
                myfile >>  buffer;
            }
            // End Street Address

            // Start City
            myfile >>  buffer;
            split[3] = buffer;

            myfile >>  buffer;
            while(buffer != "|") {
                split[3] += " " + buffer;
                myfile >>  buffer;
            }
            // End City

            // State
            myfile >>  buffer;
            split[4] = buffer;

            // |
            myfile >>  buffer;
            
            // Zip
            myfile >>  buffer;
            split[5] = buffer;

            Address *addr = new Address(
                split[0].c_str(),
                split[1].c_str(),
                split[2].c_str(),
                split[3].c_str(),
                split[4].c_str(),
                split[5].c_str()
            );

            A[addr_counter] = addr;
            addr_counter++;
        } 

        (*numRecords) = (addr_counter);         
    }
 } 