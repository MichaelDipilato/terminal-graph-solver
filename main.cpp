#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <cstdlib>
#include "Graph.h"
#include "ProblemSolver.h"
#include "ProblemSolution.h"
#include "MinimumSpanningTree.h"
#include "SingleSourceShortestPath.h"
#include "AllPairsShortestPath.h"
#include "MaximumFlow.h"

using namespace std;

void clear_terminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funzione che stampa il primo menu
void print_menu() {
    cout << "1\tImport graph from a text file (specify filename);\n";
    cout << "2\tSelect one of the available solver problems;\n";
    cout << "3\tDisplay the solution on standard output;\n";
    cout << "4\tExport the solution to a text file;\n";
    cout << "5\tExit the program.\n";
    cout << "Enter your choice: ";
}

// Funzione che stampa il secondo menu
void print_second_menu() {
    cout << "1.\tMinimum spanning tree using Prim's algorithm.\n";
    cout << "2.\tSingle-source shortest path using Dijkstra's algorithm.\n";
    cout << "3.\tAll-pairs shortest paths using Floyd-Warshall algorithm.\n";
    cout << "4.\tMaximum flow between source and destination using Ford-Fulkerson algorithm.\n";
    cout << "Your choice: ";
}

int main() {

    int choice, second_choice;

    bool file_opened, first_choice_not_valid, second_choice_not_valid;
    bool quit_request = false;

    string filename, input;
    string path = filesystem::current_path().string();

    path += "/instances";

    Graph g;

    ProblemSolver* pb = nullptr;

    ProblemSolution* ps = nullptr;

    ifstream f;

    ofstream out_file("output.txt");

    clear_terminal();
    cout << "Hello! This program allows you to solve ";
    cout << "a set of problems on a simple, connected, weighted graph.\n";
    cout << "Choose one of the 5 available options ";
    cout << "by entering the corresponding number:\n";


    while (!quit_request) {

        print_menu();

        do {
            first_choice_not_valid = false;

            getline(cin,input);
            choice = 0;

            try {
                choice = stoi(input);
            } catch (const invalid_argument&) {
                clear_terminal();
                cerr << "Invalid option!\n";
                cerr << "Please enter your option again:\n";
                print_menu();
                first_choice_not_valid = true;
            } catch (const out_of_range&) {
                clear_terminal();
                cerr << "Invalid option!\n";
                cerr << "Please enter your option again:\n";
                print_menu();
                first_choice_not_valid = true;
            }
        } while (first_choice_not_valid);

        switch (choice) {
            case 1:
                clear_terminal();
                cout << "Choose between these text files:\n";

                for(const auto& file : filesystem::directory_iterator(path))
                    cout << file.path().filename() << endl;

                cout << "\nHow to read a file name:\n";
                cout << "w_sparse means the graph is sparse; the first ";
                cout << "number indicates the number of nodes, and the second ";
                cout << "represents the number of edges.\n";
                cout << "File name: ";

                getline(cin,filename);

                file_opened = g.get_data(f,filename);

                if(file_opened) {
                    clear_terminal();
                    cout << "Great! You can now select another option:\n";
                } else {
                    clear_terminal();
                    cerr << "Failed to open the file ";
                    cerr << "(it may be missing or the name might be wrong)!\n";
                }
                break;
            case 2:

                if(!file_opened) {
                    clear_terminal();
                    cout << "Please select the file to import the graph description first!\n";
                    break;
                }

                clear_terminal();
                cout << "Great! This program ";
                cout << "allows you to solve the following problems:\n";
                print_second_menu();
                input.clear();

                do {
                    second_choice_not_valid = false;

                    getline(cin,input);
                    second_choice = 0;

                    try {
                        second_choice = stoi(input);
                    } catch (const invalid_argument&) {
                        clear_terminal();
                        cerr << "Invalid option!\n";
                        cerr << "Please enter your option again:\n";
                        second_choice_not_valid = true;
                    } catch (const out_of_range&) {
                        clear_terminal();
                        cerr << "Invalid option!\n";
                        cerr << "Please enter your option again:\n";
                        second_choice_not_valid = true;
                    }

                    if (pb != nullptr) {
                        delete pb;
                        pb = nullptr;
                    }

                    if (ps != nullptr) {
                        delete ps;
                        ps = nullptr;
                    }

                    switch(second_choice) {
                        case 1:
                            pb = new MinimumSpanningTree();
                            clear_terminal();
                            ps = pb->solve(g);
                            break;
                        case 2:
                            pb = new SingleSourceShortestPath();
                            clear_terminal();
                            ps = pb->solve(g);
                            break;
                        case 3:
                            pb = new AllPairsShortestPath();
                            clear_terminal();
                            ps = pb->solve(g);
                            break;
                        case 4:
                            pb = new MaximumFlow();
                            clear_terminal();
                            ps = pb->solve(g);
                            break;
                        default:
                            clear_terminal();
                            cerr << "Invalid option!\n";
                            cerr << "Please enter your option again:\n";
                            print_second_menu();
                            second_choice_not_valid = true;
                            break;
                    }

                } while (second_choice_not_valid);


                clear_terminal();
                cout << "Great! Problem solved!\n";
                cout << "Choose a new option:\n";
                break;
            case 3:

                if(!file_opened) {
                    clear_terminal();
                    cout << "Please select the file to import the graph description first!\n";
                    break;
                }

                clear_terminal();

                ps->output(cout);
                cout << "Here's the solution to the solved problem!\n";
                cout << "Press ENTER to go back to the main menu.\n";
                cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
                clear_terminal();
                cout << "Choose another option:\n";
                break;
            case 4:

                if(!file_opened) {
                    clear_terminal();
                    cout << "Please select the file to import the graph description first!\n";
                    break;
                }

                ps->output(out_file);
                clear_terminal();
                cout << "Perfect! Solution exported to the file 'output.txt'.\n";
                cout << "Now choose another option:\n";
                break;
            case 5:

                clear_terminal();
                cout << "Goodbye!\n";
                quit_request = true;
                break;
            default:

                clear_terminal();
                cerr << "Invalid option!\n";
                cerr << "Please enter your option again:\n";
                break;
        }
    }

    if (pb != nullptr) {
    delete pb;
    delete ps;
    }

    return 0;
}
