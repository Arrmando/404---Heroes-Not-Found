#include "../../utils/include/Job.hpp"
#include "../../model/attributes/include/AttributesProcessor.hpp"
#include "JobsInterface.hpp"

JobInterface::~JobInterface() = default;

Job JobInterface::getJob() const {
    throw std::runtime_error("Method not implemented.");
}

/**
 * Pure virtual method to execute the job's skill.
 *
 * @param attributesProcessor The AttributesProcessor object to modify attributes.
 * @param level The character's level, used to scale the skill's effect.
 */
void JobInterface::skill(AttributesProcessor& attributesProcessor, const int level) {
    throw std::runtime_error("Method not implemented.");
}

/**
 * Pure virtual method to set the character's job.
 *
 * @param selectedJob The job to set for the character.
 */
void JobInterface::setJob(const Job& selectedJob) {
    throw std::runtime_error("Method not implemented.");
}