#ifndef JOBS_H
#define JOBS_H

#include <iostream>
#include <string>
#include <memory>
#include "../model/jobs/JobsInterface.hpp"

class Jobs : public JobInterface {
public:
    Job job;

    Jobs() = default;

    Job getJob() const;
    
protected:

    void setJob(const Job& selectedJob);

};

#endif