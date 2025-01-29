#ifndef JOBS_INTERFACE_HPP
#define JOBS_INTERFACE_HPP

#include "../utils/include/Job.hpp"
#include "../model/attributes/include/AttributesProcessor.hpp"

class JobInterface {
public:

    virtual ~JobInterface() = default;

    virtual Job getJob() const = 0;
    
    virtual std::string getJobSpecialTrait() const = 0;

    virtual void skill(AttributesProcessor& attributesProcessor, const int level) = 0;

protected:    
    virtual void setJob(const Job& selectedJob) = 0;

};

#endif