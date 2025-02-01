#include <iostream>
#include <string>
#include <memory>
#include "Jobs.hpp"

Jobs::Jobs() = default;

Job Jobs::getJob() const {
    return job;
}

/**
 * Sets the character's job to the specified job.
 * This method is protected and can only be called by derived classes.
 *
 * @param selectedJob The job to set for the character.
 */
void Jobs::setJob(const Job& selectedJob) {
    job = selectedJob;
}