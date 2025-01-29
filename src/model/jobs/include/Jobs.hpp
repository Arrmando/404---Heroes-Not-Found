#ifndef JOBS_HPP
#define JOBS_HPP

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