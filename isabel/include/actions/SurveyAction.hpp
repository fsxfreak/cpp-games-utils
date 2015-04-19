#ifndef SURVEY_ACTION_HPP
#define SURVEY_ACTION_HPP

#include <actions/Action.hpp>

class SurveyAction final : public Action
{
public:
	SurveyAction(void *o);
	virtual void usage() const override;
	virtual void execute(const std::string& arg) const override;
};

#endif