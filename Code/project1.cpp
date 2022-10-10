#include <string.h>
#include <iostream>
#include <chrono>
#include "Address.h"
#include "Sorts.h"
#include "Import.h"

using namespace std;

// char first_name[50];
// char last_name[50];
// char street_address[50];
// char city[50];
// char state[50];
// char zip[50];

// state
// zip
// city 
// address
// first name
// last name

uint32_t load_file(uint8_t fileNum, Address **A) {
    uint32_t numRecords = 0;

    switch(fileNum) {
        case 0: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_5.dat");
            break;
        }
        case 1: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_100.dat");
            break;
        }
        case 2: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_200.dat");
            break;
        }
        case 3: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_5000.dat");
            break;
        }
        case 4: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_10000.dat");
            break;
        }
        case 5: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_100000.dat");
            break;
        }
        case 6: {
            Import_File(A, &numRecords, "..\\address_data\\addresses_1000000.dat");
            break;
        }
    }

    return numRecords;
}


int main()
{
    uint32_t numRecords = 0;
    Address *arr[100000];

    std::chrono::duration<double> elapsed_seconds;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();



    for(uint8_t i = 0; i < 6; i++) {
        numRecords = load_file(i, arr);

        std::cout << "Testing " << numRecords << " Records" << std::endl;

        start = std::chrono::system_clock::now();
        Insertion_Sort(arr, numRecords);
        end = std::chrono::system_clock::now();
    
        elapsed_seconds = end-start;
        std::cout << "Insertion Sort: " <<  elapsed_seconds.count() * 1000 << " ms" << std::endl;


        numRecords = load_file(i, arr);

        start = std::chrono::system_clock::now();
        Merge_Sort(arr, 0, (numRecords - 1));
        end = std::chrono::system_clock::now();
    
        elapsed_seconds = end-start;
        std::cout << "Merge Sort: " <<  elapsed_seconds.count() * 1000 << " ms" << std::endl;


        numRecords = load_file(i, arr);

        start = std::chrono::system_clock::now();
        Quick_Sort(arr, 0, (numRecords - 1));
        end = std::chrono::system_clock::now();
    
        elapsed_seconds = end-start;
        std::cout << "Quick Sort: " <<  elapsed_seconds.count() * 1000 << " ms" << std::endl;

        std::cout << std::endl;
    }


    
}