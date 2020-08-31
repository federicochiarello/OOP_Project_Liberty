#ifndef TASKPRIORITYCONTAINER_H
#define TASKPRIORITYCONTAINER_H

#include "taskcontainer.h"
#include "taskpriority.h"

class TaskPriorityContainer : public TaskContainer, public TaskPriority {
public:
	explicit TaskPriorityContainer(const std::string p_label =std::string(), const std::string p_desc =std::string(), List* p_list =nullptr, AbsTask* p_parent =nullptr, QDateTime p_priority =QDateTime());
	explicit TaskPriorityContainer(const QJsonObject& object, std::map<const unsigned short, const unsigned short>& idsMap);

    TaskPriorityContainer*                  clone() const override;
	QJsonObject toJson() const override;
    void                                    setPriority(QDateTime p_priority) override;
    QStringList                             getTaskInfo() const override;
    AbsTask*                                convertToContainer() const override;
    AbsTask*                                convertToPriority() const override;
};

#endif // TASKPRIORITYCONTAINER_H
