#pragma once

#include <string.h>
#include <iostream>

class Address {
public:
    char first_name[50];
    char last_name[50];
    char street_address[50];
    char city[50];
    char state[50];
    char zip[50];

    char first_name_disp[50];
    char last_name_disp[50];
    char street_address_disp[50];
    char city_disp[50];
    char state_disp[50];
    char zip_disp[50];

    
    Address(const char* first_name_in,
        const char* last_name_in,
        const char* street_address_in,
        const char* city_in,
        const char* state_in,
        const char* zip_in ) 
    {
        strcpy(first_name, first_name_in);
        strcpy(last_name, last_name_in);
        strcpy(street_address, street_address_in);
        strcpy(city, city_in);
        strcpy(state, state_in);
        strcpy(zip, zip_in);

        strcpy(first_name_disp, first_name_in);
        strcpy(last_name_disp, last_name_in);
        strcpy(street_address_disp, street_address_in);
        strcpy(city_disp, city_in);
        strcpy(state_disp, state_in);
        strcpy(zip_disp, zip_in);

        for(int i = 0; i < 50; i++) {
            first_name[i] = tolower(first_name[i]);
            last_name[i] = tolower(last_name[i]);
            street_address[i] = tolower(street_address[i]);
            city[i] = tolower(city[i]);
            state[i] = tolower(state[i]);
            zip[i] = tolower(zip[i]);
        }
    }

    void display() {
        std::cout << first_name_disp << " " << last_name_disp << " | " << street_address_disp << " | " << city_disp << " | " << state_disp << " | " << zip_disp << std::endl;
    }
};

bool GreaterThan(const Address *addr1, const Address *addr2);

bool LessThan(const Address *addr1, const Address *addr2);

bool EqualTo(const Address *addr1, const Address *addr2);