#include <iostream>
#include <limits>
#include <string>
#include "ProblemSolver.h"

using namespace std;

void ProblemSolver::input(int V, bool is_src) {
    string input;

    int &vrt = is_src ? src : dest;

    string descr = is_src ? "source" : "destination";

    cout << "Select the " + descr + " vertex. Valid values: from 0 to " << V - 1 << endl;
    cout << "Your choice: ";


    do {
        getline(cin,input);

        try {
            vrt = stoi(input);
            if(vrt < 0 || vrt >= V) {

                // Check OS
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif
                cout << "Invalid option!\n";
                cout << "Please choose the " + descr + " vertex again. Valid values: from 0 to " << V - 1 << endl;
                cout << "Your choice: ";
                is_not_valid = true;
            } else is_not_valid = false;
        } catch (const invalid_argument&) {
            is_not_valid  = true;
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            cout << "Invalid option!\n";
            cout << "Please choose the " + descr + " vertex again. Valid values: from 0 to " << V - 1 << endl;
            cout << "Your choice: ";
        } catch (const out_of_range&) {
            is_not_valid  = true;
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            cout << "Invalid option!\n";
            cout << "Please choose the " + descr + " vertex again. Valid values: from 0 to " << V - 1 << endl;
            cout << "Your choice: ";
        }
    } while(is_not_valid);

}
