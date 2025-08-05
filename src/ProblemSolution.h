#ifndef PROBLEMSOLUTION_H
#define PROBLEMSOLUTION_H

#include <iostream>

class ProblemSolution {
public:

    ProblemSolution() = default;

    virtual ~ProblemSolution() {}

    virtual std::ostream & output(std::ostream &) const = 0;

};

#endif
