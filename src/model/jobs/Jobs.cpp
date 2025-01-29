#include <iostream>
#include <string>
#include <memory>
#include "../model/jobs/JobsInterface.hpp"

class Jobs : public JobInterface {
public:
    Job job;

    Jobs() = default;

    Job getJob() const {
        return job;
    }
    
protected:

    void setJob(const Job& selectedJob) {
        job = selectedJob;
    };

};