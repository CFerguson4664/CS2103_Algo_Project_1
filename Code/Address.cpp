#include <string.h>
#include "Address.h"

bool GreaterThan(const Address *addr1, const Address *addr2) {
    // state
    // zip
    // city 
    // address
    // first name
    // last name
    
    int temp = strcmp(addr1->state, addr2->state);

    if(temp > 0) {
        return true;
    }
    else if(temp == 0) {
        temp = strcmp(addr1->zip, addr2->zip);

        if(temp > 0) {
            return true;
        }
        else if(temp == 0) {
            temp = strcmp(addr1->city, addr2->city);

            if(temp > 0) {
                return true;
            }
            else if(temp == 0) {
                temp = strcmp(addr1->street_address, addr2->street_address);

                if(temp > 0) {
                    return true;
                }
                else if(temp == 0) {
                    temp = strcmp(addr1->first_name, addr2->first_name);

                    if(temp > 0) {
                        return true;
                    }
                    else if(temp == 0) {
                        if(strcmp(addr1->last_name, addr2->last_name) > 0) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool LessThan(const Address *addr1, const Address *addr2) {
    // state
    // zip
    // city 
    // address
    // first name
    // last name
    
    int temp = strcmp(addr1->state, addr2->state);

    if(temp < 0) {
        return true;
    }
    else if(temp == 0) {
        temp = strcmp(addr1->zip, addr2->zip);

        if(temp < 0) {
            return true;
        }
        else if(temp == 0) {
            temp = strcmp(addr1->city, addr2->city);

            if(temp < 0) {
                return true;
            }
            else if(temp == 0) {
                temp = strcmp(addr1->street_address, addr2->street_address);

                if(temp < 0) {
                    return true;
                }
                else if(temp == 0) {
                    temp = strcmp(addr1->first_name, addr2->first_name);

                    if(temp < 0) {
                        return true;
                    }
                    else if(temp == 0) {
                        if(strcmp(addr1->last_name, addr2->last_name) < 0) {
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

bool EqualTo(const Address *addr1, const Address *addr2) {
    // state
    // zip
    // city 
    // address
    // first name
    // last name
    
    int temp = strcmp(addr1->state, addr2->state);

    if(temp != 0) {
        return false;
    }
    else {
        temp = strcmp(addr1->zip, addr2->zip);

        if(temp != 0) {
            return false;
        }
        else {
            temp = strcmp(addr1->city, addr2->city);

            if(temp != 0) {
                return false;
            }
            else {
                temp = strcmp(addr1->street_address, addr2->street_address);

                if(temp != 0) {
                    return false;
                }
                else {
                    temp = strcmp(addr1->first_name, addr2->first_name);

                    if(temp != 0) {
                        return false;
                    }
                    else {
                        if(strcmp(addr1->last_name, addr2->last_name) != 0) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}