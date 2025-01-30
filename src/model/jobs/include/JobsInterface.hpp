#ifndef JOBS_INTERFACE_HPP
#define JOBS_INTERFACE_HPP

#include "Job.hpp"
#include "AttributesProcessor.hpp"

class JobInterface {
public:

    virtual ~JobInterface();

    virtual Job getJob() const;
    
    virtual void skill(AttributesProcessor& attributesProcessor, const int level);

protected:    
    virtual void setJob(const Job& selectedJob);

};

#endif